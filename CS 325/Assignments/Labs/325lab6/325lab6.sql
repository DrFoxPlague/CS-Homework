--  Dakota Donner   --
--  Sep-29-2023     --

spool 325lab6-out.txt

prompt By: Dakota Donner
prompt

prompt Lab query 1
prompt ===

select empl_last_name
from empl
where mgr is null;

prompt Lab query 2
prompt ===

select empl_last_name, hiredate
from empl
where job_title = 'Sales';

prompt Lab query 3
prompt ===

select dept_name, salary
from dept, empl
where empl.mgr = '7839' and dept.dept_num = empl.dept_num;

prompt Lab query 4
prompt ===

select distinct job_title, mgr
from empl;

prompt Lab query 5
prompt ===

select *
from dept
where dept_loc in ('Dallas', 'Boston', 'New York');

prompt Lab query 6
prompt ===

select empl_last_name, job_title, salary
from empl
where salary > 3000 or salary < 1000;

prompt Lab query 7
prompt ===

select *
from empl
where hiredate between '01-Sep-2018' and '30-Sep-2018';

prompt Lab query 8
prompt ===

select *
from empl
where empl_last_name like 'M%';

prompt Lab query 9
prompt ===
prompt
prompt Which employees have salaries less than $1,000 and are clerks?

select *
from empl
where job_title = 'Clerk' and salary < 1000;

prompt What are the salaries of the analysts?

select job_title, salary
from empl
where job_title = 'Analyst';

spool off 