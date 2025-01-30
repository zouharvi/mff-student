#!/bin/bash

../../bin/zimadb <<EOF
.open ahoj.zima
CREATE TABLE rostlinka (age int, name varchar);
INSERT INTO rostlinka (age, name) values (24, "Sofie");
INSERT INTO rostlinka (name, age) values ("Oldřich", 11);
DELETE FROM rostlinka WHERE age = 14;
DELETE FROM rostlinka WHERE age > 14;
EOF