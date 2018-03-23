using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class ShowcaseGenomes : MonoBehaviour {

    public GameObject blankCreature;

	// Use this for initialization
	void Start () {
        Physics2D.gravity = new Vector2(0, 0);
        DoShowcase();
	}

    public static List<Genome> genomes = new List<Genome>();
    private List<GameObject> displayed = new List<GameObject>();
    public void DoShowcase()
    {
        foreach (GameObject go in displayed)
            Destroy(go);

        displayed = new List<GameObject>();
        genomes = new List<Genome>();
        for (int i = 0; i < 21; i++)
            genomes.Add(new Genome());

        CreatureAssembler.drawOrder = 0;
        for(int i = 0; i < 21; i++)
        {
            GameObject creature = Instantiate(blankCreature);
            displayed.Add(creature);
            CreatureAssembler assembler = creature.GetComponent<CreatureAssembler>();
            assembler.Setup(genomes[i]);
            assembler.DownplayForShowcase(new Vector3((i%7)*10, -((int) i/7)*10, 0));
        }
    }

    public void StartGame()
    {
        Initiate.Fade("Scenes/MainScene", Color.black, 1f);
//        SceneManager.LoadScene("Scenes/MainScene");
    }

    public GameObject aboutInfo;
    public void HideInfo()
    {
        aboutInfo.SetActive(false);
    }

    public void ShowInfo()
    {
        aboutInfo.SetActive(true);
    }
}
