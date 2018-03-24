using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GameGenSettings : MonoBehaviour {

    public Text populationText, terrainHardnessText, killTimerText, simSpeedText, individualVsFromParentsText;
    public static int POPULATION_SIZE = 21;
    public static int TERRAIN_HARDNESS = 20;
    public static int KILL_TIMER = 2;
    public static int SIMULATION_SPEED = 1;

    // percentages, must sum to 100
    public static int INDIVIDUALLY_MUTATED = 20;
    public static int MUTATED_FROM_PARENTS = 80;

    public static int KILL_SEGMENT_LENGTH = 50;

    public void SetPopulationSize(Slider slider)
    {
        POPULATION_SIZE = (int) slider.value;
        populationText.text = "Population size: " + POPULATION_SIZE;
    }

    public void SetTerrainHardness(Slider slider)
    {
        TERRAIN_HARDNESS = (int)slider.value;
        terrainHardnessText.text = "Terrain hardness: " + TERRAIN_HARDNESS;
    }

    public void SetKillTimer(Slider slider)
    {
        KILL_TIMER = (int)slider.value;
        killTimerText.text = "Kill timer: " + KILL_TIMER + "s";
    }

    public void SetSimSpeed(Slider slider)
    {
        SIMULATION_SPEED = (int)slider.value;
        simSpeedText.text = "Sim. speed: " + SIMULATION_SPEED + "x";
        Time.timeScale = SIMULATION_SPEED;
    }

    public void SetIndividuallyVSFromParents(Slider slider)
    {
        INDIVIDUALLY_MUTATED = (int)slider.value;
        MUTATED_FROM_PARENTS = 100 - INDIVIDUALLY_MUTATED;
        individualVsFromParentsText.text = "Individual/from parents: " + INDIVIDUALLY_MUTATED + "/" + MUTATED_FROM_PARENTS + "%";
    }
}
