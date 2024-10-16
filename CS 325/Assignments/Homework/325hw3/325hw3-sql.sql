--  Dakota Donner       --
--  CS 325 - Homework 3 - Problem 1  --
--  Oct-16-2023         --

-- start 325hw3-sql.sql

spool 325hw3-sql-out.txt

prompt Homework 3 Problem 1
prompt ===
prompt by Dakota Donner
prompt ===
prompt

prompt Part 1-1

select client_lname, client_credit_rtg + 0.5 "IF_BUMPED_UP"
from client
where client_credit_rtg <= 4.5;

prompt Part 1-2

select rental_num, date_due, date_due + 5 "IF_GRACE"
from rental
where date_returned is null;

prompt Part 1-3

select vid_id, vid_format, vid_rental_price * 0.8 "IF_DISCT"
from video
where vid_format != 'Blu-Ray';

prompt Part 1-4

select m.movie_title, m.category_code, c.category_name
from movie m, movie_category c
where m.category_code = c.category_code;

prompt Part 1-5

select min(vid_purchase_date) "OLDEST", max(vid_purchase_date) "NEWEST"
from video;

prompt Part 1-6

select count(vid_id) "Total Videos", avg(vid_rental_price) "Avg Rental"
from video;

prompt Part 1-7

select count(rental_num) "# Rentals", sum(vid_rental_price) "Total Rental $"
from video v, rental r
where v.vid_id = r.vid_id;

spool off