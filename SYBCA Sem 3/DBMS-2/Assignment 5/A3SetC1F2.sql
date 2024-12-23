CREATE OR REPLACE FUNCTION A5C1F2(name CHAR)
RETURNS VOID AS $$

DECLARE
    num Customer.cno%TYPE;

    c_c1b CURSOR FOR
    SELECT c.cno FROM Customer c,Ternary t,Branch b WHERE
    c.cno = t.cno AND t.br_id = b.br_id AND br_name = name;

    cnt INTEGER = 0;

BEGIN
    OPEN c_c1b;
    
    LOOP
        FETCH c_c1b INTO num;
        EXIT WHEN NOT FOUND;
        
        cnt = cnt + 1;

    END LOOP;
    
    CLOSE c_c1b;

    RAISE NOTICE 'COUNT : %',cnt;
END;
$$ LANGUAGE plpgsql;