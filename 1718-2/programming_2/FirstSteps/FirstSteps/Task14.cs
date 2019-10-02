using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FirstSteps
{
    class Task14
    {
        /// <summary>
        /// Read value of integer number N. Then read values of N integer numbers. Calculate and display how many numbers greater than 50 you have read.
        /// </summary>
        public static void Run()
        {
            Console.Write("N: ");
            int N = int.Parse(Console.ReadLine());
            int total = 0;
            for (int i = 0; i < N; i++)
                if (int.Parse(Console.ReadLine()) > 50)
                    total++;
            Console.WriteLine("No. values > 50: {0}", total);
        }
    }
}
