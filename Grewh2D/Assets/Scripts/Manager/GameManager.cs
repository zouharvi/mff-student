using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour {

    EnvironmentManager environment;
    CreatureBreeder breeder;
    CameraManager cameraManager;
    StatisticsCollector collector;
    public RectTransform goToStatisticPanel;
    public bool doOfferEnd = true;

    private void Start()
    {
        Physics2D.gravity = new Vector2(0, -9.81f);
        environment = gameObject.GetComponent<EnvironmentManager>();
        breeder = gameObject.GetComponent<CreatureBreeder>();
        cameraManager = gameObject.GetComponent<CameraManager>();
        breeder.population = ShowcaseGenomes.genomes;
        collector = gameObject.GetComponent<StatisticsCollector>();
        VanillaGame(false);
    }

    /// <summary>
    /// deprecated
    /// </summary>
    /// <param name="reset"></param>
    public void VanillaGame (bool reset) {
        breeder.CleanUp();
        if(reset)
            breeder.ResetPopulation();
        breeder.InstantiatePopulation();
        cameraManager.InitState();
        environment.GenerateTerrain();
    }

    public void SubsequentGame()
    {
        SendToCollector();
        breeder.CleanUp();
        breeder.InstantiateFollowingPopulation();
        cameraManager.InitState();
    }

    public void PrematureSubsequentGame()
    {
        breeder.KillOffRest();
        SubsequentGame();
    }

    private void SendToCollector()
    {
        collector.CollectEnd(breeder.killedAbsolutes);
    }

    public void OfferEnd()
    {
        goToStatisticPanel.gameObject.SetActive(true);
        Time.timeScale = 0;
    }

	public void GoToStatistics () {
        breeder.KillOffRest();
        SendToCollector();
        Time.timeScale = 1;
        breeder.KillOffRest();
        Initiate.Fade("Scenes/Statistics", Color.black, 1f);
    }

    public void ContinuePlaying()
    {
        goToStatisticPanel.gameObject.SetActive(false);
        Time.timeScale = GameGenSettings.SIMULATION_SPEED;
    }

    public void NewTerrain()
    {
        environment.GenerateTerrain();
        PrematureSubsequentGame();
    }
}
