--  Dakota Donner       --
--  CS 325 - Homework 2 --
--  Oct-02-2023         --

-- UNCOMMENT FOR BETTER FORMATTING
--set trimspool on
--set wrap off
--set linesize 1000

spool 325hw2-out.txt

prompt Homework 2
prompt by: Dakota Donner
prompt

prompt ===
prompt Problem 1:
prompt ===
prompt

select * 
from client
where client_credit_rtg > 3.4;

prompt ===
prompt Problem 2:
prompt ===
prompt

select distinct movie_rating, movie_yr_released
from movie;

prompt ===
prompt Problem 3:
prompt ===
prompt

select *
from client, movie_category
where client.client_fave_cat = movie_category.category_code;

prompt ===
prompt Problem 4:
prompt ===
prompt

select vid_id, date_out, date_due
from rental
where date_returned is null;

prompt ===
prompt Problem 5:
prompt ===
prompt

select vid_id, vid_format, vid_rental_price
from video
where vid_format != 'Blu-Ray';

prompt ===
prompt Problem 6:
prompt ===
prompt

select category_name, client_lname, client_credit_rtg
from client, movie_category
where client.client_fave_cat = movie_category.category_code;

prompt ===
prompt Problem 7:
prompt ===
prompt

select *
from video
where vid_purchase_date between '15-Jul-2008' and '01-Dec-2011';

prompt ===
prompt Problem 8:
prompt ===
prompt

select *
from video
where vid_rental_price >= 3.99 and vid_purchase_date >= '1-Jan-2011';

prompt ===
prompt Problem 9:
prompt ===
prompt

select movie_title, movie_rating
from movie
where movie_title like '%the%';

prompt ===
prompt Problem 10:
prompt ===
prompt

select movie_title, movie_rating
from movie
where movie_rating in ('PG-13','R','A');

spool off