using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FirstSteps
{
    class Task05
    {
        /// <summary>
        /// Read values of 2 integer numbers. Find and display the one which is lower.
        /// </summary>
        public static void Run()
        {
            Console.Write("a1: ");
            int a1 = int.Parse(Console.ReadLine());
            Console.Write("a2: ");
            int a2 = int.Parse(Console.ReadLine());
            Console.WriteLine("The lower is: {0}", (a1 > a2 ? a2 : a1));
            // no instructions in the event of equality
        }
    }
}
