using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FirstSteps
{
    class Task07
    {
        /// <summary>
        /// Read value of an integer number X. If X is odd number then read values of another 5 integer numbers. If X is the middle one, then calculate and display the sum and the product of the sequence (each on its own line).
        /// </summary>
        public static void Run()
        {
            Console.Write("X: ");
            int x = int.Parse(Console.ReadLine());
            if(x % 2 != 0)
            {
                int[] arr = new int[5];
                for (int i = 0; i < 5; i++)
                    arr[i] = int.Parse(Console.ReadLine());
                if(x == arr[2])
                {
                    int prod = 1;
                    int sum = 0;
                    for (int i = 0; i < 5; i++)
                    {
                        prod *= arr[i];
                        sum += arr[i];
                    }
                    Console.WriteLine("The sum is: {0}", sum);
                    Console.WriteLine("The product is: {0}", prod);
                }
            }
        }
    }
}
