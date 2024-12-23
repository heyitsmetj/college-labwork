CREATE OR REPLACE FUNCTION A6B1F3() RETURNS TRIGGER AS
$$

BEGIN 

IF NEW.no_of_berths > 20 THEN 

RAISE EXCEPTION 'Number of berths cannot exceed 20. Provided berths: %.',NEW.no_of_berths;

END IF;

RETURN NEW;

END;
$$ LANGUAGE plpgsql;

