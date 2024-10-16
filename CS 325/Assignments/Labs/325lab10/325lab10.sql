/*      =====
    Dakota Donner       
    Oct-27-2023
        =====
*/

-- start 325lab10.sql

spool 325lab10-out.txt

prompt By: Dakota Donner
prompt

prompt ===
prompt Lab query 1:
prompt ===

select   *
from     dept
order by dept_loc;

prompt ===
prompt Lab query 2:
prompt ===

select   *
from     dept
order by dept_name;

prompt ===
prompt Lab query 3:
prompt ===

select   empl_last_name, dept_name, salary, hiredate
from     empl e, dept d
where    d.dept_num = e.dept_num
order by dept_name, hiredate;

prompt ===
prompt Lab query 4:
prompt ===

select   empl_last_name, dept_name, salary, hiredate
from     empl e, dept d
where    d.dept_num = e.dept_num
order by salary desc, hiredate asc;

prompt ===
prompt Lab query 5:
prompt ===

select   mgr, min(hiredate)
from     empl
group by mgr;

prompt ===
prompt Lab query 6:
prompt ===

select   mgr, min(hiredate)
from     empl
where    hiredate > '01-JAN-15'
group by mgr;

prompt ===
prompt Lab query 7:
prompt ===

select   d.dept_name, count(*)
from     empl e, dept d
where    e.dept_num = d.dept_num
group by dept_name
order by count(*) asc;

prompt ===
prompt Lab query 8:
prompt ===

select   d.dept_name, count(*)
from     empl e, dept d
where    e.dept_num = d.dept_num
group by dept_name having avg(salary) < 2000
order by count(*) asc;

prompt ===
prompt Lab query 9:
prompt ===

prompt
prompt Average salary of employees in each department in ascending order?

select   d.dept_name, avg(salary)
from     dept d, empl e
where    d.dept_num = e.dept_num
group by dept_name
order by avg(salary) asc;

spool off