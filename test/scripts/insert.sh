#!/bin/bash

../../bin/zimadb <<EOF
.open ahoj.zima
create table pokus (a int);
insert into pokus (a) values (1);

insert into pokus_spatne (a) values (1);

create table pokus_spatne (a int);
insert into pokus_spatne (b) values (1);
EOF