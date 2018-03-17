using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(MeshRenderer))]
[RequireComponent(typeof(MeshFilter))]
public class DrawPolygon : MonoBehaviour {

    public Shader shader;

    /// <summary>
    /// Create graphics complete with mesh from polygon collider points
    /// </summary>
    /// <param name="shiftAmountX">offset added to polygon X</param>
    /// <param name="shiftAmountY">offset added to polygon Y</param>
	public void CreateGraphicsFromPolygonCollider(float shiftAmountX = 0, float shiftAmountY = 0) {
        PolygonCollider2D collider = gameObject.GetComponent<PolygonCollider2D>();
        Vector2[] vertices2D = collider.points;
        Vector2 shiftVector = new Vector2(shiftAmountX, shiftAmountY);
        for (int i = 0; i < vertices2D.Length; i++)
            vertices2D[i] += shiftVector;

        // Use the triangulator to get indices for creating triangles
        Triangulator tr = new Triangulator(vertices2D);
        int[] indices = tr.Triangulate();

        // Create the Vector3 vertices
        Vector3[] vertices = new Vector3[vertices2D.Length];
        for (int i = 0; i < vertices.Length; i++)
            vertices[i] = new Vector3(vertices2D[i].x, vertices2D[i].y, 0);

        // Create the mesh
        Mesh msh = new Mesh();
        msh.vertices = vertices;
        msh.triangles = indices;
        msh.RecalculateNormals();
        msh.RecalculateBounds();

        // Set up game object with mesh;
        MeshRenderer meshRenderer = gameObject.GetComponent<MeshRenderer>();
        meshRenderer.material.color = Random.ColorHSV(); // TODO: pick color based on polygon genes
        MeshFilter filter = gameObject.GetComponent<MeshFilter>();
        filter.mesh = msh;
    }
}
