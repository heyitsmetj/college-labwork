CREATE OR REPLACE FUNCTION A6A1F2() RETURNS TRIGGER AS
$$

BEGIN 

    RAISE NOTICE 'The student with number: % is being updated from class % to class %.',OLD.s_no,OLD.s_class,NEW.s_class;

RETURN NEW;

END;
$$ LANGUAGE plpgsql;

