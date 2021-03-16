using System.Windows.Forms;

namespace dss52
{
    partial class Converter
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
            if (disposing && (components != null)) {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        private void InitializeComponent()
        {
            this.inputFileBox = new System.Windows.Forms.TextBox();
            this.outputFileBox = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.selectInputFileButton = new System.Windows.Forms.Button();
            this.selectOutputFileButton = new System.Windows.Forms.Button();
            this.saveBinaryButton = new System.Windows.Forms.Button();
            this.flashSizeComboBox = new System.Windows.Forms.ComboBox();
            this.label3 = new System.Windows.Forms.Label();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.saveFileDialog1 = new System.Windows.Forms.SaveFileDialog();
            this.button1 = new System.Windows.Forms.Button();
            this.saveHexButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // inputFileBox
            // 
            this.inputFileBox.Location = new System.Drawing.Point(12, 32);
            this.inputFileBox.Name = "inputFileBox";
            this.inputFileBox.Size = new System.Drawing.Size(275, 20);
            this.inputFileBox.TabIndex = 0;
            // 
            // outputFileBox
            // 
            this.outputFileBox.Location = new System.Drawing.Point(12, 79);
            this.outputFileBox.Name = "outputFileBox";
            this.outputFileBox.Size = new System.Drawing.Size(275, 20);
            this.outputFileBox.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(9, 16);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(47, 13);
            this.label1.TabIndex = 2;
            this.label1.Text = "Input file";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(9, 63);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(55, 13);
            this.label2.TabIndex = 3;
            this.label2.Text = "Output file";
            // 
            // selectInputFileButton
            // 
            this.selectInputFileButton.Location = new System.Drawing.Point(293, 32);
            this.selectInputFileButton.Name = "selectInputFileButton";
            this.selectInputFileButton.Size = new System.Drawing.Size(34, 19);
            this.selectInputFileButton.TabIndex = 4;
            this.selectInputFileButton.Text = "...";
            this.selectInputFileButton.UseVisualStyleBackColor = true;
            this.selectInputFileButton.Click += new System.EventHandler(this.selectInputFileButton_Click);
            // 
            // selectOutputFileButton
            // 
            this.selectOutputFileButton.Location = new System.Drawing.Point(293, 80);
            this.selectOutputFileButton.Name = "selectOutputFileButton";
            this.selectOutputFileButton.Size = new System.Drawing.Size(34, 19);
            this.selectOutputFileButton.TabIndex = 5;
            this.selectOutputFileButton.Text = "...";
            this.selectOutputFileButton.UseVisualStyleBackColor = true;
            this.selectOutputFileButton.Click += new System.EventHandler(this.selectOutputFileButton_Click);
            // 
            // saveBinaryButton
            // 
            this.saveBinaryButton.Location = new System.Drawing.Point(245, 125);
            this.saveBinaryButton.Name = "saveBinaryButton";
            this.saveBinaryButton.Size = new System.Drawing.Size(82, 25);
            this.saveBinaryButton.TabIndex = 6;
            this.saveBinaryButton.Text = "Save bin";
            this.saveBinaryButton.UseVisualStyleBackColor = true;
            this.saveBinaryButton.Click += new System.EventHandler(this.saveBinaryButton_Click);
            // 
            // flashSizeComboBox
            // 
            this.flashSizeComboBox.FormattingEnabled = true;
            this.flashSizeComboBox.Location = new System.Drawing.Point(12, 128);
            this.flashSizeComboBox.Name = "flashSizeComboBox";
            this.flashSizeComboBox.Size = new System.Drawing.Size(72, 21);
            this.flashSizeComboBox.TabIndex = 7;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(9, 112);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(53, 13);
            this.label3.TabIndex = 8;
            this.label3.Text = "Flash size";
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(157, 124);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(82, 25);
            this.button1.TabIndex = 9;
            this.button1.Text = "Patch";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // saveHexButton
            // 
            this.saveHexButton.Location = new System.Drawing.Point(245, 156);
            this.saveHexButton.Name = "saveHexButton";
            this.saveHexButton.Size = new System.Drawing.Size(82, 25);
            this.saveHexButton.TabIndex = 10;
            this.saveHexButton.Text = "Save hex";
            this.saveHexButton.UseVisualStyleBackColor = true;
            this.saveHexButton.Click += new System.EventHandler(this.saveHexButton_Click);
            // 
            // Converter
            // 
            this.ClientSize = new System.Drawing.Size(337, 193);
            this.Controls.Add(this.saveHexButton);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.flashSizeComboBox);
            this.Controls.Add(this.saveBinaryButton);
            this.Controls.Add(this.selectOutputFileButton);
            this.Controls.Add(this.selectInputFileButton);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.outputFileBox);
            this.Controls.Add(this.inputFileBox);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Name = "Converter";
            this.Text = "Converter";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private TextBox inputFileBox;
        private TextBox outputFileBox;
        private Label label1;
        private Label label2;
        private Button selectInputFileButton;
        private Button selectOutputFileButton;
        private Button saveBinaryButton;
        private ComboBox flashSizeComboBox;
        private OpenFileDialog openFileDialog1;
        private SaveFileDialog saveFileDialog1;
        private Label label3;
        private Button button1;
        private Button saveHexButton;
    }
}