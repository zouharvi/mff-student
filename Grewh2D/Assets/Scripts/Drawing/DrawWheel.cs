using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(MeshRenderer))]
[RequireComponent(typeof(MeshFilter))]
public class DrawWheel : MonoBehaviour {
    public void CreateWheelGraphics() {
        MeshRenderer meshRenderer = gameObject.GetComponent<MeshRenderer>();
        meshRenderer.material.color = Random.ColorHSV(); // TODO: pick color based on wheel genes
    }
}
