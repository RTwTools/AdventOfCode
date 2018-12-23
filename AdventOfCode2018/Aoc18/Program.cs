using AocLib;
using System;
using System.Collections.Generic;
using System.Linq;

namespace Aoc18
{
  class Program
  {
    private static readonly int skipCount = 1000;

    static void Main(string[] args)
    {
      if (Input.Read(args, out string[] input))
      {
        Console.WriteLine($"Assignment 1: [{Assignment1(input, 10)}].");
        Console.WriteLine($"Assignment 2: [{Assignment2(input, 1000000000)}].");
      }
      else
      {
        Console.WriteLine($"Failed to open file.");
      }
      Console.ReadKey();
    }

    private static int Assignment1(string[] input, int minutes)
    {
      var wood = Wood.TryParse(input);
      wood.Wait(minutes);
      return wood.Value();
    }

    private static int Assignment2(string[] input, int minutes)
    {
      var wood = Wood.TryParse(input);
      wood.Wait(skipCount);

      var values = new List<int>();
      while (!values.Contains(wood.Value()))
      {
        values.Add(wood.Value());
        wood.Wait();
      }

      return values[(minutes - skipCount) % values.Count];
    }

    class Wood
    {
      public Acre[,] Acres { get; set; }

      public Wood(int size)
      {
        Acres = new Acre[size, size];
      }

      public void Wait()
      {
        var newAcres = (Acre[,])Acres.Clone();

        for (int y = 0; y < Acres.GetLength(1); y++)
        {
          for (int x = 0; x < Acres.GetLength(0); x++)
          {
            var adjacents = Adjacents(x, y);

            switch (Acres[x, y])
            {
              case Acre.Open:
                if (adjacents.Count(a => a == Acre.Trees) >= 3) { newAcres[x, y] = Acre.Trees; }
                break;
              case Acre.Trees:
                if (adjacents.Count(a => a == Acre.Lumberyard) >= 3) { newAcres[x, y] = Acre.Lumberyard; }
                break;
              case Acre.Lumberyard:
                if (!(adjacents.Any(a => a == Acre.Lumberyard) && adjacents.Any(a => a == Acre.Trees)))
                {
                  newAcres[x, y] = Acre.Open;
                }
                break;
              default:
                break;
            }
          }
        }

        Acres = newAcres;
      }

      public void Wait(int minutes)
      {
        for (int i = 0; i < minutes; i++)
        {
          Wait();
        }
      }

      public int Value()
      {
        var acres = ToList();
        var countLumberyard = acres.Count(a => a == Acre.Lumberyard);
        var countTrees = acres.Count(a => a == Acre.Trees);

        return countLumberyard * countTrees;
      }

      public List<Acre> ToList()
      {
        var list = new List<Acre>();

        for (int y = 0; y < Acres.GetLength(1); y++)
        {
          for (int x = 0; x < Acres.GetLength(0); x++)
          {
            list.Add(Acres[x, y]);
          }
        }

        return list;
      }

      public List<Acre> Adjacents(int x, int y)
      {
        var adjacents = new List<Acre>();

        var top = (y - 1) >= 0;
        var right = (x + 1) < Acres.GetLength(0);
        var bottom = (y + 1) < Acres.GetLength(1);
        var left = (x - 1) >= 0;

        if (top && left) adjacents.Add(Acres[x - 1, y - 1]);
        if (left) adjacents.Add(Acres[x - 1, y + 0]);
        if (left && bottom) adjacents.Add(Acres[x - 1, y + 1]);
        if (bottom) adjacents.Add(Acres[x, y + 1]);
        if (bottom && right) adjacents.Add(Acres[x + 1, y + 1]);
        if (right) adjacents.Add(Acres[x + 1, y + 0]);
        if (right && top) adjacents.Add(Acres[x + 1, y - 1]);
        if (top) adjacents.Add(Acres[x + 0, y - 1]);

        return adjacents;
      }

      public static Wood TryParse(string[] input)
      {
        var collection = new Wood(input.Length);

        for (int y = 0; y < input.Length; y++)
        {
          for (int x = 0; x < input[y].Length; x++)
          {
            collection.Acres[x, y] = ParseAcre(input[y][x]);
          }
        }

        return collection;
      }

      private static Acre ParseAcre(char @char)
      {
        switch (@char)
        {
          case '.': return Acre.Open;
          case '|': return Acre.Trees;
          case '#': return Acre.Lumberyard;
          default: throw new Exception($"Invalid char: {@char}!");
        }
      }

    }

    enum Acre
    {
      Open,
      Trees,
      Lumberyard
    }
  }
}
