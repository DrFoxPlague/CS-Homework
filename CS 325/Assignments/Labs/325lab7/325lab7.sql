--  Dakota Donner   --
--  Sep-29-2023     --
-- start 325lab7.sql

spool 325lab7-out.txt

prompt By: Dakota Donner
prompt

prompt ===
prompt Lab query 1:
prompt ===

select dept_name, dept_loc "LOCATION"
from dept;

prompt ===
prompt Lab query 2:
prompt ===

select empl_last_name "Last Name", hiredate "Hired", job_title "Job Title"
from empl;

prompt ===
prompt Lab query 3:
prompt ===

select empl_last_name, hiredate, hiredate + 3 "H PLUS 3"
from empl;

prompt ===
prompt Lab query 4:
prompt ===

select job_title, commission, commission * 1.2 "PLUS 20%"
from empl;

prompt ===
prompt Lab query 5:
prompt ===

select job_title, commission, commission * 1.2 "PLUS 20%"
from empl
where commission is not null;

prompt ===
prompt Lab query 6:
prompt ===

select cust_lname, empl_last_name
from customer, empl
where empl_rep = empl_num;


prompt ===
prompt Lab query 7:
prompt ===

select e.empl_last_name, d.dept_loc
from empl e, dept d
where e.dept_num = d.dept_num;

prompt ===
prompt Lab query 8:
prompt ===

select e.empl_last_name, e.dept_num, d.dept_name
from empl e, dept d
where e.dept_num = d.dept_num;

prompt ===
prompt Lab query 9:
prompt ===

select count(salary) "# SALARY > 2,000"
from empl
where salary > 2000;

prompt ===
prompt Lab query 10:
prompt ===

select min(hiredate) "MIN DATE", max(hiredate) "MAX DATE"
from empl
where job_title = 'Clerk';

prompt ===
prompt Lab query 11:
prompt ===

select count(job_title) "# SALES POS", sum(commission) "COMM SUM", avg(commission) "AVG COMM"
from empl
where job_title = 'Sales';

prompt ===
prompt Lab query 12:
prompt ===

select count(*) "# EMPLS", count(commission) "NON NULL COMMS", count(mgr) "NON NULL MGRS"
from empl;

prompt ===
prompt Lab query 13:
prompt ===

prompt What is smallest and largest salary?

select min(salary), max(salary)
from empl;

spool off