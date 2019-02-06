#!/bin/bash

../../bin/zimadb <<EOF
open a.zima
CREATE TABLE a (b int, c int);
INSERT INTO a (b, c) VALUES (0, 1);
INSERT INTO a (b, c) VALUES (2, 3);
SELECT b, c FROM a;
INSERT INTO a (b, c) VALUES (4, 5);
EOF