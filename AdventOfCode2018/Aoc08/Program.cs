using AocLib;
using System;
using System.Collections.Generic;
using System.Linq;

namespace Aoc08
{
  class Program
  {
    static void Main(string[] args)
    {
      if (Input.Read(args, out string[] input))
      {
        var node = Node.Parse(new Queue<int>(input[0].Split(' ').Select(int.Parse)));
        Console.WriteLine($"Assignment 1: [{node.MetaDataSum}].");
        Console.WriteLine($"Assignment 2: [{node.Value}].");
      }
      else
      {
        Console.WriteLine($"Failed to open file.");
      }
      Console.ReadKey();
    }
  }

  class Node
  {
    public List<Node> Childeren { get; set; } = new List<Node>();
    public List<int> Metadata { get; set; } = new List<int>();
    public int MetaDataSum { get { return Childeren.Sum(c => c.MetaDataSum) + Metadata.Sum(); } }
    public int Value
    {
      get
      {
        return (Childeren.Any())
          ? Metadata.Where(m => m <= Childeren.Count).Sum(m => Childeren[m - 1].Value)
          : MetaDataSum;
      }
    }

    public static Node Parse(Queue<int> values)
    {
      int childerenCount = values.Dequeue();
      int metadataCount = values.Dequeue();
      var node = new Node();

      for (int i = 0; i < childerenCount; i++)
      {
        node.Childeren.Add(Parse(values));
      }

      for (int i = 0; i < metadataCount; i++)
      {
        node.Metadata.Add(values.Dequeue());
      }

      return node;
    }
  }
}
