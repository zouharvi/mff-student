#!/bin/bash

rm -rf ahoj.zima
echo -e ".open ahoj.zima\n create table wild (a int);\n insert into wild (a) values (1);\n select a from wild;" | ../../bin/zimadb
