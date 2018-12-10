using AocLib;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;

namespace Aoc10
{
  class Program
  {
    static void Main(string[] args)
    {
      if (Input.Read(args, out string[] input))
      {
        var rescueOperation = new RescueOperation(input);
        Console.WriteLine($"Assignment 1: \n{rescueOperation.Wait()}");
        Console.WriteLine($"Assignment 2: [{rescueOperation.Time}].");
      }
      else
      {
        Console.WriteLine($"Failed to open file.");
      }
      Console.ReadKey();
    }

    class RescueOperation
    {
      public List<Star> Stars { get; set; }
      public int Time { get; set; }

      public RescueOperation(string[] input)
      {
        Stars = input.Select(Star.Parse).ToList();
      }

      public string Wait()
      {
        while (Stars.Max(s => s.Location.Y) - Stars.Min(s => s.Location.Y) > 10)
        {
          Stars.ForEach(s => s.Move());
          Time++;
        }

        return Print();
      }

      private string Print()
      {
        var data = "";
        var minX = Stars.Min(s => s.Location.X);
        var maxX = Stars.Max(s => s.Location.X);
        var minY = Stars.Min(s => s.Location.Y);
        var maxY = Stars.Max(s => s.Location.Y);

        for (int y = minY; y <= maxY; y++)
        {
          for (int x = minX; x <= maxX; x++)
          {
            bool empty = !Stars.Any(s => s.Location.X == x && s.Location.Y == y);
            data += (empty) ? '.' : '#';
          }
          data += Environment.NewLine;
        }

        return data;
      }
    }

    class Star
    {
      public Point Location { get; set; }
      public Point Velocity { get; set; }

      public void Move()
      {
        Location = new Point(Location.X + Velocity.X, Location.Y + Velocity.Y);
      }

      public static Star Parse(string input)
      {
        var parts = input.Split(new[] { ' ', ',', '<', '>' }, StringSplitOptions.RemoveEmptyEntries);
        return new Star()
        {
          Location = new Point(int.Parse(parts[1]), int.Parse(parts[2])),
          Velocity = new Point(int.Parse(parts[4]), int.Parse(parts[5]))
        };
      }
    }
  }
}
