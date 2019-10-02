using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FirstSteps
{
    class Task15
    {
        /// <summary>
        /// Read values of integer numbers A and B. Calculate and display the sum and the products of integers laying between the given interval <A; B> (including interval boundaries).
        /// </summary>
        public static void Run()
        {

            Console.Write("A: ");
            int A = int.Parse(Console.ReadLine());
            Console.Write("B: ");
            int B = int.Parse(Console.ReadLine());
            int prod = 1;
            int sum = 0;
            for (int i = A; i <= B; i++)
            {
                prod *= i;
                sum += i;
            }
            Console.WriteLine("The product is: {0}", prod);
            Console.WriteLine("The sum is: {0}", sum);
        }
    }
}
