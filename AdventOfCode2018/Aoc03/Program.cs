using AocLib;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;

namespace Aoc03
{
  class Program
  {
    static void Main(string[] args)
    {
      if (Input.ReadTest(args, out string[] input))
      {
        var claims = input.ToList().Select(Claim.Parse).ToList();
        var fabric = MapFabric(claims);
        Console.WriteLine($"Assignment 1: [{Assignment1(fabric)}].");
        Console.WriteLine($"Assignment 2: [{Assignment2(claims, fabric)}].");
      }
      else
      {
        Console.WriteLine($"Failed to open file.");
      }
      Console.ReadKey();
    }

    private static int Assignment1(Dictionary<(int, int), HashSet<int>> fabric)
    {
      return fabric.Count(f => f.Value.Count > 1);
    }

    private static int Assignment2(List<Claim> claims, Dictionary<(int, int), HashSet<int>> fabric)
    {
      var duplicates = fabric.Where(f => f.Value.Count > 1).SelectMany(f => f.Value).Distinct();
      return claims.First(c => !duplicates.Contains(c.Id)).Id;
    }

    private static Dictionary<(int, int), HashSet<int>> MapFabric(List<Claim> claims)
    {
      var fabric = new Dictionary<(int, int), HashSet<int>>();

      foreach (var claim in claims)
      {
        for (int x = claim.Location.X; x < (claim.Location.X + claim.Size.X); x++)
        {
          for (int y = claim.Location.Y; y < (claim.Location.Y + claim.Size.Y); y++)
          {
            if (!fabric.ContainsKey((x, y)))
            {
              fabric.Add((x, y), new HashSet<int>());
            }
            fabric[(x, y)].Add(claim.Id);
          }
        }
      }
      return fabric;
    }
  }

  class Claim
  {
    public int Id { get; set; }
    public Point Location { get; set; }
    public Point Size { get; set; }

    public static Claim Parse(string data)
    {
      var values = data.Split(new[] { '#', '@', ',', ':', 'x', ' ' },
        StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToList();

      return new Claim()
      {
        Id = values[0],
        Location = new Point(values[1], values[2]),
        Size = new Point(values[3], values[4])
      };
    }
  }
}
