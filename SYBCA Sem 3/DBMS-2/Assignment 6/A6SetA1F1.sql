CREATE OR REPLACE FUNCTION A6A1F1() RETURNS TRIGGER AS
$$

BEGIN 

IF NEW.s_no <= 0 THEN
    RAISE EXCEPTION 'Invalid student number. Student number must be a positive integer.';
END IF;

RETURN NEW;

END;
$$ LANGUAGE plpgsql;

