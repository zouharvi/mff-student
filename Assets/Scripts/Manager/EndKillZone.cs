using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EndKillZone : MonoBehaviour {

    public GameManager gm;

    void OnTriggerEnter2D(Collider2D other)
    {
        Debug.Log("trigger enter");
        // TODO: test this game object is a creature
        if (gm.doOfferEnd)
        {
            gm.OfferEnd();
            gm.doOfferEnd = false;
        } else {
            Debug.Log("premature subsequent?");
            gm.PrematureSubsequentGame();
        }
    }
}

