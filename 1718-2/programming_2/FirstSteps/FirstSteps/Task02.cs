using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FirstSteps
{
    class Task02
    {
        /// <summary>
        /// Read values of 3 integer numbers and save them as variables a1, a2, a3. Calculate and display their product.
        /// </summary>
        public static void Run()
        {
            Console.Write("a1: ");
            int a1 = int.Parse(Console.ReadLine());
            Console.Write("a2: ");
            int a2 = int.Parse(Console.ReadLine());
            Console.Write("a3: ");
            int a3 = int.Parse(Console.ReadLine());
            Console.WriteLine("The product of {0}, {1} and {2} is {3}", a1, a2, a3, a1 * a2 * a3);

        }
    }
}
