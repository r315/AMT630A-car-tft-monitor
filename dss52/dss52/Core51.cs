using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace dss52
{
    public interface IInstruction
    {
        Instruction GetInstruction(ref UInt16 pc);

        int Execute();
    }

    public class Instruction : IEqualityComparer<Instruction>
    {
        private int pc;
        private byte opcode;

        private int next_addr {
            get; set;
        }

        private string [] mnemonics;

        public Instruction()
        {
            mnemonics = null;
            this.pc = 0;
            this.opcode = 0;
            next_addr = 0;
        }

        public Instruction(int pc, byte opcode, string [] mnm)
        {
            mnemonics = mnm;
            this.pc = pc;
            this.opcode = opcode;
            next_addr = 0;
        }

        public UInt16 GetAddress()
        {
            return (UInt16)(pc & 0xFFFF);
        }

        public string [] GetStrings()
        {
            return mnemonics;
        }

        public string GetMnmemonic()
        {
            return mnemonics[2];
        }

        public string GetEncoding()
        {
            return mnemonics[1];
        }

        public bool TryGetBranch(out UInt16 jump_addr)
        {
            if (next_addr != 0) {
                jump_addr = (UInt16)(next_addr);
                return true;
            }

            jump_addr = 0;
            return false;
        }

        public void SetJump(int jmp)
        {
            if(next_addr == 0) {
                next_addr = jmp;
            }
        }

        public byte GetOpcode()
        {
            return opcode;
        }

        public bool Equals(Instruction x, Instruction y)
        {
            return x.pc == y.pc;
        }

        public int GetHashCode(Instruction inst)
        {
            return inst.GetOpcode();
        }
    }

    /**
    * ACALL addr11
    * */
    class Acall : IInstruction
    {
        private Core51 core;
        public Acall(Core51 core)
        {
            this.core = core;

            for (int i = 0; i < 8; i++)
            {
                core.AddInstruction((byte)(0x11 + (i << 5)), this);
            }
        }

        private UInt16 NextPc(UInt16 pc)
        {
            UInt16 rel = (UInt16)(((core.program_memory[pc] & 0xE0) << 3) | core.program_memory[pc + 1]);
            return (UInt16)(((pc + 2) & 0xF800) | rel);
        }

        public Instruction GetInstruction(ref UInt16 pc)
        {
            return core.Branch(ref pc, "acall ", NextPc(pc));
        }

        public int Execute()
        {
            core.push((byte)((core.pc + 2) & 255));
            core.push((byte)(((core.pc + 2) >> 8) & 255));
            core.pc = NextPc(core.pc);
            return 2;
        }
    }

    /**
    * ADD A,<src-byte>
    * ADDC A,<src-byte>
    * */
    class Add : IInstruction
    {
        private Core51 core;
        private int cycles;
        public Add(Core51 core)
        {
            this.core = core;
            for (int i = 0; i < 12; i++)
            {
                core.AddInstruction((byte)(0x24 + i), this);
                core.AddInstruction((byte)(0x34 + i), this);
            }
        }
        private void add(int value, int acc)
        {
            /* Carry: overflow from 7th bit to 8th bit */
            byte carry = (((core.acc & 0xFF) + (value & 0xFF) + acc) & 0x100) != 0 ? Core51.CY : (byte)0;

            /* Auxiliary carry: overflow from 3th bit to 4th bit */
            byte auxcarry = (((core.acc & 0x07) + (value & 0x07) + acc) & 0x10) != 0 ? Core51.AC : (byte)0;

            /* Overflow: overflow from 6th or 7th bit, but not both */
            byte overflow = ((((core.acc & 0x7F) + (value & 0x7F) + acc) & 0x80) ^ carry) != 0 ? Core51.OV : (byte)0;

            core.acc += (byte)value;

            core.psw = (byte)((core.psw & 0x3B) | carry | auxcarry | overflow);          
        }

        private Instruction Decode(ref UInt16 pc, bool execute)
        {                   
            byte opcode = core.program_memory[pc];
            byte op1 = core.program_memory[pc + 1];

            switch (opcode)
            {
                case 0x24: // ADD A,#data
                    if (execute){
                        add(op1, 0);                        
                        break;
                    }
                    return core.Operand(ref pc, String.Format("add   a,#{0:X2}h", op1));                    

                case 0x25: // ADD A,direct
                    if (execute){
                        add(core.ReadIntMemory(op1, false), 0);                        
                        break;
                    }                    
                    return core.Operand(ref pc, String.Format("add   a,{0}", core.GetDirectName(op1)));
                    

                case 0x26: // ADD A,@Ri
                case 0x27:
                    if (execute){
                        byte idx = core.r[opcode & 1];
                        add(core.ReadIntMemory(idx, true), 0);                        
                        break;
                    }
                    return core.Operand(ref pc, String.Format("add   a,@r{0}", opcode & 1));                    

                case 0x28: //ADD A,Rn
                case 0x29:
                case 0x2A:
                case 0x2B:
                case 0x2C:
                case 0x2D:
                case 0x2E:
                case 0x2F:
                    if (execute){
                        add(core.r[opcode & 7], 0);                        
                        break;
                    }
                    return core.Operand(ref pc, String.Format("add   a,r{0}", opcode & 7));                    

                case 0x34: // ADDC A,#data
                    if (execute) {                        
                        add(op1, core.carry);                        
                        break;
                    }
                    return core.Operand(ref pc, String.Format("addc  a,#{0:X2}h", op1));
                    

                case 0x35: // ADDC A,direct
                    if (execute){
                        add(core.ReadIntMemory(op1, false), core.carry);                        
                        break;
                    }
                    return core.Operand(ref pc, String.Format("addc  a,{0}", core.GetDirectName(op1)));                    

                case 0x36: // ADDC A,@Ri
                case 0x37:
                    if (execute) {
                        byte idx = core.r[opcode & 1];
                        add(core.ReadIntMemory(idx, true), core.carry);                        
                        break;
                    }
                    return core.Operand(ref pc, String.Format("addc  a,@r{0}", opcode & 1));                    

                case 0x38: //ADDC A,Rn
                case 0x39:
                case 0x3A:
                case 0x3B:
                case 0x3C:
                case 0x3D:
                case 0x3E:
                case 0x3F:
                    if (execute){
                        add(core.r[opcode & 7], core.carry);                        
                        break;
                    }
                    return core.Operand(ref pc, String.Format("addc  a,r{0}", opcode & 7));                    
            }
            if (execute) {
                core.pc = (UInt16)(core.pc + core.inst_bytes[opcode]);
                cycles = core.inst_cycles[opcode];
            }
            return null;
        }

        public Instruction GetInstruction(ref UInt16 pc)
        {
            return Decode(ref pc, false);
        }
        public int Execute()
        {
            Decode(ref core.pc, true);
            return cycles;
        }
    }
    
    /**
        * AJMP addr11
        * */
    class Ajmp : IInstruction
    {
        private Core51 core;
        public Ajmp(Core51 core)
        {
            this.core = core;

            for (int i = 0; i < 8; i++)
            {
                core.AddInstruction((byte)(0x01 + (i << 5)), this);
            }
        }

        private UInt16 nextPc(UInt16 pc)
        {
            Int32 rel = ((Int32)(core.program_memory[pc] & 0xE0) << 3) | core.program_memory[pc + 1];
            return (UInt16)(((pc + 2) & 0xF800) + rel);
        }
        public Instruction GetInstruction(ref UInt16 pc)
        {
            return core.Branch(ref pc, "ajmp  ", nextPc(pc));
        }
        public int Execute()
        {            
            core.pc = nextPc(core.pc);
            return 2;
        }
    }

    /**
       * ANL <dst-byte>,<src-byte>
       * ANL C,<src-bit>
       * */
    class Anl : IInstruction
    {
        private Core51 core;
        private int cycles;
        public Anl(Core51 core)
        {
            this.core = core;

            for (int i = 0; i < 14; i++)
            {
                core.AddInstruction((byte)(0x52 + i), this);
            }

            core.AddInstruction(0x82, this);
            core.AddInstruction(0xB0, this);
        }

        private Instruction Decode(ref UInt16 pc, bool execute)
        {
            byte opcode = core.program_memory[pc];
            byte op1 = core.program_memory[pc + 1];
            byte op2 = core.program_memory[pc + 2];

            switch (opcode)
            {
                case 0x52: // ANL direct,A
                    if (execute) {
                        core.WriteIntMemory(op1, (byte)(core.acc & core.ReadIntMemory(op1, false)), false);
                        break;
                    }
                    return core.Operand(ref pc, String.Format("anl   {0},a", core.GetDirectName(op1)));                    

                case 0x53: // ANL direct,#data
                    if (execute) {
                        core.WriteIntMemory(op1, (byte)(core.ReadIntMemory(op1, false) & op2), false);
                        break;
                    }
                    return core.Operand(ref pc, String.Format("anl   {0},#{1:X2}h", core.GetDirectName(op1), op2));
                    
                case 0x54: // ANL A,#data
                    if (execute) {
                        core.acc = (byte)(core.acc & op1);
                        break;
                    }
                    return core.Operand(ref pc, String.Format("anl   a,#{0:X2}h", op1));
                    
                case 0x55: // ANL A,direct
                    if (execute) {
                        core.acc = (byte)(core.acc & core.ReadIntMemory(op1, false));
                        break;
                    }
                    return core.Operand(ref pc, String.Format("anl   a,{0}", core.GetDirectName(op1)));

                case 0x56: // ANL A,@Ri
                case 0x57:
                    if (execute) {
                        byte idx = core.r[opcode & 1];
                        core.acc = (byte)(core.acc & core.ReadIntMemory(idx, true));
                        break;
                    }
                    return core.Operand(ref pc, String.Format("anl   a,@r{0}", opcode & 1));
                    
                case 0x58: //ANL A,Rn
                case 0x59:
                case 0x5A:
                case 0x5B:
                case 0x5C:
                case 0x5D:
                case 0x5E:
                case 0x5F:
                    if (execute) {                        
                        core.acc = (byte)(core.acc & core.r[opcode & 7]);
                        break;
                    }
                    return core.Operand(ref pc, String.Format("anl   a,r{0}", opcode & 7));

                case 0x82: // ANL C,bit
                    if (execute) {
                        core.carry = (byte)(core.carry & core.ReadBitMemory(op1));
                        break;
                    }
                    return core.Operand(ref pc, String.Format("anl   c,{0:X2}h", core.program_memory[pc + 1]));

                case 0xB0: // ANL C,/bit
                    if (execute) {
                        core.carry = (byte)(core.carry & (core.ReadBitMemory(op1) ^ 1));
                        break;
                    }
                    return core.Operand(ref pc, String.Format("anl   c,/{0:X2}h", core.program_memory[pc + 1]));

            }
            if (execute) {
                core.pc = (UInt16)(core.pc + core.inst_bytes[opcode]);
                cycles = core.inst_cycles[opcode];
            }
            return null;
        }
        public Instruction GetInstruction(ref UInt16 pc)
        {
            return Decode(ref pc, false);
        }
        public int Execute()
        {
            Decode(ref core.pc, true);
            return cycles;
        }
    }

    /**
        * CJNE <dst-byte>,<src-byte>,rel
        * */
    class Cjne : IInstruction
    {
        private Core51 core;
        private int cycles;
        public Cjne(Core51 core)
        {
            this.core = core;
            for (int i = 0; i < 12; i++)
            {
                core.AddInstruction((byte)(0xB4 + i), this);
            }

        }
        private void cjne(byte op1, byte op2, ref UInt16 pc, int next_pc)
        {
            if(op1 != op2) {
                pc = (UInt16)(next_pc & 0xffff);
            } else {
                pc = (UInt16)(pc + 3);
            }

            if(op1 < op2) {
                core.carry = 1;
            } else {
                core.carry = 0;
            }
        }

        private Instruction Decode(ref UInt16 pc, bool execute)
        {            
            byte opcode = core.program_memory[pc];
            byte op1 = core.program_memory[pc + 1];
            byte op2 = core.program_memory[pc + 2];
            Int32 next_pc;

            next_pc = (pc + 3) + ((op2 & 0x80) == 0 ? op2 : (Int32)(op2 | 0xFFFFFF00));

            switch (opcode)
            {
                case 0xB4: // CJNE A,#data,rel
                    if (execute) {
                        cjne(core.acc, op1, ref pc, next_pc);
                        break;
                    }
                    return core.Branch(ref pc, String.Format("cjne  A,#{0:X2}h,", op1), next_pc);

                case 0xB5: // CJNE A,direct,rel
                    if (execute) {
                        cjne(core.acc, core.ReadIntMemory(op1,false), ref pc, next_pc);
                        break;
                    }
                    return core.Branch(ref pc, String.Format("cjne  A,{0},", core.GetDirectName(op1)), next_pc);
                    
                case 0xB6: // CJNE @Ri,#data,rel
                case 0xB7:
                    if (execute) {
                        byte idx = core.r[opcode & 1];
                        cjne(core.ReadIntMemory(idx, true), op1, ref pc, next_pc);
                        break;
                    }
                    return core.Branch(ref pc, String.Format("cjne  @r{0},#{1:X2}h,", (opcode & 1), op1), next_pc);

                case 0xB8: // CJNE Rn,#data,rel
                case 0xB9:
                case 0xBA:
                case 0xBB:
                case 0xBC:
                case 0xBD:
                case 0xBE:
                case 0xBF:
                    if (execute) {
                        cjne(core.r[opcode & 7], op1, ref pc, next_pc);
                        break;
                    }
                    return core.Branch(ref pc, String.Format("cjne  r{0},#{1:X2}h,", (opcode & 7), op1), next_pc);
            }

            if (execute) {                
                cycles = core.inst_cycles[opcode];
            }
            return null;
        }
        public Instruction GetInstruction(ref UInt16 pc)
        {
            return Decode(ref pc, false);
        }
        public int Execute()
        {           
            Decode(ref core.pc, true);
            return cycles;
        }
    }

    /**
    * CLR A
    * CLR bit
    * CPL A
    * CPL bit
    * SETB bit
    * */
    class ClrSetCpl : IInstruction
    {
        private Core51 core;
        private int cycles;
        public ClrSetCpl(Core51 core)
        {
            this.core = core;
            core.AddInstruction(0xC2, this);
            core.AddInstruction(0xC3, this);
            core.AddInstruction(0xE4, this);

            core.AddInstruction(0xB2, this);
            core.AddInstruction(0xB3, this);
            core.AddInstruction(0xF4, this);

            core.AddInstruction(0xD3, this);
            core.AddInstruction(0xD2, this);
        }
        private Instruction Decode(ref UInt16 pc, bool execute)
        {
            byte opcode = core.program_memory[pc];
            byte op1 = core.program_memory[pc + 1];               

            switch (opcode) {
                case 0xC2: // CLR bit
                    if (execute) {
                        core.WriteBitMemory(op1, 0);
                        break;
                    }
                    return core.Operand(ref pc, String.Format("clr   {0:X2}h", op1));

                case 0xC3: // CLR C
                    if (execute) {
                        core.carry = 0;
                        break;
                    }
                    return core.Operand(ref pc, "clr   c");

                case 0xE4: // CLR A
                    if (execute) {
                        core.acc = 0;                        
                        break;
                    }
                    return core.Operand(ref pc, "clr   a");

                case 0xB2: // CPL bit
                    if (execute) {
                        core.WriteBitMemory(op1, (byte)(core.ReadBitMemory(op1) ^ 1));
                        break;
                    }
                    return core.Operand(ref pc, String.Format("cpl   {0:X2}h", op1));

                case 0xB3: // CPL C
                    if (execute) {
                        core.psw = (byte)(core.psw ^ 0x80);
                        break;
                    }
                    return core.Operand(ref pc, "cpl   c");

                case 0xF4: // CPL A
                    if (execute) {
                        core.acc = (byte)(~core.acc);
                        break;
                    }
                    return core.Operand(ref pc, "cpl   a");

                case 0xD2: // SETB bit
                    if (execute) {
                        core.WriteBitMemory(op1, 1);                                          
                        break;
                    }
                    return core.Operand(ref pc, String.Format("setb  {0:X2}h", op1));

                case 0xD3: // SETB C
                    if(execute) {
                        core.psw = (byte)(core.psw | 0x80);
                        break;
                    }
                    return core.Operand(ref pc, "setb  c");
            }

            if (execute) {
                pc = (UInt16)(pc + core.inst_bytes[opcode]);
                cycles = core.inst_cycles[opcode];
            }
            return null;
        }
        public Instruction GetInstruction(ref UInt16 pc)
        {
            return Decode(ref pc, false);
        }
        public int Execute()
        {
            Decode(ref core.pc, true);            
            return cycles; 
        }
    }
    
    /**
    * DA A
    * */
    class Da : IInstruction
    {
        private Core51 core;
        public Da(Core51 core)
        {
            this.core = core;
            core.AddInstruction(0xD4, this);
        }
        public Instruction GetInstruction(ref UInt16 pc)
        {
            return core.Operand(ref pc, "da    a");
        }
        public int Execute()
        {
            int result = core.acc;
            if ((result & 0xf) > 9 || (core.psw & Core51.AC) != 0)
                result += 0x6;
            if ((result & 0xff0) > 0x90 || (core.psw & Core51.CY) != 0)
                result += 0x60;
            if (result > 0x99)
                core.psw |= Core51.CY;

            core.acc = (byte)(result & 0xff);

            core.pc++;
            return 1;
        }
    }


    /**
    * DEC <byte>
    * */
    class Dec : IInstruction
    {
        private Core51 core;
        private int cycles;
        public Dec(Core51 core)
        {
            this.core = core;
            for (int i = 0; i < 12; i++)
            {
                core.AddInstruction((byte)(0x14 + i), this);
            }
        }        
        private Instruction Decode(ref UInt16 pc, bool execute)
        {            
            byte opcode = core.program_memory[pc];
            byte op1 = core.program_memory[pc + 1];

            switch (opcode)
            {
                case 0x14: // DEC A
                    if (execute) {
                        core.acc--;
                        break;
                    }
                    return core.Operand(ref pc, "dec   a");                   

                case 0x15: // DEC direct
                    if (execute) {
                        byte data = core.ReadIntMemory(op1, false);
                        data--;
                        core.WriteIntMemory(op1, data, false);
                        break;
                    }
                    return core.Operand(ref pc, String.Format("dec   {0}", core.GetDirectName(op1)));

                case 0x16: // DEC @Ri
                case 0x17:
                    if (execute) {
                        byte idx = core.r[opcode & 1];
                        byte data = core.ReadIntMemory(idx, true);
                        data--;
                        core.WriteIntMemory(idx, data, true);
                        break;
                    }
                    return core.Operand(ref pc, String.Format("dec   @r{0}", opcode & 1));

                case 0x18: //DEC Rn
                case 0x19:
                case 0x1A:
                case 0x1B:
                case 0x1C:
                case 0x1D:
                case 0x1E:
                case 0x1F:
                    if (execute) {
                        core.r[opcode & 7]--;
                        break;
                    }
                    return core.Operand(ref pc, String.Format("dec   r{0}", opcode & 7));

            }

            if (execute) {
                pc = (UInt16)(pc + core.inst_bytes[opcode]);
                cycles = core.inst_cycles[opcode];
            }

            return null;
        }
        public Instruction GetInstruction(ref UInt16 pc)
        {
            return Decode(ref pc, false);
        }
        public int Execute()
        {
            Decode(ref core.pc, true);
            return cycles;
        }
    }

    /**
    * DIV AB
    * */
    class Div : IInstruction
    {
        private Core51 core;
        public Div(Core51 core)
        {
            this.core = core;
            core.AddInstruction(0x84, this);
        }
        public Instruction GetInstruction(ref UInt16 pc)
        {
            return core.Operand(ref pc, "div   ab");            
        }
        public int Execute()
        {
            int a = core.acc;
            int b = core.b;
            int res;

            core.psw = (byte)(core.psw & ~(Core51.CY | Core51.OV));

            if (b != 0) {
                res = a / b;
                b = a % b;
                a = res;
            } else {
                core.psw = (byte)(core.psw | Core51.OV);
            }

            core.acc = (byte)(a & 255);
            core.b = (byte)(b & 255);
            core.pc = (UInt16)(core.pc + 1);
            return 4;
        }
    }

    /**
    * DJNE <byte>,<rel-addr>
    * */
    class Djnz : IInstruction
    {
        private Core51 core;
        private int cycles;
        public Djnz(Core51 core)
        {
            this.core = core;

            core.AddInstruction(0xD5, this);

            for (int i = 0; i < 8; i++)
            {
                core.AddInstruction((byte)(0xD8 + i), this);
            }
        }       

        public Instruction Decode(ref UInt16 pc, bool execute)
        {            
            byte opcode = core.program_memory[pc];
            byte op1 = core.program_memory[pc + 1];
            byte op2 = core.program_memory[pc + 2];
            byte data = 0;
            UInt16 next_pc = 0;

            int inst_bytes = core.inst_bytes[opcode];

            switch (opcode)
            {
                case 0xD5: // DJNE direct,rel
                    next_pc = (UInt16)((pc + inst_bytes) + ((op2 & 0x80) == 0 ? op2 : (Int32)(op2 | 0xFFFFFF00)) & 0xFFFF);
                    if (execute) {
                        data = core.ReadIntMemory(op1, false);
                        core.WriteIntMemory(op1, --data, false);                                           
                        break;
                    }                       
                    return core.Branch(ref pc, String.Format("djnz  {0},", core.GetDirectName(op1)), next_pc);                    

                case 0xD8: // DJNE Rn,rel
                case 0xD9:
                case 0xDA:
                case 0xDB:
                case 0xDC:
                case 0xDD:
                case 0xDE:
                case 0xDF:
                    next_pc = (UInt16)((pc + inst_bytes) + ((op1 & 0x80) == 0 ? op1 : (Int32)(op1 | 0xFFFFFF00)) & 0xFFFF);
                    if (execute) {
                        data = core.r[opcode & 7];
                        core.r[opcode & 7] = (--data);                        
                        break;
                    }                    
                    return core.Branch(ref pc, String.Format("djnz  r{0},", (opcode & 7)), next_pc);                    
            }

            if (execute) {
                if (data != 0) {
                    pc = next_pc;
                } else {
                    pc = (UInt16)(pc + inst_bytes);
                }
                cycles = core.inst_cycles[opcode];
            }

            return null;
        }
        public Instruction GetInstruction(ref UInt16 pc)
        {
            return Decode(ref pc, false);
        }
        public int Execute()
        {
            Decode(ref core.pc, true);
            return cycles;
        }
    }

    /**
    * INC <byte>
    * */
    class Inc : IInstruction
    {
        private Core51 core;
        private int cycles;
        public Inc(Core51 core)
        {
            this.core = core;
            for (int i = 0; i < 12; i++)
            {
                core.AddInstruction((byte)(0x04 + i), this);
            }
        }

        public Instruction Decode(ref UInt16 pc, bool execute)
        {
            byte opcode = core.program_memory[pc];
            byte op1 = core.program_memory[pc + 1];
            byte op2 = core.program_memory[pc + 2];            

            int inst_bytes = core.inst_bytes[opcode];

            switch (opcode)
            {
                case 0x04: // INC A
                    if (execute) {
                        core.acc++;
                        break;
                    }
                    return core.Operand(ref pc, "inc   a");                    

                case 0x05: // INC direct
                    if (execute) {
                        byte data = core.ReadIntMemory(op1, false);
                        data++;
                        core.WriteIntMemory(op1, data, false);
                        break;
                    }
                    return core.Operand(ref pc, String.Format("inc   {0}", core.GetDirectName(op1)));                    

                case 0x06: // INC @Ri
                case 0x07:
                    if (execute) {
                        byte idx = core.r[opcode & 1];
                        byte data = core.ReadIntMemory(idx, true);
                        data++;
                        core.WriteIntMemory(idx, data, true);
                        break;
                    }                    
                    return core.Operand(ref pc, String.Format("inc   @r{0}", opcode & 1));                    

                case 0x08: //INC Rn
                case 0x09:
                case 0x0A:
                case 0x0B:
                case 0x0C:
                case 0x0D:
                case 0x0E:
                case 0x0F:
                    if (execute) {
                        core.r[opcode & 7]++;
                        break;
                    }
                    return core.Operand(ref pc, String.Format("inc   r{0}", opcode & 7));
            }

            if (execute) {
                pc = (UInt16)(pc + core.inst_bytes[opcode]);
                cycles = core.inst_cycles[opcode];
            }

            return null;
        }
        public Instruction GetInstruction(ref UInt16 pc)
        {
            return Decode(ref pc, false);
        }
        public int Execute()
        {
            Decode(ref core.pc, true);
            return cycles;
        }
    }

    /**
    * INC dptr
    * */
    class Inc_dptr : IInstruction
    {
        private Core51 core;
        public Inc_dptr(Core51 core)
        {
            this.core = core;
            core.AddInstruction(0xA3, this);
        }
        public Instruction GetInstruction(ref UInt16 pc)
        {
            return core.Operand(ref pc, "inc   dptr");
        }
        public int Execute()
        {
            core.dptr++;
            core.pc++;
            return 2;
        }
    }

    /**
    * JBC bit,rel
    * JB bit,rel
    * JNB bit,rel
    * JC rel
    * JNC rel
    * JZ rel
    * JNZ rel
    * */
    class Jbit : IInstruction
    {
        private Core51 core;
        private int cycles;
        public Jbit(Core51 core)
        {
            this.core = core;
            core.AddInstruction(0x10, this);
            core.AddInstruction(0x20, this);
            core.AddInstruction(0x30, this);
            core.AddInstruction(0x40, this);
            core.AddInstruction(0x50, this);
            core.AddInstruction(0x60, this);
            core.AddInstruction(0x70, this);
        }

        private UInt16 NextPc(UInt16 pc, int inst_bytes, byte rel)
        {           
            return (UInt16)(((pc + inst_bytes) + ((rel & 0x80) == 0 ? rel : (Int32)(rel | 0xFFFFFF00))) & 0xFFFF);            
        }
        public Instruction Decode(ref UInt16 pc, bool execute)
        {
            byte opcode = core.program_memory[pc];
            byte op1 = core.program_memory[pc + 1];
            byte op2 = core.program_memory[pc + 2];            
            int inst_bytes = core.inst_bytes[opcode];
            UInt16 next_pc = 0;
            bool jump = false;

            switch (opcode) {                

                case 0x10: // JBC bit,rel
                    next_pc = NextPc(pc, inst_bytes, op2);
                    if (execute) {
                        if(core.ReadBitMemory(op1) != 0) {
                            core.WriteBitMemory(op1, 0);
                            jump = true;
                        } 
                        break;
                    }
                    return core.Branch(ref pc, String.Format("jbc   {0:X2}h,", op1), next_pc);

                case 0x20: // JB bit,rel
                    next_pc = NextPc(pc, inst_bytes, op2);
                    if (execute) {
                        jump = core.ReadBitMemory(op1) != 0;
                        break;
                    }                    
                    return core.Branch(ref pc, String.Format("jb    {0:X2}h,", op1), next_pc);

                case 0x30: // JNB bit,rel
                    next_pc = NextPc(pc, inst_bytes, op2);
                    if (execute) {
                        jump = core.ReadBitMemory(op1) == 0;
                        break;
                    }                    
                    return core.Branch(ref pc, String.Format("jnb   {0:X2}h,", op1), next_pc);

                case 0x40: // JC rel
                    next_pc = next_pc = NextPc(pc, inst_bytes, op1);
                    if (execute) {
                        jump = (core.psw & Core51.CY) != 0 ;
                        break;
                    }
                    return core.Branch(ref pc, "jc    ", next_pc);

                case 0x50: // JNC rel
                    next_pc = next_pc = NextPc(pc, inst_bytes, op1);
                    if (execute) {
                        jump = (core.psw & Core51.CY) == 0;
                        break;
                    }
                    return core.Branch(ref pc, "jnc   ", next_pc);

                case 0x60: // JZ rel
                    next_pc = next_pc = NextPc(pc, inst_bytes, op1);
                    if (execute) {
                        jump = core.acc == 0;
                        break;
                    }
                    return core.Branch(ref pc, "jz    ", next_pc);

                case 0x70: // JNZ rel
                    next_pc = next_pc = NextPc(pc, inst_bytes, op1);
                    if (execute) {
                        jump = core.acc != 0;
                        break;
                    }
                    return core.Branch(ref pc, "jnz   ", next_pc);

            }

            if (execute) {
                pc = jump ? next_pc : (UInt16)(pc + inst_bytes);
                cycles = core.inst_cycles[opcode];
            }
            return null;
        }
        public Instruction GetInstruction(ref UInt16 pc)
        {
            return Decode(ref pc, false);
        }
        public int Execute()
        {
            Decode(ref core.pc, true);
            return cycles;
        }
    }    
   
    /**
    * JMP @A+DPTR
    * */
    class Jmp : IInstruction
    {
        private Core51 core;
        public Jmp(Core51 core)
        {
            this.core = core;
            core.AddInstruction(0x73, this);
        }
        public Instruction GetInstruction(ref UInt16 pc)
        {
            return core.Operand(ref pc, "jmp   @a+dptr");
        }
        public int Execute()
        {
            core.pc = (UInt16)(core.acc + core.dptr);
            return 2;
        }
    }
    
    /**
    * LCALL addr16
    * */
    class Lcall : IInstruction
    {
        private Core51 core;
        public Lcall(Core51 core)
        {
            this.core = core;
            core.AddInstruction(0x12, this);
        }
        private UInt16 nextPc(UInt16 pc)
        {
            return (UInt16)((core.program_memory[pc + 1] << 8) | core.program_memory[pc + 2]);
        }
        public Instruction GetInstruction(ref UInt16 pc)
        {            
            return core.Branch(ref pc, "lcall ", nextPc(pc));
        }
        public int Execute()
        {
            core.push((byte)((core.pc + 3) & 255));
            core.push((byte)(((core.pc + 3) >> 8) & 255));
            core.pc = nextPc(core.pc);
            return 2;
        }
    }

    /**
    * LJMP addr16
    * */
    class Ljmp : IInstruction
    {
        private Core51 core;
        public Ljmp(Core51 core)
        {
            this.core = core;
            core.AddInstruction(0x02, this);
        }

        private UInt16 nextPc(UInt16 pc)
        {
            return (UInt16)((core.program_memory[pc + 1] << 8) | core.program_memory[pc + 2]);
        }
        public Instruction GetInstruction(ref UInt16 pc)
        {            
            return core.Branch(ref pc, "ljmp  ", nextPc(pc));
        }
        public int Execute()
        {
            core.pc = nextPc(core.pc);
            return 2;
        }
    }


    /**
    * Mov <dst-byte>,<src-byte>
    * */
    class Mov : IInstruction
    {
        private Core51 core;
        private int cycles;
        public Mov(Core51 core)
        {
            this.core = core;

            core.AddInstruction((byte)(0x74), this);
            core.AddInstruction((byte)(0x75), this);
            core.AddInstruction((byte)(0x76), this);
            core.AddInstruction((byte)(0x77), this);
            core.AddInstruction((byte)(0x85), this);
            core.AddInstruction((byte)(0x86), this);
            core.AddInstruction((byte)(0x87), this);
            core.AddInstruction((byte)(0x92), this);
            core.AddInstruction((byte)(0xA2), this);
            core.AddInstruction((byte)(0xA6), this);
            core.AddInstruction((byte)(0xA7), this);
            core.AddInstruction((byte)(0xE5), this);
            core.AddInstruction((byte)(0xE6), this);
            core.AddInstruction((byte)(0xE7), this);
            core.AddInstruction((byte)(0xF5), this);
            core.AddInstruction((byte)(0xF6), this);
            core.AddInstruction((byte)(0xF7), this);


            for (int i = 0; i < 8; i++)
            {
                core.AddInstruction((byte)(0x78 + i), this);
                core.AddInstruction((byte)(0x88 + i), this);
                core.AddInstruction((byte)(0xA8 + i), this);
                core.AddInstruction((byte)(0xE8 + i), this);
                core.AddInstruction((byte)(0xF8 + i), this);
            }
        }
        private Instruction Decode(ref UInt16 pc, bool execute)
        {            
            byte opcode = core.program_memory[pc];
            byte op1 = core.program_memory[pc + 1];
            byte op2 = core.program_memory[pc + 2];

            switch (opcode)
            {
                case 0x74: // MOV A,#data
                    if (execute) {
                        core.acc = op1;                        
                        break;
                    }
                    return core.Operand(ref pc, String.Format("mov   a,#{0:X2}h", op1));                    

                case 0x75: // MOV direct,#data
                    if (execute) {
                        core.WriteIntMemory(op1, op2, false);                        
                        break;
                    }
                    return core.Operand(ref pc, String.Format("mov   {0},#{1:X2}h", core.GetDirectName(op1), op2));                    

                case 0x76: // MOV @Ri,#data
                case 0x77:
                    if (execute) {
                        byte idx = core.r[opcode & 1];
                        core.WriteIntMemory(idx, op1, true);                        
                        break;
                    }
                    return core.Operand(ref pc, String.Format("mov   @r{0},#{1:X2}h", (opcode & 1), op1));                    

                case 0x78: // MOV Rn,#data
                case 0x79:
                case 0x7A:
                case 0x7B:
                case 0x7C:
                case 0x7D:
                case 0x7E:
                case 0x7F:
                    if (execute) {                        
                        core.r[opcode & 7] = op1;                        
                        break;
                    }
                    return core.Operand(ref pc, String.Format("mov   r{0},#{1:X2}h", (opcode & 7), op1));

                case 0x85: // MOV direct,direct
                    if (execute) {                        
                        core.WriteIntMemory(op1, core.ReadIntMemory(op2, false), false);
                        break;
                    }
                    return core.Operand(ref pc, String.Format("mov   {0},{1}", core.GetDirectName(op1), core.GetDirectName(op2)));                    

                case 0x86: // MOV direct,@Ri
                case 0x87:
                    if (execute) {
                        byte idx = core.r[opcode & 1];                        
                        core.WriteIntMemory(op1, core.ReadIntMemory(idx, true), false);
                        break;
                    }
                    return core.Operand(ref pc, String.Format("mov   {0},@r{1}", core.GetDirectName(op1), (opcode & 1)));                    

                case 0x88: // MOV direct,Rn
                case 0x89:
                case 0x8A:
                case 0x8B:
                case 0x8C:
                case 0x8D:
                case 0x8E:
                case 0x8F:
                    if (execute) {
                        core.WriteIntMemory(op1, core.r[opcode & 7], false);                        
                        break;
                    }
                    return core.Operand(ref pc, String.Format("mov   {0},r{1}", core.GetDirectName(op1), (opcode & 7)));                    

                case 0x92: // MOV bit,C
                    if (execute) {
                        core.WriteBitMemory(op1, core.carry);
                        break;
                    }
                    return core.Operand(ref pc, String.Format("mov   {0:X2}h,c", op1));                    

                case 0xA2: // MOV C,bit
                    return core.Operand(ref pc, String.Format("mov   c,{0:X2}h", op1));

                case 0xA6: // MOV @Ri,direct
                case 0xA7:
                    if (execute) {
                        byte idx = core.r[opcode & 1];
                        core.WriteIntMemory(core.ReadIntMemory(idx, false), op1, true);                        
                        break;
                    }
                    return core.Operand(ref pc, String.Format("mov   @r{0},{1}", (opcode & 1), core.GetDirectName(op1)));                    

                case 0xA8: // MOV Rn,direct
                case 0xA9:
                case 0xAA:
                case 0xAB:
                case 0xAC:
                case 0xAD:
                case 0xAE:
                case 0xAF:
                    if (execute) {
                        core.r[opcode & 7] = core.ReadIntMemory(op1, false);
                        break;
                    }
                    return core.Operand(ref pc, String.Format("mov   r{0},{1}", (opcode & 7), core.GetDirectName(op1)));                    

                case 0xE5: // MOV A,direct
                    if(execute) {
                        core.acc = core.ReadIntMemory(op1, false);                        
                        break;
                    }
                    return core.Operand(ref pc, String.Format("mov   a,{0}", core.GetDirectName(op1)));                    

                case 0xE6: // MOV A,@Ri
                case 0xE7:
                    if (execute) {
                        byte idx = core.r[opcode & 1];
                        core.acc = core.ReadIntMemory(idx, true);                        
                        break;
                    }
                    return core.Operand(ref pc, String.Format("mov a,@r{0}", opcode & 1));                    

                case 0xE8: // MOV A,Rn
                case 0xE9:
                case 0xEA:
                case 0xEB:
                case 0xEC:
                case 0xED:
                case 0xEE:
                case 0xEF:
                    if (execute) {
                        core.acc = core.r[opcode & 7];                       
                        break;
                    }
                    return core.Operand(ref pc, String.Format("mov   a,r{0}", (opcode & 7)));                    

                case 0xF5: // MOV direct,A
                    if (execute) {
                        core.WriteIntMemory(op1, core.acc, false);
                        break;
                    }
                    return core.Operand(ref pc, String.Format("mov   {0},a", core.GetDirectName(op1)));                    

                case 0xF6: // MOV @Ri,a
                case 0xF7:
                    if (execute) {
                        byte idx = core.r[opcode & 1];
                        core.WriteIntMemory(idx, core.acc, true);                        
                        break;
                    }
                    return core.Operand(ref pc, String.Format("mov   @r{0},a", (opcode & 1)));                    

                case 0xF8: // MOV Rn,A
                case 0xF9:
                case 0xFA:
                case 0xFB:
                case 0xFC:
                case 0xFD:
                case 0xFE:
                case 0xFF:
                    if (execute) {
                        core.r[opcode & 7] = core.acc;                       
                        break;
                    }
                    return core.Operand(ref pc, String.Format("mov   r{0},a", (opcode & 7)));                        
            }
            if (execute) {
                core.pc = (UInt16)(core.pc + core.inst_bytes[opcode]);
                cycles = core.inst_cycles[opcode];
            }
            return null;
        }
        public Instruction GetInstruction(ref UInt16 pc)
        {
            return Decode(ref pc, false);
        }
        public int Execute()
        {
            Decode(ref core.pc, true);
            return cycles;
        }
    }

    /**
   * MOV dptr,#data16
   * */
    class Mov_dptr : IInstruction
    {
        private Core51 core;
        public Mov_dptr(Core51 core)
        {
            this.core = core;
            core.AddInstruction((byte)(0x90), this);
        }
        public Instruction GetInstruction(ref UInt16 pc)
        {
            byte op1 = core.program_memory[pc + 1];
            byte op2 = core.program_memory[pc + 2];

            return core.Operand(ref pc, String.Format("mov   dptr,#{0:X2}{1:X2}h", op1, op2));
        }
        public int Execute()
        {
            core.dph = core.program_memory[core.pc + 1];
            core.dpl = core.program_memory[core.pc + 2];
            core.pc = (UInt16)(core.pc + 3);
            return 2;
        }
    }
    
    /**
    * MOVC A,@A+<base-reg>
    * MOVX <dst-byte>,<src-byte>
    * */
    class Movx : IInstruction
    {
        private Core51 core;
        private int cycles;
        public Movx(Core51 core)
        {
            this.core = core;

            core.AddInstruction((byte)(0x83), this);
            core.AddInstruction((byte)(0x93), this);

            core.AddInstruction((byte)(0xE0), this);
            core.AddInstruction((byte)(0xE2), this);
            core.AddInstruction((byte)(0xE3), this);
            core.AddInstruction((byte)(0xF0), this);
            core.AddInstruction((byte)(0xF2), this);
            core.AddInstruction((byte)(0xF3), this);
        }
        private Instruction Decode(ref UInt16 pc, bool execute)
        {
            byte opcode = core.program_memory[pc];           

            switch (opcode)
            {
                case 0x83: // MOVC A,@A+PC
                    if (execute) {
                        core.acc = core.program_memory[core.acc + core.pc];
                        break;
                    }
                    return core.Operand(ref pc, "movc   a,@a+pc");

                case 0x93: // MOVC A,@A+DPTR
                    if (execute) {
                        core.acc = core.program_memory[core.acc + core.dptr];
                        break;
                    }
                    return core.Operand(ref pc, "movc   a,@a+dptr");

                case 0xE0: // MOVX A,@DPTR
                    if (execute) {
                        core.acc = core.data_memory[core.dptr];
                        break;
                    }
                    return core.Operand(ref pc, "movx  a,@dptr");                    

                case 0xE2: // MOVX A,@Ri
                case 0xE3:
                    if (execute) {
                        core.acc = core.data_memory[core.r[opcode & 1]];
                        break;
                    }
                    return core.Operand(ref pc, String.Format("movx  a,@r{0}", (opcode & 1)));
                    
                case 0xF0: // MOVX @DPTR,A
                    if (execute) {
                        core.data_memory[core.dptr] = core.acc;
                        break;
                    }
                    return core.Operand(ref pc, "movx  @dptr,a");                    

                case 0xF2: // MOVX @Ri,A
                case 0xF3:
                    if (execute) {
                        core.data_memory[core.r[opcode & 1]] = core.acc;
                        break;
                    }
                    return core.Operand(ref pc, String.Format("movx  @r{0},a", (opcode & 1)));

            }

            if (execute) {
                core.pc = (UInt16)(core.pc + core.inst_bytes[opcode]);
                cycles = core.inst_cycles[opcode];
            }

            return null;
        }
        public Instruction GetInstruction(ref UInt16 pc)
        {
            return Decode(ref pc, false);
        }
        public int Execute()
        {
            Decode(ref core.pc, true);
            return cycles;
        }
    }

    /**
    * MUL AB
    * */
    class Mul : IInstruction
    {
        private Core51 core;
        public Mul(Core51 core)
        {
            this.core = core;
            core.AddInstruction(0xA4, this);
        }
        public Instruction GetInstruction(ref UInt16 pc)
        {
            return core.Operand(ref pc, "mul   ab");
        }
        public int Execute()
        {
            int a = core.acc;
            int b = core.b;
            int res = a * b;

            core.acc = (byte)(res & 0xff);
            core.b = (byte)(res >> 8);

            core.psw = (byte)(core.psw & ~(Core51.CY | Core51.OV));
            
            if (core.b != 0)
                core.psw = (byte)(core.psw | Core51.OV);

            core.pc++;

            return 4;            
        }
    }

    /**
    * NOP
    * */
    class Nop : IInstruction
    {
        private Core51 core;
        public Nop(Core51 core)
        {
            this.core = core;
            core.AddInstruction(0x00, this);
            core.AddInstruction(0xA5, this);
        }
        public Instruction GetInstruction(ref UInt16 pc)
        {
            if(core.program_memory[pc] == 0xA5){
                return core.Operand(ref pc, "Invalid Opcode");
            }
            return core.Operand(ref pc, "nop");
        }
        public int Execute()
        {
            core.pc++;
            return 1;
        }
    }

    /**
    * ORL <dst-byte>,<src-byte>
    * ORL C,<src-bit>
    * */
    class Orl : IInstruction
    {
        private Core51 core;
        private int cycles;
        public Orl(Core51 core)
        {
            this.core = core;

            core.AddInstruction(0x72, this);
            core.AddInstruction(0xA0, this);

            for (int i = 0; i < 14; i++)
            {
                core.AddInstruction((byte)(0x42 + i), this);
            }
        }
        private Instruction Decode(ref UInt16 pc, bool execute)        
        {
            byte opcode = core.program_memory[pc];
            byte op1 = core.program_memory[pc + 1];
            byte op2 = core.program_memory[pc + 2];
            int inst_bytes = core.inst_bytes[opcode];

            switch (opcode)
            {
                case 0x42: // ORL direct,A
                    if (execute) {
                        core.WriteIntMemory(op1, (byte)(core.acc | core.ReadIntMemory(op1, false)), false);
                        break;
                    }
                    return core.Operand(ref pc, String.Format("orl   {0},a", core.GetDirectName(op1)));                    

                case 0x43: // ORL direct,#data
                    if (execute) {
                        core.WriteIntMemory(op1, (byte)(core.ReadIntMemory(op1, false) | op2), false);
                        break;
                    }
                    return core.Operand(ref pc, String.Format("orl   {0},#{1:X2}h", core.GetDirectName(op1), op2));                    

                case 0x44: // ORL A,#data
                    if (execute) {
                        core.acc = (byte)(core.acc | op1);
                        break;
                    }
                    return core.Operand(ref pc, String.Format("orl   a,#{0:X2}h", op1));

                case 0x45: // ORL A,direct
                    if (execute) {
                        core.acc = (byte)(core.acc | core.ReadIntMemory(op1, false));
                        break;
                    }
                    return core.Operand(ref pc, String.Format("orl   a,{0}", core.GetDirectName(op1)));                    

                case 0x46: // ORL A,@Ri
                case 0x47:
                    if (execute) {
                        byte idx = core.r[opcode & 1];
                        core.acc = (byte)(core.acc | core.ReadIntMemory(idx, true));
                        break;
                    }
                    return core.Operand(ref pc, String.Format("orl   a,@r{0}", (opcode & 1)));                    

                case 0x48: // ORL A,Rn
                case 0x49:
                case 0x4A:
                case 0x4B:
                case 0x4C:
                case 0x4D:
                case 0x4E:
                case 0x4F:
                    if (execute) {
                        core.acc = (byte)(core.acc | core.r[opcode & 7]);
                        break;
                    }
                    return core.Operand(ref pc, String.Format("orl   a,r{0}", (opcode & 7)));

                case 0x72: // ORL C,bit
                    if (execute) {
                        core.carry = (byte)(core.carry | core.ReadBitMemory(op1));
                        break;
                    }
                    return core.Operand(ref pc, String.Format("orl   c,{0:X2}h", op1));

                case 0xA0: // ORL C,/bit
                    if (execute) {                        
                        core.carry = (byte)(core.carry | (core.ReadBitMemory(op1) ^ 1));
                        break;
                    }
                    return core.Operand(ref pc, String.Format("orl   c,/{0:X2}h", op1));
            }
            if (execute) {
                pc = (UInt16)(pc + inst_bytes);
                cycles = core.inst_cycles[opcode];
            }
            return null;
        }
        public Instruction GetInstruction(ref UInt16 pc)
        {
            return Decode(ref pc, false);
        }
        public int Execute()
        {
            Decode(ref core.pc, true);
            return cycles;
        }
    }
    
    /**
    * POP direct
    * */
    class Pop : IInstruction
    {
        private Core51 core;
        public Pop(Core51 core)
        {
            this.core = core;

            core.AddInstruction(0xD0, this);
        }
        public Instruction GetInstruction(ref UInt16 pc)
        {
            return core.Operand(ref pc, String.Format("pop   {0}", core.GetDirectName(core.program_memory[pc + 1])));
        }
        public int Execute()
        {
            byte idx = core.program_memory[core.pc + 1];
            core.WriteIntMemory(idx, core.pop(), false);
            core.pc = (UInt16)(core.pc + 2);
            return 2;
        }
    }

    /**
    * PUSH direct
    * */
    class Push : IInstruction
    {
        private Core51 core;
        public Push(Core51 core)
        {
            this.core = core;

            core.AddInstruction(0xC0, this);
        }
        public Instruction GetInstruction(ref UInt16 pc)
        {
            return core.Operand(ref pc, String.Format("push  {0}", core.GetDirectName(core.program_memory[pc + 1])));
        }
        public int Execute()
        {
            byte idx = core.program_memory[core.pc + 1];
            core.push(core.ReadIntMemory(idx, false));            
            core.pc = (UInt16)(core.pc + 2);
            return 2;
        }
    }

    /**
    * RET
    * RETI
    * */
    class Ret : IInstruction
    {
        private Core51 core;
        public Ret(Core51 core)
        {
            this.core = core;
            core.AddInstruction(0x22, this);
            core.AddInstruction(0x32, this);
        }
        public Instruction GetInstruction(ref UInt16 pc)
        {
            byte opcode = core.program_memory[pc];
            return core.Operand(ref pc, (opcode == 0x22) ? "ret" : "reti");
        }
        public int Execute()
        {
            if(core.program_memory[core.pc] == 0x32) {
                core.WriteBitMemory(0xAF, 1); // EA = 1
            }

            core.pc = (UInt16)(core.pop() << 8);
            core.pc |= core.pop();

            return 2;            
        }
    }

    /**
    * RL A
    * RLC A
    * RR A
    * RRC A
    * */
    class Rl : IInstruction
    {
        private Core51 core;
        public Rl(Core51 core)
        {
            this.core = core;

            core.AddInstruction(0x23, this);
            core.AddInstruction(0x33, this);
            core.AddInstruction(0x03, this);
            core.AddInstruction(0x13, this);
        }
        private Instruction Decode(ref UInt16 pc, bool execute)
        {
            byte opcode = core.program_memory[pc];

            switch (opcode)
            {
                case 0x03: // RR A
                    if (execute) {
                        core.acc = (byte)(core.acc >> 1);
                        break;
                    }
                    return core.Operand(ref pc, "rr    a");                    

                case 0x13: // RRC A
                    if (execute) {
                        byte a0 = (byte)(core.acc & 1);
                        core.acc = (byte)((core.acc >> 1) | (core.psw & Core51.CY));
                        core.carry = a0;
                        break;
                    }
                    return core.Operand(ref pc, "rrc   a");                    

                case 0x23: // RL A
                    if (execute) {
                        core.acc = (byte)(core.acc << 1);
                        break;
                    }
                    return core.Operand(ref pc, "rl    a");

                case 0x33: // RLC A
                    if (execute) {
                        byte a7 = (byte)(core.acc >> 7);
                        core.acc = (byte)((core.acc << 1) | core.carry);
                        core.carry = a7;
                        break;
                    }
                    return core.Operand(ref pc, "rlc   a");
            }

            return null;
        }
        public Instruction GetInstruction(ref UInt16 pc)
        {
            return Decode(ref pc, false);
        }
        public int Execute()
        {
            Decode(ref core.pc, true);
            core.pc = (UInt16)(core.pc + 1);
            return 1;
        }
    }

    /**       
    * SJMP rel
    * */
    class Sjmp : IInstruction
    {
        private Core51 core;
        public Sjmp(Core51 core)
        {
            this.core = core;

            core.AddInstruction(0x80, this);
        }

        private UInt16 NextPc(int pc, byte rel)
        {
            return (UInt16)((pc + 2) + ((rel & 0x80) == 0 ? rel : (Int32)(rel | 0xFFFFFF00)));
        }
        public Instruction GetInstruction(ref UInt16 pc)
        {
            byte op1 = core.program_memory[pc + 1];
            return core.Branch(ref pc, "sjmp  ", NextPc(pc, op1));
        }
        public int Execute()
        {
            core.pc = NextPc(core.pc, core.program_memory[core.pc + 1]);
            return 2;
        }
    }

    /**       
    * SUBB A
    * */
    class Subb : IInstruction
    {
        private Core51 core;
        private int cycles;
        public Subb(Core51 core)
        {
            this.core = core;

            for (int i = 0; i < 12; i++)
            {
                core.AddInstruction((byte)(0x94 + i), this);
            }

        }

        private byte Sub(int op1, int op2)
        {
            op1 += core.carry;

            int carry = (((op1 & 255) - (op2 & 255)) >> 8) & 1;
            int auxcarry = (((op1 & 7) - (op2 & 7)) >> 3) & 1;
            int overflow = ((((op1 & 127) - (op2 & 127)) >> 7) & 1) ^ carry;

            core.psw = (byte)((core.psw & 0x3B) | carry | auxcarry | overflow);

            return (byte)(op1 - op2);
        }
        private Instruction Decode(ref UInt16 pc, bool execute)
        {
            byte opcode = core.program_memory[pc];
            byte op1 = core.program_memory[pc + 1];            

            switch (opcode)
            {
                case 0x94: // SUBB A,#data
                    if (execute) {
                        core.acc = Sub(core.acc, op1);
                        break;
                    }
                    return core.Operand(ref pc, String.Format("subb  a,#{0:X2}h", op1));
                    
                case 0x95: // SUBB A,direct
                    if (execute) {
                        core.acc = Sub(core.acc, core.ReadIntMemory(op1, false));
                        break;
                    }
                    return core.Operand(ref pc, String.Format("subb  a,{0}", core.GetDirectName(op1)));

                case 0x96: // SUBB A,@Ri
                case 0x97:
                    if (execute) {
                        byte idx = core.r[opcode & 1];
                        core.acc = Sub(core.acc, core.ReadIntMemory(idx, true));
                        break;
                    }
                    return core.Operand(ref pc, String.Format("subb  a,@r{0}", (opcode & 1)));                    

                case 0x98: // SUBB A,Rn
                case 0x99:
                case 0x9A:
                case 0x9B:
                case 0x9C:
                case 0x9D:
                case 0x9E:
                case 0x9F:
                    if (execute) {
                        core.acc = Sub(core.acc, core.r[opcode & 7]);
                        break;
                    }
                    return core.Operand(ref pc, String.Format("subb  a,r{0}", (opcode & 7)));                    
            }

            if (execute) {
                pc = (UInt16)(pc + core.inst_bytes[opcode]);
                cycles = core.inst_cycles[opcode];
            }

            return null;
        }
        public Instruction GetInstruction(ref UInt16 pc)
        {
            return Decode(ref pc, false);
        }
        public int Execute()
        {
            Decode(ref core.pc, true);
            return cycles;
        }
    }

    /**       
   * SWAP A
   * */
    class Swap : IInstruction
    {
        private Core51 core;
        public Swap(Core51 core)
        {
            this.core = core;

            core.AddInstruction(0xC4, this);
        }
        public Instruction GetInstruction(ref UInt16 pc)
        {
            return core.Operand(ref pc, "swap  a");
        }
        public int Execute()
        {
            core.acc = (byte)((core.acc >> 4) | (core.acc << 4));
            core.pc ++;
            return 1;
        }
    }

    /**       
   * XCH A,<byte>
   * */
    class Xch : IInstruction
    {
        private Core51 core;
        private int cycles;
        public Xch(Core51 core)
        {
            this.core = core;

            core.AddInstruction(0xD6, this);
            core.AddInstruction(0xD7, this);

            for (int i = 0; i < 11; i++)
            {
                core.AddInstruction((byte)(0xC5 + i), this);
            }
        }
        private Instruction Decode(ref UInt16 pc, bool execute)
        {
            byte opcode = core.program_memory[pc];
            byte op1 = core.program_memory[pc + 1];            

            switch (opcode)
            {
                case 0xC5: // XCH A,direct
                    if (execute) {
                        byte data = core.ReadIntMemory(op1, false);
                        core.WriteIntMemory(op1, core.acc, false);
                        core.acc = data;
                        break;
                    }
                    return core.Operand(ref pc, String.Format("xch   a,{0}", core.GetDirectName(op1)));                    

                case 0xC6: // XCH A,@Ri
                case 0xC7:
                    if (execute) {
                        byte idx = core.r[opcode & 1];
                        byte data = core.ReadIntMemory(idx, true);
                        core.WriteIntMemory(idx, core.acc, true);
                        core.acc = data;
                        break;
                    }
                    return core.Operand(ref pc, String.Format("xch   a,@r{0}", (opcode & 1)));                    

                case 0xC8: // XCH A,Rn
                case 0xC9:
                case 0xCA:
                case 0xCB:
                case 0xCC:
                case 0xCD:
                case 0xCE:
                case 0xCF:
                    if (execute) {
                        byte data = core.r[opcode & 7];
                        core.r[opcode & 7] = core.acc;
                        core.acc = data;
                        break;
                    }
                    return core.Operand(ref pc, String.Format("xch   a,r{0}", (opcode & 7)));

                case 0xD6: // XCHD A,@Ri
                case 0xD7:
                    if (execute) {
                        byte idx = core.r[opcode & 1];
                        byte d1 = core.ReadIntMemory(idx, true);
                        byte d2 = core.acc;
                        core.acc = (byte)((d2 & 0xF0) | (d1 & 0x0F));
                        core.WriteIntMemory(idx, (byte)((d1 & 0xF0) | (d2 & 0x0F)), true);                        
                        break;
                    }
                    return core.Operand(ref pc, String.Format("xchd  a,@r{0}", (opcode & 1)));
            }

            if (execute) {
                pc = (UInt16)(pc + core.inst_bytes[opcode]);
                cycles = core.inst_cycles[opcode];
            }

            return null;
        }
        public Instruction GetInstruction(ref UInt16 pc)
        {
            return Decode(ref pc, false);
        }
        public int Execute()
        {            
            Decode(ref core.pc, true);
            return cycles;
        }
    }

    /**       
  * XRL <dst-byte>,<src-byte>
  * */
    class Xrl : IInstruction
    {
        private Core51 core;
        private int cycles;
        public Xrl(Core51 core)
        {
            this.core = core;

            for (int i = 0; i < 14; i++)
            {
                core.AddInstruction((byte)(0x62 + i), this);
            }
        }
        private Instruction Decode(ref UInt16 pc, bool execute)
        {
            byte opcode = core.program_memory[pc];
            byte op1 = core.program_memory[pc + 1];
            byte op2 = core.program_memory[pc + 2];            

            switch (opcode)
            {
                case 0x62: // XRL direct,A
                    if (execute) {
                        byte data = core.ReadIntMemory(op1, false);
                        core.WriteIntMemory(op1, (byte)(core.acc ^ data), false);                        
                        break;
                    }
                    return core.Operand(ref pc, String.Format("xrl   {0},a", core.GetDirectName(op1)));
                    

                case 0x63: // XRL direct,#data
                    if (execute) {
                        byte data = core.ReadIntMemory(op1, false);
                        core.WriteIntMemory(op1, (byte)(op1 ^ data), false);
                        break;
                    }
                    return core.Operand(ref pc, String.Format("xrl   {0},#{1:X2}h", core.GetDirectName(op1), op2));                    

                case 0x64: // XRL A,#data
                    if (execute) {
                        core.acc = (byte)(core.acc ^ op1);
                        break;
                    }
                    return core.Operand(ref pc, String.Format("xrl   a,#{0:X2}h", op1));

                case 0x65: // XRL A,direct
                    if (execute) {
                        byte data = core.ReadIntMemory(op1, false);
                        core.acc = (byte)(core.acc ^ data);
                        break;
                    }
                    return core.Operand(ref pc, String.Format("xrl   a,{0}", core.GetDirectName(op1)));                    

                case 0x66: // XRL A,@Ri
                case 0x67:
                    if (execute) {
                        byte idx = core.r[opcode & 1];
                        byte data = core.ReadIntMemory(idx, true);
                        core.acc = (byte)(core.acc ^ data);
                        break;
                    }
                    return core.Operand(ref pc, String.Format("xrl   a,@r{0}", (opcode & 1)));                    

                case 0x68: // XRL A,Rn
                case 0x69:
                case 0x6A:
                case 0x6B:
                case 0x6C:
                case 0x6D:
                case 0x6E:
                case 0x6F:
                    if (execute) {                        
                        core.acc = (byte)(core.acc ^ core.r[opcode & 7]);
                        break;
                    }
                    return core.Operand(ref pc, String.Format("xrl   a,r{0}", (opcode & 7)));                    
            }

            if (execute) {
                pc = (UInt16)(pc + core.inst_bytes[opcode]);
                cycles = core.inst_cycles[opcode];
            }

            return null;
        }

        public Instruction GetInstruction(ref UInt16 pc)
        {
            return Decode(ref pc, false);
        }

        public int Execute()
        {
            Decode(ref core.pc, true);
            return cycles;
        }
    }

    class Core51
    {
        private const string LABEL_PREFIX = "X";
        public static readonly string[] registerNames = { "A", "B", "R0", "R1", "R2", "R3", "R4", "R5", "R6", "R7", "PSW", "SP", "DPL", "DPH" };

        public static readonly string[] sfrNames = {
            "P0",    "SP",   "DPL",    "DPH",    "84h", "85h", "86h", "PCON",  // 80h            
            "TCON",  "TMOD", "TL0",    "TL1",    "TH0", "TH1", "8Eh", "8Fh",   // 88h
            "P1",    "91h",  "92h",    "93h",    "94h", "95h", "96h", "97h",   // 90h
            "SCON",  "SBUF", "9Ah",    "9Bh",    "9Ch", "9Dh", "9Eh", "9Fh",   // 98h
            "P2",    "A1h",  "A2h",    "A3h",    "A4h", "A5h", "A6h", "A7h",   // A0h
            "IE",    "A9h",  "AAh",    "ABh",    "ACh", "ADh", "AEh", "AFh",   // A8h
            "P3",    "B1h",  "B2h",    "B3h",    "B4h", "B5h", "B6h", "B7h",   // B0h
            "IP",    "B9h",  "BAh",    "BBh",    "BCh", "BDh", "BEh", "BFh",   // B8h
            "C0h",   "C1h",  "C2h",    "C3h",    "C4h", "C5h", "C6h", "C7h",   // C0h
            "T2CON", "C9h",  "RCAP2h", "RCAP2L", "TL2", "TH2", "CEh", "CFh",   // C8h            
            "PSW",   "D1h",  "D2h",    "D3h",    "D4h", "D5h", "D6h", "D7h",   // D0h
            "D8H",   "D9h",  "DAh",    "DBh",    "DCh", "DDh", "DEh", "DFh",   // D8h
            "ACC",   "E1h",  "E2h",    "E3h",    "E4h", "E5h", "E6h", "E7h",   // E0h
            "E8h",   "E9h",  "EAh",    "EBh",    "ECh", "EDh", "EEh", "EFh",   // E8h
            "B",     "F1h",  "F2h",    "F3h",    "F4h", "F5h", "F6h", "F7h",   // F0h
            "F8h",   "F9h",  "FAh",    "FBh",    "FCh", "FDh", "FEh", "FFh",   // F8h
        };

        public byte[] inst_bytes = {
        //  0 1 2 3 4 5 6 7 8 9 A B C D E F
            1,2,3,1,1,2,1,1,1,1,1,1,1,1,1,1, // 00
            3,2,3,1,1,2,1,1,1,1,1,1,1,1,1,1, // 10
            3,2,1,1,2,2,1,1,1,1,1,1,1,1,1,1, // 20
            3,2,1,1,2,2,1,1,1,1,1,1,1,1,1,1, // 30
            2,2,2,3,2,2,1,1,1,1,1,1,1,1,1,1, // 40
            2,2,2,3,2,2,1,1,1,1,1,1,1,1,1,1, // 50
            2,2,2,3,2,2,1,1,1,1,1,1,1,1,1,1, // 60
            2,2,2,1,2,3,2,2,2,2,2,2,2,2,2,2, // 70
            2,2,2,1,1,3,2,2,2,2,2,2,2,2,2,2, // 80
            3,2,2,1,2,2,1,1,1,1,1,1,1,1,1,1, // 90
            2,2,2,1,1,1,2,2,2,2,2,2,2,2,2,2, // A0
            2,2,2,1,3,3,3,3,3,3,3,3,3,3,3,3, // B0
            2,2,2,1,1,2,1,1,1,1,1,1,1,1,1,1, // C0
            2,2,2,1,1,3,1,1,2,2,2,2,2,2,2,2, // D0
            1,2,1,1,1,2,1,1,1,1,1,1,1,1,1,1, // E0
            1,2,1,1,1,2,1,1,1,1,1,1,1,1,1,1, // F0
        };

        public readonly byte[] inst_cycles = {
            1,2,3,1,1,1,1,1,1,1,1,1,1,1,1,1, // 00
            1,2,3,1,1,1,1,1,1,1,1,1,1,1,1,1, // 00
            1,2,3,1,1,1,1,1,1,1,1,1,1,1,1,1, // 00
            1,2,3,1,1,1,1,1,1,1,1,1,1,1,1,1, // 00
            1,2,3,1,1,1,1,1,1,1,1,1,1,1,1,1, // 00
            1,2,3,1,1,1,1,1,1,1,1,1,1,1,1,1, // 00
            1,2,3,1,1,1,1,1,1,1,1,1,1,1,1,1, // 00
            1,2,3,1,1,1,1,1,1,1,1,1,1,1,1,1, // 00
            1,2,3,1,1,1,1,1,1,1,1,1,1,1,1,1, // 00
            1,2,3,1,1,1,1,1,1,1,1,1,1,1,1,1, // 00
            1,2,3,1,1,1,1,1,1,1,1,1,1,1,1,1, // 00
            1,2,3,1,1,1,1,1,1,1,1,1,1,1,1,1, // 00
            1,2,3,1,1,1,1,1,1,1,1,1,1,1,1,1, // 00
            1,2,3,1,1,1,1,1,1,1,1,1,1,1,1,1, // 00
            1,2,3,1,1,1,1,1,1,1,1,1,1,1,1,1, // 00
            1,2,3,1,1,1,1,1,1,1,1,1,1,1,1,1, // 00
        };

        public const byte CY  = (1 << 7);
        public const byte AC  = (1 << 6);
        public const byte F0  = (1 << 5);
        public const byte RS1 = (1 << 4);
        public const byte RS0 = (1 << 3);
        public const byte OV  = (1 << 2);
        public const byte P   = (1 << 0);

        public byte[] program_memory;
        public byte[] data_memory;
        protected byte[] sfrs;
        protected byte[] internal_memory;

        protected int total_cycles = 0;

        protected Action<int, int> sfrWriteAction = null;

        public byte ReadIntMemory(byte addr, bool indirect)
        {
            if (indirect || addr < 0x80) {
                return internal_memory[addr];
            }            
            return sfrs[addr & 0x7F];
        }

        public void WriteIntMemory(byte addr, byte data, bool indirect)
        {
            if (indirect || addr < 0x80) {
                internal_memory[addr] = data;
            } else {
                sfrs[addr & 0x7F] = data;
                
                switch (addr) {
                    case 0x99: // SET TI flag
                        WriteBitMemory(0x99, 1);
                        break;
                }

                if (sfrWriteAction != null) {
                    sfrWriteAction(addr, data);
                }

            }
        }
        private byte ReadBitMemory(byte [] src, byte bit_addr)
        {
            int data = src[bit_addr & 0x78] >> (bit_addr & 7);
            return (byte)(data & 1);
        }
        public byte ReadBitMemory(byte bit_addr)
        {            
            if (bit_addr > 127) {
                return ReadBitMemory(sfrs, bit_addr);
            } 
            return ReadBitMemory(internal_memory, bit_addr);
        }
        private void WriteBitMemory(byte [] dst, byte bit_addr, byte value)
        {
            if((value & 1) == 1) {
                dst[bit_addr & 0x78] = (byte)(dst[bit_addr & 0x78] | (1 << (bit_addr & 7)));
            } else {
                dst[bit_addr & 0x78] = (byte)(dst[bit_addr & 0x78] & ~(1 << (bit_addr & 7)));
            }
        }
        public void WriteBitMemory(byte bit_addr, byte value)
        {
            if (bit_addr > 127) {
                WriteBitMemory(sfrs, bit_addr, value);
            } else {
                WriteBitMemory(internal_memory, bit_addr, value);
            }
        }
        public byte carry
        {
            get { return (byte)((psw >> 7) & 1); }
            set { psw = ((value & 1) == 1) ? (byte)(psw | Core51.CY) : (byte)(psw & ~Core51.CY); }
        }

        public UInt16 dptr
        {
            get { return (UInt16)((dph << 8) | dpl); }
            set {
                dph = (byte)(value >> 8);
                dpl = (byte)(value & 255);
            }
        }

        public UInt16 pc;
        public byte acc
        {
            get { return sfrs[0xE0 & 0x7F]; }
            set { sfrs[0xE0 & 0x7F] = value; }
        }
        public byte b
        {
            get { return sfrs[0xF0 & 0x7F]; }
            set { sfrs[0xF0 & 0x7F] = value; }
        }
        public byte dpl
        {
            get { return sfrs[0x82 & 0x7F]; }
            set { sfrs[0x82 & 0x7F] = value; }
        }
        public byte dph
        {
            get { return sfrs[0x83 & 0x7F]; }
            set { sfrs[0x83 & 0x7F] = value; }
        }
        public byte psw {
            get { return sfrs[0xd0 & 0x7F]; }
            set { sfrs[0xd0 & 0x7F] = value; }
        }
        public byte sp{
            get { return sfrs[0x81 & 0x7F]; }
            set { sfrs[0x81 & 0x7F] = value; }
        }
        public bool EA
        {
            //IE.7 Enable all interrupts
            get { return ReadBitMemory(0xAF) != 0; }
            set { WriteBitMemory(0xAF, (byte)(value ? 1 : 0)); }
        }
        public bool ET2
        {
            //IE.5 Timer2 overflow interrupt enable
            get { return (sfrs[0x28] & (1 << 5)) != 0; }
        }

        public bool ES
        {
            //IE.4 Serial interrupt enable
            get { return ReadBitMemory(0xAC) != 0; }
            set { WriteBitMemory(0xAC, (byte)(value ? 1 : 0)); }
        }
        public bool ET1
        {
            //IE.3 Timer 1 overflow interrupt enable
            get { return (sfrs[0x28] & (1 << 3)) != 0; }
        }
        public bool EX1
        {
            //IE.2 External 1 interrupt enable
            get { return (sfrs[0x28] & (1 << 2)) != 0; }
        }

        public bool ET0
        {
            //IE.1 Timer 0 overflow interrupt enable
            get { return (sfrs[0x28] & (1 << 1)) != 0; }
        }
        public bool EX0
        {
            //IE.0 External 0 interrupt enable
            get { return (sfrs[0x28] & (1 << 0)) != 0; }
        }
       
        public bool TF1
        {
            //TCON.7 Timer 1 overflow flag
            get { return (sfrs[0x08] & (1 << 7)) != 0; }
        }
        public bool TF0
        {
            //TCON.5 Timer 0 overflow flag
            get { return (sfrs[0x08] & (1 << 5)) != 0; }
        }
        public bool IE1
        {
            //TCON.3 External 1 edge detected
            get { return (sfrs[0x08] & (1 << 3)) != 0; }
        }
        public bool IE0
        {
            //TCON.1 External 0 edge detected
            get { return (sfrs[0x08] & (1 << 1)) != 0; }
        }        

        public bool TI
        {
            //SCON.1 Transmit interrupt flag
            get { return ReadBitMemory(0x99) != 0; }
            set { WriteBitMemory(0x99, (byte)((value == true) ? 1 : 0)); }
        }
        public bool RI
        {
            //SCON.0 Receive interrupt flag
            get { return ReadBitMemory(0x98) != 0; }
            set { WriteBitMemory(0x98, (byte)((value == true) ? 1 : 0)); }
        }
        public bool EXF2
        {
            //T2CON.6
            get { return (sfrs[0x48] & (1 << 6)) != 0; }
        }

        public bool TF2
        {
            //T2CON.7
            get { return (sfrs[0x48] & (1 << 7)) != 0; }
        }

        public class RegBank
        {
            private Core51 core;
            public RegBank(Core51 core)
            {
                this.core = core;
            }
            public byte this[int idx]
            {                
                get {
                        int bank = ((core.psw >> 3) & 3);
                        return core.internal_memory[(bank * 8) + idx];}
                set {
                        int bank = ((core.psw >> 3) & 3);
                        core.internal_memory[(bank * 8) + idx] = value;
                }
            }
        }

        public RegBank r;

        private Dictionary<byte, IInstruction> menemonics;
      
        /**
        * [PC]  [OP code] [mnemonic]
        * */
        public Instruction Operand(ref UInt16 pc, string mnm)
        {

            string [] decoded = new string[3];

            byte opcode = program_memory[pc];

            int nbytes = inst_bytes[program_memory[pc]];
            
            decoded[0] = String.Format("{0:X4}", pc);

            switch (nbytes) {
                case 1:                        
                    decoded[1] = String.Format("{0:X2}", opcode);
                    break;
                case 2:
                    decoded[1] = String.Format("{0:X2} {1:X2}", opcode, program_memory[pc + 1]);
                    break;
                case 3:
                    decoded[1] = String.Format("{0:X2} {1:X2} {2:X2}", opcode, program_memory[pc + 1], program_memory[pc + 2]);
                    break;
            }            

            decoded[2] = mnm;

            Instruction inst = new Instruction(pc, opcode, decoded);

            pc = (UInt16)((pc + nbytes) & 0xFFFF);

            return inst;
        }

        public string GetDirectName(byte addr)
        {
            if (addr < 0x80) {
                return $"{addr:X2}h";
            }

            return sfrNames[addr & 0x7F];            
        }
       
        /**
         *  3 + 3 + 3 + 1
         * [PC]  [OP code] [OP1] [OP2] [mnemonic] [branch]
         * */
        public Instruction Branch(ref UInt16 pc, string mnm, Int32 next_pc)
        {
            string branch = String.Format("{0}{1}{2:X4}", mnm, LABEL_PREFIX, next_pc);
            Instruction inst = Operand(ref pc, branch);
            inst.SetJump(next_pc);
            return inst;
        }      

        public byte pop()
        {
            return internal_memory[sp--];
        }
        public void push(byte data)
        {
            internal_memory[++sp] = data;
        }

        public Core51()
        {
            menemonics = new Dictionary<byte, IInstruction>();
            r = new RegBank(this);

            new Acall(this);
            new Add(this);            
            new Ajmp(this);
            new Anl(this);
            new Cjne(this);            
            new ClrSetCpl(this);            
            new Da(this);
            new Dec(this);
            new Div(this);
            new Djnz(this);
            new Inc(this);
            new Inc_dptr(this);
            new Jbit(this);            
            new Jmp(this);            
            new Lcall(this);
            new Ljmp(this);
            new Mov(this);
            new Mov_dptr(this);            
            new Movx(this);
            new Mul(this);
            new Nop(this);
            new Orl(this);            
            new Pop(this);
            new Push(this);
            new Ret(this);
            new Rl(this);            
            new Sjmp(this);
            new Subb(this);
            new Swap(this);
            new Xch(this);
            new Xrl(this);

            program_memory = new byte[0x10000];
            data_memory = new byte[0x10000];
            internal_memory = new byte[256];
            sfrs = new byte[128];
        }

        public void AddInstruction(byte opcode, IInstruction inst)
        {
            menemonics.Add(opcode, inst);
        }

        /**
         * return : string array
         *              [0] Address
         *              [1] Encoding
         *              [2] Mnemonic
         * */
        protected Instruction Decode(ref UInt16 pcd, bool execute)
        {
            IInstruction instruction;
            try {
                if (menemonics.TryGetValue(program_memory[pcd], out instruction)) {
                    if (execute) {
                        total_cycles += instruction.Execute();
                        return null;
                    }
                    return instruction.GetInstruction(ref pcd);
                }
                throw new NotSupportedException($"Invalid opcode: ");
            } catch (Exception ex) {
                throw new Exception($"{ex.Message}: {pcd:X4}={program_memory[pcd]:X2}");
            }
        }
    }
}
