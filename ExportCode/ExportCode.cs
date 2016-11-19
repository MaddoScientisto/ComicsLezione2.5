using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;

namespace ExportCode
{

    public class ExportCode
    {
        public readonly string DestinationPath = "export";

        public void Program(string[] args)
        {
#if DEBUG
            args = new[] {".."};
#endif
            var a = GetWorkingFolder(args);
            if (string.IsNullOrWhiteSpace(a))
            {
                Console.WriteLine("Stringa vuota o non valida");
                return;
            }
            DirectoryInfo i = new DirectoryInfo(a);
            Console.WriteLine(i.FullName);

            List<FileInfo> files = GetFilesList(i);

            Directory.CreateDirectory(DestinationPath);
            foreach (var file in files)
            {
                string destFile = Path.Combine(DestinationPath, file.Name);
                file.CopyTo(Path.Combine(DestinationPath, file.Name), true);
                Console.WriteLine($"{file.FullName} -> {destFile}");
                //if (!File.Exists(destFile))
                //{
                //    file.CopyTo(Path.Combine(DestinationPath, file.Name), true);
                //    Console.WriteLine($"{file.FullName} -> {destFile}");
                //}
                //else
                //{
                //    Console.WriteLine($"File already exists: {destFile}");
                //}
            }
        }

        private string GetWorkingFolder(string[] args)
        {
            if (args.Any())
            {

                string p = Path.Combine(GetApplicationDirectory());
                if (Directory.Exists(p))
                {

                    return p;
                }
                else
                {
                    return string.Empty;
                }
            }
            else
            {
                Console.WriteLine("Non è stata selezionata una cartella");
            }
            return string.Empty;
        }

        List<FileInfo> GetFilesList(DirectoryInfo directory)
        {
            var f = directory.EnumerateFiles("*", SearchOption.AllDirectories).Where(x => x.Extension == ".cpp" || x.Extension == ".h").ToList();

            return f;
        }

        private string GetApplicationDirectory()
        {
            return Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location);
        }
    }
}
