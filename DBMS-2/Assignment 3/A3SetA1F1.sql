CREATE OR REPLACE FUNCTION A3A1F1 ()
RETURNS INT AS 
$$

DECLARE

emp_count INT;

BEGIN 

SELECT COUNT(*) INTO emp_count FROM Employee
WHERE joining_date < '01-01-2007';

RETURN emp_count;

END;
$$ LANGUAGE plpgsql;