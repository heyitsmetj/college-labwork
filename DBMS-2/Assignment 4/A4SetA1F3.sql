CREATE OR REPLACE FUNCTION A4A1F3(month_num INTEGER)
RETURNS VOID AS $$
DECLARE

r RECORD;

BEGIN
    -- Return persons whose birthday is in the specified month
    FOR r IN
    SELECT *
    FROM Person p
    WHERE EXTRACT(MONTH FROM birthdate) = month_num
    LOOP
    
    IF NOT FOUND THEN
    RAISE EXCEPTION 'No persons found with a birthday in month %', month_num;
    ELSE
    RAISE NOTICE 'Persons found with a birthday in month % : % || % || % || % || %', month_num,r.pno,r.pname,r.birthdate,r.income,r.aname;
    END IF;
    
    END LOOP;

END;
$$ LANGUAGE plpgsql;


