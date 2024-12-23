CREATE OR REPLACE FUNCTION A3C2F1() RETURNS VOID AS 
$$

DECLARE

    total_amt DECIMAL(7,2);

BEGIN

    SELECT SUM(ticket_amt) INTO total_amt
    FROM TICKET
    WHERE tdate = '2019-12-12';
    
    RAISE NOTICE 'Total ticket amount paid by all passengers on 2019-12-12 is %',total_amt;

END;

$$ LANGUAGE plpgsql;
