--  Dakota Donner   --
--  Oct-13-2023     --
-- start 325lab8.sql

spool 325lab8-out.txt

prompt By: Dakota Donner
prompt

prompt ===
prompt Lab query 1:
prompt ===

select  empl_last_name, hiredate
from    empl
where   job_title = 'Manager'
and     salary >
        (select avg(salary)
         from empl
         where job_title = 'Manager');


prompt ===
prompt Lab query 2:
prompt ===

select  hiredate
from    empl
where   dept_num in
        (select dept_num
         from dept
         where dept_loc = 'New York');

prompt ===
prompt Lab query 3:
prompt ===

select  empl_last_name, hiredate
from    empl
where   hiredate >
        (select max(hiredate)
         from empl
         where job_title = 'Manager');

prompt ===
prompt Lab query 4:
prompt ===

select distinct empl_last_name "Employee", dept_name || ' (' || dept_loc || ')' "Department (Location)"
from empl, dept
where empl.dept_num = dept.dept_num;

prompt ===
prompt Lab query 5:
prompt ===

select  dept_name
from    dept
where   exists
        (select salary
         from empl
         where empl.dept_num = dept.dept_num
         and salary >= 3000);

prompt ===
prompt Lab query 6:
prompt ===

select  empl_last_name
from    empl
where   not exists
        (select empl_rep
         from customer
         where empl.empl_num = customer.empl_rep)
and     job_title = 'Sales';

prompt ===
prompt Lab query 7:
prompt ===

prompt What is the number, name, and salary of the manager with the highest salary?

select  empl_num "Num", empl_last_name "Name", salary "Salary"
from    empl
where   salary = 
        (select max(salary)
        from empl
        where job_title = 'Manager');

spool off