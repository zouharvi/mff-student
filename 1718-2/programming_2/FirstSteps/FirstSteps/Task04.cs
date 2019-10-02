using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FirstSteps
{
    class Task04
    {
        /// <summary>
        /// Read values of 4 integer values and save them as variables a1, a2, a3, a4. Using MODULO operation, find the even ones and calculate and display their sum.
        /// </summary>
        public static void Run()
        {
            Console.Write("a1: ");
            int a1 = int.Parse(Console.ReadLine());
            Console.Write("a2: ");
            int a2 = int.Parse(Console.ReadLine());
            Console.Write("a3: ");
            int a3 = int.Parse(Console.ReadLine());
            Console.Write("a4: ");
            int a4 = int.Parse(Console.ReadLine());
            int sum = (a1 % 2 == 0 ? a1 : 0) + (a2 % 2 == 0 ? a2 : 0) + (a3 % 2 == 0 ? a3 : 0) + (a4 % 2 == 0 ? a4 : 0);
            Console.WriteLine("The sum of the even ones is: {0}", sum);
        }
    }
}
