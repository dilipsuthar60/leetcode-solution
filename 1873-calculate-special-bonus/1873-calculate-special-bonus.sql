select employee_id, 
case
when mod(employee_id ,2)!=0 and name not like 'm%' then salary
else 0
end as bonus
from employees order by employee_id;
