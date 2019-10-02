using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FirstSteps
{
    class Task06
    {
        /// <summary>
        /// Read values of 4 integer numbers. Find and display the one with the highest value.
        /// </summary>
        public static void Run()
        {
            int highest = int.MinValue;
            for(int i = 0; i < 4; i++)
            {
                Console.Write("a{0}: ", i+1);
                int a = int.Parse(Console.ReadLine());
                highest = Math.Max(a, highest);
            }
            Console.WriteLine("The highest one is: {0}", highest);
        }
    }
}
