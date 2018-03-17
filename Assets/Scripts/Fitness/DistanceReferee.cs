using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DistanceReferee : AReferee {
    
    public override float GetScore()
    {
        return torso.transform.position.x - initX;
    }

    public override void Update()
    {

    }

    private float initX;
    private GameObject torso;
    public override void Start()
    {
        torso = gameObject.GetComponent<CreatureAssembler>().torso.gameObject;
        initX = torso.transform.position.x;
    }
}
