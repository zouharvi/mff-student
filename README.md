# ZimaDB
SQLite-like database implementation from scratch (semestral project by Petr Chmel and Vilém Zouhar).

## Documentation
Read concept assignment in `doc/concept.md`.

## Build
`make zimadb`

We use makefile with a simple cascade:
`zimadb` requires all of the source files to be compiled as well as `libzimadbe.a`, located in `engine/`. This folder contains its own makefile with `engine` target, which requires all of this folders source files to be compiled. The product is `engine/bin/libzimadbe.a` which is linked back with the rest of top level zimadb objects.

## Sources
- [Never write your own database](https://medium.com/@terrycrowley/never-write-your-own-database-736f704c780) by Terry Crowley
- [Database systems: the complete book](https://vufind.techlib.cz/Record/000144487#description) by Hector Garcia-Molina, Jeffrey D. Ullman, Jennifer Widom
- [How does a database work](https://cstack.github.io/db_tutorial/) by Connor Stack