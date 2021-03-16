namespace dss52
{
    partial class Form_Main
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.openToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exportAssemblyToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.viewToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.showEncodingToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.terminalToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.debugToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.resetMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.runMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.pauseMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.stepMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.hexConverterToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.contextMenu1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.followMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.runToHereToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.jumpHereToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.gotoToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.disassembleToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.programCounterStripStatusLabel = new System.Windows.Forms.ToolStripStatusLabel();
            this.cyclesStripStatusLabel = new System.Windows.Forms.ToolStripStatusLabel();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.programMemory = new System.Windows.Forms.TextBox();
            this.dataMemory = new System.Windows.Forms.TextBox();
            this.internalMemory = new System.Windows.Forms.TextBox();
            this.registersListView = new System.Windows.Forms.ListView();
            this.disassemblyListView = new System.Windows.Forms.ListView();
            this.CYcheckBox = new System.Windows.Forms.CheckBox();
            this.ACcheckBox = new System.Windows.Forms.CheckBox();
            this.F0checkBox = new System.Windows.Forms.CheckBox();
            this.OVcheckBox = new System.Windows.Forms.CheckBox();
            this.PcheckBox = new System.Windows.Forms.CheckBox();
            this.RS1checkBox = new System.Windows.Forms.CheckBox();
            this.RS0checkBox = new System.Windows.Forms.CheckBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.checkBox1 = new System.Windows.Forms.CheckBox();
            this.EX0checkBox = new System.Windows.Forms.CheckBox();
            this.ET0checkBox = new System.Windows.Forms.CheckBox();
            this.EX1checkBox = new System.Windows.Forms.CheckBox();
            this.ET1checkBox = new System.Windows.Forms.CheckBox();
            this.EScheckBox = new System.Windows.Forms.CheckBox();
            this.ET2checkBox = new System.Windows.Forms.CheckBox();
            this.EAcheckBox = new System.Windows.Forms.CheckBox();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.TIcheckBox = new System.Windows.Forms.CheckBox();
            this.RIcheckBox = new System.Windows.Forms.CheckBox();
            this.contextMenu2 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.toolStripMenuItem4 = new System.Windows.Forms.ToolStripMenuItem();
            this.copyToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.contextMenu1.SuspendLayout();
            this.statusStrip1.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.contextMenu2.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.viewToolStripMenuItem,
            this.debugToolStripMenuItem,
            this.toolsToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(995, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.openToolStripMenuItem,
            this.exportAssemblyToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.fileToolStripMenuItem.Text = "&File";
            // 
            // openToolStripMenuItem
            // 
            this.openToolStripMenuItem.Name = "openToolStripMenuItem";
            this.openToolStripMenuItem.Size = new System.Drawing.Size(162, 22);
            this.openToolStripMenuItem.Text = "&Open";
            this.openToolStripMenuItem.Click += new System.EventHandler(this.openToolStripMenuItem_Click);
            // 
            // exportAssemblyToolStripMenuItem
            // 
            this.exportAssemblyToolStripMenuItem.Name = "exportAssemblyToolStripMenuItem";
            this.exportAssemblyToolStripMenuItem.Size = new System.Drawing.Size(162, 22);
            this.exportAssemblyToolStripMenuItem.Text = "&Export Assembly";
            // 
            // viewToolStripMenuItem
            // 
            this.viewToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.showEncodingToolStripMenuItem,
            this.terminalToolStripMenuItem});
            this.viewToolStripMenuItem.Name = "viewToolStripMenuItem";
            this.viewToolStripMenuItem.Size = new System.Drawing.Size(44, 20);
            this.viewToolStripMenuItem.Text = "View";
            // 
            // showEncodingToolStripMenuItem
            // 
            this.showEncodingToolStripMenuItem.Name = "showEncodingToolStripMenuItem";
            this.showEncodingToolStripMenuItem.Size = new System.Drawing.Size(156, 22);
            this.showEncodingToolStripMenuItem.Text = "Show encoding";
            this.showEncodingToolStripMenuItem.Click += new System.EventHandler(this.assemblyAnBinaryToolStripMenuItem_Click);
            // 
            // terminalToolStripMenuItem
            // 
            this.terminalToolStripMenuItem.Name = "terminalToolStripMenuItem";
            this.terminalToolStripMenuItem.Size = new System.Drawing.Size(156, 22);
            this.terminalToolStripMenuItem.Text = "Terminal";
            this.terminalToolStripMenuItem.Click += new System.EventHandler(this.terminalToolStripMenuItem_Click);
            // 
            // debugToolStripMenuItem
            // 
            this.debugToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.resetMenuItem,
            this.runMenuItem,
            this.pauseMenuItem,
            this.stepMenuItem});
            this.debugToolStripMenuItem.Name = "debugToolStripMenuItem";
            this.debugToolStripMenuItem.Size = new System.Drawing.Size(54, 20);
            this.debugToolStripMenuItem.Text = "Debug";
            // 
            // resetMenuItem
            // 
            this.resetMenuItem.Name = "resetMenuItem";
            this.resetMenuItem.Size = new System.Drawing.Size(105, 22);
            this.resetMenuItem.Text = "Reset";
            this.resetMenuItem.Click += new System.EventHandler(this.resetMenuItem_Click);
            // 
            // runMenuItem
            // 
            this.runMenuItem.Name = "runMenuItem";
            this.runMenuItem.Size = new System.Drawing.Size(105, 22);
            this.runMenuItem.Text = "Run";
            this.runMenuItem.Click += new System.EventHandler(this.runMenuItem_Click);
            // 
            // pauseMenuItem
            // 
            this.pauseMenuItem.Name = "pauseMenuItem";
            this.pauseMenuItem.Size = new System.Drawing.Size(105, 22);
            this.pauseMenuItem.Text = "Pause";
            this.pauseMenuItem.Click += new System.EventHandler(this.pauseMenuItem_Click);
            // 
            // stepMenuItem
            // 
            this.stepMenuItem.Name = "stepMenuItem";
            this.stepMenuItem.Size = new System.Drawing.Size(105, 22);
            this.stepMenuItem.Text = "Step";
            this.stepMenuItem.Click += new System.EventHandler(this.stepMenuItem_Click);
            // 
            // toolsToolStripMenuItem
            // 
            this.toolsToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.hexConverterToolStripMenuItem});
            this.toolsToolStripMenuItem.Name = "toolsToolStripMenuItem";
            this.toolsToolStripMenuItem.Size = new System.Drawing.Size(46, 20);
            this.toolsToolStripMenuItem.Text = "Tools";
            // 
            // hexConverterToolStripMenuItem
            // 
            this.hexConverterToolStripMenuItem.Name = "hexConverterToolStripMenuItem";
            this.hexConverterToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.hexConverterToolStripMenuItem.Text = "Converter";
            this.hexConverterToolStripMenuItem.Click += new System.EventHandler(this.hexConverterToolStripMenuItem_Click);
            // 
            // contextMenu1
            // 
            this.contextMenu1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.followMenuItem,
            this.runToHereToolStripMenuItem,
            this.jumpHereToolStripMenuItem,
            this.gotoToolStripMenuItem,
            this.disassembleToolStripMenuItem});
            this.contextMenu1.Name = "contextMenuStrip1";
            this.contextMenu1.Size = new System.Drawing.Size(140, 114);
            // 
            // followMenuItem
            // 
            this.followMenuItem.Name = "followMenuItem";
            this.followMenuItem.Size = new System.Drawing.Size(139, 22);
            this.followMenuItem.Text = "Follow";
            this.followMenuItem.Click += new System.EventHandler(this.followToolStripMenuItem_Click);
            // 
            // runToHereToolStripMenuItem
            // 
            this.runToHereToolStripMenuItem.Name = "runToHereToolStripMenuItem";
            this.runToHereToolStripMenuItem.Size = new System.Drawing.Size(139, 22);
            this.runToHereToolStripMenuItem.Text = "Run to here";
            this.runToHereToolStripMenuItem.Click += new System.EventHandler(this.runToHereToolStripMenuItem_Click);
            // 
            // jumpHereToolStripMenuItem
            // 
            this.jumpHereToolStripMenuItem.Name = "jumpHereToolStripMenuItem";
            this.jumpHereToolStripMenuItem.Size = new System.Drawing.Size(139, 22);
            this.jumpHereToolStripMenuItem.Text = "Jump here";
            this.jumpHereToolStripMenuItem.Click += new System.EventHandler(this.jumpHereToolStripMenuItem_Click);
            // 
            // gotoToolStripMenuItem
            // 
            this.gotoToolStripMenuItem.Name = "gotoToolStripMenuItem";
            this.gotoToolStripMenuItem.Size = new System.Drawing.Size(139, 22);
            this.gotoToolStripMenuItem.Text = "Go to";
            this.gotoToolStripMenuItem.Click += new System.EventHandler(this.gotoToolStripMenuItem_Click);
            // 
            // disassembleToolStripMenuItem
            // 
            this.disassembleToolStripMenuItem.Name = "disassembleToolStripMenuItem";
            this.disassembleToolStripMenuItem.Size = new System.Drawing.Size(139, 22);
            this.disassembleToolStripMenuItem.Text = "Disassemble";
            this.disassembleToolStripMenuItem.Click += new System.EventHandler(this.disassembleToolStripMenuItem_Click);
            // 
            // statusStrip1
            // 
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.programCounterStripStatusLabel,
            this.cyclesStripStatusLabel});
            this.statusStrip1.Location = new System.Drawing.Point(0, 564);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(995, 22);
            this.statusStrip1.TabIndex = 2;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // programCounterStripStatusLabel
            // 
            this.programCounterStripStatusLabel.Name = "programCounterStripStatusLabel";
            this.programCounterStripStatusLabel.Size = new System.Drawing.Size(43, 17);
            this.programCounterStripStatusLabel.Text = "PC:000";
            // 
            // cyclesStripStatusLabel
            // 
            this.cyclesStripStatusLabel.Name = "cyclesStripStatusLabel";
            this.cyclesStripStatusLabel.Size = new System.Drawing.Size(77, 17);
            this.cyclesStripStatusLabel.Text = "Cycles: 00000";
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            // 
            // programMemory
            // 
            this.programMemory.BackColor = System.Drawing.Color.White;
            this.programMemory.ContextMenuStrip = this.contextMenu2;
            this.programMemory.Font = new System.Drawing.Font("Consolas", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.programMemory.Location = new System.Drawing.Point(7, 424);
            this.programMemory.Multiline = true;
            this.programMemory.Name = "programMemory";
            this.programMemory.ReadOnly = true;
            this.programMemory.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.programMemory.Size = new System.Drawing.Size(580, 133);
            this.programMemory.TabIndex = 4;
            // 
            // dataMemory
            // 
            this.dataMemory.BackColor = System.Drawing.Color.White;
            this.dataMemory.ContextMenuStrip = this.contextMenu2;
            this.dataMemory.Font = new System.Drawing.Font("Consolas", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.dataMemory.Location = new System.Drawing.Point(593, 424);
            this.dataMemory.Multiline = true;
            this.dataMemory.Name = "dataMemory";
            this.dataMemory.ReadOnly = true;
            this.dataMemory.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.dataMemory.Size = new System.Drawing.Size(140, 133);
            this.dataMemory.TabIndex = 5;
            // 
            // internalMemory
            // 
            this.internalMemory.BackColor = System.Drawing.Color.White;
            this.internalMemory.Font = new System.Drawing.Font("Consolas", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.internalMemory.Location = new System.Drawing.Point(739, 424);
            this.internalMemory.Multiline = true;
            this.internalMemory.Name = "internalMemory";
            this.internalMemory.ReadOnly = true;
            this.internalMemory.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.internalMemory.Size = new System.Drawing.Size(256, 133);
            this.internalMemory.TabIndex = 6;
            // 
            // registersListView
            // 
            this.registersListView.GridLines = true;
            this.registersListView.HideSelection = false;
            this.registersListView.Location = new System.Drawing.Point(419, 27);
            this.registersListView.Name = "registersListView";
            this.registersListView.Scrollable = false;
            this.registersListView.Size = new System.Drawing.Size(148, 254);
            this.registersListView.TabIndex = 7;
            this.registersListView.UseCompatibleStateImageBehavior = false;
            // 
            // disassemblyListView
            // 
            this.disassemblyListView.Font = new System.Drawing.Font("Consolas", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.disassemblyListView.GridLines = true;
            this.disassemblyListView.HideSelection = false;
            this.disassemblyListView.LabelEdit = true;
            this.disassemblyListView.Location = new System.Drawing.Point(7, 27);
            this.disassemblyListView.MultiSelect = false;
            this.disassemblyListView.Name = "disassemblyListView";
            this.disassemblyListView.Size = new System.Drawing.Size(403, 376);
            this.disassemblyListView.TabIndex = 8;
            this.disassemblyListView.UseCompatibleStateImageBehavior = false;
            this.disassemblyListView.MouseClick += new System.Windows.Forms.MouseEventHandler(this.disassemblyListView_MouseClick);
            // 
            // CYcheckBox
            // 
            this.CYcheckBox.AutoSize = true;
            this.CYcheckBox.CheckAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.CYcheckBox.Font = new System.Drawing.Font("Consolas", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.CYcheckBox.Location = new System.Drawing.Point(3, 0);
            this.CYcheckBox.Name = "CYcheckBox";
            this.CYcheckBox.Size = new System.Drawing.Size(23, 31);
            this.CYcheckBox.TabIndex = 9;
            this.CYcheckBox.Text = "CY";
            this.CYcheckBox.UseVisualStyleBackColor = true;
            // 
            // ACcheckBox
            // 
            this.ACcheckBox.AutoSize = true;
            this.ACcheckBox.CheckAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.ACcheckBox.Font = new System.Drawing.Font("Consolas", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ACcheckBox.Location = new System.Drawing.Point(23, 0);
            this.ACcheckBox.Name = "ACcheckBox";
            this.ACcheckBox.Size = new System.Drawing.Size(23, 31);
            this.ACcheckBox.TabIndex = 10;
            this.ACcheckBox.Text = "AC";
            this.ACcheckBox.UseVisualStyleBackColor = true;
            // 
            // F0checkBox
            // 
            this.F0checkBox.AutoSize = true;
            this.F0checkBox.CheckAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.F0checkBox.Font = new System.Drawing.Font("Consolas", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.F0checkBox.Location = new System.Drawing.Point(43, 0);
            this.F0checkBox.Name = "F0checkBox";
            this.F0checkBox.Size = new System.Drawing.Size(23, 31);
            this.F0checkBox.TabIndex = 11;
            this.F0checkBox.Text = "F0";
            this.F0checkBox.UseVisualStyleBackColor = true;
            // 
            // OVcheckBox
            // 
            this.OVcheckBox.AutoSize = true;
            this.OVcheckBox.CheckAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.OVcheckBox.Font = new System.Drawing.Font("Consolas", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.OVcheckBox.Location = new System.Drawing.Point(63, 0);
            this.OVcheckBox.Name = "OVcheckBox";
            this.OVcheckBox.Size = new System.Drawing.Size(23, 31);
            this.OVcheckBox.TabIndex = 12;
            this.OVcheckBox.Text = "OV";
            this.OVcheckBox.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.OVcheckBox.UseVisualStyleBackColor = true;
            // 
            // PcheckBox
            // 
            this.PcheckBox.AutoSize = true;
            this.PcheckBox.CheckAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.PcheckBox.Font = new System.Drawing.Font("Consolas", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.PcheckBox.Location = new System.Drawing.Point(83, 0);
            this.PcheckBox.Name = "PcheckBox";
            this.PcheckBox.Size = new System.Drawing.Size(23, 31);
            this.PcheckBox.TabIndex = 13;
            this.PcheckBox.Text = "P ";
            this.PcheckBox.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.PcheckBox.UseVisualStyleBackColor = true;
            // 
            // RS1checkBox
            // 
            this.RS1checkBox.AutoSize = true;
            this.RS1checkBox.CheckAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.RS1checkBox.Font = new System.Drawing.Font("Consolas", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.RS1checkBox.Location = new System.Drawing.Point(103, 0);
            this.RS1checkBox.Name = "RS1checkBox";
            this.RS1checkBox.Size = new System.Drawing.Size(23, 31);
            this.RS1checkBox.TabIndex = 14;
            this.RS1checkBox.Text = "R1";
            this.RS1checkBox.UseVisualStyleBackColor = true;
            // 
            // RS0checkBox
            // 
            this.RS0checkBox.AutoSize = true;
            this.RS0checkBox.CheckAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.RS0checkBox.Font = new System.Drawing.Font("Consolas", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.RS0checkBox.Location = new System.Drawing.Point(123, 0);
            this.RS0checkBox.Name = "RS0checkBox";
            this.RS0checkBox.Size = new System.Drawing.Size(23, 31);
            this.RS0checkBox.TabIndex = 15;
            this.RS0checkBox.Text = "R0";
            this.RS0checkBox.UseVisualStyleBackColor = true;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.RS0checkBox);
            this.groupBox1.Controls.Add(this.CYcheckBox);
            this.groupBox1.Controls.Add(this.RS1checkBox);
            this.groupBox1.Controls.Add(this.ACcheckBox);
            this.groupBox1.Controls.Add(this.PcheckBox);
            this.groupBox1.Controls.Add(this.F0checkBox);
            this.groupBox1.Controls.Add(this.OVcheckBox);
            this.groupBox1.Location = new System.Drawing.Point(416, 360);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(148, 43);
            this.groupBox1.TabIndex = 11;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "groupBox1";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.checkBox1);
            this.groupBox2.Controls.Add(this.EX0checkBox);
            this.groupBox2.Controls.Add(this.ET0checkBox);
            this.groupBox2.Controls.Add(this.EX1checkBox);
            this.groupBox2.Controls.Add(this.ET1checkBox);
            this.groupBox2.Controls.Add(this.EScheckBox);
            this.groupBox2.Controls.Add(this.ET2checkBox);
            this.groupBox2.Controls.Add(this.EAcheckBox);
            this.groupBox2.Location = new System.Drawing.Point(748, 27);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(235, 50);
            this.groupBox2.TabIndex = 16;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "IE";
            // 
            // checkBox1
            // 
            this.checkBox1.AutoSize = true;
            this.checkBox1.CheckAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.checkBox1.Enabled = false;
            this.checkBox1.Font = new System.Drawing.Font("Consolas", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.checkBox1.Location = new System.Drawing.Point(35, 19);
            this.checkBox1.Name = "checkBox1";
            this.checkBox1.Size = new System.Drawing.Size(17, 31);
            this.checkBox1.TabIndex = 6;
            this.checkBox1.Text = "-";
            this.checkBox1.UseVisualStyleBackColor = true;
            // 
            // EX0checkBox
            // 
            this.EX0checkBox.AutoSize = true;
            this.EX0checkBox.CheckAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.EX0checkBox.Font = new System.Drawing.Font("Consolas", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.EX0checkBox.Location = new System.Drawing.Point(203, 19);
            this.EX0checkBox.Name = "EX0checkBox";
            this.EX0checkBox.Size = new System.Drawing.Size(29, 31);
            this.EX0checkBox.TabIndex = 0;
            this.EX0checkBox.Text = "EX0";
            this.EX0checkBox.UseVisualStyleBackColor = true;
            // 
            // ET0checkBox
            // 
            this.ET0checkBox.AutoSize = true;
            this.ET0checkBox.CheckAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.ET0checkBox.Font = new System.Drawing.Font("Consolas", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ET0checkBox.Location = new System.Drawing.Point(174, 19);
            this.ET0checkBox.Name = "ET0checkBox";
            this.ET0checkBox.Size = new System.Drawing.Size(29, 31);
            this.ET0checkBox.TabIndex = 1;
            this.ET0checkBox.Text = "ET0";
            this.ET0checkBox.UseVisualStyleBackColor = true;
            // 
            // EX1checkBox
            // 
            this.EX1checkBox.AutoSize = true;
            this.EX1checkBox.CheckAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.EX1checkBox.Font = new System.Drawing.Font("Consolas", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.EX1checkBox.Location = new System.Drawing.Point(145, 19);
            this.EX1checkBox.Name = "EX1checkBox";
            this.EX1checkBox.Size = new System.Drawing.Size(29, 31);
            this.EX1checkBox.TabIndex = 2;
            this.EX1checkBox.Text = "EX1";
            this.EX1checkBox.UseVisualStyleBackColor = true;
            // 
            // ET1checkBox
            // 
            this.ET1checkBox.AutoSize = true;
            this.ET1checkBox.CheckAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.ET1checkBox.Font = new System.Drawing.Font("Consolas", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ET1checkBox.Location = new System.Drawing.Point(116, 19);
            this.ET1checkBox.Name = "ET1checkBox";
            this.ET1checkBox.Size = new System.Drawing.Size(29, 31);
            this.ET1checkBox.TabIndex = 3;
            this.ET1checkBox.Text = "ET1";
            this.ET1checkBox.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.ET1checkBox.UseVisualStyleBackColor = true;
            // 
            // EScheckBox
            // 
            this.EScheckBox.AutoSize = true;
            this.EScheckBox.CheckAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.EScheckBox.Font = new System.Drawing.Font("Consolas", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.EScheckBox.Location = new System.Drawing.Point(87, 19);
            this.EScheckBox.Name = "EScheckBox";
            this.EScheckBox.Size = new System.Drawing.Size(29, 31);
            this.EScheckBox.TabIndex = 4;
            this.EScheckBox.Text = "ES ";
            this.EScheckBox.UseVisualStyleBackColor = true;
            this.EScheckBox.CheckedChanged += new System.EventHandler(this.EScheckBox_CheckedChanged);
            // 
            // ET2checkBox
            // 
            this.ET2checkBox.AutoSize = true;
            this.ET2checkBox.CheckAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.ET2checkBox.Font = new System.Drawing.Font("Consolas", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ET2checkBox.Location = new System.Drawing.Point(58, 19);
            this.ET2checkBox.Name = "ET2checkBox";
            this.ET2checkBox.Size = new System.Drawing.Size(29, 31);
            this.ET2checkBox.TabIndex = 5;
            this.ET2checkBox.Text = "ET2";
            this.ET2checkBox.UseVisualStyleBackColor = true;
            // 
            // EAcheckBox
            // 
            this.EAcheckBox.AutoSize = true;
            this.EAcheckBox.CheckAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.EAcheckBox.Font = new System.Drawing.Font("Consolas", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.EAcheckBox.Location = new System.Drawing.Point(6, 19);
            this.EAcheckBox.Name = "EAcheckBox";
            this.EAcheckBox.Size = new System.Drawing.Size(29, 31);
            this.EAcheckBox.TabIndex = 7;
            this.EAcheckBox.Text = "EA ";
            this.EAcheckBox.UseVisualStyleBackColor = true;
            this.EAcheckBox.CheckedChanged += new System.EventHandler(this.EAcheckBox_CheckedChanged);
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.TIcheckBox);
            this.groupBox3.Controls.Add(this.RIcheckBox);
            this.groupBox3.Location = new System.Drawing.Point(748, 83);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(235, 50);
            this.groupBox3.TabIndex = 18;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "SCON";
            // 
            // TIcheckBox
            // 
            this.TIcheckBox.AutoSize = true;
            this.TIcheckBox.CheckAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.TIcheckBox.Font = new System.Drawing.Font("Consolas", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TIcheckBox.Location = new System.Drawing.Point(177, 10);
            this.TIcheckBox.Name = "TIcheckBox";
            this.TIcheckBox.Size = new System.Drawing.Size(23, 31);
            this.TIcheckBox.TabIndex = 9;
            this.TIcheckBox.Text = "TI";
            this.TIcheckBox.UseVisualStyleBackColor = true;
            this.TIcheckBox.CheckedChanged += new System.EventHandler(this.TIcheckBox_CheckedChanged);
            // 
            // RIcheckBox
            // 
            this.RIcheckBox.AutoSize = true;
            this.RIcheckBox.CheckAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.RIcheckBox.Font = new System.Drawing.Font("Consolas", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.RIcheckBox.Location = new System.Drawing.Point(206, 10);
            this.RIcheckBox.Name = "RIcheckBox";
            this.RIcheckBox.Size = new System.Drawing.Size(23, 31);
            this.RIcheckBox.TabIndex = 10;
            this.RIcheckBox.Text = "RI";
            this.RIcheckBox.UseVisualStyleBackColor = true;
            this.RIcheckBox.CheckedChanged += new System.EventHandler(this.RIcheckBox_CheckedChanged);
            // 
            // contextMenu2
            // 
            this.contextMenu2.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripMenuItem4,
            this.copyToolStripMenuItem});
            this.contextMenu2.Name = "contextMenuStrip1";
            this.contextMenu2.Size = new System.Drawing.Size(104, 48);
            // 
            // toolStripMenuItem4
            // 
            this.toolStripMenuItem4.Name = "toolStripMenuItem4";
            this.toolStripMenuItem4.Size = new System.Drawing.Size(103, 22);
            this.toolStripMenuItem4.Text = "Go to";
            // 
            // copyToolStripMenuItem
            // 
            this.copyToolStripMenuItem.Name = "copyToolStripMenuItem";
            this.copyToolStripMenuItem.Size = new System.Drawing.Size(103, 22);
            this.copyToolStripMenuItem.Text = "Copy";
            // 
            // Form_Main
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(995, 586);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.disassemblyListView);
            this.Controls.Add(this.registersListView);
            this.Controls.Add(this.dataMemory);
            this.Controls.Add(this.programMemory);
            this.Controls.Add(this.internalMemory);
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form_Main";
            this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
            this.Text = "Form1";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.contextMenu1.ResumeLayout(false);
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.contextMenu2.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem openToolStripMenuItem;
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.ContextMenuStrip contextMenu1;
        private System.Windows.Forms.ToolStripMenuItem followMenuItem;
        private System.Windows.Forms.TextBox programMemory;
        private System.Windows.Forms.TextBox dataMemory;
        private System.Windows.Forms.TextBox internalMemory;
        private System.Windows.Forms.ListView registersListView;
        private System.Windows.Forms.ToolStripMenuItem viewToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem showEncodingToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exportAssemblyToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem debugToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem resetMenuItem;
        private System.Windows.Forms.ToolStripMenuItem runMenuItem;
        private System.Windows.Forms.ToolStripMenuItem pauseMenuItem;
        private System.Windows.Forms.ToolStripMenuItem stepMenuItem;
        private System.Windows.Forms.ToolStripStatusLabel programCounterStripStatusLabel;
        private System.Windows.Forms.ListView disassemblyListView;
        private System.Windows.Forms.CheckBox CYcheckBox;
        private System.Windows.Forms.CheckBox ACcheckBox;
        private System.Windows.Forms.CheckBox F0checkBox;
        private System.Windows.Forms.CheckBox OVcheckBox;
        private System.Windows.Forms.CheckBox PcheckBox;
        private System.Windows.Forms.CheckBox RS1checkBox;
        private System.Windows.Forms.CheckBox RS0checkBox;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.ToolStripMenuItem terminalToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem jumpHereToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem runToHereToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem gotoToolStripMenuItem;
        private System.Windows.Forms.ToolStripStatusLabel cyclesStripStatusLabel;
        private System.Windows.Forms.ToolStripMenuItem toolsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem hexConverterToolStripMenuItem;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.CheckBox EX0checkBox;
        private System.Windows.Forms.CheckBox ET0checkBox;
        private System.Windows.Forms.CheckBox EX1checkBox;
        private System.Windows.Forms.CheckBox ET1checkBox;
        private System.Windows.Forms.CheckBox EScheckBox;
        private System.Windows.Forms.CheckBox ET2checkBox;
        private System.Windows.Forms.CheckBox EAcheckBox;
        private System.Windows.Forms.ToolStripMenuItem disassembleToolStripMenuItem;
        private System.Windows.Forms.CheckBox checkBox1;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.CheckBox TIcheckBox;
        private System.Windows.Forms.CheckBox RIcheckBox;
        private System.Windows.Forms.ContextMenuStrip contextMenu2;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem4;
        private System.Windows.Forms.ToolStripMenuItem copyToolStripMenuItem;
    }
}

