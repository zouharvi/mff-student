# SMAKE Simple Markable And Keyword Extractor

First version based on RAKE (Automatic Keyword Extraction from Individual Documents), but the formula changed later significantly. The plan is to create a manual feature extractor and feed these vectors to two dense layers with TensorFlow binding.

## Speed

### Language comparison comparison

Out of curiosity the program (at f9fdd9d4) was rewritten to an almost™ equivalent code in Python. It was then tested on 5x supersampled Hulth 2003 dataset (5000 docs).

|program|user|hit ratio|
|-|-|-|
|Python 3.8.2|5.20s|1.498|
|Rust debug|13.21s|1.539|
|Rust release|0.76s|1.539|
|CS .net core release|4.8|1.15|

### Optimization

The first round was measured on 100 huth2003 documents (1000-1099) on a hot run.

|description|user|
|-|-|
|base|4.3s|
|DocAll introduction|4.3s|
|crf removal|4.2s|
|frq_map access optimization|3.8s|
|deg_map access optimization|3.7s|
|lazy_static candidate regex building|2.4s|
|lazy_static split regex building|0.89s|
|uncontr wrapping|0.85s|
|keywords cleanup|0.82s|

The second run was measured on all huth2003 documents (1000) on a hot run.

|description|user|
|-|-|
|base (keywords cleanup)|83s|
|document word->occurence mapping|3.6s|


## Dataset

Test runs are based on 1000 docs from Hulth 2003.

## References

```
@inproceedings{hulth-2003-improved,
    title = "Improved Automatic Keyword Extraction Given More Linguistic Knowledge",
    author = "Hulth, Anette",
    booktitle = "Proceedings of the 2003 Conference on Empirical Methods in Natural Language Processing",
    year = "2003",
    url = "https://www.aclweb.org/anthology/W03-1028",
    pages = "216--223",
}
@inbook{inbook,
    author = {Rose, Stuart and Engel, Dave and Cramer, Nick and Cowley, Wendy},
    year = {2010},
    month = {03},
    pages = {1 - 20},
    title = {Automatic Keyword Extraction from Individual Documents},
    isbn = {9780470689646},
    journal = {Text Mining: Applications and Theory},
    doi = {10.1002/9780470689646.ch1}
}
```