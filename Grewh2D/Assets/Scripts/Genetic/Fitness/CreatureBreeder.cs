using System.Collections;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;

public class CreatureBreeder : MonoBehaviour {

    public GameObject blankCreature;
    public List<Genome> population;
    List<GameObject> instances;
    List<Genome> killed;
    public List<float> killedAbsolutes;

    private float killTimeAcc = 0;

    public void ResetPopulation () {
        population = new List<Genome>();
        for (int i = 0; i < GameGenSettings.POPULATION_SIZE; i++)
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


    void Update () {
        killTimeAcc += Time.deltaTime;
        if(killTimeAcc >= GameGenSettings.KILL_TIMER)
        {
            killTimeAcc = 0;
            GameObject toKill = Best(-1);
            if (toKill == null)
                return;
            GameObject toBest = Best(0);
            float toKillScore = toKill.GetComponent<AReferee>().GetScore();
            float toBestScore = toBest.GetComponent<AReferee>().GetScore();
            if (toKillScore < 0 || toBestScore-toKillScore > GameGenSettings.KILL_SEGMENT_LENGTH)
            {
                KillGenomed(toKill);
                if(instances.Count <= 1)
                {
                    gameObject.GetComponent<GameManager>().SubsequentGame();
                }
            }
        }
    }

    public void InstantiateFollowingPopulation()
    {
        killed.Reverse();
        population = GenomeMixer.FromPopulation(killed);
        InstantiatePopulation();

    }

    public void ValidateGenomes()
    {
        // URGENT TODO: super important - fix supercreatures
    }

    public void InstantiatePopulation()
    {
        ValidateGenomes();
        CreatureAssembler.drawOrder = 0;
        killTimeAcc = -7;
        killed = new List<Genome>();
        killedAbsolutes = new List<float>();
        instances = new List<GameObject>();
        foreach (Genome g in population)
        {
            GameObject creature = Instantiate(blankCreature);
            CreatureAssembler assembler = creature.GetComponent<CreatureAssembler>();
            assembler.Setup(g);
            instances.Add(creature);
        }
    }

    public void KillOffRest()
    {
        while (instances.Count != 0)
        {
            KillGenomed(Best(-1));
        }
    }

    public void KillGenomed(GameObject toKill)
    {
        AReferee r = toKill.GetComponent<AReferee>();
        killedAbsolutes.Add(r.GetAbsolute());
        Genome g = toKill.GetComponent<CreatureAssembler>().genome;
        // IMP: reshuffle dependencies so that this wouldn't need to happen?
        g.cretin = r.IsCretin();
        killed.Add(g);
        toKill.GetComponent<CreatureAssembler>().Kill();
        instances.RemoveAt(instances.Count - 1);
    }

    /// <summary>
    /// Sorting is happening here, be careful with this
    /// </summary>
    /// <param name="pos">0..N-1 or -1..-N</param>
    /// <returns></returns>
    public GameObject Best(int pos)
    {
        instances = instances.OrderBy(item => -item.GetComponent<AReferee>().GetScore()).ToList();
       // instances.Sort(AReferee.CREATURE_COMPARER);
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
