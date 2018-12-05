using AocLib;
using System;
using System.Collections.Generic;
using System.Linq;

namespace Aoc05
{
  class Program
  {
    static void Main(string[] args)
    {
      if (Input.Read(args, out string[] input))
      {
        Console.WriteLine($"Assignment 1: [{Assignment1(input[0])}].");
        Console.WriteLine($"Assignment 2: [{Assignment2(input[0])}].");
      }
      else
      {
        Console.WriteLine($"Failed to open file.");
      }
      Console.ReadKey();
    }

    private static int Assignment1(string input)
    {
      return TriggerPolarities(input);
    }

    private static int Assignment2(string input)
    {
      var lengths = new HashSet<int>();
      var usedChars = input.Select(c => c.ToString().ToLower()).Distinct();

      foreach (var @char in usedChars)
      {
        var polymer = input.Replace(@char, "", StringComparison.OrdinalIgnoreCase);
        lengths.Add(TriggerPolarities(polymer));
      }

      return lengths.Min();
    }

    private static int TriggerPolarities(string input)
    {
      var polymer = new Stack<char>();

      foreach (var @char in input)
      {
        if (polymer.Any() && ToggleCase(polymer.Peek()) == @char)
        { 
          polymer.Pop();
        }
        else
        {
          polymer.Push(@char);
        }
      }

      return polymer.Count;
    }

    private static char ToggleCase(char @char)
    {
      return (char.IsUpper(@char)) ? char.ToLower(@char) : char.ToUpper(@char);
    }
  }
}
