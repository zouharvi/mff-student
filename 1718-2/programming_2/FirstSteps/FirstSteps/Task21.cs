using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FirstSteps
{
    class Task21
    {
        /// <summary>
        /// Read value of an integer number N. Find and display all prime numbers from interval <1; N>.
        /// </summary>
        public static void Run()
        {
            Console.Write("N: ");
            int N = int.Parse(Console.ReadLine());
            for(int i = 2; i <= N; i++)
            {
                if (IsPrime(i))
                    Console.WriteLine(i);
            }
        }
        public static bool IsPrime(int A)
        {
            for (int i = 2; i < A; i++) // sqrt, but this for sure
                if (A % i == 0)
                    return false;
            return true;
        }
    }
}
