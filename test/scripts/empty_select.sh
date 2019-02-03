#!/bin/bash

rm -rf ahoj.zima
echo -e ".open ahoj.zima\n create table pokus (a int);\n select * from pokus;" | ../../bin/zimadb
