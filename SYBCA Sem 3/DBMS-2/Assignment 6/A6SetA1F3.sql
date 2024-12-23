CREATE OR REPLACE FUNCTION A6A1F3() RETURNS TRIGGER AS
$$

BEGIN 

IF NEW.experience < 2 THEN

    RAISE EXCEPTION 'Experience must be at least 2 years.';

END IF;

RETURN NEW;

END;
$$ LANGUAGE plpgsql;

