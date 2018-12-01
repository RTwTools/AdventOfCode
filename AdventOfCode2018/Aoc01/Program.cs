using AocLib;
using System;
using System.Collections.Generic;
using System.Linq;

namespace Aoc01
{
  class Program
  {
    static void Main(string[] args)
    {
      if (Input.Read(args, out string[] input))
      {
        Console.WriteLine($"Assignment 1: [{Assignment1(input)}].");
        Console.WriteLine($"Assignment 2: [{Assignment2(input)}].");
      }
      else
      {
        Console.WriteLine($"Failed to open file.");
      }
      Console.ReadLine();
    }

    private static int Assignment1(string[] input)
    {
      int freq = 0;
      input.ToList().ForEach(f => freq += int.Parse(f));
      return freq;
    }

    private static int Assignment2(string[] input)
    {
      int freq = 0;
      var freqs = new List<int>() { freq };

      while (true)
      {
        foreach (var line in input)
        {
          freq += int.Parse(line);
          if (freqs.Contains(freq))
          {
            return freq;
          }
          freqs.Add(freq);
        }
      }
    }
  }
}
