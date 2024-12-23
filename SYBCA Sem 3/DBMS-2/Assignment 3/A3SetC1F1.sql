CREATE OR REPLACE FUNCTION A3C1F1() RETURNS VOID AS $$
DECLARE
    me RECORD;
BEGIN

SELECt t.*,e.amount INTO me
FROM Trip t,Expense e WHERE
t.tno = e.tno ORDER BY e.amount DESC LIMIT 1;
    
RAISE NOTICE '% || % || % || % || % || %',me.tno,me.from_city,me.to_city,me.departure_date,me.return_date,me.amount;

END;

$$ LANGUAGE plpgsql;
