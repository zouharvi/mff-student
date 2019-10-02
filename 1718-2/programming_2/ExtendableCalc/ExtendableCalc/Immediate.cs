using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExtendableCalc
{
    class Immediate : IOperator
    {
        public bool CanProcess(string line)
        {
            return double.TryParse(line, out double ignore);
        }

        public double Process(double left, string right)
        {
            return double.Parse(right);
        }
    }
}
