using System.Collections.Generic;

namespace AocLib
{
  public static class CircularLinkedList
  {
    public static LinkedListNode<T> PreviousOrLast<T>(this LinkedListNode<T> current)
    {
      return current.Previous ?? current.List.Last;
    }

    public static LinkedListNode<T> NextOrFirst<T>(this LinkedListNode<T> current)
    {
      return current.Next ?? current.List.First;
    }

    public static LinkedListNode<T> PreviousOrLast<T>(this LinkedListNode<T> current, int number)
    {
      for (int i = 0; i < number; i++)
      {
        current = current.PreviousOrLast();
      }
      return current;
    }

    public static LinkedListNode<T> NextOrFirst<T>(this LinkedListNode<T> current, int number)
    {
      for (int i = 0; i < number; i++)
      {
        current = current.NextOrFirst();
      }
      return current;
    }
  }
}
