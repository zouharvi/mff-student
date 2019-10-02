using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FirstSteps
{
    class Task13
    {
        /// <summary>
        /// Read values of a real number X and an integer number N. Calculate and display the N-th power of X.
        /// </summary>
        public static void Run()
        {
            Console.Write("N: ");
            int N = int.Parse(Console.ReadLine());
            Console.Write("x: ");
            int x = int.Parse(Console.ReadLine());
            int prod = 1;
            for (int i = 0; i < N; i++) // this could be done logarithmicaly
                prod *= x;

            Console.WriteLine("x^N: {0}", prod);
        }
    }
}
