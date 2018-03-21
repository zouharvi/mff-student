using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GameSettings : MonoBehaviour {

    public Text populationText, terrainHardnessText, killTimerText;
    public int POPULATION_SIZE = 20;
    public int TERRAIN_HARDNESS = 25;
    public int KILL_TIMER = 25;
    public int SIMULATION_SPEED = 1;

    // percentages, must sum to 100
    public int SUPER_CREATURES = 5;
    public int INDIVIDUALLY_MUTATED = 20;
    public int MUTATED_FROM_PARENTS = 75;

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
}
