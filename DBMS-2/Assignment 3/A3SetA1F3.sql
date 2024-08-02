CREATE OR REPLACE FUNCTION A3A1F3 (name VARCHAR) RETURNS VOID AS
$$

DECLARE

r RECORD;

BEGIN 
FOR r IN
SELECT e.* INTO project_count FROM Project p,Employee e, Project_Employee pe WHERE p.pno = pe.pno AND e.eno = pe.eno AND p.pname = name
LOOP

RAISE NOTICE '% % % %',r.eno,r.ename,r.qualification,r.joining_date;

END;
$$ LANGUAGE plpgsql;