using System.Collections.Generic;
using System.Linq;

namespace AocLib
{
  public static class StringUtility
  {
    /// <summary>
    /// Counts how often every char occurs in a word. 
    /// </summary>
    /// <param name="word">Word.</param>
    public static Dictionary<char, int> CountChars(string word)
    {
      var letters = new Dictionary<char, int>();

      foreach (var letter in word)
      {
        if (!letters.ContainsKey(letter))
        {
          letters.Add(letter, 1);
        }
        else
        {
          letters[letter] += 1;
        }
      }
      return letters;
    }

    /// <summary>
    /// Creates a list of all the chars that are equal at the same location in the string.
    /// </summary>
    /// <param name="word1">Word 1.</param>
    /// <param name="word2">Word 2.</param>
    public static List<char> EqualChars(string word1, string word2)
    {
      return word1.Where((@char, index) => @char == word2[index]).ToList();
    }
  }
}
