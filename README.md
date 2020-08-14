# SMAKE Simple Markable And Keyword Extractor

First version based on [RAKE](https://catalogimages.wiley.com/images/db/pdf/9780470749821.excerpt.pdf).

## Optimization

### Round 1

Measured on 100 huth2003 documents (1000-1099) on a hot run.

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


### Round 2

Measured on all huth2003 documents on a hot run.

|description|user|
|-|-|
|base (keywords cleanup)|83s|
|document word->occurence mapping|3.6s|

### Python comparison

Comparison to an almost™ equivalent code in Python on 5x inflated Hulth 2003 dataset (5000 docs).

|program|user|hit ratio|
|-|-|-|
|Python 3.8.2|5.20s|1.498|
|Rust debug|13.21s|1.539|
|Rust release|0.76s|1.539|

## Dataset

Hulth 2003 used:

```
@inproceedings{hulth-2003-improved,
    title = "Improved Automatic Keyword Extraction Given More Linguistic Knowledge",
    author = "Hulth, Anette",
    booktitle = "Proceedings of the 2003 Conference on Empirical Methods in Natural Language Processing",
    year = "2003",
    url = "https://www.aclweb.org/anthology/W03-1028",
    pages = "216--223",
}
```