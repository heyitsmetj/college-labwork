CREATE OR REPLACE FUNCTION A6A2F2() RETURNS TRIGGER AS
$$

BEGIN 

IF NEW.duration <= 0 THEN

RAISE EXCEPTION 'Duration should be grater than zero.';

END IF;

RETURN NEW;

END;
$$ LANGUAGE plpgsql;

