﻿using System;
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

            // parallelizing DocAll doesn't seem to help -> I/O bottleneck? (profiler suggests so)
            var data = new DocAll(sws);

            int hits = 0;
            var filesToProcess = Directory.GetFiles(Options.G_ABSTR_DIR, Options.G_ABSTR_PATTERN);

            if (Options.MAKE_PARALLEL) { hits = filesToProcess.AsParallel().Select(f => ProcessAbstr(data, sws, f)).Sum(); }
            else { hits = filesToProcess.Select(f => ProcessAbstr(data, sws, f)).Sum(); }

            Console.WriteLine($"Hit ratio: {hits / (float)filesToProcess.Length}");
        }

        private static int ProcessAbstr(DocAll data, HashSet<string> sws, string fAbstr)
        {
            string fUncontr = $"{fAbstr.RemoveFromEnd("abstr")}uncontr";

            var docRaw = File.ReadAllText(fAbstr);
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
                    true => csum / Math.Pow(candidate.Count(), Options.LENGTH_POWER),
                    false => csum / Math.Pow(candidate.Count(), Options.LENGTH_POWER) + Options.DUPLICITY_SCORE,
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
                if (uncontr.Contains(key))
                {
                    if (Options.PRINT_RESULTS) { Console.WriteLine($" * {val:F3}: {key}"); }
                    hits++;
                }
                else
                {
                    if (Options.PRINT_RESULTS) { Console.WriteLine($"   {val:F3}: {key}"); }
                }
            }

            return hits;
        }

    }
}
