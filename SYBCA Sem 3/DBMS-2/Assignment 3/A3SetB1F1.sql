CREATE OR REPLACE FUNCTION A3B1F1 (num INTEGER) RETURNS VOID AS
$$

DECLARE

r RECORD;

BEGIN 

FOR r IN 
select b.* FROM Bus b WHERE b.route_no = num
LOOP

RAISE NOTICE '% || % || % || %',r.bus_no,r.b_capacity,r.depot_name,r.route_no;

END LOOP;

END;
$$ LANGUAGE plpgsql;