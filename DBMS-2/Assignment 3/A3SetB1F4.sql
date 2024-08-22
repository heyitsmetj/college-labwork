CREATE OR REPLACE FUNCTION A3B1F4 (dpname VARCHAR) RETURNS VOID AS
$$

DECLARE

r  RECORD;

BEGIN 

FOR r IN
SELECT d.* FROM Bus b,Driver d,Bus_Driver bd WHERE bd.driver_no = d.driver_no AND b.bus_no = bd.bus_no
AND b.depot_name = dpname AND d.d_age > 50
LOOP

RAISE NOTICE '% % % % % %',r.driver_no,r.driver_name,r.license_no,r.address,r.d_age,r.salary;

END LOOP;

END;
$$ LANGUAGE plpgsql;