using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CreatureAssembler : MonoBehaviour {

    //CreatureDescriptor descriptor;
    public GameObject blankWheel, blankTorso;

    private Genome genome;
    public CreatureTorso torso;
    public List<CreatureWheel> wheels = new List<CreatureWheel>();

    /// <summary>
    /// Randomization constructor
    /// </summary>
    public void Setup()
    {
        torso = new CreatureTorso();
        wheels.Add(new CreatureWheel());
        wheels.Add(new CreatureWheel());
        wheels.Add(new CreatureWheel());
    }

    /// <summary>
    /// Genome constructor
    /// </summary>
    public void Setup(Genome genome)
    {
        this.genome = genome;
    }

    // Use this for initialization
    void Start () {
        Setup();

        torso.Instantiate(blankTorso, transform);
        List<Vector2> newPoints = new List<Vector2>();

        foreach (CreatureWheel cWheel in wheels)
        {
            // adds wheel positions
            newPoints.Add(cWheel.position);
            cWheel.Instantiate(blankWheel, transform, torso.gameObject.GetComponent<Rigidbody2D>());
        }

        // set true collider points and create pretty polygon shape
        torso.ExtendPolygon(newPoints);
        // create mesh
        torso.CreateGraphics();
    }

}
