using System;
using System.Linq;

namespace Aoc11
{
  class Program
  {
    static void Main(string[] args)
    {
      var fuelGrid = new FuelGrid(3031, 300);
      Console.WriteLine($"Assignment 1: [{fuelGrid.LargestSquareSum(3).Location}].");
      Console.WriteLine($"Assignment 2: [{fuelGrid.LargestSquareSumAnySize().LocationSize}].");
      Console.ReadKey();
    }
  }

  class FuelGrid
  {
    private int[,] SummedArea { get; set; }
    public int SerialNumber { get; set; }
    public int GridSize { get { return SummedArea.GetLength(0); } }

    public FuelGrid(int serialNumber, int gridSize)
    {
      SerialNumber = serialNumber;
      SummedArea = new int[gridSize, gridSize];
      CreateSummedTable();
    }

    public BatterySquare LargestSquareSum(int squareSize)
    {
      var largestSum = new BatterySquare(-1, -1, -1);

      for (int y = 1; y <= (GridSize - squareSize); y++)
      {
        for (int x = 1; x <= (GridSize - squareSize); x++)
        {
          var sum = SumOfSquare(x, y, squareSize);

          if (sum > largestSum.Power)
          {
            largestSum = new BatterySquare(x, y, sum, squareSize);
          }
        }
      }
      return largestSum;
    }

    public BatterySquare LargestSquareSumAnySize()
    {
      var batterySquare = new BatterySquare(-1, -1, -1);

      for (int i = 1; (GridSize - i) >= 0; i++)
      {
        var currentSquare = LargestSquareSum(i);
        if (currentSquare.Power > batterySquare.Power)
        {
          batterySquare = currentSquare;
        }
      }

      return batterySquare;
    }

    public int SumOfSquare(int x, int y, int size)
    {
      var xloc = x - 1;
      var yloc = y - 1;
      if (((xloc + size) > GridSize) ||
         (((yloc + size) > GridSize)))
      { 
        return -1;
      }

      var power = SummedArea[xloc + (size - 1), yloc + (size - 1)];
      var up = (yloc <= 0) ? 0 : SummedArea[xloc + (size - 1), yloc - 1];
      var left = (xloc <= 0) ? 0 : SummedArea[xloc - 1, yloc + (size - 1)];
      var upperleft = (xloc <= 0 || yloc <= 0) ? 0 : SummedArea[xloc - 1,yloc -1];

      return power - up - left + upperleft;
    }

    private void CreateSummedTable()
    {
      for (int y = 0; y < GridSize; y++)
      {
        for (int x = 0; x < GridSize; x++)
        {
          var power = PowerLevel(x + 1, y + 1);

          var up = (y <= 0) ? 0 : SummedArea[x, y - 1];
          var left = (x <= 0) ? 0 : SummedArea[x - 1, y];
          var upperleft = (x <= 0 || y <= 0) ? 0 : SummedArea[x - 1, y - 1];
          var sum = power + up + left - upperleft;
          SummedArea[x, y] = sum;
        }
      }
    }

    private int PowerLevel(int x, int y)
    {
      var rackId = x + 10;
      var powerLevel = ((rackId * y) + SerialNumber) * rackId;
      return (powerLevel >= 100) ? int.Parse((powerLevel / 100).ToString().Last().ToString()) - 5 : -5;
    }
  }

  public class BatterySquare
  {
    public int X { get; set; }
    public int Y { get; set; }
    public int Power { get; set; }
    public int Size { get; set; }
    public string Location { get { return $"{X},{Y}"; } }
    public string LocationSize { get { return $"{Location},{Size}"; } }

    public BatterySquare(int x, int y, int power, int size = -1)
    {
      X = x;
      Y = y;
      Power = power;
      Size = size;
    }
  }
}