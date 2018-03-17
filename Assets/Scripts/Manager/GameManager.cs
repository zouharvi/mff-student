using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour {

    EnvironmentManager environment;
    CreatureBreeder breeder;

    private void Start()
    {
        environment = gameObject.GetComponent<EnvironmentManager>();
        breeder = gameObject.GetComponent<CreatureBreeder>();
    }

    public void VanillaGame () {
        breeder.CleanUp();
        breeder.ResetPopulation();
        breeder.InstantiateNew();
        Debug.Log("Started vanilla");
    }
	
	void Update () {
		
	}
}
