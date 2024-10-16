/*      =====
    Dakota Donner       
    CS 325 - Homework 6
    Dec-08-2023
        =====
*/

/*
start 325hw6.sql
*/


start movies-create.sql
start movies-pop.sql

spool 325hw6-out.txt

clear breaks columns computes
set pagesize 35
set linesize 75
ttitle 'CS 325|Homework 6'
btitle 'CS 325|Homework 6'
set feedback off


prompt Homework 6
prompt by: Dakota Donner
prompt

prompt ===
prompt Problem 3:
prompt ===

drop view rental_history;

create  view rental_history as
select  c.client_lname || ', ' || c.client_fname as client_name, m.movie_title, v.vid_format, v.vid_rental_price
from    client c
join    rental r on c.client_num = r.client_num
join    video v on r.vid_id = v.vid_id
join    movie m on v.movie_num = m.movie_num;

select  *
from    rental_history
order   by client_name, vid_rental_price desc, movie_title;

prompt ===
prompt Problem 4:
prompt ===

col client_name heading 'Client' format a15
col movie_title heading 'Movie Title' format a37
col vid_format heading 'Format' format a7
col vid_rental_price heading 'Rental Price' format $999.99

/

prompt ===
prompt Problem 5:
prompt ===

drop view category_stats;

create   view category_stats as
select   c.category_name, count(m.category_code) as vid_count, avg(vid_rental_price) as avg_rent
from     movie_category c
join     movie m on c.category_code = m.category_code
join     video v on m.movie_num = v.movie_num
group by c.category_name;

select   *
from     category_stats
order by vid_count desc, avg_rent desc;

prompt ===
prompt Problem 6:
prompt ===

set pagesize 20

col category_name heading 'Category' format a10
col vid_count heading '# Videos' format 999
col avg_rent heading 'Avg Price' format $99.99

/

prompt ===
prompt Problem 7:
prompt ===

commit;

prompt 7a
prompt ~~~

update  video
set     vid_rental_price = vid_rental_price - 0.25
where   vid_format = 'Blu-Ray';

select   *
from     category_stats
order by vid_count desc, avg_rent desc;

prompt 7b
prompt ~~~

select  distinct client_name
from    rental_history
where   movie_title = 'Gone with the Wind'
order   by client_name;

prompt 7c
prompt ~~~

delete  from rental
where   client_num = '5555';

select  distinct client_name
from    rental_history
where   movie_title = 'Gone with the Wind'
order   by client_name;

prompt 7d
prompt ~~~

select  client_name, count(*) as rental_count
from    rental_history
group   by client_name
order   by rental_count desc, client_name;

rollback;

prompt ===
prompt Problem 8:
prompt ===

set pagesize 45

break on client_name skip 1

select  distinct client_name, movie_title
from    rental_history
order   by client_name, movie_title;


prompt ===
prompt Problem 9:
prompt ===

set pagesize 45

compute avg of vid_rental_price on client_name

select  *
from    rental_history
order   by client_name, movie_title;

prompt ===
prompt Problem 10:
prompt ===

spool off

clear columns breaks computes
set feedback on
set feedback 6
set pagesize 14
set linesize 80
ttitle off
btitle off