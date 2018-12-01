using System.IO;

namespace AocLib
{
  public static class Input
  {
    /// <summary>
    /// Default input file.
    /// </summary>
    private static readonly string DefaultFile = "input.txt";

    /// <summary>
    /// Read a file from the disk.
    /// </summary>
    /// <param name="filePath">Filepath of the file to read.</param>
    /// <param name="content">Returned content of the file.</param>
    public static bool Read(string filePath, out string[] content)
    {
      if (File.Exists(filePath))
      {
        content = File.ReadAllLines(filePath);
        return true;
      }

      content = new string[0];
      return false;
    }

    /// <summary>
    /// Read content of input file from arguments.
    /// If not available reads the default file <see cref="DefaultFile"/>.
    /// </summary>
    /// <param name="args">Command line Arguments</param>
    /// <param name="content"></param>
    /// <returns></returns>
    public static bool Read(string[] args, out string[] content)
    {
      string filePath = (args.Length < 1) ? DefaultFile : args[0];
      return Read(filePath, out content);
    }
  }
}
