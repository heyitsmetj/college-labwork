CREATE OR REPLACE FUNCTION A5A1F1 (no INTEGER)
RETURNS VOID AS 
$$

DECLARE

c_a1a CURSOR FOR
select s_name,t_name FROM Student s,Teacher t,Student_Teacher st WHERE
 s.s_no = st.s_no AND t.t_no = st.t_no AND subject = 'RDBMS' AND
 s.s_no = no;

 v_sname Student.s_name%TYPE;
 v_tname Teacher.t_name%TYPE;

BEGIN 

OPEN c_a1a;
LOOP

FETCH c_a1a INTO v_sname, v_tname;
EXIT WHEN NOT FOUND;

RAISE NOTICE 'Student Name: % , Teacher Name: % ',v_sname,v_tname;

END LOOP;

CLOSE c_a1a;

END;
$$ LANGUAGE plpgsql;