#!/bin/bash

./klepl $@ > tmp_klepl
./compile_run.sh $@ > tmp_me
diff tmp_klepl tmp_me
