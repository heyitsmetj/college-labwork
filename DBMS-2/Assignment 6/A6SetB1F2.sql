CREATE OR REPLACE FUNCTION A6B1F2() RETURNS TRIGGER AS
$$

BEGIN 

IF NEW.age > 5 THEN 

    RAISE NOTICE 'Age above 5 will be charged full fare. Passenger age: %',NEW.age;

END IF;

RETURN NEW;

END;
$$ LANGUAGE plpgsql;

