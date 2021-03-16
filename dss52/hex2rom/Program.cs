using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace hex2rom
{
    public static class Extensions
    {
        public static T[] SubArray<T>(this T[] array, int offset, int length)
        {
            T[] result = new T[length];
            Array.Copy(array, offset, result, 0, length);
            return result;
        }

        public static void SetArray<T>(this T[] array, Int32 offset, T value, Int32 count)
        {
            for (int i = offset; i < offset + count; i++) {
                array[i] = value;
            }
        }
    }

    class Program
    {
        private static bool parseHexFile(string inputfile, byte[] dst)
        {
            try {
                string line;
                System.IO.StreamReader file = new System.IO.StreamReader(inputfile);

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
                        return true; // we're done
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
            } catch (FileNotFoundException fnf) {
                Console.WriteLine($"Unable to open file: {inputfile}");
            } catch (Exception ex ) {
                Console.WriteLine($"Error: {ex.Message}");                
            }

            return false;
        }

        static void Main(string[] args)
        {
            if(args.Length < 2) {
                string codebase = Assembly.GetExecutingAssembly().CodeBase;
                Console.WriteLine($"Usage: {Path.GetFileName(codebase)} <inputfile.hex> <outputfile> [romsize]");
                Console.WriteLine($"\tromsize\t default 0x10000");
                return;
            }

            string inputfile = args[0];
            string outputfile = args[1];

            int size = 0x10000;

            if(args.Length > 2) {
                try {
                    size = Convert.ToInt32(args[2], 16);
                }catch(Exception ex) {
                    Console.WriteLine($"Invalid romsize : {args[2]}");
                }
            }

            byte[] rom = new byte[size];
            rom.SetArray<byte>(0, 0xFF, size);

            if(parseHexFile(inputfile, rom)) {
                try {
                    File.WriteAllBytes(outputfile, rom);
                }catch(Exception ex) {
                    Console.WriteLine(ex.Message);
                }
            }
        }
    }
}
