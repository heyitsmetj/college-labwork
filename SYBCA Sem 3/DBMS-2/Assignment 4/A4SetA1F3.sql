CREATE OR REPLACE FUNCTION A4A1F3(month_num INT)
RETURNS VOID AS $$
DECLARE

name VARCHAR;

BEGIN

    SELECT p.pname INTO name
    FROM Person p
    WHERE EXTRACT(MONTH FROM birthdate) = month_num;
    
    IF NOT FOUND THEN
    RAISE EXCEPTION 'No persons found with a birthday in month %', month_num;
    ELSE
    RAISE NOTICE 'Persons found with a birthday in month % : %',month_num,name;
    END IF;
END;
$$ LANGUAGE plpgsql;


