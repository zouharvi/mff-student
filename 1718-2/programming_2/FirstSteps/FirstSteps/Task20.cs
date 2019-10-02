using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FirstSteps
{
    class Task20
    {
        /// <summary>
        /// Read value of an integer number A. Find out and display whether number A is a prime.
        /// </summary>
        public static void Run()
        {
            Console.Write("A: ");
            int A = int.Parse(Console.ReadLine());
            bool prime = true;
            for (int i = 2; i < A; i++) // sqrt, but this for sure
                if (A % i == 0)
                {
                    prime = false;
                    break;
                }
            Console.WriteLine(prime ? "The number is prime" : "The number is not prime");
        }
    }
}
