#!/bin/bash

echo "1. Jmeno"
grep -e '^[A-Z][a-z]* [A-Z][a-z]*$' src_1
echo "2. Jmeno, vice"
grep -E '^[A-Z][a-z]*( [A-Z][a-z]*)+$' src_1
echo "3. Algebraicky vyraz"
grep -e '^[0-9+\-\*\\\(\) ]*$' src_1
echo "5. Data"
grep -E '^[0-9]{1,2}\. [0-9]{1,2}\. [0-9]{1,4}$' src_1
echo "6. HTML tagy"
grep -E '^( *(</|<)[a-zA-Z ]*>)*$' src_1
echo "7. Obce"
grep -E '^[a-zA-Z]* (nad|pod) [a-zA-Z]*$' src_1
