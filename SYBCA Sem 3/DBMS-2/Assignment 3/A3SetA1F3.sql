CREATE OR REPLACE FUNCTION A3A1F3 (name CHAR) RETURNS VOID AS
$$

DECLARE

r RECORD;


BEGIN 
FOR r IN
SELECT e.* FROM Project p,Employee e, Project_Employee pe WHERE p.pno = pe.pno AND e.eno = pe.eno AND no_of_hours_worked > 2000 AND p.pname = name
LOOP

RAISE NOTICE '% % % %',r.eno,r.ename,r.qualification,r.joining_date;

END LOOP;
END;
$$ LANGUAGE plpgsql;