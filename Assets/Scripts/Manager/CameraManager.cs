using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraManager : MonoBehaviour {

    private CreatureBreeder breeder;
    private int state = 0;
    private static readonly int MAX_STATE = 3;

    public UnityEngine.UI.Text textToChange;

    // general vars
    public float repeatInterval;

    // follow vars
    Transform transformToFollow;

    // camera drag vars
    public float dragSpeed;
    public float cameraYMin;
    public float cameraYMax;
    private Vector3 dragOrigin;
    private string[] followTexts = { "> Second best", "> Last", "> Free movement", "> Leader"};

    private void Start()
    {
        breeder = gameObject.GetComponent<CreatureBreeder>();
        InvokeRepeating("Refresh", 2, repeatInterval);
    }

    public void NextState()
    {
        state++;
        if (state > MAX_STATE)
            state = 0;
        textToChange.text = followTexts[state];
        Refresh();
    }
    
    public void InitState()
    {
        state = 0;
        // Don't refresh here, game objects are not ready
    }

    private void Refresh() {
        Debug.Log("refreshed");

        switch (state)
        {
            case 0:
                // follow leader
                transformToFollow = breeder.Best(0).GetComponent<CreatureAssembler>().torso.gameObject.transform;
                break;
            case 1:
                // follow second best
                transformToFollow = breeder.Best(1).GetComponent<CreatureAssembler>().torso.gameObject.transform;
                break;
            case 2:
                // follow last
                transformToFollow = breeder.Best(-1).GetComponent<CreatureAssembler>().torso.gameObject.transform;
                break;
            case 3:
                // free movement
                // TODO: !!
                break;
        }
    }

    void Update()
    {
        switch (state)
        {
            case 0:
            case 1:
            case 2:
                if (transformToFollow == null)
                    break;
                Vector3 t = transformToFollow.position;
                t.z = Camera.main.transform.position.z;
                Camera.main.transform.position = t;
                break;
            case 3:
                if (Input.GetMouseButtonDown(0))
                {
                    dragOrigin = Input.mousePosition;
                    break;
                }

                if (!Input.GetMouseButton(0)) break;

                Vector3 pos = Camera.main.ScreenToViewportPoint(Input.mousePosition - dragOrigin);
                Vector3 move = new Vector3(pos.x * -dragSpeed, pos.y * -dragSpeed, 0);

                Vector3 d = Camera.main.transform.position + move;

                d.y = Mathf.Clamp(d.y, cameraYMin, cameraYMax);
                Camera.main.transform.position = d; // Translate(move, Space.World);
                
                break;
        }
    }
}
