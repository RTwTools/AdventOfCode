using AocLib;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;

namespace Aoc13
{
  class Program
  {
    static void Main(string[] args)
    {
      if (Input.Read(args, out string[] input))
      {
        Console.WriteLine($"Assignment 1: [{Assignment1(input)}].");
        Console.WriteLine($"Assignment 2: [{Assignment2(input)}].");
      }
      else
      {
        Console.WriteLine($"Failed to open file.");
      }
      Console.ReadKey();
    }

    private static string Assignment1(string[] input)
    {
      var track = new Track(input);
      Point location;
      while (!track.Tick(true, out location)) {}
      return $"{location.X},{location.Y}";
    }

    private static string Assignment2(string[] input)
    {
      var track = new Track(input);
      Point location;
      while (!track.Tick(false, out location)) { }
      return $"{location.X},{location.Y}";
    }

    class Track
    {
      public List<Cart> Carts { get; set; } = new List<Cart>();
      public char[][] Road { get; set; }

      public Track(string[] input)
      {
        Road = new char[input.Length][];
        for (int y = 0; y < input.Length; y++)
        {
          Road[y] = input[y].ToArray();
          Carts.AddRange(GetCarts(y));
        }
      }

      public bool Tick(bool partA, out Point location)
      {
        foreach (var cart in Carts.OrderBy(c => c.Y).ThenBy(c => c.X))
        {
          cart.Move(Road);
          if (Crash(cart))
          {
            if (partA)
            {
              location = new Point(cart.X, cart.Y);
              return true;
            }
            else
            {
              Carts.RemoveAll(c => c.X == cart.X && c.Y == cart.Y);
            }
          }
        }

        location = (partA || Carts.Count > 1)
          ? new Point(-1, -1)
          : new Point(Carts.First().X, Carts.First().Y);
        return !(partA || Carts.Count > 1);
      }

      public bool Crash(Cart cart)
      {
        return (Carts.Count(c => c.X == cart.X && c.Y == cart.Y) >= 2);
      }

      private List<Cart> GetCarts(int y)
      {
        var carts = new List<Cart>();

        while(true)
        {
          var road = new string(Road[y]);
          var x = road.IndexOfAny(new[] { 'v', '<', '>', '^' });
          if (x == -1) break;
          carts.Add(new Cart(x, y, road[x]));
          Road[y][x] = (road[x] == 'v' || road[x] == '^') ? '|' : '-';
        }

        return carts;
      }
    }
  }

  class Cart
  {
    public int X { get; set; }
    public int Y { get; set; }
    public Direction Direction { get; set; }
    public InterSectionAction InterSectionAction { get; set; }

    public Cart(int x, int y, char direction)
    {
      X = x;
      Y = y;
      Direction = ParseDirection(direction);
      InterSectionAction = InterSectionAction.Left;
    }

    public void Move(char[][] road)
    {
      NewLocation();

      char location = road[Y][X];
      if (location == '+')
      {
        Intersection();
      }
      else if(location == '\\' || location == '/')
      {
        Curve(location);
      }
    }

    private void Curve(char turn)
    {
      switch (turn)
      {
        case '\\':
          Direction = (Direction == Direction.Right || Direction == Direction.Left)
            ? (Direction == Direction.Left) ? Direction.Up : Direction.Down
            : (Direction == Direction.Up) ? Direction.Left : Direction.Right;
          break;
        case '/':
          Direction = (Direction == Direction.Right || Direction == Direction.Left)
            ? (Direction == Direction.Right) ? Direction.Up : Direction.Down
            : (Direction == Direction.Down) ? Direction.Left : Direction.Right;
          break;
        default:
          break;
      }
    }

    private void Intersection()
    {
      switch (InterSectionAction)
      {
        case InterSectionAction.Left:
          Direction = (Direction == Direction.Right || Direction == Direction.Left)
            ? (Direction == Direction.Right) ? Direction.Up : Direction.Down
            : (Direction == Direction.Up) ? Direction.Left : Direction.Right;
          break;
        case InterSectionAction.Right:
          Direction = (Direction == Direction.Right || Direction == Direction.Left)
            ? (Direction == Direction.Left) ? Direction.Up : Direction.Down
            : (Direction == Direction.Down) ? Direction.Left : Direction.Right;
          break;
        default:
          break;
      }

      InterSectionAction = (InterSectionAction)
        (((int)InterSectionAction + 1) % (int)InterSectionAction.Count);
    }

    public void NewLocation()
    {
      switch (Direction)
      {
        case Direction.Up: Y -= 1; break;
        case Direction.Down: Y += 1; break;
        case Direction.Left: X -= 1; break;
        case Direction.Right: X += 1; break;
        default: break;
      }      
    }

    public Direction ParseDirection(char direction)
    {
      switch (direction)
      {
        case '^': return Direction.Up;
        case '>': return Direction.Right;
        case 'v': return Direction.Down;
        case '<': return Direction.Left;
        default:
          throw new Exception($"Invalid direction token {direction}.");
      }
    }
  }

  enum Direction
  {
    Up,
    Right,
    Down,
    Left
  }

  enum InterSectionAction
  {
    Left,
    Straight,
    Right,
    Count
  }
}
