using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Snake
{
    class TimeDelta
    {
        private long now;
        private long delta;

        public TimeDelta()
        {
            now = (long)DateTime.UtcNow.TimeOfDay.TotalMilliseconds;
            delta = 0;
        }

        public long GetDelta()
        {
            return delta;
        }

        public void Update()
        {
            long now2 = (long)DateTime.UtcNow.TimeOfDay.TotalMilliseconds;
            delta = now2 - now;
            now = now2;
        }




    }
}
