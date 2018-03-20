using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Genome {
    public List<CreatureWheelDef> wheels = new List<CreatureWheelDef>();
    public CreatureTorsoDef torso;

    public Genome(Genome g)
    {
        foreach (CreatureWheelDef cwd in g.wheels)
            wheels.Add(new CreatureWheelDef(cwd));
        torso = new CreatureTorsoDef(torso);
    }

    public Genome(Genome g1, Genome g2)
    {
        for (int i = 0; i < g1.wheels.Count && i < g2.wheels.Count; i++)
        {
            // just plain average here, could be improved
            CreatureWheelDef cwd = new CreatureWheelDef();
            cwd.size = (g1.wheels[i].size + g2.wheels[i].size) / 2.0f;
            cwd.torque = (g1.wheels[i].torque + g2.wheels[i].torque) / 2.0f;
            cwd.speed = (g1.wheels[i].speed + g2.wheels[i].speed) / 2.0f;
            cwd.position = (g1.wheels[i].position + g2.wheels[i].position) / 2.0f;
            wheels.Add(cwd);
        }
        torso = new CreatureTorsoDef(0);
        for (int i = 0; i < g1.torso.points.Count && i < g2.torso.points.Count; i++)
        {
            if (Random.value >= 0.5f)
                torso.points.Add(g1.torso.points[i]);
            else
                torso.points.Add(g2.torso.points[i]);
        }
    }

    public Genome()
    {
        wheels.Add(new CreatureWheelDef());
        wheels.Add(new CreatureWheelDef());
        wheels.Add(new CreatureWheelDef());
        torso = new CreatureTorsoDef(5);
    }

    // Use this for initialization
    void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		
	}
}
