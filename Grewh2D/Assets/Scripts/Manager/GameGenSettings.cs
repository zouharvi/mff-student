using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GameGenSettings : MonoBehaviour {

    public Text populationText, terrainHardnessText, gravityText, killTimerText, simSpeedText, individualVsFromParentsText, mutationText;
    public static int POPULATION_SIZE;
    public static int TERRAIN_HARDNESS;
    public static float GRAVITY_Y;
    public static int KILL_TIMER;
    public static int SIMULATION_SPEED;

    private static int MUTATION_RAW;
    public static float MUTATION;

    // percentages, must sum to 100
    public static int INDIVIDUALLY_MUTATED;
    public static int MUTATED_FROM_PARENTS;

    public static int KILL_SEGMENT_LENGTH;

    private void Awake()
    {
        POPULATION_SIZE = 21;
        TERRAIN_HARDNESS = 20;
        GRAVITY_Y = -9.8f;
        KILL_TIMER = 2;
        SIMULATION_SPEED = 1;
        MUTATION_RAW = 20;
        MUTATION = 0.2f;
        INDIVIDUALLY_MUTATED = 20;
        MUTATED_FROM_PARENTS = 80;
        KILL_SEGMENT_LENGTH = 50;
        Debug.Log(Physics2D.gravity.y);
        Physics2D.gravity = new Vector2(0, GRAVITY_Y);
    }

    public void SetPopulationSize(Slider slider)
    {
        POPULATION_SIZE = (int) slider.value;
        populationText.text = "Population: " + POPULATION_SIZE;
    }

    public void SetTerrainHardness(Slider slider)
    {
        TERRAIN_HARDNESS = (int)slider.value;
        terrainHardnessText.text = "Terrain: " + TERRAIN_HARDNESS;
    }

    public void SetGravity(Slider slider)
    {
        GRAVITY_Y = slider.value;
        Physics2D.gravity = new Vector2(0, GRAVITY_Y);
        gravityText.text = "Gravity: " + ( (int) GRAVITY_Y*100.0f)/100.0f + " m/s";
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

    public void SetMutation(Slider slider)
    {
        MUTATION_RAW = (int)slider.value;
        MUTATION = MUTATION_RAW / 100.0f;
        mutationText.text = "Mutation: " + MUTATION_RAW + "%";
    }
}
