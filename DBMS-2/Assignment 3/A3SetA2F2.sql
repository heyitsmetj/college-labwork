CREATE OR REPLACE FUNCTION A3A2F2() RETURNS VOID AS 
$$
DECLARE 

BEGIN
UPDATE Person
SET income = (income::numeric * 1.20)::money
WHERE aname IN (SELECT a.aname
FROM Person p, Area a
WHERE p.aname = a.aname AND a.area_type = 'urban');

END;

$$ LANGUAGE plpgsql;
