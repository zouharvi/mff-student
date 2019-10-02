using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FirstSteps
{
    class Task16
    {
        /// <summary>
        /// Read integer number N. Calculate and display the product of the first N natural numbers that can be divided by 3.
        /// </summary>
        public static void Run()
        {
            int prod = 1;

            Console.Write("N: ");
            int N = int.Parse(Console.ReadLine());

            for (int i = 1; i <= N; i++) 
                if (i % 3 == 0) // this could be done better
                    prod *= i;
            Console.WriteLine("The product is: {0}", prod);
        }
    }
}
