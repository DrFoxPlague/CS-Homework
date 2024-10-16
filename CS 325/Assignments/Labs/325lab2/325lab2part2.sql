-- Name: Dakota Donner
-- Date: 9-1-2023

spool 325lab2part2-out.txt

drop table GameWeapons cascade constraints;

create table GameWeapons
(weapon_name	varchar2(25),
 weapon_dmg	decimal(5,2),
 dmg_type	varchar2(20),
 weapon_type	varchar2(20),
 weapon_lvl	integer,
 material_type	varchar2(20),
 primary key	(weapon_name)
);

insert into GameWeapons
values
('Dakotas Dagger', 234.53, 'void', 'dagger', 3, 'obsidian');

insert into GameWeapons
values
('Peters Candy Cane', 003.00, 'sugar', 'candy cane', 9, 'candy');

insert into GameWeapons
values
('Andrews Bow', 176.34, 'lightning', 'bow', 7, 'elderwood');

insert into GameWeapons
values
('Trevors Large Rod', 999.99, 'poison', 'staff', 421, 'peasant bones');

insert into GameWeapons
values
('Michaels Gun', 295.00, 'fire', 'firearm', 10, 'dragon bones');

insert into GameWeapons
values
('Kristians Dual Daggers', 888.33, 'fire', 'dual dagger', 100, 'steel');

prompt Describe GameWeapons:
describe GameWeapons;

prompt Select GameWeapons:
select	*
from	GameWeapons;

drop table GameWeapon_Enchantments;

create table GameWeapon_Enchantments
(weapon		varchar2(25),
 ench_name	varchar2(25),
 ench_lvl	integer,
 primary key	(weapon),
 foreign key	(weapon) references GameWeapons(weapon_name)
);

insert into GameWeapon_Enchantments
values
('Michaels Gun', 'Soul Stealing', 6);

insert into GameWeapon_Enchantments
values
('Andrews Bow','Death Defying', 99);

insert into GameWeapon_Enchantments
values
('Dakotas Dagger', 'Frostbite', 3);

insert into GameWeapon_Enchantments
values
('Kristians Dual Daggers','Fire Breath', 23);

prompt Describe GameWeapon_Enchantments:
describe GameWeapon_Enchantments;

prompt Select GameWeapon_Enchantments:
select	*
from	GameWeapon_Enchantments;

spool off
