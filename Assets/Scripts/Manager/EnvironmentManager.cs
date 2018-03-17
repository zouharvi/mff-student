using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnvironmentManager : MonoBehaviour {
    public GameObject floor;
    private static readonly float BLOCK_WIDTH = 3;
    private static readonly float BLOCK_HEIGHT = 3;

    public void GenerateTerrain(int length)
    {
        // TODO: left and right block
        float curLevel = 1;

        List<Vector2> newPoints = new List<Vector2>();
        newPoints.Add(new Vector2(0, -10));
        for (int i = 0; i < length; i++)
        {
            curLevel += (Random.value-0.5f)*BLOCK_HEIGHT;
            if (curLevel < 0) curLevel = 0;
            newPoints.Add(new Vector2(i * BLOCK_WIDTH, curLevel));
        }
        newPoints.Add(new Vector2(BLOCK_WIDTH*length, -10));
        floor.GetComponent<PolygonCollider2D>().points = newPoints.ToArray();
        floor.GetComponent<DrawPolygon>().CreateGraphicsFromPolygonCollider(0, 0.05f);
    }
}
