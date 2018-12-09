using AocLib;
using System;
using System.Collections.Generic;
using System.Linq;

namespace Aoc09
{
  class Program
  {
    static void Main(string[] args)
    {
      Console.WriteLine($"Assignment 1: [{new MarbleGame(471, 72026).Players.Max()}].");
      Console.WriteLine($"Assignment 2: [{new MarbleGame(471, 7202600).Players.Max()}].");
      Console.ReadKey();
    }

    class MarbleGame
    {
      public LinkedList<long> Marbles = new LinkedList<long>();
      public List<long> Players { get; set; }
      public LinkedListNode<long> Current { get; set; }

      public MarbleGame(int players, int marbles)
      {
        Current = Marbles.AddFirst(0);
        Players = new List<long>(new long[players]);

        for (int i = 0; i < marbles; i++)
        {
          Players[i % Players.Count] += AddMarble(i + 1);
        }
      }

      private long AddMarble(long value)
      {
        if (value % 23 == 0)
        {
          Current = Current.PreviousOrLast(6);
          long score = value + Current.PreviousOrLast().Value;
          Marbles.Remove(Current.PreviousOrLast());

          return score;
        }
        else
        {
          Current = Marbles.AddAfter(Current.NextOrFirst(), value);
          return 0;
        }
      }
    }
  }
}
