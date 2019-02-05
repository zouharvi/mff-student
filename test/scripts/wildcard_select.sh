#!/bin/bash

../../bin/zimadb <<EOF
.open ahoj.zima
create table DRAK (a int);
insert into DRAK (a) values (1);
select * from DRAK;
EOF