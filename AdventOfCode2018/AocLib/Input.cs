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
    /// Default test input file.
    /// </summary>
    private static readonly string DefaultTestFile = "test1.txt";

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
    /// Read content of input file (Filepath passed by arguments).
    /// FileNotFound? => read the default file <see cref="DefaultFile"/>.
    /// </summary>
    /// <param name="args">Command line Arguments.</param>
    /// <param name="content">Content of file.</param>
    public static bool Read(string[] args, out string[] content)
    {
      string filePath = (args.Length < 1) ? DefaultFile : args[0];
      return Read(filePath, out content);
    }

    /// <summary>
    /// Read content of input file (Filepath passed by arguments).
    /// FileNotFound? => read the default file <see cref="DefaultTestFile"/>.
    /// </summary>
    /// <param name="args">Command line Arguments.</param>
    /// <param name="content">Content of file.</param>
    public static bool ReadTest(string[] args, out string[] content)
    {
      string filePath = (args.Length < 1) ? DefaultTestFile : args[0];
      return Read(filePath, out content);
    }
  }
}
