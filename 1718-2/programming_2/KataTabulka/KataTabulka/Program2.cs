using System;
using System.Collections.Generic;
using System.Linq;

namespace KataTabulka
{
    class Program2
    {
        public const int CHAR_TOTAL = 256;
        class Coord
        {
            public int x, y;
            public Coord(int x, int y) { this.x = x; this.y = y; }
            public Coord() { }
        }

        static List<Coord>[] coords;
        static string input;
        static int F(int i, int j, int x, int y)
        {
            int m = int.MaxValue/2;
            List<Coord> c = coords[input[j-1]];
            //for (int k = 0; k < c.Count; k++)
            return 0;
            //    m = Math.Min(m, Math.Abs());
        }

        private static void Main2(string[] args)
        {
            // init
           coords = new List<Coord>[CHAR_TOTAL];
            for (int i = 0; i < CHAR_TOTAL; i++) coords[i] = new List<Coord>();
            bool[] present = new bool[CHAR_TOTAL];

            // load
            int wX = int.Parse(Console.ReadLine()); int wY = int.Parse(Console.ReadLine());
            string loaded = Console.ReadLine();
            for (int i = 0; i < wX * wY; i++)
            {
                present[loaded[i]] = true;
                coords[loaded[i]].Add(new Coord(i % wX, i / wX));
            }
            string inputRaw = Console.ReadLine();

            // corner case
            if (wX == 0 || wY == 0)
            {
                Console.WriteLine("0");
                return;
            }

            // strip input
            input = "";
            for (int i = 0; i < inputRaw.Length; i++)
                if (present[inputRaw[i]])
                    input += inputRaw[i];

            // find minimal
            List<Coord> prevChar = coords[input[0]];
            List<Coord> curChar;
            List<int> prevSolution = new List<int>();
            List<int> curSolution;
            for (int i = 0; i < prevChar.Count; i++)
                prevSolution.Add(prevChar[i].x + prevChar[i].y + 1);

            for (int k = 1; k < input.Length; k++)
            {
                curSolution = new List<int>();
                curChar = coords[input[k]];
                for (int j = 0; j < curChar.Count; j++)
                {
                    curSolution.Add(int.MaxValue);
                    for (int i = 0; i < prevChar.Count; i++)
                    {
                        int dst = Math.Abs(prevChar[i].x - curChar[j].x) + Math.Abs(prevChar[i].y - curChar[j].y);
                        if (dst + prevSolution[i] < curSolution[j])
                            curSolution[j] = dst + prevSolution[i] + 1;
                    }
                }
                prevChar = curChar;
                prevSolution = curSolution;
            }

            // out
            Console.WriteLine(prevSolution.Min());

            // wait
            //Console.ReadLine();
        }
    }
}
