create or replace function A4A2F3(qualif CHAR) returns void as $$
DECLARE
    t_cnt int;
BEGIN
    select tname from teacher where qualiification=qualif;
    
    IF NOT FOUND THEN 
    RAISE EXCEPTION 'Invalid Qualification!';
    
    ELSE 
    RAISE NOTICE '% ',tname;
    
    END IF;
    
END;
$$ language 'plpgsql'  

