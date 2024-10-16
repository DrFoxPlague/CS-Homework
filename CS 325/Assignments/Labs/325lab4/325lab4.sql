--  Dakota Donner   --
--  Sep-15-2023     --

spool 325lab4-out.txt
prompt By: Dakota Donner

-- Problem 1
prompt true relational selections

select  *
from    dept
where   dept_num > 300;

select  *
from    empl
where   job_title = 'Sales';

-- Problem 2
prompt true relational projections

select  distinct dept_name, dept_loc
from    dept;

select  distinct empl_last_name, empl_num, job_title
from    empl;

-- Problem 3
prompt true Cartesian product

select  *
from    empl, dept;

-- Problem 4
prompt true equi-join of customer and empl

select  *
from    customer, empl
where   customer.empl_rep = empl.empl_num;

spool off