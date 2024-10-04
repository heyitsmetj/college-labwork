CREATE OR REPLACE FUNCTION A4A2F1(stud_name VARCHAR) RETURNS VOID AS 
$$

DECLARE
    t_cnt int;

BEGIN
    select count(*) into t_cnt from teacher,student,stud_teach where student.sno=stud_teach.sno and 
    teacher.tno=stud_teach.tno and sname=stud_name;
    
    IF t_cnt=0 THEN 
    RAISE EXCEPTION 'Innvalid student name : %',stud_name;
    else 
    RAISE NOTICE 'Total no. of Teachers %',t_cnt;
    end if;
    
END;
$$ language 'plpgsql'  