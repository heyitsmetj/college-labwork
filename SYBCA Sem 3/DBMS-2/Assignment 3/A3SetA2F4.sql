CREATE OR REPLACE FUNCTION A3A2F4 (name VARCHAR) RETURNS VOID AS
$$

DECLARE

r RECORD;

BEGIN

FOR r IN 
SELECT p.* FROM Person p,Area a WHERE p.aname = a.aname and DATE_PART('YEAR',AGE(birthdate)) > 60 and a.aname = name
LOOP

RAISE NOTICE '% || % || % || % || %',r.pno,r.pname,r.birthdate,r.income,r.aname;

END LOOP;
END;
$$ LANGUAGE plpgsql;

