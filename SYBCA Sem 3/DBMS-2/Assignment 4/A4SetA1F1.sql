CREATE OR REPLACE FUNCTION A4A1F1(name VARCHAR)
RETURNS VOID AS $$
DECLARE
    person_count INTEGER;
BEGIN

    SELECT COUNT(*) INTO person_count
    FROM Person
    WHERE aname = name;

    IF person_count = 0 THEN
        RAISE EXCEPTION 'Invalid Area Name: %',name;
    ELSE
        RAISE NOTICE 'Total persons in % is : %',name,person_count;
    END IF;
END;
$$ LANGUAGE plpgsql;
