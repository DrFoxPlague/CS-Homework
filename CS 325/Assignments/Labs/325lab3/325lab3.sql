-- Dakota Donner
-- 9-8-2023

start 325lect02-2.sql

spool 325lab3-out.txt

prompt NAME: Dakota Donner

insert into parts
values
(10654, 'power cell', 5, 325.60, 'PSC', '12-Jan-2023');

insert into part_orders
values
('202301', '20233621', 10654, '08-Sep-2023', 2, 'B', 'F');

insert into part_orders
values
('202302', '20230908', 10654, '08-Sep-2023', 2, 'B', 'P');

insert into part_orders
values
('202303', '20230901', 10654, '08-Sep-2023', 1, 'I', 'F');

select  *
from    parts;

select  *
from    part_orders;

spool off