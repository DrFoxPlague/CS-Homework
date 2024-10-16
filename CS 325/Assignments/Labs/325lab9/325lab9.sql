--  Dakota Donner   --
--  Oct-20-2023     --
-- start 325lab9.sql

spool 325lab9-out.txt

prompt By: Dakota Donner
prompt

prompt ===
prompt Lab query 1:
prompt ===

(select empl_last_name, job_title, hiredate
from empl
where hiredate > '01-Jan-2018')
union
(select empl_last_name, job_title, hiredate
from empl
where empl.dept_num =
      (select dept_num
       from dept
       where dept_loc = 'Dallas'));

prompt ===
prompt Lab query 2:
prompt ===

(select cust_fname, cust_lname, cust_balance
from customer
where cust_balance > 100)
union
(select cust_fname, cust_lname, cust_balance
from customer
where cust_city = 'Arcata');

prompt ===
prompt Lab query 3:
prompt ===

(select empl_last_name, salary+commission "Total Recompense"
from empl
where commission is not null)
union
(select empl_last_name, salary
from empl
where commission is null);

prompt ===
prompt Lab query 4:
prompt ===

select empl_last_name, job_title
from empl
where dept_num =
      (select dept_num
       from dept
       where dept_name = &dept_name);

prompt ===
prompt Lab query 5:
prompt ===

select cust_fname, cust_lname
from customer
where empl_rep in
      (select empl_num
       from empl
       where job_title = &job_title);

prompt ===
prompt Lab query 6:
prompt ===

prompt What is the last name and job title with salaries lesser than what the user enters?

select empl_last_name, job_title
from empl
where salary < &salary;

spool off