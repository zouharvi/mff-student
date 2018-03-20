using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Genome {
    public List<CreatureWheelDef> wheels = new List<CreatureWheelDef>();
    public CreatureTorsoDef torso;

    public Genome(Genome g)
    {
        foreach(CreatureWheelDef cwd in g.wheels)
            wheels.Add(new CreatureWheelDef(cwd));
        torso = new CreatureTorsoDef(torso);
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
