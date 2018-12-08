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
        var node = Node.Parse(input[0].Split(' ').Select(int.Parse).ToList());
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
    private static readonly int HeaderSize = 2;
    public List<Node> Childeren { get; set; }
    public List<int> Metadata { get; set; }
    public int SizeOf { get { return SizeOfChilderen + HeaderSize + Metadata.Count; } }
    public int SizeOfChilderen { get { return Childeren.Sum(c => c.SizeOf); } }
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

    public Node()
    {
      Childeren = new List<Node>();
      Metadata = new List<int>();
    }

    public static Node Parse(List<int> values)
    {
      int childerenCount = values[0];
      int metadataCount = values[1];
      var node = new Node();

      for (int i = 0; i < childerenCount; i++)
      {
        node.Childeren.Add(Parse(values.Skip(node.SizeOf).ToList()));
      }

      node.Metadata.AddRange(values.GetRange(node.SizeOf, metadataCount));

      return node;
    }
  }
}
