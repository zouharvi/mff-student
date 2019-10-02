using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FirstSteps
{
    class Task17
    {
        /// <summary>
        /// Read integer number N. Then read a sequence of N integer numbers. Find the maximal and minimal value from that sequence and display them.
        /// </summary>
        public static void Run()
        {
            int min = int.MaxValue;
            int max = int.MinValue;

            Console.Write("N: ");
            int N = int.Parse(Console.ReadLine());
            
            for(int i = 0; i < N; i++)
            {
                int a = int.Parse(Console.ReadLine());
                min = Math.Min(a, min);
                max = Math.Max(a, max);
            }
            Console.WriteLine("Min: {0}, Max: {1}", min, max);
        }
    }
}
