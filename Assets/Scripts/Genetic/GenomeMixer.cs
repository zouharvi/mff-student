using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GenomeMixer {
    private struct PROB
    {
        public static float NEW_WHEEL_POINT = 0.1f;
        public static float REMOVE_WHEEL_POINT = 0.1f;
        public static float NEW_TORSO_POINT = 0.1f;
    }

    public static Genome Mutate(Genome g)
    {
        Genome r = new Genome(g);

        // TODO: make this dependend on the number of present wheels
        if (Random.value < PROB.NEW_WHEEL_POINT)
            r.wheels.Add(new CreatureWheelDef());
        if (Random.value < PROB.REMOVE_WHEEL_POINT && r.wheels.Count != 0)
            r.wheels.RemoveAt(Random.Range(0, r.wheels.Count));


        return r;
    }
}
