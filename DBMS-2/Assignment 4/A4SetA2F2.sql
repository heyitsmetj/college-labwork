CREATE OR REPLACE FUNCTION count_students_for_subject(subject_name VARCHAR)
RETURNS INTEGER AS $$
DECLARE
    student_count INTEGER;
BEGIN
    -- Count the number of students for the specified subject
    SELECT COUNT(DISTINCT sno) INTO student_count
    FROM Student_Teacher
    WHERE subject = subject_name;
    
    -- If no students exist for the subject, return 0 or raise an exception
    IF student_count = 0 THEN
        RAISE EXCEPTION 'Subject name does not exist';
    END IF;
    
    RETURN student_count;
END;
$$ LANGUAGE plpgsql;


