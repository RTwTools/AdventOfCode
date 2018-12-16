using AocLib;
using System;
using System.Collections.Generic;
using System.Linq;

namespace Aoc14
{
  class Program
  {
    static void Main(string[] args)
    {
      if (Input.Read(args, out string[] input))
      {
        Console.WriteLine($"Assignment 1: [{new Recipes().GetScore(int.Parse(input[0]))}].");
        int[] recipes = input[0].ToList().Select(i => int.Parse(i.ToString())).ToArray();
        Console.WriteLine($"Assignment 2: [{new Recipes().FindRecipes(recipes)}].");
      }
      else
      {
        Console.WriteLine($"Failed to open file.");
      }
      Console.ReadKey();
    }

    public class Recipes
    {
      private static readonly int ScoreCount = 10;
      public List<int> List { get; set; } = new List<int>() { 3, 7 };
      public List<int> Elves { get; set; } = new List<int>() { 0, 1 };

      public void Create()
      {
        var sum = List[Elves[0]] + List[Elves[1]];
        if (sum > 9) List.Add(1);
        List.Add(sum % 10);

        for (int i = 0; i < Elves.Count; i++)
        {
          Elves[i] = (Elves[i] + List[Elves[i]] + 1) % List.Count;
        }
      }

      public int GetScore(int count)
      {
        while (List.Count < (count + ScoreCount)) Create();
        return int.Parse(string.Join("", List.GetRange(count, ScoreCount).Select(r => r.ToString())));
      }

      public int FindRecipes(int[] recipes)
      {
        int index = 0;

        while (true)
        {
          Create();

          while ((index + recipes.Length < List.Count))
          {
            for (int i = 0; i < recipes.Length; i++)
            {
              if (recipes[i] != List[index+i]) break;
              if (i == recipes.Length - 1) return index;
            }
            index++;
          }
        }
      }
    }
  }
}
