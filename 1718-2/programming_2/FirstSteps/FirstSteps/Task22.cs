 using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FirstSteps
{
    class Task22
    {
        /// <summary>
        /// Read integer values until you encounter number 42. Calculate and display the sum of all numbers you have read.
        /// </summary>
        public static void Run()
        {
            int sum = 0;
            while(true)
            {
                int a = int.Parse(Console.ReadLine());
                if (a == 42)
                    break;
                sum += a;
            }
            Console.WriteLine("The sum is: {0}", sum);
        }
    }
}
