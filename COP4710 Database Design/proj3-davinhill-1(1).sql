--  Before you try the code in this file from the psql client, you need to create your database NBA-xxx and copy data from NBA to it. For example,
--  createdb NBA-tuy
--  pg_dump -t player_rs_career NBA | psql NBA-tuy
--  Note that those should be done under the Linux console. Then you can log into NBA-xxx and try the following scripts.

--  The following line only needs to be executed once before you do anything at all with pgplsql functions
-- CREATE LANGUAGE 'plpgsql';


-- function 1 declaration

CREATE OR REPLACE FUNCTION nba_efficiency (fn VARCHAR, lsn VARCHAR) RETURNS int AS $$
DECLARE
Efficiency int:=0;
BEGIN
-- the function body goes here

SELECT into Efficiency (PSC.pts + PSC.reb + PSC.stl + PSC.asts + PSC.blk - PSC.turnover - ((PSC.fga - PSC.fgm) + (PSC.fta - PSC.ftm) + (PSC.tpa - PSC.tpm)))
FROM player_rs_career as PSC 
WHERE(PSC.firstname = $1 AND PSC.lastname = $2);
IF Efficiency IS NULL
THEN
RETURN 0;
Else
return Efficiency;
END IF;

END;
$$ LANGUAGE plpgsql;


-- function 2 declaration

CREATE OR REPLACE FUNCTION body_mass_index (fn VARCHAR, lsn VARCHAR) RETURNS float AS $$
DECLARE
BMI float :=0.0;
BEGIN

SELECT into BMI (((weight*0.45) / ((P.h_feet*12*2.54 + P.h_inches*2.54)*(P.h_feet*12*2.54 + P.h_inches*2.54)))*10000)
FROM players as P
WHERE(P.firstname = $1 AND P.lastname = $2);


IF BMI IS NULL
THEN
Return 0;
Else
return BMI;

END IF;

END

$$ LANGUAGE plpgsql;
