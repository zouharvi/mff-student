using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

namespace smake
{
    static class DataUtils
    {
        public static IEnumerable<IEnumerable<string>> CreateCandidates(IEnumerable<string> words, HashSet<string> sws)
        {
            var buffer = new List<string>();
            var candidates = new List<List<string>>();

            foreach (var word in words)
            {
                if (sws.Contains(word.ToLower()))
                {
                    if (buffer.Count > 0)
                    {
                        if (!WordHeuristics(buffer)) 
                        { candidates.Add(buffer); }
                        buffer = new List<string>(); 
                    }
                }
                else if (Regex.Match(word, @"\p{Lu}.+").Success)
                {
                    if (buffer.Count > 0)
                    {
                        if (!WordHeuristics(buffer)) 
                        { candidates.Add(buffer); }
                        buffer = new List<string>();
                    }
                    buffer.Add(word.ToLower());
                }
                else
                {
                    buffer.Add(word.ToLower());
                }
            }
            return candidates;
        }

        private static bool WordHeuristics(List<string> buffer)
        {
            return Regex.Match(buffer[^1], @".*ed").Success || buffer[0].Length <= 3;
        }

        public static (Dictionary<string, int>, Dictionary<string, int>) ComputeFrqDeg(IEnumerable<IEnumerable<string>> candidates)
        {
            var frqMap = new Dictionary<string, int>();
            var degMap = new Dictionary<string, HashSet<string>>();

            foreach (var cset in candidates)
            {
                foreach (var w1 in cset)
                {
                    frqMap.Add1OrIncrement(w1);

                    if (!degMap.ContainsKey(w1))
                    {
                        degMap.Add(w1, new HashSet<string>());
                    }

                    foreach (var w2 in cset) { degMap[w1].Add(w2); }
                }
            }

            var deg = new Dictionary<string, int>();
            foreach (var degPair in degMap)
            {
                deg.Add(degPair.Key, degPair.Value.Count);
            }

            return (frqMap, deg);
        }
    }
}
