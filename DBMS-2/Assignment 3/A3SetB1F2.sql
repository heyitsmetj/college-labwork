CREATE OR REPLACE FUNCTION A3B1F2 (snum INTEGER,dpname VARCHAR) RETURNS VOID AS
$$

DECLARE

r RECORD;

BEGIN 

FOR r IN 
select d.* FROM Bus b,Driver d,Bus_Driver bd WHERE b.bus_no = bd.bus_no AND bd.driver_no = d.driver_no AND date_of_duty_allotted = '2020-07-02' AND shift = snum AND depot_name = dpname
LOOP

RAISE NOTICE '% || % || % || % || % || %',r.bus_no,r.b_capacity,r.depot_name,r.route_no;

END LOOP;

END;
$$ LANGUAGE plpgsql;