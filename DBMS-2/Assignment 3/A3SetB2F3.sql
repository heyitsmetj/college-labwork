CREATE OR REPLACE FUNCTION A3B2F3()
RETURNS VOID AS 
$$
DECLARE

 total_approved MONEY;

BEGIN

SELECT SUM(l_amt_approved)
INTO total_approved
FROM Loan_application
WHERE l_date > '2019-05-30';

RAISE NOTICE 'Total Loan Amount Approved After 30/05/2019: %', total_approved;

END;
$$ LANGUAGE plpgsql;
