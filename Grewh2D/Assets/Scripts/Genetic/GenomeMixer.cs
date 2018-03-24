using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GenomeMixer {
    private struct PROB
    {
        public static float NEW_WHEEL_POINT = 0.2f;
        public static float REMOVE_WHEEL_POINT = 0.2f;
        public static float WHEEL_CHANGE = 0.3f;

        public static float NEW_TORSO_POINT = 0.2f;
        public static float REMOVE_TORSO_POINT = 0.2f;
        public static float TORSO_POINT_CHANGE = 0.3f;
    }

    public static Genome Mutate(Genome g)
    {
        Genome r = new Genome(g);

        // TODO: make this dependend on the number of present wheels
        if (Random.value < PROB.NEW_WHEEL_POINT)
            r.wheels.Add(new CreatureWheelDef());   
        if (Random.value < PROB.REMOVE_WHEEL_POINT && r.wheels.Count != 0)
            r.wheels.RemoveAt(Random.Range(0, r.wheels.Count));
        // modify individual wheels
        for (int i = 0; i < g.wheels.Count; i++)
        {
            if (Random.value >= PROB.WHEEL_CHANGE)
            {
                g.wheels[i].size = Mathf.Clamp(g.wheels[i].size + Random.value * 0.3f - 0.15f, 0.1f, 1);
                g.wheels[i].torque = Mathf.Clamp(g.wheels[i].torque + Random.value * 0.3f - 0.15f, -0.25f, 1);
                g.wheels[i].speed = Mathf.Clamp(g.wheels[i].speed + Random.value * 0.3f - 0.15f, -1, 1);
                g.wheels[i].position = new Vector2(
                    Mathf.Clamp(g.wheels[i].position.x + Random.value * 0.3f - 0.15f, -1, 1),
                    Mathf.Clamp(g.wheels[i].position.y + Random.value * 0.3f - 0.15f, -1, 1)
                );
            }
        }

        // TODO: make this dependend on the number of present points
        if (Random.value < PROB.NEW_TORSO_POINT)
            r.torso.points.Add(new Vector2(Random.value * 2 - 1, Random.value * 2 - 1));
        if (Random.value < PROB.REMOVE_TORSO_POINT && r.torso.points.Count > 3)
            r.torso.points.RemoveAt(Random.Range(0, r.torso.points.Count));

        // modify individual torso points
        for (int i = 0; i < g.torso.points.Count; i++)
        {
            if (Random.value >= PROB.TORSO_POINT_CHANGE)
            {
                g.torso.points[i] = new Vector2(
                    Mathf.Clamp(g.torso.points[i].x + Random.value * 0.3f - 0.15f, -1, 1),
                    Mathf.Clamp(g.torso.points[i].y + Random.value * 0.3f - 0.15f, -1, 1)
                );
            }
        }

        return r;
    }

    public static Genome FromParents(Genome g1, Genome g2)
    {
        return new Genome(g1, g2);
    }
    
    public static List<Genome> FromPopulation(List<Genome> oldPopulation)
    {
        int cCount = 0;
        List<Genome> newPopulation = new List<Genome>();
        for (int i = 0; i < oldPopulation.Count; i++)
            if (oldPopulation[i].cretin)
            {
                oldPopulation[i] = new Genome(); // replace genomes incapable of movement
                cCount++;
            }
        Debug.Log("cCount: " + cCount.ToString() + " pop size: " + oldPopulation.Count);
        newPopulation.Add(oldPopulation[0]); // the best one carries over

        for (int i = 0; i < oldPopulation.Count * GameGenSettings.INDIVIDUALLY_MUTATED/100.0f; i++)
                newPopulation.Add(Mutate(oldPopulation[i]));
        for (int i = oldPopulation.Count * GameGenSettings.INDIVIDUALLY_MUTATED / 100; i < oldPopulation.Count; i++)
        // URGENT TODO: think of a better function for choosing two parents
            newPopulation.Add(
                Mutate(FromParents(oldPopulation[0], oldPopulation[1]))
                );

        // fill/remove if count doesnt match properly (rounding errors)
        if(newPopulation.Count > GameGenSettings.POPULATION_SIZE)
            newPopulation.RemoveRange(GameGenSettings.POPULATION_SIZE - 1, newPopulation.Count - GameGenSettings.POPULATION_SIZE);
        while (newPopulation.Count < GameGenSettings.POPULATION_SIZE)
            newPopulation.Add(new Genome());
        return newPopulation;
    }
}
