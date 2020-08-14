using System;
using System.Collections.Generic;
using System.Collections.Immutable;
using System.IO;
using System.Linq;
using System.Text.RegularExpressions;
using static smake.DataUtils;

namespace smake
{
    class Program
    {

        static void Main(string[] args)
        {
            Console.WriteLine($"Opening stopwords from {Options.F_STOPWORDS}");
            using var swReader = new StreamReader(Options.F_STOPWORDS);

            HashSet<string> sws = new HashSet<string>(swReader.ReadLines());
            var data = new DocAll(sws);

            int hits = 0;
            int docCount = 0;
            foreach (var entry in Directory.GetFiles(Options.G_ABSTR_DIR, Options.G_ABSTR_PATTERN))
            {
                docCount += 1;
                var uncontrPath = $"{entry.RemoveFromEnd("abstr")}uncontr";
                hits += ProcessAbstr(data, sws, entry, uncontrPath);
            }
            Console.WriteLine($"Hit ratio: {hits / (float)docCount}");
        }

        private static int ProcessAbstr(DocAll data, HashSet<string> sws, string fAbstr, string fUncontr)
        {
            var docRaw = File.ReadAllText(fAbstr).ToLower();
            var docWords = Regex.Split(docRaw, @"[^\p{L}]+");

            var uncontrRaw = File.ReadAllText(fUncontr).ToLower().Replace("\n", "").Replace("\t", "").Replace("\r", "");
            var uncontr = new HashSet<string>(uncontrRaw.Split("; "));

            var candidates = CreateCandidates(docWords, sws);
            var (frqs, degs) = ComputeFrqDeg(candidates);

            var rat = new Dictionary<string, float>();
            foreach (var (key, fval) in frqs)
            {
                var dVal = degs[key];
                rat[key] = dVal / (float)fval;
            }

            var keywords = new Dictionary<string, float>();

            foreach (var candidate in candidates)
            {
                var key = string.Join(" ", candidate);
                var csum = candidate.Select(word => rat.GetValueOrDefault(word, 0) * data.TermIdf(word)).Sum();

                var score = keywords.ContainsKey(key) switch
                {
                    true => csum / Math.Pow(candidate.Count(), Options.LENGTH_POWER) + Options.DUPLICITY_SCORE,
                    false => csum / Math.Pow(candidate.Count(), Options.LENGTH_POWER),
                };

                keywords[key] = (float)score;
            }

            var keywordsVec = keywords.ToArray();
            Array.Sort(keywordsVec, (a, b) => b.Value.CompareTo(a.Value));

            var hits = 0;
            if (Options.PRINT_RESULTS)
            {
                Console.WriteLine($"Score Keyword {fAbstr}");
            }

            for (int n = 0; n < Options.CONSIDERED_RESULTS; n++)
            {
                if (n >= keywordsVec.Length)
                {
                    break;
                }

                var (key, val) = keywordsVec[n];
                if (Options.PRINT_RESULTS) { Console.WriteLine($"{val}: {key}"); }
                if (uncontr.Contains(key))
                {
                    hits++;
                }
            }

            return hits;
        }

    }
}
