using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DistanceReferee : AReferee {

    private static readonly float MINIMAL_PER_SECOND = 1;
    private float initTime;

    public override float GetScore()
    {
        float expected = MINIMAL_PER_SECOND * (Time.time - initTime);
        // parentheses next time, pls
        return -expected - initX + torso.transform.position.x;
    }


    public override float GetAbsolute()
    {
        return torso.transform.position.x- initX;
    }

    public override bool IsCretin()
    {
        // incapable of movement
        return 7 >  torso.transform.position.x - initX;
    }

    private float initX;
    private GameObject torso;
    public override void Start()
    {
        initTime = Time.time;
        torso = gameObject.GetComponent<CreatureAssembler>().torso.gameObject;
        initX = torso.transform.position.x;
    }
}
