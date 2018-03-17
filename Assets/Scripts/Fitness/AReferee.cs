using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public abstract class AReferee : MonoBehaviour {

    public abstract float GetScore();   // score is absolute
    public virtual void Update() {  }
    public virtual void Start() {  }
}