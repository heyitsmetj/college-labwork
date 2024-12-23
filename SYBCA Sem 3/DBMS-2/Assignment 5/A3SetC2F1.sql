CREATE OR REPLACE FUNCTION A5C2F1 (p_date DATE,p_name VARCHAR)
RETURNS VOID AS 
$$

DECLARE

berths INTEGER = 0;
total_amt DECIMAL(7,2) = 0.00;

c_c2a CURSOR FOR
SELECT t.no_of_berths,t.ticket_amt FROM
Ticket t,Passenger p WHERE t.passenger_id = p.passenger_id
AND t.tdate = p_date AND p.passenger_name = p_name;

rec RECORD;

BEGIN

OPEN c_c2a;
LOOP

FETCH c_c2a INTO rec;
EXIT WHEN NOT FOUND;

berths = berths + rec.no_of_berths;
total_amt = total_amt + rec.ticket_amt;

END LOOP;
CLOSE c_c2a;

RAISE NOTICE 'Passenger : % , Date : % , Total Berths Reserved : % , Total Amount Paid : % ',p_name,p_date,berths,total_amt;

END;
$$ LANGUAGE plpgsql;