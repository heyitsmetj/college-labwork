CREATE OR REPLACE FUNCTION A5B2F2()
RETURNS VOID AS $$

DECLARE
    cn Customers.cname%TYPE;

    c_b2b CURSOR FOR
        SELECT DISTINCT c.cname FROM 
        Customers c,Orders o,Order_Items oi,Items i WHERE
         c.cno = o.cno AND o.ono = oi.ono AND oi.itemno = i.itemno
        AND i.cost BETWEEN 50000 AND 100000;

BEGIN
    OPEN c_b2b;
    
    LOOP
        FETCH c_b2b INTO cn;
        EXIT WHEN NOT FOUND;
        
        RAISE NOTICE 'Customer Name: %',cn;
    END LOOP;
    
    CLOSE c_b2b;
END;
$$ LANGUAGE plpgsql;