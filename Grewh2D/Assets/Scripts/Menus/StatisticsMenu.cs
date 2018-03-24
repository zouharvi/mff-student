using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class StatisticsMenu: MonoBehaviour {


	void Start () {
        // displaying nonexistent statistics
     //   Grapher.Init(target);
	}

    public void TryAgain()
    {
        Initiate.Fade("Scenes/Showcase", Color.black, 1f);
    }
}
