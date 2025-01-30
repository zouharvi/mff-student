using System.Collections;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;

public class CustomMath {

    /// <summary>
    /// Warning: mutates array
    /// </summary>
    /// <returns></returns>
    public static void CreatePrettyPolygon(ref List<Vector2> points)
    {
        /* TODO: make a proper note here pointing to readme entry.
           Points are sorted clockwise here, but funnily enough, minimal triangulation
           appears to be an open problem, as it closely relates to the traveling salesman problem.
         */
        // points.Sort(new ClockwiseVector2Comparer());
        points = points.OrderBy(item => Mathf.Atan2(item.x, item.y)).ToList();

        for (int i = 1; i < points.Count; i++)
        {
            if(Vector2.Angle(points[i-1], points[i]) < 5 && points.Count > 3)
            {
                points.RemoveAt(i); // TODO: what if wheel point is removed?
                i--;
            }
        }
    }

    /* broken on webgl builds
    public class ClockwiseVector2Comparer : IComparer<Vector2>
    {
        public int Compare(Vector2 v1, Vector2 v2)
        {
            return Mathf.Atan2(v1.x, v1.y).CompareTo(Mathf.Atan2(v2.x, v2.y));
        }
    }
     */

    /// <summary>
    /// returns with opposite linear probability
    /// </summary>
    /// <param name="totalSize"></param>
    /// <returns></returns>
    public static int RandGood(int totalSize)
    {
        return (int)(RandomFromDistribution.RandomLinear(4) * totalSize / 5.0f);
    }


    public static void Normalize(ref List<float> values)
    {
        float min = values.Min();
        float max = values.Max();
        // shift
        for (int i = 0; i < values.Count; i++)
            values[i] = values[i] - min;
        max = max - min;
        for (int i = 0; i < values.Count; i++)
            values[i] = values[i] / max;
    }

    public static void NormalizeByMax(ref List<float> values, float max)
    {
        float min = values.Min();
        // shift
        for (int i = 0; i < values.Count; i++)
            values[i] = values[i] - min;
        max -= min;
        for (int i = 0; i < values.Count; i++)
            values[i] = values[i] / max;
    }
}
