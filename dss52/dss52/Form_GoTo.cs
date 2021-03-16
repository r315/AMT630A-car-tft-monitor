using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace dss52
{
    public partial class Form_GoTo : Form
    {
        public Form_GoTo()
        {
            InitializeComponent();
            this.AcceptButton = buttonOK;
        }

        public DialogResult InputBox(string title, string promptText, ref UInt16 value)
        {
            this.Text = title;
            labelPromptText.Text = promptText;
            textBox.Text = $"{value:X4}";
            
            buttonOK.DialogResult = DialogResult.OK;
            buttonCancel.DialogResult = DialogResult.Cancel;

            labelPromptText.AutoSize = true;
            
            DialogResult dialogResult = DialogResult.Cancel;

            do {
                try {
                    dialogResult = this.ShowDialog();

                    if(dialogResult == DialogResult.Cancel) {
                        return dialogResult;
                    }

                    if (radioButtonHex.Checked) {
                        value = Convert.ToUInt16(textBox.Text, 16);
                    } else {
                        value = Convert.ToUInt16(textBox.Text);
                    }
                                        
                    return dialogResult;

                } catch (FormatException fe){
                    MessageBox.Show($"Invalid address!\n{fe}", "Error");
                }
             } while (true);
        }    
    }
}
