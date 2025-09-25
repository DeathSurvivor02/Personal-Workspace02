-- Question 1
create view contact
as select contact, phone
-- from publisher;


-- select contact from contact;


-- Question 2
from publisher
with read only;
select contact from contact order by contact;


--Question 3
create force view homework
as select col1, col2 from firstattempt;

 desc homework;
-- Question 4
create view reorderinfo
as select isbn, title, contact, phone 
from books join publisher using (pubid);
-- select contact from contact order by contact;