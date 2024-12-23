CREATE OR REPLACE FUNCTION A3B2F1 (bname VARCHAR) RETURNS VOID AS
$$

DECLARE

r RECORD;

BEGIN 

FOR r IN 
select c.* FROM Branch b,Customer c,Loan_application la,Ternary t WHERE
b.br_id = t.br_id AND la.lno = t.lno AND c.cno = t.cno AND
b.br_name = bname AND la.l_amt_required > la.l_amt_approved 
LOOP

RAISE NOTICE '% || % || % || %',r.cno,r.c_name,r.caddr,r.city;

END LOOP;

END;
$$ LANGUAGE plpgsql;