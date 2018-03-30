using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class StatisticsCollector : MonoBehaviour {

    public static List<float> avgGenFitnessPerGen;
    public static List<float> bestGenFitnessPerGen;

    public void CollectEnd(List<float> absolutes)
    {
        float best = 0;
        float sum = 0;
        foreach(float f in absolutes)
        {
            best = Mathf.Max(best, f);
            sum += f;
        }
        bestGenFitnessPerGen.Add(best);
        avgGenFitnessPerGen.Add(sum * 1.0f / absolutes.Count);
    }

    // Use this for initialization
    void Start () {
        avgGenFitnessPerGen = new List<float>();
        bestGenFitnessPerGen = new List<float>();
	}
	
    public void DumpLog()
    {
        string s = "";
        foreach (float f in avgGenFitnessPerGen)
            s += f + ", ";
        Debug.Log("AVGS: "+s);
        s = "";
        foreach (float f in bestGenFitnessPerGen)
            s += f + ", ";
        Debug.Log("BESTS: " + s);
    }
}
