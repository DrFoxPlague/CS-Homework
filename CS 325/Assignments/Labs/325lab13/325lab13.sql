/*      =====
    Dakota Donner       
    Nov-17-2023
        =====
*/

-- start 325lab13.sql

spool 325lab13-out.txt

prompt By: Dakota Donner
prompt

prompt ===
prompt Lab problem 1:
prompt ===

drop view empl_salaries;

create view empl_salaries as
select  empl_last_name, salary
from    empl;

prompt ===
prompt Lab problem 2:
prompt ===

select  *
from    empl_salaries;

prompt ===
prompt Lab problem 3:
prompt ===

select  max(salary)
from    empl_salaries;

prompt ===
prompt Lab problem 4:
prompt ===

drop view earliest_hires;

create view earliest_hires as
select   job_title, min(hiredate) "EARLIEST_HIRE"
from     empl
group by job_title;

prompt ===
prompt Lab problem 5:
prompt ===

select  *
from    earliest_hires;

prompt ===
prompt Lab problem 6:
prompt ===

select  max(EARLIEST_HIRE)
from    earliest_hires;

prompt ===
prompt Lab problem 7:
prompt ===

drop view cust_reps;

create view cust_reps as
select  c.cust_lname || ', ' || c.cust_fname "CUSTOMER", e.empl_last_name "REPD_BY", d.dept_loc
from    customer c, empl e, dept d
where   c.empl_rep = e.empl_num
and     e.dept_num = d.dept_num;

prompt ===
prompt Lab problem 8:
prompt ===

select  *
from    cust_reps;

prompt ===
prompt Lab problem 9:
prompt ===

prompt
prompt I would like to know the max salary for every department location

drop view max_sal_per_dept;

create view max_sal_per_dept as
select   max(e.salary) "MAX_SAL", d.dept_loc "DEP_LOC"
from     empl e, dept d
where    e.dept_num = d.dept_num
group by d.dept_loc;

select  *
from    max_sal_per_dept;

select  min(MAX_SAL)
from    max_sal_per_dept;

spool off