using UnityEngine;

public class CreatureWheel {

    public CreatureWheelDef def;
    public GameObject gameObject;

    /// <summary>
    /// Randomization constructor, obsolete!
    /// </summary>
    public CreatureWheel()
    {
        def = new CreatureWheelDef();
    }

    /// <summary>
    /// Def constructor
    /// </summary>
    public CreatureWheel(CreatureWheelDef def)
    {
        this.def = def;
    }

    public GameObject Instantiate(GameObject blankWheel, Transform parent, Rigidbody2D torsoRigidBody, int order)
    {
        // dirty order trick
        gameObject = GameObject.Instantiate(blankWheel, parent);
        gameObject.transform.localScale = new Vector3(def.size * CreatureWheelDef.MAX_SIZE, def.size * CreatureWheelDef.MAX_SIZE, 1);
        gameObject.transform.localPosition += new Vector3(0, 0, -0.5f * order);
        HingeJoint2D hingeJoint = gameObject.GetComponent<HingeJoint2D>();
        hingeJoint.connectedBody = torsoRigidBody;
        hingeJoint.connectedAnchor = def.position;

        if (def.torque < 0) // turn motor off on negative torque
            hingeJoint.useMotor = false;
        else
        {
            JointMotor2D motor = hingeJoint.motor;
            motor.motorSpeed = CreatureWheelDef.MAX_SPEED * def.speed;
            motor.maxMotorTorque = CreatureWheelDef.MAX_TORQUE * def.torque;
            hingeJoint.motor = motor;
        }

        gameObject.GetComponent<DrawWheel>().CreateWheelGraphics();
        return gameObject;
    }
}
