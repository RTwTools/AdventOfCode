using AocLib;
using System;
using System.Collections.Generic;
using System.Linq;

namespace Aoc07
{
  class Program
  {
    static void Main(string[] args)
    {
      if (Input.Read(args, out string[] input))
      {
        Console.WriteLine($"Assignment 1: [{new Process(input, 1).Result}].");
        Console.WriteLine($"Assignment 2: [{new Process(input, 5).Time}].");
      }
      else
      {
        Console.WriteLine($"Failed to open file.");
      }
      Console.ReadKey();
    }
  }

  class Process
  {
    public List<Instruction> Instructions { get; set; }
    public List<string> Steps { get; set; }
    public string Result { get; set; }
    public List<Step> Workers { get; set; }
    public int Time { get; set; }

    public Process(string[] input, int nrOfWorkers)
    {
      Instructions = input.Select(Instruction.Parse).ToList();
      Steps = Instructions.SelectMany(s => new[] { s.Id, s.Dependency }).Distinct().OrderBy(i => i).ToList();
      Workers = new List<Step>(nrOfWorkers);
      Execute();
    }

    private void Execute()
    {
      while (Steps.Any() || Workers.Any())
      {
        // Remove completed steps.
        Workers.Where(w => w.Time <= Time).OrderBy(w => w.Id).ToList().ForEach(j =>
        {
          Result += j.Id;
          Instructions.RemoveAll(i => i.Dependency == j.Id);
          Workers.Remove(j);
        });

        var availableSteps = Steps.Where(s => !Instructions.Any(d => d.Id == s)).ToList();

        // Assign available steps to workers.
        while(Workers.Count < Workers.Capacity && availableSteps.Any())
        {
          var id = availableSteps.First();
          Workers.Add(new Step(id, Time));
          Steps.Remove(id);
          availableSteps.Remove(id);
        }

        if (Workers.Any()) Time++;
      }
    }
  }

  class Step
  {
    public string Id { get; set; }
    public int Time { get; set; }
    public Step(string id, int currentTime)
    {
      Id = id;
      Time = id[0] - 'A' + 61 + currentTime;
    }
  }

  class Instruction
  {
    public string Id { get; set; }
    public string Dependency { get; set; }

    public static Instruction Parse(string data)
    {
      return new Instruction(data.Split()[7], data.Split()[1]);
    }

    public Instruction(string id, string dependency)
    {
      Id = id;
      Dependency = dependency;
    }
  }
}
