using AocLib;
using System;
using System.Collections.Generic;
using System.Linq;

namespace Aoc04
{
  class Program
  {
    static void Main(string[] args)
    {
      if (Input.Read(args, out string[] input))
      {
        var logbook = input.ToList().Select(Log.Parse).OrderBy(l => l.DateTime);
        var guardLog = GenerateGuardLog(logbook);
        Console.WriteLine($"Assignment 1: [{Assignment1(guardLog)}].");
        Console.WriteLine($"Assignment 2: [{Assignment2(guardLog)}].");
      }
      else
      {
        Console.WriteLine($"Failed to open file.");
      }
      Console.ReadKey();
    }

    private static int Assignment1(Dictionary<int, Dictionary<int, int>> guardLog)
    {
      var sleepGuard = guardLog.Aggregate((l, r) => l.Value.Values.Sum() > r.Value.Values.Sum() ? l : r);
      var sleepMinute = sleepGuard.Value.Aggregate((l, r) => l.Value > r.Value ? l : r).Key;

      return sleepGuard.Key * sleepMinute;
    }

    private static int Assignment2(Dictionary<int, Dictionary<int, int>> guardLog)
    {
      var freqGuard = guardLog.Where(g => g.Value.Values.Count > 0).Aggregate((l, r) => l.Value.Values.Max() > r.Value.Values.Max() ? l : r);
      var freqMinute = freqGuard.Value.Aggregate((l, r) => l.Value > r.Value ? l : r).Key;

      return freqGuard.Key * freqMinute;
    }

    private static Dictionary<int, Dictionary<int, int>> GenerateGuardLog(IEnumerable<Log> logbook)
    {
      var guardLog = new Dictionary<int, Dictionary<int, int>>();
      int currentGuard = 0;
      int sleepStart = 0;

      foreach (var log in logbook)
      {
        switch (log.Event)
        {
          case EventType.StartShift:
            currentGuard = log.GuardId;
            if (guardLog.ContainsKey(currentGuard) == false)
            {
              guardLog.Add(currentGuard, new Dictionary<int, int>());
            }
            break;
          case EventType.FallAsleep:
            sleepStart = log.DateTime.Minute;
            break;
          case EventType.WakeUp:
            for (int minute = sleepStart; minute < log.DateTime.Minute; minute++)
            {
              if (!guardLog[currentGuard].ContainsKey(minute))
              {
                guardLog[currentGuard].Add(minute, 0);
              }
              guardLog[currentGuard][minute]++;
            }
            break;
        }
      }

      return guardLog;
    }
  }

  public enum EventType
  {
    StartShift,
    FallAsleep,
    WakeUp
  };

  public class Log
  {
    public DateTime DateTime { get; set; }
    public EventType Event { get; set; }
    public int GuardId { get; set; }

    public static Log Parse(string data)
    {
      return new Log()
      {
        DateTime = GetDateTime(data),
        Event = GetEventType(data),
        GuardId = GetGuardId(data)
      };
    }

    private static EventType GetEventType(string data)
    {
      if (data.Contains("wakes")) return EventType.WakeUp;
      if (data.Contains("falls")) return EventType.FallAsleep;
      if (data.Contains("shift")) return EventType.StartShift;

      throw new Exception($"Invalid event, data: [{data}]!");
    }

    private static int GetGuardId(string data)
    {
      if (!data.Contains("shift")) return -1;

      var parts = data.Split(new[] { ' ', '#' }, StringSplitOptions.RemoveEmptyEntries);
      return int.Parse(parts[3]);
    }

    private static DateTime GetDateTime(string data)
    {
      var dateTime = data.Substring(1, data.IndexOf(']') - 1);
      return DateTime.Parse(dateTime);
    }
  }
}
