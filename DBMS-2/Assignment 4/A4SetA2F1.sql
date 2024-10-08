CREATE OR REPLACE FUNCTION A4A2F1(stud_name VARCHAR) RETURNS VOID AS 
$$

DECLARE
    t_cnt int;

BEGIN
    select COUNT(*) into t_cnt from teacher t,student s,stud_teacher st where s.sno=st.sno and 
    t.tno=st.tno and s.sname=stud_name;
    
    IF t_cnt=0 THEN 
    RAISE EXCEPTION 'Invalid student name : %',stud_name;
    else 
    RAISE NOTICE 'Total no. of Teachers: %',t_cnt;
    end if;
    
END;
$$ language 'plpgsql'  