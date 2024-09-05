CREATE OR REPLACE FUNCTION A6B2F1() RETURNS TRIGGER AS
$$

BEGIN 

IF NEW.d_age > 18 AND NEW.d_age < 50 THEN 

RAISE NOTICE 'Entry within valid range (%).',NEW.d_age;

ELSE

RAISE EXCEPTION 'Invalid age (%).', NEW.d_age;

END IF;

RETURN NEW;

END;
$$ LANGUAGE plpgsql;

