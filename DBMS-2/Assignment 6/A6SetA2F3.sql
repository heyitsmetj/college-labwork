CREATE OR REPLACE FUNCTION A6A2F3() RETURNS TRIGGER AS
$$

BEGIN 

RAISE NOTICE 'Employee record with ID: % is being deleted.',OLD.cno;

RETURN OLD;

END;
$$ LANGUAGE plpgsql;
