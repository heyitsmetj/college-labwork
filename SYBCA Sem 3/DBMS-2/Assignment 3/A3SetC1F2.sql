CREATE OR REPLACE FUNCTION A3C1F2 () RETURNS INTEGER AS
$$

DECLARE

t_count INTEGER;

BEGIN 

SELECT COUNT(*) INTO t_count FROM 
Trip WHERE from_city ='Pune' AND to_city ='Mumbai';

RETURN t_count;

END;
$$ LANGUAGE plpgsql;