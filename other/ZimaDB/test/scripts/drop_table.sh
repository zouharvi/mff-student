#!/bin/bash

../../bin/zimadb <<EOF
.open ahoj.zima
create table pokus (a int);
create table hlemyzd (a int, b varchar(150), c VaRCHAR, d double, tttttt TINYint);

TRUNCATE TABLE pokus;
DROP TABLE pokus;
DROP TABLE hlemyzd;
SELECT * FROM pokus;
EOF