using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DistanceReferee : AReferee {

    private static readonly float MINIMAL_PER_SECOND = 1;
    private float initTime;

    public override float GetScore()
    {
        float expected = MINIMAL_PER_SECOND * (Time.time - initTime);
        return -expected - initX + torso.transform.position.x ;
    }

    //private float health = 2;
    //private static readonly float DETEORIATION_SPEED = 0.1f;
    //private static readonly int SEGMENT_LENGTH = 20;
    //private int nextBase = SEGMENT_LENGTH;

    //public override float GetHealth()
    //{
    //    throw new System.NotImplementedException();
    //}

    public override void Update()
    {
        //health -= Time.deltaTime * DETEORIATION_SPEED;
        //if(torso.transform.position.x >= nextBase)
        //{
        //    health++;
        //    nextBase += SEGMENT_LENGTH;
        //}
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
