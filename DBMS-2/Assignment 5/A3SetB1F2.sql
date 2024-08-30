CREATE OR REPLACE FUNCTION A5B1F2()
RETURNS VOID AS $$
DECLARE
    rt Trip%ROWTYPE;

    c_b1b CURSOR FOR
        SELECT t.tno,from_city,to_city,departure_date,return_date FROM Trip t,Expense e WHERE
        t.tno = e.tno order by amount DESC LIMIT 1;
BEGIN
    OPEN c_b1b;
    
    LOOP
        FETCH  c_b1b INTO rt;
        EXIT WHEN NOT FOUND;
        
        RAISE NOTICE '% || % || % || % || % ||',rt.tno,rt.from_city,rt.to_city,rt.departure_date,rt.return_date;

    END LOOP;
    
    CLOSE c_b1b;
END;
$$ LANGUAGE plpgsql;