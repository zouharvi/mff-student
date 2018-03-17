using UnityEngine;

public class CreatureWheel {
    public Vector2 position; // [0, 1]
    public float speed;      // [-1, 1]
    public float torgue;     // (-infty, 1] negative turns off the motor
    public float size;       // [0, 1]

    public const int MAX_SIZE   = 2;
    public const int MAX_SPEED  = 1000;
    public const int MAX_TORQUE = 20000;

    public GameObject gameObject;

    /// <summary>
    /// Randomization constructor
    /// </summary>
    public CreatureWheel()
    {
        position = new Vector2(Random.value * 2 - 1, Random.value * 2 - 1);
        speed  = Random.value*2-1;
        torgue = Random.value * 1.5f - 0.5f;
        size   = Random.value*0.9f+0.1f;
    }

    /// <summary>
    /// Absolute constructor
    /// </summary>
    public CreatureWheel(Vector2 position, float speed, float size)
    {
        this.position = position;
        this.speed = speed;
        this.size = size;
    }

    public GameObject Instantiate(GameObject blankWheel, Transform parent, Rigidbody2D torsoRigidBody)
    {
        gameObject = GameObject.Instantiate(blankWheel, parent);
        gameObject.transform.localScale = new Vector3(size * MAX_SIZE, size * MAX_SIZE, 1);
        HingeJoint2D hingeJoint = gameObject.GetComponent<HingeJoint2D>();
        hingeJoint.connectedBody = torsoRigidBody;
        hingeJoint.connectedAnchor = position;

        if (torgue < 0) // turn motor off on negative torque
            hingeJoint.useMotor = false;
        else
        {
            JointMotor2D motor = hingeJoint.motor;
            motor.motorSpeed = MAX_SPEED * speed;
            motor.maxMotorTorque = MAX_TORQUE * torgue;
            hingeJoint.motor = motor;
        }

        gameObject.GetComponent<DrawWheel>().CreateWheelGraphics();
        return gameObject;
    }
}
