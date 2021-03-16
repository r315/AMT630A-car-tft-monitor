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
    public partial class terminalForm : Form
    {
        private event Action evt;
        private LinkedList<string> queue; 
        public terminalForm()
        {
            InitializeComponent();
            queue = new LinkedList<string>();
            evt += this.UpdateText;
        }

        private void UpdateText()
        {         
            while(queue.Count > 0) {
                string s = queue.First();
                terminalTextBox.AppendText(s);
                queue.RemoveFirst();
            }
        }

        public void PutChar(char c)
        {
            queue.AddLast(c.ToString());

            if(this.Visible == false) {
                return;
            }

            if (this.InvokeRequired) {
                this.BeginInvoke((MethodInvoker)delegate () {
                    evt?.Invoke();
                });
            } else {
                evt?.Invoke();
            }
        }        

        private void terminalForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (e.CloseReason == CloseReason.UserClosing) {
                e.Cancel = true;
                Hide();
            }
        }

        private void terminalForm_Load(object sender, EventArgs e)
        {
            UpdateText();
        }
    }
}
