#!/bin/bash

../../bin/zimadb <<EOF
.open employees.zima
CREATE TABLE emp (emp_id INT, emp_name VARCHAR(255), emp_age INT);
SELECT * FROM emp;
INSERT INTO emp (emp_id, emp_name, emp_age) VALUES (0, "Jarda", 20);
INSERT INTO emp (emp_age, emp_name) VALUES (25, "Milan");
INSERT INTO emp (emp_age, emp_name) VALUES (20+15, "Lenka");
SELECT * FROM emp;
EOF