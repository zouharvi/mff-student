#!/bin/bash

../../bin/zimadb <<EOF
.open ahoj.zima
create table pokus (a int);
insert into pokus (a) values (1);
insert into pokus (a) values (2);
insert into pokus (a) values (2);
TRUNCATE TABLE pokus;
SELECT * FROM pokus;
EOF