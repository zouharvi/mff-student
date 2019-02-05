#!/bin/bash

../../bin/zimadb <<EOF
.open ahoj.zima
create table pokus (a int);
create table hlemyzd (a int, b varchar(150), c VaRCHAR, d double);
create table dikobraz (a int primary key, b int);
EOF