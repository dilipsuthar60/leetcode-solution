select customers.name as customers from customers where customers.id not in (select orders.customerid from orders);