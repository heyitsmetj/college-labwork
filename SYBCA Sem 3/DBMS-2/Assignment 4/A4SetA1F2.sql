CREATE OR REPLACE FUNCTION A4A1F2(a_type VARCHAR)
RETURNS VOID AS $$
DECLARE
    total_income MONEY;
BEGIN

    SELECT SUM(income) INTO total_income
    FROM Person p,Area a WHERE p.aname = a.aname
    AND a.area_type = a_type;
    
    IF total_income IS NULL THEN
        RAISE EXCEPTION 'Invalid area type % or no data available.',a_type;
    ELSE
        RAISE NOTICE 'Total income in % areas: %',a_type,total_income;
    END IF;
END;
$$ LANGUAGE plpgsql;


