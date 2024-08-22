CREATE OR REPLACE FUNCTION A3B2F4()
RETURNS VOID AS 
$$

DECLARE

r RECORD;

BEGIN

FOR r IN
        SELECT c.cno, c.c_name, c.caddr, c.city, COUNT(DISTINCT t.br_id) AS branch_count
        FROM Customer c, Ternary t
        WHERE c.cno = t.cno
        GROUP BY c.cno, c.c_name, c.caddr, c.city
        HAVING COUNT(DISTINCT t.br_id) > 1
    LOOP
        RAISE NOTICE 'Customer ID: %, Name: %, Address: %, City: %, Branch Count: %',
            r.cno, r.c_name, r.caddr, r.city,
            r.branch_count;
    END LOOP;

END;

$$ LANGUAGE plpgsql;
