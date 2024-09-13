CREATE OR REPLACE FUNCTION A6C1F2() RETURNS TRIGGER AS
$$


BEGIN 


IF NEW.year > EXTRACT(YEAR FROM CURRENT_DATE)  THEN 

RAISE EXCEPTION 'Year is invalid. Year: % is greater than the current year.',NEW.year;

END IF;

END;
$$ LANGUAGE plpgsql;

