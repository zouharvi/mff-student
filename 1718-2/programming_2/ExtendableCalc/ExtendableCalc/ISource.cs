using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExtendableCalc
{
    interface ISource
    {
        /// <summary>
        /// Whether we have another line of input ready.
        /// </summary>
        /// <returns></returns>
        bool HasNext();

        /// <summary>
        /// Gets another line of input; valid to call only if HasNext() reports true.
        /// </summary>
        /// <returns></returns>
        string GetLine();
    }
}
