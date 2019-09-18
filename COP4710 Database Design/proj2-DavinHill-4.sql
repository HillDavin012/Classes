--1
SELECT t1.firstname, t1.lastname, t1.cid  FROM(SELECT firstname, lastname, cid, COUNT(DISTINCT tid) AS num_teams FROM coaches_season GROUP BY firstname, lastname, cid) AS t1 WHERE(num_teams = 1) ORDER BY lastname;

--2
SELECT DISTINCT a.firstname, a.ilkid FROM player_rs a, player_rs b WHERE(a.tid = 'DEN' AND b.tid = 'BOS' AND a.ilkid = b.ilkid);

--3
SELECT C.firstname , C.lastname , C.year , T.name FROM coaches_season C, player_rs p, teams T WHERE (C.tid = p.tid AND C.tid = T.tid AND T.tid = p.tid AND C.year = p.year AND C.cid = p.ilkid) ORDER BY YEAR;

--4
SELECT b.name, a.firstname, a.lastname, c.year, AVG ((d.h_feet*30.48)+ (d.h_inches*2.54)) AS Avg_h FROM coaches_season a JOIN teams b ON b.tid = a.tid AND a.year = 2001 JOIN player_rs c ON (c.tid = b.tid AND c.year = 2001) JOIN players d ON d.ilkid = c.ilkid GROUP BY a.firstname, b.name, c.year, a.lastname ORDER BY Avg_h DESC;

--5
SELECT a.firstname, a.lastname, a.cid FROM coaches_season a, player_rs c WHERE (a.year = 1999 AND a.tid = c.tid AND c.year = 1999) GROUP BY a.firstname, a.lastname, a.cid HAVING COUNT(DISTINCT c.ilkid) = (SELECT max(t2.player_num) FROM (SELECT count(*) AS player_num FROM coaches_season c2, player_rs p2 WHERE(c2.year = 1999 AND c2.tid = p2.tid AND p2.year = 1999) GROUP BY c2.cid)T2);

--6
SELECT DISTINCT  a.firstname, a.lastname, a.cid FROM coaches_season a JOIN teams b ON b.tid = a.tid JOIN player_rs c ON (c.tid = b.tid)  GROUP BY a.firstname, a.cid, a.lastname HAVING COUNT(DISTINCT b.league) > 1;

--7
SELECT a.firstname, a.lastname, a.year, d.name, c.name FROM coaches_season a, player_rs b, teams c, teams d WHERE (a.tid = c.tid AND b.tid = d.tid AND c.tid != d.tid AND a.year = b.year AND a.cid = b.ilkid);

--8
SELECT t1.firstname, t1.lastname, (t1.pts-(SELECT t2.pts FROM player_rs_career t2 WHERE(t2.firstname = 'Michael' AND t2.lastname='Jordan')))AS Points FROM player_rs_career t1 WHERE(t1.pts >(SELECT t2.pts FROM player_rs_career t2 WHERE(t2.firstname = 'Michael' AND t2.lastname='Jordan')));

--9
SELECT DISTINCT firstname, lastname, SUM(1.00*season_win)/(SUM(1.00*season_win+1.00*season_loss)) as successlevel 
FROM coaches_season 
GROUP BY lastname, firstname
ORDER BY successlevel DESC OFFSET 1 ROWS FETCH NEXT 1 ROW ONLY;

--10
SELECT draft_from, COUNT(DISTINCT ilkid) AS myCount FROM draft WHERE league = 'N' or league ='B' or league ='A' GROUP BY draft_from ORDER BY myCount DESC LIMIT 3;