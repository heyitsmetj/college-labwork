CREATE OR REPLACE FUNCTION A3A2F1 (name VARCHAR) RETURNS INTEGER AS
$$

DECLARE

count_p INTEGER;

BEGIN 

SELECT COUNT(pno) INTO count_p FROM Person p,Area a WHERE p.aname = a.aname AND a.aname = name;

RETURN count_p;

END;
$$ LANGUAGE plpgsql;