#!/bin/bash

#sed 's%\([0-9]{1,2}\). \([0-9]{1,2}\). \([0-9]{1,4}\)%\3-\2-\1%p' src_3
sed -e 's%([0-9]{1,2})\. %\1%' src_3