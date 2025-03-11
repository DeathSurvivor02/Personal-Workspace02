create table instructor (
   ins_id    int,
   lastname  varchar(255) not null,
   firstname varchar(255) not null,
   city      varchar(255),
   country   varchar(255),
   primary key ( ins_id )
   
);

drop table instructor;

COMMIT;