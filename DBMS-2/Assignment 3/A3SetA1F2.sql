CREATE OR REPLACE FUNCTION A3A1F2 (emp_no INTEGER) RETURNS INT AS
$$

DECLARE

project_count INT;

BEGIN 

SELECT COUNT(p.pno) INTO project_count FROM Project p,Employee e, Project_Employee pe WHERE p.pno = pe.pno AND e.eno = pe.eno AND e.eno = emp_no;

RETURN project_count;

END;
$$ LANGUAGE plpgsql;