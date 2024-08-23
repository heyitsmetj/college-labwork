CREATE OR REPLACE FUNCTION A3B2F2 (bname VARCHAR) RETURNS VOID AS
$$

DECLARE

r RECORD;

BEGIN 

FOR r IN 
SELECT c.c_name,la.lno,la.l_amt_approved FROM
Customer c,Branch b,Loan_application la,Ternary t WHERE
c.cno = t.cno AND t.br_id = b.br_id AND la.lno = t.lno AND
b.br_name = bname AND la.l_date >= '2019-06-01'
LOOP

RAISE NOTICE '% || % || %',r.c_name,r.lno,r.l_amt_approved;

END LOOP;

END;
$$ LANGUAGE plpgsql;