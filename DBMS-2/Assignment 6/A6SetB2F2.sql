CREATE OR REPLACE FUNCTION A6B2F2() RETURNS TRIGGER AS
$$

BEGIN 

IF OLD.b_capacity < 10 THEN 

RAISE NOTICE 'Bus with capacity less than 10 has been deleted.';

END IF;

RETURN OLD;

END;
$$ LANGUAGE plpgsql;

