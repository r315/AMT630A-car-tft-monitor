using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Reflection;
using System.Windows.Forms;

namespace dss52
{
    class Cpu : Core51
    {        
        public int loadCode(byte[] binary)
        {
            Int32 size = (binary.Length < 0x10000) ? binary.Length : 0x10000;
            Array.Copy(binary, program_memory, size);
            program_memory.SetArray(size, (byte)0xFF, program_memory.Length - size);
            reset();
            return size;
        }
        public void reset()
        {
            data_memory.SetArray(0, (byte)0xFF, data_memory.Length);
            sfrs.SetArray(0, (byte)0, sfrs.Length);
            this.acc = 0;
            this.b = 0;
            this.dpl = 0;
            this.dph = 0;
            this.pc = 0;
            this.sp = 7;
            this.psw = 0;
            total_cycles = 0;
            data_memory[0x1234] = 0xa0;
            data_memory[0x1235] = 0xa1;
            data_memory[0x1236] = 0xa2;
        }

        public byte[] getCodeMemory()
        {
            return program_memory;
        }
        public byte[] getInternalMemory()
        {
            return internal_memory;
        }
        public byte[] getDataMemory()
        {
            return data_memory;
        }
        public byte[] getSfrValues()
        {
            return internal_memory.SubArray(0x80, 0x80);
        }
        public byte[] getSfrs()
        {
            return sfrs;
        }

        private string bufToString(int addr, byte[] mem)
        {
            StringBuilder sbhex = new StringBuilder(String.Format("CODE:{0:X4} ", addr));
            StringBuilder sbasc = new StringBuilder(" ");
                
            for (int i = addr; i < addr + 16; i++) {
                byte data = mem[i];
                sbhex.Append(String.Format("{0:X2} ", data));
                if(data < 0x20 || data > 0x7F) {
                    sbasc.Append(".");
                } else {
                    sbasc.Append(Convert.ToChar(data).ToString());
                }
            }

            sbhex.Append(sbasc);

            return sbhex.ToString();
        }
        public List<string> codeMemToString()
        {
            List<string> code = new List<string>();

            for (int i = 0; i < program_memory.Length; i+= 16) {
                code.Add(bufToString(i, program_memory));
            }

            return code;
        }
        public List<string> intMemToString()
        {
            List<string> data = new List<string>();

            for (int i = 0; i < internal_memory.Length; i+=8) {               
                data.Add(String.Format("DATA:{0:X2} {1:X2} {2:X2} {3:X2} {4:X2} {5:X2} {6:X2} {7:X2} {8:X2}",
                    i,
                    internal_memory[i + 0],
                    internal_memory[i + 1],
                    internal_memory[i + 2],
                    internal_memory[i + 3],
                    internal_memory[i + 4],
                    internal_memory[i + 5],
                    internal_memory[i + 6],                    
                    internal_memory[i + 7]));
            }

            return data;
        }
        public List<string> dataMemToString()
        {
            List<string> xdata = new List<string>();

            for (int i = 0; i < data_memory.Length; i++) {
                xdata.Add(String.Format("XDATA:{0:X4} {1:X2}", i, data_memory[i]));
            }

            return xdata;
        }

        private void JumpToVector(int vector)
        {
            push((byte)((pc + 3) & 255));
            push((byte)(((pc + 3) >> 8) & 255));
            pc = (UInt16)vector;
            WriteBitMemory(0xAF, 0); // EA = 0
        }

        private void Interrupts()
        {
            if (!EA) {
                return;
            }

            if (EX0 && IE0) {

            }

            if (ET0 && TF0) {

            }

            if (EX1 && IE1) {

            }

            if (ET1 && TF1) {

            }

            if(ES && (RI || TI)) {
                JumpToVector(0x0023);  
            }

            if(ET2 && (TF2 || EXF2)) {

            }
        }

        public void Step()
        {
            Decode(ref this.pc, true);
            Interrupts();
        }

        private void DisassembleRecursive(Dictionary<UInt16, Instruction> dst, ref UInt16 pc)
        {
            // Stop condition, we got to the end of program memory or
            // we already decoded this address
            if(pc >= program_memory.Length - 3 || dst.ContainsKey(pc)) {
                return;
            }

            UInt16 bpc = pc;
            Instruction inst = Decode(ref pc, false);

            dst.Add(bpc, inst);

            if (inst.TryGetBranch(out bpc)) {                
                DisassembleRecursive(dst, ref bpc);                
            }

            if (inst.GetOpcode() != 0x22) {
                DisassembleRecursive(dst, ref pc);
            }
        }

        public Instruction DisassembleSingle(ref UInt16 saddr)
        {
            return Decode(ref saddr, false);
        }
       
        public List<Instruction> DisassembleBlock(ref UInt16 saddr, int eaddr)
        {
            if (saddr > eaddr) {
                throw new Exception("Invalid address range");
            }

#if true
            List<Instruction> asm = new List<Instruction>();
            while (saddr < eaddr && saddr < program_memory.Length - 3) // -3 because instructions get pc+2 opcode
            {
                asm.Add(Decode(ref saddr, false));
            }
            return asm;
#else
            Dictionary<UInt16, Instruction> asmDico = new Dictionary<UInt16, Instruction>();
            DisassembleRecursive(asmDico, ref saddr);
            List<Instruction> asmList = new List<Instruction>(asmDico.Values);
            asmList.Sort((x, y) => {
                return x.GetAddress() - y.GetAddress();
            });

            return asmList;
#endif
        }

        public int GetCycles()
        {
            return total_cycles;
        }

        public void SetSfrWriteAction(Action<int,int> action)
        {
            sfrWriteAction = action;
        }
    }
}
