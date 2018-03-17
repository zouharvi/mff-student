using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CreatureBreeder : MonoBehaviour {

    public GameObject blankCreature;
    List<Genome> population;
    List<GameObject> instances;

    public static int POPULATION_SIZE = 10;

    public void ResetPopulation () {
        population = new List<Genome>();
        for (int i = 0; i < POPULATION_SIZE; i++)
            population.Add(new Genome()); // randomization constructor
	}

    public void CleanUp()
    {
        // kill old ones
        if (instances != null)
        {
            foreach (GameObject go in instances)
                Destroy(go);
        }

    }

    public void InstantiateNew()
    {
        instances = new List<GameObject>();
        foreach(Genome g in population)
        {
            GameObject creature = Instantiate(blankCreature);
            CreatureAssembler assembler = creature.GetComponent<CreatureAssembler>();
            assembler.Setup(g);
        }
    }

    // Update is called once per frame
    void Update () {
		
	}
}
