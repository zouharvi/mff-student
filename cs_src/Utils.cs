using System.Collections.Generic;
using System.ComponentModel.Design;
using System.IO;
using System.Net.Http.Headers;

namespace smake
{
    static class Utils
    {
        public static IEnumerable<string> ReadLines(this StreamReader sr)
        {
            var line = sr.ReadLine();
            while (line != null)
            {
                yield return line;
                line = sr.ReadLine();
            }
        }

        public static string RemoveFromEnd(this string s, string suffix)
        {
            if (s.EndsWith(suffix))
            {
                return s.Substring(0, s.Length - suffix.Length);
            }
            else
            {
                return s;
            }
        }

        public static void Add1OrIncrement<T>(this Dictionary<T, int> dict, T key)
            where T : notnull
        {
            if (!dict.ContainsKey(key)) { dict.Add(key, 1); }
            else { dict[key]++; }
        }

    }
}
