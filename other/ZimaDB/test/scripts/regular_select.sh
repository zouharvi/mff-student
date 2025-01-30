#!/bin/bash

../../bin/zimadb <<EOF
.open ahoj.zima
create table wild (a int);
insert into wild (a) values (1);
insert into wild (a) values (1);
insert into wild (a) values (2);
select a from wild;
EOF