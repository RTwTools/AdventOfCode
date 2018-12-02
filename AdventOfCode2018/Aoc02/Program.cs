using AocLib;
using System;
using System.Collections.Generic;
using System.Linq;

namespace Aoc02
{
  class Program
  {
    static void Main(string[] args)
    {
      if (Input.Read(args, out string[] input))
      {
        Console.WriteLine($"Assignment 1: [{Assignment1(input, out List<string> boxIds)}].");
        Console.WriteLine($"Assignment 2: [{Assignment2(boxIds)}].");
      }
      else
      {
        Console.WriteLine($"Failed to open file.");
      }
      Console.ReadKey();
    }

    private static int Assignment1(string[] input, out List<string> boxIds)
    {
      var words = new List<Dictionary<char, int>>();
      var ids = new HashSet<string>();

      input.ToList().ForEach(boxId => 
      {
        words.Add(StringUtility.CountChars(boxId));
        if (words.Last().Values.Max() > 1) ids.Add(boxId);
      });
      boxIds = ids.ToList();

      var twoCount = words.Where(w => w.ContainsValue(2)).Count();
      var threeCount = words.Where(w => w.ContainsValue(3)).Count();
      
      return twoCount * threeCount;
    }

    private static string Assignment2(List<string> boxIds)
    {
      var commonLetters = new List<char>();

      boxIds.ForEach(id1 =>
      {
        boxIds.ForEach(id2 =>
        {
          if (id1 == id2) return;
          var letters = StringUtility.EqualChars(id1, id2);
          if (letters.Count > commonLetters.Count) commonLetters = letters;
        });
      });

      return new string(commonLetters.ToArray());
    }
  }
}
