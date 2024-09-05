CREATE OR REPLACE FUNCTION A6C2F3() RETURNS TRIGGER AS
$$

BEGIN 

IF NEW.cno <= 0 THEN

RAISE EXCEPTION 'Customer number cannot be negative or zero';

END IF;

IF NEW.cname IS NULL THEN

RAISE EXCEPTION 'Customer name cannot be NULL';

END IF;

RETURN NEW;

END;
$$ LANGUAGE plpgsql;

