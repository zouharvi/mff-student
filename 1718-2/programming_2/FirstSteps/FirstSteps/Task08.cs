using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FirstSteps
{
    class Task08
    {
        /// <summary>
        /// Display all odd numbers between 0 and 100.
        /// </summary>
        public static void Run()
        {
            for (int i = 1; i <= 100; i += 2)
                Console.WriteLine(i);
        }
    }
}
