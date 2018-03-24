using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Grapher : MonoBehaviour {
    private new LineRenderer renderer;
    // Use this for initialization
    void Start () {
        renderer = gameObject.AddComponent<LineRenderer>();
        renderer.startWidth = renderer.endWidth = 0.2f;
        renderer.startColor = renderer.endColor = Color.blue;
        renderer = GetComponent<LineRenderer>();
        renderer.material.color = Color.blue;
        renderer.positionCount = 2;
        renderer.SetPosition(0, new Vector3(0, 0, 0));
        renderer.SetPosition(1, new Vector3(10, 10, 0));
    }
	
	// Update is called once per frame
	void Update () {
		
	}
}
