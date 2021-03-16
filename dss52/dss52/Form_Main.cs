using System;
using System.Collections.Generic;

using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Security;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;



namespace dss52
{

    public partial class Form_Main : Form
    {
        Cpu x52 = null;        
        
        bool debugging = false;
        private volatile bool debug_cpu_running = false;

        ListViewItem debug_cur_item;
        List<Instruction> decoded_instructions = null;
        Dictionary<int, ListViewItem> decoded_items = null;
        private UInt16 last_goto;
        private readonly int DEFAULT_LINES_TO_DECODE = 16;

        private terminalForm terminal = new terminalForm();

        public Form_Main()
        {
            InitializeComponent();

            x52 = new Cpu();

            openFileDialog1 = new OpenFileDialog() {
                FileName = "Select file",
                Filter = "Binary|*.bin;*.hex|Bin|*.bin|Hex|*.hex|All|*.*",
                Title = "Open code memory"
            };

            // Registers ListBox configuration
            registersListView.View = View.Details;
            registersListView.GridLines = true;
            registersListView.FullRowSelect = true;
            //registersListView.LabelEdit = true;

            registersListView.Columns.Add("Register", -2, HorizontalAlignment.Left);
            registersListView.Columns.Add("Value", -2, HorizontalAlignment.Left);

            ListViewItem[] regs = new ListViewItem[Cpu.registerNames.Length];

            for (int i = 0; i < regs.Length; i++) {
                regs[i] = new ListViewItem(Cpu.registerNames[i]);
                regs[i].SubItems.Add("0");
            }

            registersListView.Items.AddRange(regs);
            registersListView.Height = (registersListView.Items.Count * 20) - 9; // Magic
            registersListView.DoubleBuffered(true);

            /**
             * Disassembly listview
             * */
            disassemblyListView.View = View.Details;
            disassemblyListView.FullRowSelect = true;
            disassemblyListView.GridLines = true;
            disassemblyListView.LabelEdit = false;

            disassemblyListView.Columns.Add("Address", 90, HorizontalAlignment.Left);
            disassemblyListView.Columns.Add("Encoding", 90, HorizontalAlignment.Left);            
            disassemblyListView.Columns.Add("Mnemonic", 200, HorizontalAlignment.Left);

            disassemblyListView.DoubleBuffered(true);

            //disassemblyListView.HeaderStyle = System.Windows.Forms.ColumnHeaderStyle.None;

            /**
             * Configure Menus
             * */
            showEncodingToolStripMenuItem.Checked = true;

            runMenuItem.ShortcutKeys = Keys.F5;
            runMenuItem.ShowShortcutKeys = true;

            resetMenuItem.ShortcutKeys = Keys.F4;
            resetMenuItem.ShowShortcutKeys = true;

            stepMenuItem.ShortcutKeys = Keys.F10;
            stepMenuItem.ShowShortcutKeys = true;

            pauseMenuItem.ShortcutKeys = Keys.F6;
            pauseMenuItem.ShowShortcutKeys = true;

            // -------------------------------------------           
            LoadAssemblyLinesAsync(0, 20);
            UpdateMemoryWindow();
            UpdateCodeWindow();
            //StopDebug();

            x52.SetSfrWriteAction(updateSfr);

            programMemory.DoubleBuffered(true);
            dataMemory.DoubleBuffered(true);
            internalMemory.DoubleBuffered(true);
        }

        private void updateSfr(int addr, int data)
        {
            switch (addr) {
                case 0x99:
                    terminal.PutChar(Convert.ToChar(data));
                    break;
            }
        }

        private void UpdateCpuRegisters()
        {
            registersListView.BeginUpdate();

            registersListView.Items[0].SubItems[1].Text = $"{x52.acc:X2}";
            registersListView.Items[1].SubItems[1].Text = $"{x52.b:X2}";
            for (int i = 0; i < 8; i++) {
                registersListView.Items[2 + i].SubItems[1].Text = $"{x52.r[i]:X2}";
            }
            registersListView.Items[10].SubItems[1].Text = $"{x52.psw:X2}";
            registersListView.Items[11].SubItems[1].Text = $"{x52.sp:X2}";
            registersListView.Items[12].SubItems[1].Text = $"{x52.dpl:X2}";
            registersListView.Items[13].SubItems[1].Text = $"{x52.dph:X2}";

            CYcheckBox.Checked = (x52.psw & Core51.CY) != 0;
            ACcheckBox.Checked = (x52.psw & Core51.AC) != 0;
            F0checkBox.Checked = (x52.psw & Core51.F0) != 0;
            OVcheckBox.Checked = (x52.psw & Core51.OV) != 0;
            RS1checkBox.Checked = (x52.psw & Core51.RS1) != 0;
            RS0checkBox.Checked = (x52.psw & Core51.RS0) != 0;

            TIcheckBox.Checked = x52.TI;
            RIcheckBox.Checked = x52.RI;

            EAcheckBox.Checked = x52.EA;
            ET2checkBox.Checked = x52.ET2;
            EScheckBox.Checked = x52.ES;
            ET1checkBox.Checked = x52.ET1;
            EX1checkBox.Checked = x52.EX1;
            ET0checkBox.Checked = x52.ET0;            
            EX0checkBox.Checked = x52.EX0;

            registersListView.EndUpdate();
        }
        private async void UpdateMemoryWindow()
        {
            string [] res = await Task.Run(() => {
                string[] result = new string[2];                
                result[0] = String.Join(Environment.NewLine, x52.dataMemToString());
                result[1] = String.Join(Environment.NewLine, x52.intMemToString());
                return result;
            });
            dataMemory.Text = res[0];
            internalMemory.Text = res[1];            
        }

        private async void UpdateCodeWindow()
        {
            string res = await Task.Run(() => {                
                return String.Join(Environment.NewLine, x52.codeMemToString());
            });            
            programMemory.Text = res;            
        }

        /**
         * Dissabemble n assembly lines
         * */
        private List<Instruction> DisassembleLines(UInt16 saddr, int lines)
        {
            List<Instruction> instList = new List<Instruction>();
            for (int i = 0; i < lines; i++) {
                instList.Add(x52.DisassembleSingle(ref saddr));
            }
            return instList;
        }

        /**
         * Diasassemble program counter range
         * */
        private Task<List<Instruction>> DisassembleToListAsync(UInt16 saddr, int eaddr)
        {
            return new Task<List<Instruction>>(() => {
                return x52.DisassembleBlock(ref saddr, eaddr);
            });
        }

        /**
         * Diasassemble n assembly lines
         * */
        private Task<List<Instruction>> DisassembleLinesToListAsync(UInt16 saddr, int lines)
        {
            return new Task<List<Instruction>>(() => {
                return DisassembleLines(saddr, lines);
            });
        }

        /**
         * Convert List<Instruction> to ListViewItem []
         * */
        private Task<Dictionary<int,ListViewItem>> CreateListViewItemsAsync(List<Instruction> inst, bool show_encoding)
        {
            return new Task<Dictionary<int, ListViewItem>>(() => {
                return CreateListViewItems(inst, show_encoding);
            });
        }       

        private void StartDebug()
        {
            x52.reset();
            UpdateCpuRegisters();

            if (disassemblyListView.FocusedItem != null) {
                disassemblyListView.FocusedItem.Focused = false;
                disassemblyListView.SelectedItems.Clear();
            }

            PauseDebug();

            NavigateTo(x52.pc, false);

            programCounterStripStatusLabel.Text = $"PC:{x52.pc:X4}";

            runToHereToolStripMenuItem.Enabled = true;
            jumpHereToolStripMenuItem.Enabled = true;
        }

        private void PauseDebug()
        {
            if (debugging) {
                debug_cpu_running = false;
            }
        }

        private void StopDebug()
        {
            debugging = false;
            debug_cpu_running = false;
            runToHereToolStripMenuItem.Enabled = false;
            jumpHereToolStripMenuItem.Enabled = false;
            if(debug_cur_item != null) {
                debug_cur_item.BackColor = Color.White;
            }
        }

        /**
         * 
         * 
         * 
         * 
         * 
         * 
         * 
         * */

        private Dictionary<int,ListViewItem> CreateListViewItems(List<Instruction> insts, bool show_encoding)
        {
            Dictionary<int, ListViewItem> asmDico = new Dictionary<int, ListViewItem>();
            List<UInt16> jumpList = new List<UInt16>();

            try {
                foreach (Instruction inst in insts) {
                    ListViewItem item = new ListViewItem();
                    item.Name = $"{inst.GetAddress():X4}";

                    if (show_encoding) {
                        item.Text = $"CODE:{inst.GetAddress():X4}";
                        item.SubItems.Add(inst.GetEncoding());
                    } else {
                        UInt16 jump;                        
                        if (inst.TryGetBranch(out jump)) {
                            // Save branch address
                            if(jumpList.Contains(jump) == false) {
                                jumpList.Add(jump);
                            }
                        }
                        item.SubItems.Add("");
                    }
                    item.SubItems.Add(inst.GetMnmemonic());
                    asmDico.Add(inst.GetAddress(), item);
                }

                // Place labels
                foreach (UInt16 entry in jumpList) {
                    // Place labels only if address has been decoded
                    if (asmDico.ContainsKey(entry)) {
                        asmDico[entry].SubItems[1].Text = $"X{entry:X4}:";
                    }
                }
                return asmDico;

            }catch(Exception ex) {
                throw new Exception($"CreateListViewItems:\n{ex}");
            }
        }
        private async void NavigateTo(UInt16 addr, bool selected_cursor)
        {
            ListViewItem next_item;            

            if (decoded_items.TryGetValue(addr, out next_item) == false) {
                var task = AppendAssemblyLinesAsync(addr, DEFAULT_LINES_TO_DECODE, showEncodingToolStripMenuItem.Checked);
                task.Start();
                ListViewItem[] result = await task;

                disassemblyListView.Items.Clear();
                disassemblyListView.Items.AddRange(result);
            }
            
            if (selected_cursor) {
                decoded_items[addr].Selected = true;
                decoded_items[addr].Focused = true;
            }

            // If debugging, preserve selection of PC
            if (debugging) {
                // deselect previous line
                debug_cur_item.BackColor = Color.White;
                // Highlight the next instruction to be executed
                debug_cur_item = decoded_items[x52.pc];
                debug_cur_item.BackColor = Color.Aqua;              

                programCounterStripStatusLabel.Text = $"PC:{x52.pc:X4}";
                cyclesStripStatusLabel.Text = $"Cycles: {x52.GetCycles()}";
            }

            decoded_items[addr].EnsureVisible();
        }      
        

        private async void LoadAssemblyLinesAsync(UInt16 pc, int lines)
        {
            bool show_encoding = showEncodingToolStripMenuItem.Checked;
            ListViewItem[] result = await Task.Run(() => {
                decoded_instructions = DisassembleLines(pc, lines);
                decoded_items = CreateListViewItems(decoded_instructions, show_encoding);
                return decoded_items.Values.ToArray();
            });

            disassemblyListView.Items.Clear();
            disassemblyListView.Items.AddRange(result);
        }

        private Task<ListViewItem []> AppendAssemblyLinesAsync(UInt16 pc, int lines, bool show_encoding)
        {             
            return new Task<ListViewItem []>(()=> {
                AppendAssemblyLines(pc, lines, show_encoding);                
                return decoded_items.Values.ToArray();
            });            
        }

        private void AppendAssemblyLines(UInt16 pc, int lines, bool show_encoding)
        {            
            List<Instruction> new_block = DisassembleLines(pc, lines);
            decoded_instructions.AddRange(new_block);
            decoded_instructions = decoded_instructions.Distinct(new Instruction()).ToList();
            decoded_instructions.Sort((a, b) => { return a.GetAddress() - b.GetAddress(); });
            decoded_items = CreateListViewItems(decoded_instructions, show_encoding);           
        }

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog() == DialogResult.OK) {
                try {                    
                    if (Path.GetExtension(openFileDialog1.FileName) == ".hex") {
                        x52.loadCode(Converter.hex2bin(openFileDialog1.FileName, x52.getCodeMemory().Length));
                    } else {
                        x52.loadCode(File.ReadAllBytes(openFileDialog1.FileName));
                    }
                    LoadAssemblyLinesAsync(0, 16);
                    UpdateCodeWindow();
                    if (debugging) {
                        StopDebug();
                    }
                } catch (Exception ex) {
                    MessageBox.Show($"openToolStripMenuItem_Click: {ex.Message}\n\n");
                }
            }
        }

        private async void assemblyAnBinaryToolStripMenuItem_Click(object sender, EventArgs e)
        {
            showEncodingToolStripMenuItem.Checked = !showEncodingToolStripMenuItem.Checked;
            int selected_address = -1;
            try {
                // get selected address, if any                
                selected_address = Convert.ToUInt16(disassemblyListView.SelectedItems[0].Name, 16);                
            } catch (Exception ex){
                
            }

            // Create new item list from decoded_intructions w/wo encoding
            Task<Dictionary<int, ListViewItem>> item_task = CreateListViewItemsAsync(decoded_instructions, showEncodingToolStripMenuItem.Checked);
            item_task.Start();
            decoded_items = await item_task;            
            disassemblyListView.Items.Clear();
            disassemblyListView.Items.AddRange(decoded_items.Values.ToArray());
            // if an address was selected, make it visible
            if(selected_address > 0) {
                decoded_items[selected_address].Selected = true;
                decoded_items[selected_address].EnsureVisible();
            }
        }
        private void pauseMenuItem_Click(object sender, EventArgs e)
        {
            PauseDebug();
        }
        private async void runMenuItem_Click(object sender, EventArgs e)
        {
            bool show_encoding = showEncodingToolStripMenuItem.Checked;
            bool update_lv = false;

            if (!debugging) {
                debugging = true;
                if (debug_cur_item == null) {
                    debug_cur_item = disassemblyListView.Items[0];
                }
                StartDebug();
            } else {
                if (debug_cpu_running) {
                    return;
                }

                await Task.Run(() => {
                    debug_cpu_running = true;
                    programCounterStripStatusLabel.Text = $"PC: Running..";

                    while (debug_cpu_running) {
                        x52.Step();
                        //Task.Delay(10);
                        ListViewItem lvi;
                        if (decoded_items.TryGetValue(x52.pc, out lvi) == false) {
                            AppendAssemblyLines(x52.pc, DEFAULT_LINES_TO_DECODE, show_encoding);
                            update_lv = true;
                        }
                    }
                    debug_cpu_running = false;
                });

                UpdateCpuRegisters();
                UpdateMemoryWindow();

                if (update_lv) {
                    disassemblyListView.Items.Clear();
                    disassemblyListView.Items.AddRange(decoded_items.Values.ToArray());
                }

                NavigateTo(x52.pc, false);
            }
        }        

        private void stepMenuItem_Click(object sender, EventArgs e)
        {
            if (!debugging) {
                return;
            }

            x52.Step();
            try {                
                NavigateTo(x52.pc, false);
                UpdateCpuRegisters();
                UpdateMemoryWindow();
            } catch (Exception ex){
                MessageBox.Show($"Error:\n{ex}");
            }
        }

        private void resetMenuItem_Click(object sender, EventArgs e)
        {
            if (!debugging) {
                return;
            }
            try {
                StartDebug();
            }catch (Exception ex) {
                MessageBox.Show($"Error:\n{ex}");
            }
        }

        private void hexConverterToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Converter hc = new Converter();
            hc.Show();
        }

        private void terminalToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (terminal.Visible) {
                return;
            }
            terminal.Show();
        }
        /**
         * Helper to show context menu
         * */
        private void disassemblyListView_MouseClick(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Right) {
                if (disassemblyListView.FocusedItem.Bounds.Contains(e.Location)) {
                    contextMenu1.Show(Cursor.Position);
                }
            }
        }
        
        private void followToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try {
                ListViewItem lvi = disassemblyListView.SelectedItems[0];
                lvi.Selected = false;
                UInt16 follow_addr = Convert.ToUInt16(lvi.SubItems[2].Text.Split('X')[1], 16);
                NavigateTo(follow_addr, true);

            } catch (Exception ex) {
                MessageBox.Show($"Error:\n{ex}");
            }
        }

        private void gotoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            var dialog = new Form_GoTo();

            if (dialog.InputBox("Go to address", "Address:", ref last_goto) == DialogResult.OK) {
                NavigateTo(last_goto, true);
            }
        }

        private void jumpHereToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (!debugging) {
                return;
            }
            
            try {                
                x52.pc = Convert.ToUInt16(disassemblyListView.SelectedItems[0].Name, 16);
                NavigateTo(x52.pc, false);
            } catch (Exception ex) {
                MessageBox.Show($"{ex}");
            }
        }

        private async void runToHereToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // Avoid start running while already running or if not debugging at all
            if (!debugging || debug_cpu_running) {
                return;
            }

            bool show_encoding = showEncodingToolStripMenuItem.Checked;
            bool update_lv = false;
            try {
                ListViewItem lvi = disassemblyListView.SelectedItems[0];
                await Task.Run(() => {
                    UInt16 addr = Convert.ToUInt16(lvi.Name, 16);
                    debug_cpu_running = true;
                    programCounterStripStatusLabel.Text = $"PC: Running..";

                    while (x52.pc != addr && debug_cpu_running) {
                        x52.Step();                        
                        if (decoded_items.TryGetValue(x52.pc, out lvi) == false) {
                            AppendAssemblyLines(x52.pc, DEFAULT_LINES_TO_DECODE, show_encoding);
                            update_lv = true;
                        }
                    }
                    debug_cpu_running = false;
                });

                UpdateCpuRegisters();
                if (update_lv) {
                    disassemblyListView.Items.Clear();
                    disassemblyListView.Items.AddRange(decoded_items.Values.ToArray());
                }
                NavigateTo(x52.pc, false);
                disassemblyListView.SelectedItems.Clear();

            } catch (Exception ex) {
                MessageBox.Show($"{ex}\n\nRun execption at {x52.pc:X4}:{x52.program_memory[x52.pc]:X2}");
            }
        }

        private void disassembleToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try {
                throw new NotImplementedException();
                ListViewItem lvi = disassemblyListView.SelectedItems[0];
                lvi.Selected = false;
                UInt16 follow_addr = Convert.ToUInt16(lvi.Name, 16);
                NavigateTo(follow_addr, true);

            } catch (Exception ex) {
                MessageBox.Show($"Error:\n{ex}");
            }
        }
         

        private void EAcheckBox_CheckedChanged(object sender, EventArgs e)
        {
            x52.EA = EAcheckBox.Checked;
        }

        private void EScheckBox_CheckedChanged(object sender, EventArgs e)
        {
            x52.ES = EScheckBox.Checked;
        }

        private void TIcheckBox_CheckedChanged(object sender, EventArgs e)
        {
            x52.TI = TIcheckBox.Checked;
        }
        private void RIcheckBox_CheckedChanged(object sender, EventArgs e)
        {
            x52.RI = RIcheckBox.Checked;
        }
    }
}
