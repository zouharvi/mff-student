using System;
using System.Collections.Generic;
using System.Linq;

namespace Hades
{
    internal class FitnessEvaluator
    {
        // Eval code by Josef Starýchfojtů
        public static long Eval(string raw)
        {
            // Load input
            var width = 8;
            var height = 8;
            var keys = raw;
            var word = Program.INPUT;

            var keyLocations = new Dictionary<char, IList<KeyPosition>>();

            for (var i = 0; i < height * width; i++)
            {
                var key = keys[i];
                if (!keyLocations.ContainsKey(key))
                {
                    keyLocations[key] = new List<KeyPosition>();
                }
                keyLocations[key].Add(new KeyPosition(i % width, i / width));
            }

            // Main program
            var bestPaths = new Dictionary<KeyPosition, int> { { new KeyPosition(0, 0), 0 } };
            var letters = word.ToCharArray().Where(l => keyLocations.ContainsKey(l)).ToArray();

            foreach (var letter in letters)
            {
                var positions = keyLocations[letter];
                var newBestPaths = positions.ToDictionary(p => p, p => int.MaxValue);

                foreach (var kvp in bestPaths)
                {
                    var currentPosition = kvp.Key;
                    var currentDistance = kvp.Value;

                    foreach (var position in positions)
                    {
                        var distance = currentPosition.GetDistance(position) + currentDistance;
                        if (distance < newBestPaths[position])
                        {
                            newBestPaths[position] = distance;
                        }
                    }
                }

                bestPaths = newBestPaths;
            }

            // Print result
            return (bestPaths.Values.Min() + letters.Length);
        }

        public class KeyPosition
        {
            public KeyPosition(int x, int y)
            {
                X = x;
                Y = y;
            }

            public int X { get; }

            public int Y { get; }

            public int GetDistance(KeyPosition other)
            {
                return Math.Abs(X - other.X) + Math.Abs(Y - other.Y);
            }
        }
    }
}