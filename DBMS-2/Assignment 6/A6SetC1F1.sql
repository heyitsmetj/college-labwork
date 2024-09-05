CREATE OR REPLACE FUNCTION A6C1F1() RETURNS TRIGGER AS
$$

BEGIN 

IF NEW.rank > 3 THEN 

RAISE EXCEPTION 'Invalid Rank value. Rank % exceeds the allowed maximum of 3.',NEW.rank;

END IF;

RETURN OLD;

END;
$$ LANGUAGE plpgsql;

