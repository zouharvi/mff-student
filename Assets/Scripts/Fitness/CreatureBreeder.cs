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
            instances.Add(creature);
        }
    }

    void Update () {
		//TODO: sort every second
	}

    /// <summary>
    /// Sorting is happening here, be careful with this
    /// </summary>
    /// <param name="pos">0..N-1 or -1..-N</param>
    /// <returns></returns>
    public GameObject Best(int pos)
    {
        instances.Sort(AReferee.CREATURE_COMPARER);
        if(pos >= 0)
        {
            pos = Mathf.Min(instances.Count-1, pos);
            // pos == -1 should never happen
            return instances[pos];
        } else
        {
            pos = Mathf.Max(-instances.Count, pos);
            // pos == 0 should never happen
            return instances[instances.Count + pos];
        }
    }


}
