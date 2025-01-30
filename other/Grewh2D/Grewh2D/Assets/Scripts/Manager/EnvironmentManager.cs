﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnvironmentManager : MonoBehaviour {
    public GameObject floor;
    public GameObject endKillZone;
    private static readonly float BLOCK_WIDTH = 3;

    public void GenerateTerrain(int length = 100)
    {
        length += 5; // more robust

        float curLevel = 1;

        List<Vector2> newPoints = new List<Vector2>();

        float levelMax = 0;
        for (int i = 0; i < length; i++)
        {
            curLevel += (Random.value-0.5f)*GameGenSettings.TERRAIN_HARDNESS/10.0f;
            levelMax = Mathf.Max(levelMax, curLevel);
            if (curLevel < 0) curLevel = 0;
            newPoints.Add(new Vector2(i * BLOCK_WIDTH, curLevel));
        }

        // inserts are quite heavy
        newPoints.Insert(0, new Vector2(-100, -10));
        newPoints.Insert(1, new Vector2(-100, levelMax + 70));
        newPoints.Insert(2, new Vector2(-5, levelMax + 70));
        newPoints.Add(new Vector2(BLOCK_WIDTH*length+5, levelMax + 70));
        newPoints.Add(new Vector2(BLOCK_WIDTH*length+100, levelMax + 70));
        newPoints.Add(new Vector2(BLOCK_WIDTH*length+100, -10));


        floor.GetComponent<PolygonCollider2D>().points = newPoints.ToArray();
        floor.GetComponent<DrawPolygon>().CreateGraphicsFromPolygonCollider(Random.ColorHSV(0, 1, 0, 1, 0, 0.4f), 0, 0.05f);

        endKillZone.transform.position = new Vector3(BLOCK_WIDTH * (length-5), 0, 0);

        CameraManager cameraManager = gameObject.GetComponent<CameraManager>();
        cameraManager.cameraXMin = -10;
        cameraManager.cameraXMax = BLOCK_WIDTH*length;
        cameraManager.cameraYMin = -10;
        cameraManager.cameraYMax = levelMax + 20;
    }
}
