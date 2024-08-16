CREATE OR REPLACE FUNCTION A3A2F2 () RETURNS VOID AS
$$

DECLARE
r record;
i person.income%type;
update_income person.income%type;
BEGIN 
for r in 
select income into i from person,area  where person.aname=area.aname and area_type='urban' loop 
update_income=i+ (i *0.2);
raise notice '%',update_income ;
end loop;
END;
$$ LANGUAGE plpgsql;

