#!/bin/bash

../../bin/zimadb <<EOF
.open employees.zima
CREATE TABLE emp (emp_id INT, emp_name VARCHAR(255), emp_age INT);

SELECT * FROM emp;

INSERT INTO emp (emp_id, emp_name, emp_age) VALUES (0, "Jarda", 20);
INSERT INTO emp (emp_age, emp_name, emp_id) VALUES (25, "Milan", 1);
INSERT INTO emp (emp_name, emp_age, emp_id) VALUES ("Lenka", 20+15, 2);
INSERT INTO emp (emp_name, emp_id, emp_age) VALUES ("Jarmila", 3, "50"-13);

SELECT *, emp_age*12, emp_age*emp_id FROM emp;

CREATE TABLE sec (sec_id INT, sec_level TINYINT);
INSERT INTO sec (sec_id, sec_level) VALUES (0, 10);
INSERT INTO sec (sec_id, sec_level) VALUES (1, 5);
INSERT INTO sec (sec_id, sec_level) VALUES (2, 5);
INSERT INTO sec (sec_id, sec_level) VALUES (3, 50);

SELECT * FROM emp, sec;
SELECT * FROM emp, sec WHERE emp_id = sec_id;
SELECT emp_name FROM emp, sec WHERE emp_id = sec_id AND emp_age > 30;
EOF
