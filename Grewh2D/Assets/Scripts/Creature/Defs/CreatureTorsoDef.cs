using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CreatureTorsoDef
{
    public List<Vector2> points = new List<Vector2>();
    public const int MAX_WIDTH = 3;

    /// <summary>
    /// Genome constructor
    /// </summary>
    /// <param name="ctd"></param>
    public CreatureTorsoDef(CreatureTorsoDef ctd)
    {
        foreach (Vector2 v in ctd.points)
            points.Add(new Vector2(v.x, v.y));
    }

    /// <summary>
    /// Randomization constructor
    /// </summary>
    /// <param name="total"></param>
    public CreatureTorsoDef(int total)
    {
        for (int i = 0; i < total+1; i++)
            points.Add(new Vector2(Random.value * 2 - 1, Random.value * 2 - 1));
    }
}
