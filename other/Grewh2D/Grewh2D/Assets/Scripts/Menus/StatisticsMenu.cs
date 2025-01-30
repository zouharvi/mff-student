using System.Collections;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;
using UnityEngine.SceneManagement;

public class StatisticsMenu: MonoBehaviour {

    public Grapher grapherAvg;
    public Grapher grapherBest;
	void Start () {
        grapherAvg.SetPosition(new Vector3(5, -18, 0));
        grapherAvg.Plot(StatisticsCollector.avgGenFitnessPerGen, 25, 15, StatisticsCollector.bestGenFitnessPerGen.Max());
        grapherBest.SetPosition(new Vector3(33, -18, 0));
        grapherBest.Plot(StatisticsCollector.bestGenFitnessPerGen, 25, 15, null);
    }

    public void TryAgain()
    {
        Initiate.Fade("Scenes/Showcase", Color.black, 1f);
    }
}
