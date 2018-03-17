using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DistanceReferee : AReferee {
    
    public override float GetFitness()
    {
        throw new System.NotImplementedException();
    }
    
    public override float GetScore()
    {
        return gameObject.transform.position.x - initX;
    }

    public override void Update()
    {
        throw new System.NotImplementedException();
    }


    private float initX;
    public override void Start()
    {
        initX = gameObject.transform.position.x;
    }
}
