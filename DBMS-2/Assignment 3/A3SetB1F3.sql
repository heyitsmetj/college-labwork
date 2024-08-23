CREATE OR REPLACE FUNCTION A3B1F3 (sname VARCHAR) RETURNS VOID AS
$$

DECLARE

b_count INTEGER;

BEGIN 

SELECT COUNT(DISTINCT b.bus_no) INTO b_count FROM Bus b, Route r WHERE b.route_no = r.route_no AND r.source = sname;

RAISE NOTICE 'Bus COUNT: %',b_count;

END;

$$ LANGUAGE plpgsql;