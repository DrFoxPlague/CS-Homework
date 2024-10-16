/*      =====
    Dakota Donner       
    Nov-03-2023
        =====
*/

-- start 325lab11.sql

start set-up-ex-tbls.sql

spool 325lab11-out.txt

prompt By: Dakota Donner
prompt

prompt ===
prompt Lab query 1:
prompt ===

(select  job_title, mgr
from    empl
where   salary < 2000)
union
(select  job_title, mgr
from    empl
where   commission is not null);

prompt ===
prompt Lab query 2:
prompt ===

(select  job_title, mgr
from    empl
where   salary < 2000)
intersect
(select  job_title, mgr
from    empl
where   commission is not null);

prompt ===
prompt Lab query 3:
prompt ===

(select  job_title, mgr
from    empl
where   salary < 2000)
minus
(select  job_title, mgr
from    empl
where   commission is not null);

prompt ===
prompt Lab query 4:
prompt ===

(select empl_last_name, salary * 2 "TWICE_SALARY"
from    empl
where   job_title = 'Clerk')
minus
(select empl_last_name, salary * 2 "TWICE_SALARY"
from    empl
where   hiredate < '01-Jan-15')
order by TWICE_SALARY desc;

prompt ===
prompt Lab query-set 5:
prompt ===

select  empl_last_name, commission
from    empl
where   commission is not null;

select  empl_last_name, 0
from    empl
where   commission is null;

(select  empl_last_name, commission "COMM_VALUE"
from     empl
where    commission is not null)
union
(select  empl_last_name, 0 "COMM_VALUE"
from     empl
where    commission is null)
order by COMM_VALUE desc, empl_last_name;

prompt ===
prompt Lab query-set 6:
prompt ===

select  empl_last_name, job_title, salary
from    empl
where   job_title != 'Manager'
and     salary >
        (select min(salary)
         from empl
         where job_title = 'Manager');

select  empl_last_name, job_title, salary
from    empl e, dept d
where   e.dept_num = d.dept_num
and     d.dept_loc = 'New York';

(select  empl_last_name, job_title, salary
from     empl
where    job_title != 'Manager'
and      salary >
        (select min(salary)
         from empl
         where job_title = 'Manager'))
union
(select  empl_last_name, job_title, salary
from     empl e, dept d
where    e.dept_num = d.dept_num
and      d.dept_loc = 'New York')
order by salary;

prompt ===
prompt Lab problem 7:
prompt ===

select  empl_last_name, job_title, salary, commission
from    empl
where   commission is not null;

update  empl
set     commission = commission + 100
where   job_title = 'Sales'
and     salary < (select avg(salary)
                  from empl
                  where job_title = 'Sales');

select  empl_last_name, job_title, salary, commission
from    empl;

prompt ===
prompt Lab problem 8:
prompt ===

delete  from empl
where   salary < (select min(salary)
                  from empl
                  where job_title = 'Sales');

select  empl_last_name, job_title, salary
from    empl;

prompt ===
prompt Lab problem 9:
prompt ===

prompt What is the intersection of employee last names and salaries whose job
prompt title is Manager and the employee last names and salaries whose salaries
prompt is above 1000?

(select empl_last_name, salary
from    empl
where   job_title = 'Manager')
intersect
(select empl_last_name, salary
from    empl
where   salary > 1000);

spool off