CREATE OR REPLACE FUNCTION A6A2F1() RETURNS TRIGGER AS
$$

BEGIN 

IF NEW.joining_date > CURRENT_DATE THEN

RAISE EXCEPTION 'Joining date should be before current date. Provided Date: %',NEW.joining_date;

END IF;

RETURN NEW;

END;
$$ LANGUAGE plpgsql;

