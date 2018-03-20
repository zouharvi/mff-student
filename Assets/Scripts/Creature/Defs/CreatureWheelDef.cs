using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CreatureWheelDef
{
    public Vector2 position; // [0, 1]
    public float speed;      // [-1, 1]
    public float torque;     // [-0.5, 1] negative turns off the motor
    public float size;       // [0.1, 1]

    public const int MAX_SIZE = 3;
    public const int MAX_SPEED = 500;
    public const int MAX_TORQUE = 1000;

    public CreatureWheelDef(CreatureWheelDef cwd)
    {
        position = new Vector2(cwd.position.x, cwd.position.y);
        speed = cwd.speed;
        torque = cwd.torque;
        size = cwd.size;
    }

    public CreatureWheelDef()
    {
        position = new Vector2(Random.value * 2 - 1, Random.value * 2 - 1);
        speed = Random.value * 2 - 1;
        torque = Random.value * 1.5f - 0.5f;
        size = Random.value * 0.9f + 0.1f;
    }
}
