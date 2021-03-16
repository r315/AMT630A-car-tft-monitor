using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace dss52
{
    public partial class Converter : Form
    {       
        private bool isBinary = false;

        public Converter()
        {
            InitializeComponent();

            flashSizeComboBox.Items.AddRange(new object[]{"64kB", "128kB", "256kB", "512kB", "1MB"});
            flashSizeComboBox.SelectedIndex = 0;

            openFileDialog1 = new OpenFileDialog() {
                FileName = "Select file",
                Filter = "Intel Hex|*.hex|Binary|*.bin|All|*.*",
                Title = "Open file"
            };

            saveFileDialog1 = new SaveFileDialog() {
                FileName = "Select file",
                Filter = "Binary|*.bin|All|*.*",
                Title = "Save binary file"
            };

            openFileDialog1.FileName = null;
            saveFileDialog1.FileName = null;
        }

        private static void parseHexFile(string filename, byte [] dst)
        {
            string line;
            System.IO.StreamReader file = new System.IO.StreamReader(filename);

            try {
                while ((line = file.ReadLine()) != null) {
                    byte recordlength;
                    UInt16 address;
                    int recordtype;
                    int checksum;

                    if (line[0] != ':') {
                        throw new Exception($"Unexpedted start code: {line[0]}");
                    }

                    recordlength = Convert.ToByte(line.Substring(1, 2), 16);
                    address = Convert.ToUInt16(line.Substring(3, 4), 16);
                    recordtype = Convert.ToByte(line.Substring(7, 2), 16);

                    if (recordtype == 1)
                        break; // we're done
                    if (recordtype != 0)
                        throw new Exception($"unsupported record type");

                    // final checksum = 1 + not(checksum)
                    checksum = recordtype + recordlength + (address & 0xff) + (address >> 8);

                    for (int i = 0; i < recordlength; i++) {
                        byte data = Convert.ToByte(line.Substring(9 + (i * 2), 2), 16);
                        checksum += data;
                        dst[address + i] = data;
                    }

                    checksum &= 0xff;
                    checksum = 256 - checksum;

                    if (Convert.ToByte(line.Substring(9 + (recordlength * 2), 2), 16) != (checksum & 0xff)) {
                        file.Close();
                        throw new Exception("Checksum failure");
                    }
                }
                file.Close();                
            } catch (Exception ex) {
                throw ex;
            }
        }

        private static void createHexFile(string filename, byte [] src)
        {
            byte[] line = new byte[75];  // 1 + 2 + 4 + 2 + n*2 + 2
            const int BYTE_COUNT = 32;
            System.IO.StreamWriter file = null;

            Func<int, byte> htoa = (data) => {
                data = data & 0x0f;
                return (byte)((data > 9) ? '7' + data : '0' + data);
            };

            Func<int, int, string> createLine = (offset, size) => {
                if(size == 0) {
                    return ":00000001FF";                   
                } else {
                    line[0] = 0x3A; // ':'
                    line[1] = htoa(size >> 4);
                    line[2] = htoa(size >> 0);
                    line[3] = htoa(offset >> 12);
                    line[4] = htoa(offset >> 8);
                    line[5] = htoa(offset >> 4);
                    line[6] = htoa(offset >> 0);
                    line[7] = htoa(0);
                    line[8] = htoa(0);

                    int checksum = size + 0 + (offset & 0xff) + (offset >> 8);

                    for (int i = 0; i < size; i++) {
                        int data = src[offset + i];
                        checksum += data;
                        line[9 + (i *2)] = htoa(data >> 4);
                        line[10 + (i * 2)] = htoa(data);
                    }

                    checksum &= 0xff;
                    checksum = 256 - checksum;
                    line[9 + (size * 2)] = htoa(checksum >> 4);
                    line[10 + (size * 2)] = htoa(checksum);                    
                }

            return System.Text.Encoding.Default.GetString(line); // TODO: build string with size : (11 + (size * 2))
            };

            try {

                file = new System.IO.StreamWriter(filename);
                int remaning = src.Length;

                while (remaning > BYTE_COUNT) {
                    file.WriteLine(createLine(src.Length - remaning, BYTE_COUNT));
                    remaning -= BYTE_COUNT;
                }

                if (remaning > 0)
                    file.WriteLine(createLine(remaning, remaning));

                file.WriteLine(createLine(0, 0));
                
            }catch(Exception ex) {
                throw ex;
            } finally {
                file?.Close();
            }
        }

        public static byte [] hex2bin(string filename, int size)
        {
            byte[] code = new byte[size];
            code.SetArray<byte>(0, 0xFF, size);
            parseHexFile(filename, code);
            return code;           
        }

        public static void bin2hex(string filenameBin, string filenameHex)
        {
            byte[] src = File.ReadAllBytes(filenameBin);            
            createHexFile(filenameHex, src);
        }
        //
        // Used to add/remove padding to binary file
        //
        public static byte [] bin2bin(string filename, int size)
        {
            byte[] dst = new byte[size];
            byte[] src = File.ReadAllBytes(filename);

            int count = (dst.Length < src.Length) ? dst.Length : src.Length;

            Array.Copy(src, dst, count);
            
            if (dst.Length - count > 0) {
                dst.SetArray<byte>(count, 0xFF, dst.Length - count);
            }
            
            return dst;
        }

        public static void patchBinary(string filenameBin, string filenameHex)
        {            
            byte[] dst = File.ReadAllBytes(filenameBin);
            parseHexFile(filenameHex, dst);
            File.WriteAllBytes(filenameBin, dst);            
        }

        private void selectInputFileButton_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog() == DialogResult.OK) {
                try {
                    if (Path.GetExtension(openFileDialog1.FileName) == ".hex") {
                        isBinary = false;                        
                    } else {
                        isBinary = true;
                    }
                    inputFileBox.Text = openFileDialog1.FileName;
                } catch (Exception ex) {
                    MessageBox.Show($"openToolStripMenuItem_Click: {ex.Message}\n\n");
                }
            }
        }

        private void selectOutputFileButton_Click(object sender, EventArgs e)
        {
            if (saveFileDialog1.ShowDialog() == DialogResult.OK) {
                try {                   
                    outputFileBox.Text = saveFileDialog1.FileName;                    
                } catch (Exception ex) {
                    MessageBox.Show($"openToolStripMenuItem_Click: {ex.Message}\n\n");
                }
            }
        }

        private void saveBinaryButton_Click(object sender, EventArgs e)
        {
            try {
                int size = (0x10000 << flashSizeComboBox.SelectedIndex);
                byte[] converted = isBinary ? bin2bin(openFileDialog1.FileName, size) : hex2bin(openFileDialog1.FileName, size);
                File.WriteAllBytes(saveFileDialog1.FileName, converted);
            } catch (Exception ex) {
                MessageBox.Show($"Error: {ex.Message}\n\n");
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try {
                patchBinary(saveFileDialog1.FileName, openFileDialog1.FileName);
            } catch (Exception ex) {
                MessageBox.Show($"Error: {ex.Message}\n\n");
            }
        }

        private void saveHexButton_Click(object sender, EventArgs e)
        {
            try {
                bin2hex(openFileDialog1.FileName, saveFileDialog1.FileName);                
            } catch (Exception ex)  {
                MessageBox.Show($"Error: {ex.Message}\n\n");
            }
        }
    }
}
