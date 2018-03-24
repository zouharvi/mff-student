using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CreatureTorso
{
    public CreatureTorsoDef def;
    public GameObject gameObject;

    /// <summary>
    /// Randomization constructor, obsolete!
    /// </summary>
    public CreatureTorso()
    {
        def = new CreatureTorsoDef(5);
    }

    /// <summary>
    /// Def constructor
    /// </summary>
    public CreatureTorso(CreatureTorsoDef def)
    {
        this.def = def;
    }

    public void ExtendPolygon(List<Vector2> newPoints)
    {
        def.points.AddRange(newPoints);
        CustomMath.CreatePrettyPolygon(ref def.points);
        Vector2[] pointsArr = new Vector2[def.points.Count];
        //List<int> toRemove = new List<int>();
        for (int i = 0; i < def.points.Count; i++)
        {
            pointsArr[i] = def.points[i] * CreatureTorsoDef.MAX_WIDTH;
            // remove points too close to each other (causes problems with tesselation)
            /* THIS NEEDS TO BE RESOLVED NICELY
            if (i > 0)
            {
                if(Mathf.Abs(Mathf.Atan2(def.points[i].x, def.points[i].y) - Mathf.Atan2(def.points[i-1].x, def.points[i-1].y)) < 0.05)
                {
                    float dx = Random.value;
                    float dy = Random.value;
                    def.points[i] = new Vector2(
                        Mathf.Clamp(def.points[i].x + dx, -1, 1),
                        Mathf.Clamp(def.points[i].y + dy, -1, 1)
                        );
                    def.points[i-1] = new Vector2(
                        Mathf.Clamp(def.points[i-1].x - dx, -1, 1),
                        Mathf.Clamp(def.points[i-1].y - dy, -1, 1)
                        );
                    i--;
                    // a chance of getting into an infinite loop are infinitesimal
                }
            }
             */
        }
        gameObject.GetComponent<PolygonCollider2D>().points = pointsArr;
    }

    public GameObject Instantiate(GameObject blankTorso, Transform parent)
    {
        gameObject = GameObject.Instantiate(blankTorso, parent);
        return gameObject;
    }

    public void CreateGraphics()
    {
        // TODO: base color on creature genes
        gameObject.GetComponent<DrawPolygon>().CreateGraphicsFromPolygonCollider(Random.ColorHSV());
    }
}
