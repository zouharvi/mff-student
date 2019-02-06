#!/bin/bash

../../bin/zimadb <<EOF
.open ahoj.zima
create table DRAK (a int, b int);
insert into DRAK (a, b) values (1, 3);
select * from DRAK;
EOF