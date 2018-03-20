using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour {

    EnvironmentManager environment;
    CreatureBreeder breeder;
    CameraManager cameraManager;
    public RectTransform goToStatisticPanel;

    private void Start()
    {
        environment = gameObject.GetComponent<EnvironmentManager>();
        breeder = gameObject.GetComponent<CreatureBreeder>();
        cameraManager = gameObject.GetComponent<CameraManager>();
        VanillaGame();
    }

    public void VanillaGame () {
        breeder.CleanUp();
        breeder.ResetPopulation();
        breeder.InstantiateNew();
        cameraManager.InitState();
        environment.GenerateTerrain(100);
        Debug.Log("Started vanilla");
    }

    public void SubsequentGame()
    {
        breeder.CleanUp();
        breeder.ResetPopulation();
        breeder.InstantiateFollowingPopulation();
        cameraManager.InitState();
        Debug.Log("Started subsequent");
    }

    public void PrematureSubsequentGame()
    {
        Debug.Log("Ending run prematurely");
        breeder.KillOffRest();
        SubsequentGame();
    }
	
    public void OfferEnd()
    {
        goToStatisticPanel.localScale = new Vector3(1, 1, 1);
        Time.timeScale = 0;
    }

	void Update () {
		
	}
}
