using AocLib;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Aoc12
{
  class Program
  {
    static void Main(string[] args)
    {
      if (Input.Read(args, out string[] input))
      {
        Console.WriteLine($"Assignment 1: [{new Garden(input).Wait(20)}].");
        Console.WriteLine($"Assignment 2: [{new Garden(input).Wait(50000000000)}].");
      }
      else
      {
        Console.WriteLine($"Failed to open file.");
      }
      Console.ReadKey();
    }
  }

  class Garden
  {
    public StringBuilder Pots { get; set; }
    public IEnumerable<string> Manipulations { get; set; }
    public int StartIndex { get; set; } = 0;

    public Garden(string[] input)
    {
      Pots = new StringBuilder(input[0].Split(' ')[2]);
      Manipulations = input.Skip(2).Where(i => i.Last() == '#').Select(i => i.Split(' ')[0]);
    }

    public long Wait(long years)
    {
      string prevPots = string.Empty;
      long prevCountOfPlants = 0;

      for (long year = 0; year < years; year++)
      {
        FillFront();
        FillEnd();

        var currentPots = Pots.ToString();

        if (prevPots == currentPots)
        {
          var diff = CountOfPlants() - prevCountOfPlants;
          return CountOfPlants() + (diff * (years - year));
        }

        prevPots = currentPots;
        prevCountOfPlants = CountOfPlants();

        for (int i = 0; i < currentPots.Length - 4; i++)
        {
          Pots[i + 2] = (Manipulations.Contains(currentPots.Substring(i, 5)))
            ? '#'
            : '.';
        }
      }

      return CountOfPlants();
    }

    private long CountOfPlants()
    {
      long count = 0;
      for (int i = 0; i < Pots.Length; i++)
      {
        if (Pots[i] == '#')
        {
          count += (i + StartIndex);
        }
      }
      return count;
    }

    private void FillFront()
    {
      var index = 3 - Pots.ToString().IndexOf('#');

      if (index > 0)
      {
        for (int i = 0; i < index; i++)
        {
          Pots.Insert(0, ".");
          StartIndex -= 1;
        }
      }
      else
      {
        Pots.Remove(0, Math.Abs(index));
        StartIndex += Math.Abs(index);
      }
    }

    private void FillEnd()
    {
      var index = ((Pots.Length - 1) - Pots.ToString().LastIndexOf('#')) - 3;

      if (index > 0)
      {
        Pots.Remove(Pots.Length - 1 - index, index);
      }
      else
      {
        for (int i = 0; i > index; i--)
        {
          Pots.Insert(Pots.Length, ".");
        }
      }
    }
  }
}
