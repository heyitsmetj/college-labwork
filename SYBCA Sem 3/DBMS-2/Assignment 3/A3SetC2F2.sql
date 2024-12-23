CREATE OR REPLACE FUNCTION A3C2F2() RETURNS VOID AS 
$$

DECLARE

BEGIN

    UPDATE TICKET
    SET status = 'C'
    WHERE passenger_id = (SELECT passenger_id FROM PASSENGER WHERE passenger_name = 'Rohan Mohite')
    AND status = 'W';
    
    RAISE NOTICE 'Status of the ticket for passenger Mr.Mohite has been updated to Confirmed';

END;

$$ LANGUAGE plpgsql;
