using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FirstSteps
{
    class Task18
    {
        /// <summary>
        /// Read value of a real number A. Calculate and display the value of an edge, volume and surface of a cube that has a length of its body diagonal A.
        /// Tip: Math.Sqrt(double)
        /// </summary>
        public static void Run()
        {
            double A = double.Parse(Console.ReadLine());
            double edge = Math.Sqrt(3) * A;
            double surface = 6* edge * edge;
            double volume = edge * edge * edge;
            Console.WriteLine("Edge: {0}, Surface: {1}, Volume: {2}", edge, surface, volume);
        }
    }
}
