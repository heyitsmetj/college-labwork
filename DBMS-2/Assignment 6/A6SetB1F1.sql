CREATE OR REPLACE FUNCTION A6B1F1() RETURNS TRIGGER AS
$$

BEGIN 

IF NEW.bogie_capacity > 30 THEN 

    RAISE EXCEPTION 'Bogie capacity cannot exceed 30!';

END IF;

RETURN NEW;

END;
$$ LANGUAGE plpgsql;

