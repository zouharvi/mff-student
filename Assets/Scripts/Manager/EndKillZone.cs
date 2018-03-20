using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EndKillZone : MonoBehaviour {

    public GameManager gm;

    void OnTriggerEnter2D(Collider2D other)
    {
        // TODO: test this game object is a creature
        gm.OfferEnd();
    }
}

