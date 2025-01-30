using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EndKillZone : MonoBehaviour {

    public GameManager gm;

    void OnTriggerEnter2D(Collider2D other)
    {
        if (other.transform.parent.GetComponentInChildren<CreatureAssembler>().dead)
            return;

        // TODO: test this game object is a creature
        if (gm.doOfferEnd)
        {
            gm.OfferEnd();
            gm.doOfferEnd = false;
        } else {
            gm.PrematureSubsequentGame();
        }
    }
}

