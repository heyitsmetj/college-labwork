CREATE OR REPLACE FUNCTION A5C1F3()
RETURNS VOID AS $$

DECLARE

c_c1c CURSOR FOR
SELECT lno,l_amt_approved FROM Loan_Application;

loan_id Loan_Application.lno%TYPE;
approved_amt Loan_Application.l_amt_approved%TYPE;

BEGIN
    OPEN c_c1c;
    
    LOOP
        FETCH c_c1c INTO loan_id,approved_amt;
        EXIT WHEN NOT FOUND;
    
        UPDATE Loan_Application SET l_amt_approved =(l_amt_approved::NUMERIC * 1.35)::MONEY
        WHERE lno = loan_id;

    RAISE NOTICE 'Loan ID : % , Updated Approved Amount : % ',loan_id,(approved_amt::NUMERIC * 1.35)::MONEY;
    END LOOP;
    
    CLOSE c_c1c;

END;
$$ LANGUAGE plpgsql;