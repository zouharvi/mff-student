using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CreatureTorso
{

    public List<Vector2> points = new List<Vector2>();
    public const int MAX_WIDTH = 3;
    public GameObject gameObject;

    /// <summary>
    /// Randomization constructor
    /// </summary>
    public CreatureTorso()
    {
        for (int i = 0; i < 5; i++)
            points.Add(new Vector2(Random.value * 2 - 1, Random.value * 2 - 1) * MAX_WIDTH);
    }

    public void ExtendPolygon(List<Vector2> newPoints)
    {
        points.AddRange(newPoints);
        CustomMath.CreatePrettyPolygon(ref points);
        gameObject.GetComponent<PolygonCollider2D>().points = points.ToArray();
    }

    public GameObject Instantiate(GameObject blankTorso, Transform parent)
    {
        gameObject = GameObject.Instantiate(blankTorso, parent);
        return gameObject;
    }

    public void CreateGraphics()
    {
        gameObject.GetComponent<DrawPolygon>().CreateGraphicsFromPolygon();
    }
}
