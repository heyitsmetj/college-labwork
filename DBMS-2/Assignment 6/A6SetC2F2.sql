CREATE OR REPLACE FUNCTION A6C2F2() RETURNS TRIGGER AS
$$

BEGIN 

IF NEW.l_amt_approved > NEW.l_amt_required THEN

RAISE EXCEPTION 'Loan amount approved cannot be greater than Loan amount required.';

END IF;

RETURN NEW;

END;
$$ LANGUAGE plpgsql;

