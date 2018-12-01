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
      Console.ReadKey();
    }

    private static int Assignment1(string[] input)
    {
      return input.Select(int.Parse).Sum();
    }

    private static int Assignment2(string[] input)
    {
      int curFreq = 0;
      var freqs = new HashSet<int>() { curFreq };

      while (true)
      {
        foreach (var freq in input.Select(f => int.Parse(f) + curFreq))
        {
          if (!freqs.Add(freq)) return freq;
          curFreq = freq;
        }
      }
    }
  }
}
