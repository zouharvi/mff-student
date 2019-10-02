using System;
using System.Collections.Generic;
using System.Linq;

namespace KataTabulka
{
    class Program
    {
        public const int CHAR_TOTAL = 256;

        static char[,] table;
        static int[,,] dynamic;
        static string input;
        static int wX, wY;

        static int f(int row, int col, int pos)
        {
            if (table[row, col] != input[pos])
                return int.MaxValue/2;
            if (pos == 0)
                return 0;

            if (dynamic[pos, row, col] != -1)
                return dynamic[pos, row, col];

            //Console.WriteLine("f(" + row + ", " + col + ", " + pos + ")");
            int m = int.MaxValue;
            for (int i = 0; i < wX; i++)
                for (int j = 0; j < wY; j++)
                    if(table[i,j] == input[pos-1])
                        m = Math.Min(m, f(i, j, pos - 1) + Math.Abs(row - i) + Math.Abs(col - j));
            dynamic[pos, row, col] = m;
            return m;
        }

        static void Main(string[] args)
        {
            // init
            bool[] present = new bool[CHAR_TOTAL];

            // load
            wX = int.Parse(Console.ReadLine()); wY = int.Parse(Console.ReadLine());
            table = new char[wX, wY];
            string loaded = Console.ReadLine();
            for (int i = 0; i < wX * wY; i++)
            {
                present[loaded[i]] = true;
                table[i % wX, i / wX] = loaded[i];
            }
            string inputRaw = Console.ReadLine();

            // strip input
            input = "";
            for (int i = 0; i < inputRaw.Length; i++)
                if (present[inputRaw[i]])
                    input += inputRaw[i];

            dynamic = new int[input.Length, wX, wY];
            for (int k = 0; k < input.Length; k++)
                for (int i = 0; i < wX; i++)
                    for (int j = 0; j < wY; j++)
                        dynamic[k, i, j] = -1;

            // find minimal
            int m = int.MaxValue;
            for (int i = 0; i < wX; i++)
                for (int j = 0; j < wY; j++)
                {
                    //Console.WriteLine("table[" + i + "," + j + "] == " + table[i, j]);
                    if(table[i,j] == input[input.Length-1])
                        m = Math.Min(m, f(i, j, input.Length - 1));
                }
            Console.WriteLine(m+input.Length);

            // wait
            Console.ReadLine();
        }
    }
}
