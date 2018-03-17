using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour {

    EnvironmentManager environment;
    CreatureBreeder breeder;
    CameraManager cameraManager;

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
	
	void Update () {
		
	}
}
