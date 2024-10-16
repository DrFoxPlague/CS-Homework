/*      =====
    Dakota Donner       
    CS 325 - Homework 4 
    Oct-26-2023
        =====
*/

/*
start 325hw4.sql
*/

spool 325hw4-out.txt

prompt Homework 4
prompt by: Dakota Donner

prompt ===
prompt Problem 1:
prompt ===

select  vid_id, vid_format
from    video
where   vid_rental_price <
        (select avg(vid_rental_price)
        from video); 

prompt ===
prompt Problem 2:
prompt ===

select  client_lname, client_fname
from    client
where   client_num in
        (select client_num
        from rental
        where vid_id = '130012');

prompt ===
prompt Problem 3:
prompt ===

select  movie_title || ': ' || movie_rating "Movie: Rating"
from    movie;

prompt ===
prompt Problem 4:
prompt ===

select  movie_title || ' (' || movie_yr_released || ')' "Movies", movie_director_lname "Directors"
from    movie;

prompt ===
prompt Problem 5:
prompt ===

select  movie_title
from    movie m, video v
where   vid_purchase_date =
        (select min(vid_purchase_date)
        from video)
and     m.movie_num = v.movie_num;

prompt ===
prompt Problem 6:
prompt ===

select  client_lname, client_fname, client_phone
from    client c
where   exists
        (select 'a'
        from rental r
        where r.client_num = c.client_num
        and date_returned is null);

prompt ===
prompt Problem 7:
prompt ===

select  movie_title
from    movie m
where   not exists
        (select 'a'
         from video v
         where v.movie_num = m.movie_num
         and vid_format = 'Blu-Ray');

prompt ===
prompt Problem 8:
prompt ===

select  movie_title, movie_yr_released
from    movie
where   movie_director_lname = &director_name;

prompt ===
prompt Problem 9:
prompt ===

select  movie_title, movie_director_lname
from    movie
where   category_code =
        (select category_code
         from movie_category
         where category_name = &cat_name);

spool off