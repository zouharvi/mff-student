using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FirstSteps
{
    class Task01
    {
        /// <summary>
        /// Read values of 2 integer numbers and save them as variables a1, a2. Calculate and display their sum.
        /// </summary>
        public static void Run()
        {
            Console.Write("a1: ");
            int a1 = int.Parse(Console.ReadLine());
            Console.Write("a2: ");
            int a2 = int.Parse(Console.ReadLine());
            Console.WriteLine("The sum of {0} and {1} is {2}", a1, a2, a1 + a2);
        }

    }
}
