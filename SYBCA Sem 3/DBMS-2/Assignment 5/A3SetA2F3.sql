CREATE OR REPLACE FUNCTION A5A2F3()
RETURNS VOID AS $$
DECLARE
    pr RECORD;

    c_a2c CURSOR FOR
        SELECT p.p_name, COUNT(DISTINCT mp.m_name) as movie_count
        FROM Movie_Actor ma,Producer p,Movie_Producer mp WHERE p.producer_id = mp.producer_id AND
         mp.m_name = ma.m_name AND ma.a_name = 'Amitabh Bachchan'
        GROUP BY p.p_name
        HAVING COUNT(DISTINCT mp.m_name) > 2;
BEGIN
    OPEN c_a2c;
    
    LOOP
        FETCH  c_a2c INTO pr;
        EXIT WHEN NOT FOUND;
        
        RAISE NOTICE 'Producer: % has produced % movies with Amitabh Bachchan',pr.p_name, pr.movie_count;
    END LOOP;
    
    CLOSE c_a2c;
END;
$$ LANGUAGE plpgsql;