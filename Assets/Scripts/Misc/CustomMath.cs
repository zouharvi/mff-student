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
        points.Sort(new ClockwiseVector2Comparer());

        for (int i = 1; i < points.Count; i++)
        {
            if(Vector2.Angle(points[i-1], points[i]) < 5)
            {
                points.RemoveAt(i); // TODO: what if wheel point is removed?
                i--;
            }
        }
    }

    public class ClockwiseVector2Comparer : IComparer<Vector2>
    {
        public int Compare(Vector2 v1, Vector2 v2)
        {
            return Mathf.Atan2(v1.x, v1.y).CompareTo(Mathf.Atan2(v2.x, v2.y));
        }
    }
}
