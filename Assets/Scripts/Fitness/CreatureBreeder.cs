using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CreatureBreeder : MonoBehaviour {

    public GameObject blankCreature;
    List<Genome> population;
    List<GameObject> instances;
    List<Genome> killed;

    public static int POPULATION_SIZE = 10;
    public static float KILL_TIMER = 2;
    public static readonly int KILL_SEGMENT_LENGTH = 50;
    private float killTimeAcc = 0;

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
        killed = new List<Genome>();
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
        killTimeAcc += Time.deltaTime;
        if(killTimeAcc >= KILL_TIMER)
        {
            killTimeAcc = 0;
            Debug.Log("kill tick");
            GameObject toKill = Best(-1);
            GameObject toBest = Best(0);
            float toKillScore = toKill.GetComponent<AReferee>().GetScore();
            float toBestScore = toBest.GetComponent<AReferee>().GetScore();
            Debug.Log("killing, because toKill: " + (toKill.GetComponent<AReferee>().GetScore()).ToString());
            Debug.Log("killing, because toBest: " + (toBest.GetComponent<AReferee>().GetScore()).ToString());
            if (toKillScore < 0 || toBestScore-toKillScore > KILL_SEGMENT_LENGTH)
            {
                Genome g = toKill.GetComponent<CreatureAssembler>().genome;
                g.SaveScore(toBest.GetComponent<AReferee>().GetScore());
                killed.Add(g);
                Destroy(toKill); // TODO: kill gracefully? fade..
                instances.RemoveAt(instances.Count - 1);
                if(instances.Count == 1)
                {
                    Debug.Log("game end");
                }
            }
        }
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
