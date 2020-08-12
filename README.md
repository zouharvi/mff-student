# SMAKE Simple Markable And Keyword Extractor

First version based on [RAKE](https://catalogimages.wiley.com/images/db/pdf/9780470749821.excerpt.pdf).

## Run times

Measured on 100 huth2003 documents (1000-1099) on hot run.

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