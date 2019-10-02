using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FirstSteps
{
    class Task11
    {
        /// <summary>
        /// Read values of 100 integer numbers. Calculate and display their sum.
        /// </summary>
        public static void Run()
        {
            int sum = 0;
            for (int i = 0; i < 100; i++)
                sum += int.Parse(Console.ReadLine());
            Console.WriteLine("The sum is: {0}", sum);
        }
    }
}
