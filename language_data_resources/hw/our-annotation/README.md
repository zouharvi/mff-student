### Annotation

This annotation is relevant to the Ptakopět/Bergamot project ([ptakopet.vilda.net](https://ptakopet.vilda.net)).

Users were asked to work with an MT system with backward translation and quality estimation. While they don't speak German, they were tasked with the translation of Czech sentences to German using this tool.
Annotating the quality of such translations is key in further research.

### Participants

Martin Stunda (`strip_1.csv`), Vilém Zouhar (`strip_0.csv`)

### Format

The file is comma separated: `SCORE,ID,SRC,MT`:
- `SCORE` is a value from `0` to `1.0`
- `ID` is the stimuli id, it can be ignored for this purpose
- `SRC` original sentence
- `MT` machine translated sentence

### Note
Commas in fields are escaped to `&#44;`

### Program

The values are normalized with respect to each annotator and then binarized by comparison to 0.5.

Run `make all` to get the output.


### Output

```
IAA: 64.00%
By chance: 53.60%
Cohen's Kappa:: 22.41%
```

The low Kappa can be explained by our lack of training in both translatology and the German language (both annotators are B1).
