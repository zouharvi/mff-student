using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CreatureAssembler : MonoBehaviour {
    public static int drawOrder = 0;

    //CreatureDescriptor descriptor;
    public GameObject blankWheel, blankTorso;

    public Genome genome;
    public CreatureTorso torso;
    public List<CreatureWheel> wheels = new List<CreatureWheel>();

    /// <summary>
    /// Randomization constructor
    /// </summary>
    public void Setup()
    {
        Setup(new Genome());
    }

    /// <summary>
    /// Genome constructor
    /// </summary>
    public void Setup(Genome genome)
    {
        this.genome = genome;
        torso = new CreatureTorso(genome.torso);
        foreach (CreatureWheelDef cwd in genome.wheels)
            wheels.Add(new CreatureWheel(cwd));
        gameObject.transform.position += new Vector3(0, 0, -3 * (drawOrder++));
        torso.Instantiate(blankTorso, transform);
        List<Vector2> newPoints = new List<Vector2>();

        int i = 0;
        foreach (CreatureWheel cWheel in wheels)
        {
            // adds wheel positions
            newPoints.Add(cWheel.def.position);
            cWheel.Instantiate(blankWheel, transform, torso.gameObject.GetComponent<Rigidbody2D>(), i++);
        }

        // set true collider points and create pretty polygon shape
        torso.ExtendPolygon(newPoints);
        // create mesh
        torso.CreateGraphics();
    }

    // Use this for initialization
    void Start () {
    }


    public void Kill()
    {
        // TODO: destroy gracefully
        Destroy(gameObject);
    }
}
