#!/bin/bash

rm -rf ahoj.zima
echo -e ".open ahoj.zima\n create table ins (a int);\n insert into ins (a) values (1);" | ../../bin/zimadb
