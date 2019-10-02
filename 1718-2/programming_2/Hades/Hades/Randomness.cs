using System;
using System.Collections.Generic;
using System.Text;

namespace Hades
{
    class Randomness
    {
        // Returns random in range [0,1] with linear distribution of given slope.
        public static float RandomLinear(float slope)
        {

            float abs_value = RandomFromLinearWithPositiveSlope(Math.Abs(slope));
            if (slope < 0)
            {
                return 1 - abs_value;
            }
            else
            {
                return abs_value;
            }
        }


        private static Random r = new Random();
        // Returns random in range [0,1] with linear distribution of given slope.
        private static float RandomFromLinearWithPositiveSlope(float slope)
        {
            float x, y;
            do
            {
                x = (float) r.NextDouble();
                y = (float) r.NextDouble();
                if (slope < 1)
                {
                    y -= (1 - slope) / 2.0f;
                }
            } while (y > x * slope);

            return x;

        }

    }
}
