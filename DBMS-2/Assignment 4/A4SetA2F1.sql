CREATE OR REPLACE FUNCTION count_teachers_for_student(student_name VARCHAR)
RETURNS INTEGER AS $$
DECLARE
    teacher_count INTEGER;
BEGIN
    -- Count the number of teachers teaching to the specified student
    SELECT COUNT(DISTINCT tno) INTO teacher_count
    FROM Student_Teacher
    JOIN Student ON Student.sno = Student_Teacher.sno
    WHERE Student.s_name = student_name;
    
    -- If no student exists, return 0 or raise an exception
    IF teacher_count = 0 THEN
        RAISE EXCEPTION 'Student name does not exist';
    END IF;
    
    RETURN teacher_count;
END;
$$ LANGUAGE plpgsql;


