CREATE OR REPLACE FUNCTION A6B2F3() RETURNS TRIGGER AS
$$

BEGIN 

IF OLD.address = 'Pune' THEN 

RAISE EXCEPTION 'Deletion not allowed. Driver lives at %.',OLD.address;

END IF;

RETURN OLD;

END;
$$ LANGUAGE plpgsql;

