using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public abstract class AReferee : MonoBehaviour {

    public abstract float GetScore();   // score is absolute
    public virtual void Update() {  }
    public virtual void Start() {  }

    public static CreatureComparer CREATURE_COMPARER = new CreatureComparer();
    public class CreatureComparer : IComparer<GameObject>
    {
        public int Compare(GameObject c1, GameObject c2)
        {
            return (int)(100 * c1.GetComponent<AReferee>().GetScore() - 100 * c2.GetComponent<AReferee>().GetScore());
        }
    }
}