using System.Collections;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;

public class Grapher : MonoBehaviour {
    private new LineRenderer renderer;
    // Use this for initialization
    void Start () {
        renderer = gameObject.AddComponent<LineRenderer>();
        renderer.startWidth = renderer.endWidth = 0.05f;
        renderer.startColor = renderer.endColor = Color.blue;
        renderer = GetComponent<LineRenderer>();
        renderer.material.color = new Color(0.9433962f, 0.8966974f, 0.5206479f);
    }
	
    public void SetPosition(Vector3 pos)
    {
        renderer.transform.position = pos;
    }

    public void Plot(List<float> values, float width, float height, float? max)
    {
        if(max != null)
            CustomMath.NormalizeByMax(ref values, (float) max);
        else
            CustomMath.Normalize(ref values);
        renderer.positionCount = values.Count;
        for(int i = 0; i < values.Count; i++)
            renderer.SetPosition(i, new Vector3(renderer.transform.position.x + i *width/values.Count, renderer.transform.position.y + values[i]*height, 0));
    }
}
