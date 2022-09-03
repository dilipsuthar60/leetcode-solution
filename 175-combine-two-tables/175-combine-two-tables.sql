# Write your MySQL query statement below
select firstname,lastname,city,state from person  left join address  on person.personid=address.personid;
