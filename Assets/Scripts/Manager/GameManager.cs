using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour {

    EnvironmentManager environment;
    CreatureBreeder breeder;
    CameraManager cameraManager;
    public RectTransform goToStatisticPanel;
    public bool doOfferEnd = true;

    private void Start()
    {
        Physics2D.gravity = new Vector2(0, -9.81f);
        environment = gameObject.GetComponent<EnvironmentManager>();
        breeder = gameObject.GetComponent<CreatureBreeder>();
        cameraManager = gameObject.GetComponent<CameraManager>();
        breeder.population = ShowcaseGenomes.genomes;
        VanillaGame(false);
    }

    public void VanillaGame (bool reset) {
        breeder.CleanUp();
        if(reset)
            breeder.ResetPopulation();
        breeder.InstantiatePopulation();
        cameraManager.InitState();
        environment.GenerateTerrain(100);
    }

    public void SubsequentGame()
    {
        breeder.CleanUp();
        breeder.InstantiateFollowingPopulation();
        cameraManager.InitState();
    }

    public void PrematureSubsequentGame()
    {
        breeder.KillOffRest();
        SubsequentGame();
    }

    public void OfferEnd()
    {
        goToStatisticPanel.gameObject.SetActive(true);
        //goToStatisticPanel.localScale = new Vector3(1, 1, 1);
        Time.timeScale = 0;
    }

	public void GoToStatistics () {
        breeder.KillOffRest();
        Initiate.Fade("Scenes/Statistics", Color.black, 1f);
    }
}
