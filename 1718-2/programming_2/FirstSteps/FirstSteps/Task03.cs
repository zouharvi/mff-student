using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FirstSteps
{
    class Task03
    {
        /// <summary>
        /// Read values of 3 integer numbers, save values as variables a1, a2, a3. Calculate and display the number of values that are equal to 0.
        /// </summary>
        public static void Run()
        {
            Console.Write("a1: ");
            int a1 = int.Parse(Console.ReadLine());
            Console.Write("a2: ");
            int a2 = int.Parse(Console.ReadLine());
            Console.Write("a3: ");
            int a3 = int.Parse(Console.ReadLine());
            int noZero = (a1 == 0 ? 1 : 0) + (a2 == 0 ? 1 : 0) + (a3 == 0 ? 1 : 0);
            Console.WriteLine("Number of zero a* variables: {0}", noZero);
            // Russell (self referential) paradox:
            // if a1, a2, a3 = 0, then noZero = 0, but noZero is a variable and it's value is 0, so noZero should be 1, but then there is no zero variable, etc
        }
    }
}
