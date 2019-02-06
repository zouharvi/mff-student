#!/bin/bash

../../bin/zimadb <<EOF
.open employees.zima
CREATE TABLE emp (emp_id INT, emp_name VARCHAR(255), emp_age INT);
INSERT INTO emp (emp_id, emp_name, emp_age) VALUES (0, "Jarda", 20);
SELECT emp_name from emp;
EOF
