CREATE OR REPLACE FUNCTION A6C2F1() RETURNS TRIGGER AS
$$

BEGIN 

IF OLD.cno <> NEW.cno THEN

RAISE EXCEPTION 'You cannot change existing customer number.';

END IF;

RETURN NEW;

END;
$$ LANGUAGE plpgsql;

