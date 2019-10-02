using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FirstSteps
{
    class Task19
    {
        /// <summary>
        /// Read value of an integer number N. Then read values of N real numbers. Calculate and display the average of real numbers.
        /// </summary>
        public static void Run()
        {
            Console.Write("N: ");
            int N = int.Parse(Console.ReadLine());
            double sum = 0;
            for (int i = 0; i < N; i++)
                sum += double.Parse(Console.ReadLine());
            Console.WriteLine("The avg is: {0}", sum / N);
        }
    }
}
