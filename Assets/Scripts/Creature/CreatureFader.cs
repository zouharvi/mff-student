using System.Collections;
using System.Collections.Generic;
using UnityEngine;

// required, but messes up prefabs:
// [RequireComponent(typeof(MeshRenderer))]
public class CreatureFader : MonoBehaviour {

    private bool fading = false;
    private float alpha = 1.0f;
    private Color curColor;
    private new MeshRenderer renderer;
    public static readonly float DURATION = 2;

    private void Start()
    {
        // testing only:
        // Invoke("StartFadingToParentDeath", 2);
    }

    public void StartFadingToParentDeath () {
        Debug.Log("started fading");
        fading = true;
        renderer = gameObject.GetComponent<MeshRenderer>();
        curColor = new Color(renderer.material.color.r, renderer.material.color.g, renderer.material.color.b, 1);
    }
	
	void Update () {
		if(fading)
        {
            alpha -= Time.deltaTime / DURATION;
            UpdateAlpha();
            if (alpha <= 0)
                Destroy(gameObject.transform.parent.gameObject);
        }
	}

    private void UpdateAlpha()
    {
        curColor.a = alpha;
        //curColor.r = alpha;
        renderer.material.color = curColor;
    }
}
