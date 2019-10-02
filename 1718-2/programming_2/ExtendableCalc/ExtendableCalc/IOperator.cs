using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExtendableCalc
{
    interface IOperator
    {
        /// <summary>
        /// Whether the implementation can handle 'line'.
        /// </summary>
        /// <param name="line"></param>
        /// <returns></returns>
        bool CanProcess(string line);

        /// <summary>
        /// Can be called IF AND ONLY IF "right" can be processed, check for that
        /// by calling CanProcess(right).
        /// </summary>
        /// <param name="left"></param>
        /// <param name="right"></param>
        /// <returns></returns>
        double Process(double left, string right);
    }
}
