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
      return ShrinkPolymer(input);
    }

    private static int Assignment2(string input)
    {
      Dictionary<char, int> combinations = new Dictionary<char, int>();
      for (char i = 'a'; i <= 'z'; i++)
      {
        combinations.Add(i, ShrinkPolymer(input.Replace(i.ToString(), "").Replace(char.ToUpper(i).ToString(), "")));
      }

      return combinations.Values.Min();
    }

    private static int ShrinkPolymer(string input)
    {
      string output = input;
      string polymer;
      do
      {
        polymer = output;
        output = TriggerPolarities(polymer);
      }
      while (output.Length != polymer.Length);

      return output.Length;
    }

    private static string TriggerPolarities(string input)
    {
      string polymer = input;

      for (int i = 0; i < polymer.Length - 1; i++)
      {
        if (ToggleCase(polymer[i]) == polymer[i + 1])
        {
          polymer = polymer.Remove(i, 2);
        }
      }

      return polymer;
    }

    private static char ToggleCase(char @char)
    {
      return (char.IsUpper(@char)) ? char.ToLower(@char) : char.ToUpper(@char);
    }
  }
}
