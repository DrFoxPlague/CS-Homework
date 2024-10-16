/*      =====
    Dakota Donner       
    CS 325 - Homework 5 - Problem 3
    Nov-09-2023
        =====
*/

/*
start 325hw5.sql
*/

start movies-create.sql
start movies-pop.sql

spool 325hw5-out.txt

prompt Homework 5 Problem 3
prompt by: Dakota Donner
prompt

prompt ===
prompt Problem 3-1:
prompt ===

prompt
prompt query 1:
prompt ~~~

select   *
from     client
order by client_credit_rtg asc;

prompt query 2:
prompt ~~~

select   *
from     client
order by client_credit_rtg desc;

prompt ===
prompt Problem 3-2:
prompt ===

select   movie_title || ': ' || movie_rating "Movie: Rating"
from     movie
order by movie_rating asc, movie_title asc;

prompt ===
prompt Problem 3-3:
prompt ===

select   category_name, movie_title, movie_rating
from     movie m, movie_category c
where    m.category_code = c.category_code
order by movie_rating, category_name desc, movie_title;

prompt ===
prompt Problem 3-4:
prompt ===

select   client_lname, client_phone, client_credit_rtg
from     client
where    client_credit_rtg < (select avg(client_credit_rtg)
                              from client)
order by client_credit_rtg desc;

prompt ===
prompt Problem 3-5:
prompt ===

select   vid_format, count(vid_format) "QTY", avg(vid_rental_price) "AVG RENTAL PRICE"
from     video
group by vid_format;

prompt ===
prompt Problem 3-6:
prompt ===

select   vid_rental_price, count(vid_rental_price) "QUANTITY"
from     video
group by vid_rental_price
order by vid_rental_price desc;

prompt ===
prompt Problem 3-7:
prompt ===

select   vid_rental_price, count(vid_rental_price) "QUANTITY"
from     video
group by vid_rental_price
having   count(vid_rental_price) >= 5
order by vid_rental_price desc;

spool off