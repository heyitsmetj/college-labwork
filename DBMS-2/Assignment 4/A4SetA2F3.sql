CREATE OR REPLACE FUNCTION get_teachers_by_qualification(teacher_qualification VARCHAR)
RETURNS TABLE(tno INTEGER, t_name VARCHAR, qualification VARCHAR, experience INTEGER) AS $$
BEGIN
    -- Return teacher details for the given qualification
    RETURN QUERY
    SELECT tno, t_name, qualification, experience
    FROM Teacher
    WHERE qualification = teacher_qualification;
    
    -- If no teachers exist with the qualification, raise an exception
    IF NOT FOUND THEN
        RAISE EXCEPTION 'Invalid qualification';
    END IF;
END;
$$ LANGUAGE plpgsql;


