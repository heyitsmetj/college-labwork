CREATE OR REPLACE FUNCTION A3A2F3 (a_type VARCHAR) RETURNS VOID AS
$$

DECLARE
r RECORD;

BEGIN

FOR r IN 
SELECT p.* FROM Person p,Area a WHERE p.aname = a.aname and a.area_type = a_type
LOOP

RAISE NOTICE '% || % || % || % || %',r.pno,r.pname,r.birthdate,r.income,r.aname;

END LOOP;
END;
$$ LANGUAGE plpgsql;

