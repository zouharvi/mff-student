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