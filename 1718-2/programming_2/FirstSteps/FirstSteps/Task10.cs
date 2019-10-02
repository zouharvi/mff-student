using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FirstSteps
{
    class Task10
    {
        /// <summary>
        /// Read value of an integer number N. Calculate and display the sum of odd numbers from interval [1; N].
        /// </summary>
        public static void Run()
        {
            Console.Write("N: ");
            int N = int.Parse(Console.ReadLine());
            int x = (N % 2 == 0 ? N - 1 : N);
            int y = (N % 2 == 0 ? N/2: N/2+1);
            Console.WriteLine(((x+1) * y/2));
        }
    }
}
