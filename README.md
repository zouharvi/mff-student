![ZimaDB logo](https://raw.githubusercontent.com/zouharvi/ZimaDB/master/doc_meta/logo/zimadb.png)

SQLite-like database implementation from scratch (semestral project by Petr Chmel and Vilém Zouhar).

[![Build Status](https://travis-ci.org/zouharvi/ZimaDB.svg?branch=master)](https://travis-ci.org/zouharvi/ZimaDB)
[![Build Status](https://travis-ci.org/zouharvi/ZimaDB.svg?branch=develop)](https://travis-ci.org/zouharvi/ZimaDB)


## Documentation
Read concept assignment in `doc_meta/concept.md`.

## Build
`make` (**ZimaDB** is already the default target)

`make run` will build & run **ZimaDB**.

`make re` will clean & run **ZimaDB**.

We used a makefile with a simple cascade, but due to linkage complexity we work in three main directories: `share/`, `engine/` and `core/`.

`engine/` (storage, processor) is maintained by Petr Chmel and `core/` (lexing, parsing) by Vilém Zouhar. 

## Sources
- [Never write your own database](https://medium.com/@terrycrowley/never-write-your-own-database-736f704c780) by Terry Crowley
- [Database systems: the complete book](https://vufind.techlib.cz/Record/000144487#description) by Hector Garcia-Molina, Jeffrey D. Ullman, Jennifer Widom
- [How does a database work](https://cstack.github.io/db_tutorial/) by Connor Stack

## Requirements
- The `readline` library is needed to build the program. It can be obtained from most of the maintained repositories, eg. `dnf install readline-devel`.
