using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FirstSteps
{
    class Task12
    {
        /// <summary>
        /// Read values of 100 integer numbers. Find and display the one with the highest value.
        /// </summary>
        public static void Run()
        {
            int highest = int.MinValue;
            for (int i = 0; i < 100; i++)
                highest = Math.Max(highest, int.Parse(Console.ReadLine()));
            Console.WriteLine("The highest is: {0}", highest);
        }
    }
}
