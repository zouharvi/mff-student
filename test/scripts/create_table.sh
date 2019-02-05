#!/bin/bash

../../bin/zimadb <<EOF
.open ahoj.zima
create table pokus (a int);
create table hlemyzd (a int, b varchar(150), c VaRCHAR, d double, tttttt TINYint);
create table pokus (a int ASC, b int DESC);
create table pokus2 (a int ASC, b int DESC);
create table dikobraz (a int PRIMARY KEY DESC, b int);
create table rostlinka (a int PRIMARY KEY, b int PRIMARY KEY);
EOF