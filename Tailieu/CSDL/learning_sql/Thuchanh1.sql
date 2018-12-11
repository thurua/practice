--4.1 select
select * from CHUNHAN
select * from CONGNHAN 
select * from THIETKE
select * from THAMGIA
select * from KIENTRUCSU

select a. * from CHUNHAN a --tao alias

select a.MSCH, a.TENCHU from CHUNHAN a
select b.DIACHITHAU, b.DIENTHOAI, b.MSCT, b.TENTHAU from CHUTHAU b

select b.DIACHITHAU, b.DIENTHOAI, b.MSCT, b.TENTHAU,'TC'+ convert(varchar,  b.MSCT) KIHIEU  from CHUTHAU b

--4.2 distinct
select a.PHAI from CHUNHAN a

select distinct a.PHAI from CHUNHAN a --loc nhung du lieu trung lap

select distinct a.CHUYENMON from CONGNHAN a

--4.3 where
select * from CHUNHAN where DIACHICHU = '85 Mau Than'

--4.4 and, or
select DIACHICHU, MSCH from CHUNHAN where DIACHICHU LIKE '%o%' and MSCH=001

select MSCH, TENCHU, DIACHICHU from CHUNHAN where DIACHICHU LIKE '%o%' and TENCHU like '%g' or MSCH=001

select MSCH, TENCHU, DIACHICHU from CHUNHAN where TENCHU like '%g' and MSCH=001 or DIACHICHU LIKE '%o%'

select MSCH, TENCHU, DIACHICHU from CHUNHAN where DIACHICHU LIKE '%o%' and MSCH=001 or TENCHU like '%g'

select MSCH, TENCHU, DIACHICHU from CHUNHAN where (DIACHICHU LIKE '%o%' or DIACHICHU LIKE '%h') and MSCH=001 

--4.5 in
select * from CHUNHAN where DIACHICHU in ('54 Xo Viet Nghe Tinh', '29 Nguyen Van Troi')

--4.6 between
select * from CHUNHAN where MSCH between 4 and 10

--4.7 wildcard
select NGAYSINH from CONGNHAN where NGAYSINH like '%_%'

--4.8 like 
select HOTENCN from CONGNHAN where HOTENCN like 'L%'

--4.9 order by
select HOTENCN from CONGNHAN order by HOTENCN asc --tang dan 
select HOTENCN from CONGNHAN order by HOTENCN
select HOTENCN from CONGNHAN order by HOTENCN desc --giam dan

--4.10 group by
select MSKTS, sum(STTCT) [SUM] from THIETKE group by MSKTS
select MSKTS, avg(STTCT) [AGV] from THIETKE group by MSKTS
select MSKTS, count(STTCT) [COUNT] from THIETKE group by MSKTS
select MSKTS, min (STTCT) [MIN] from THIETKE group by MSKTS
select MSKTS, max(STTCT) [MAX] from THIETKE group by MSKTS
select MSKTS, sum(STTCT), count(STTCT), min (STTCT), max(STTCT), avg(STTCT) from THIETKE group by MSKTS 

--4.11 having
select MSKTS, sum(STTCT), count(STTCT), min (STTCT), max(STTCT), avg(STTCT) from THIETKE group by MSKTS having sum(STTCT) >= 15

--5.1 insert into
insert into CONGNHAN(MSCN, HOTENCN, NGAYSINH, PHAI, CHUYENMON) values ('016', 'Nguyen Ngoc Huyen', 1995-09-17, 'Nu', 'may')

--5.2 insert into select
insert into KIENTRUCSU(MSKTS, HOTENKTS, NGAYSINH, PHAI, NOITN, DIACHIKTS ) 
select MSCN, HOTENCN, NGAYSINH, '0', 'Ha Noi', '34 Mau Than-Can Tho' 
from CONGNHAN 
where MSCN = '011'

--6 update
update THIETKE
set THULAO = THULAO*2 
where STTCT = '6'
select * from THIETKE

--7 delete
delete THIETKE
where THULAO = '6'
select * from THIETKE

--8.1 count
select count(THULAO) [COUNT] from THIETKE

--8.2 sum
select sum(THULAO) [SUM] from THIETKE

--8.3 avg
select avg(THULAO) [AVG] from THIETKE

--8.4 min
select min(THULAO) [MIN] from THIETKE

--8.5 max
select max(THULAO) [MAX] from THIETKE

--9.1 join
select MSCN, NGAYTG, SONGAY from THAMGIA
join THIETKE
on THAMGIA.STTCT=THIETKE.STTCT

--9.2 left join
select MSCN, NGAYTG, SONGAY from THAMGIA
left join THIETKE
on THAMGIA.STTCT=THIETKE.STTCT

--9.3 right join
select MSCN, NGAYTG, SONGAY from THAMGIA
right join THIETKE
on THAMGIA.STTCT=THIETKE.STTCT

--9.4 full join 
select MSCN, NGAYTG, SONGAY from THAMGIA
full join THIETKE
on THAMGIA.STTCT=THIETKE.STTCT

--10.1 Subquery trong mệnh đề Where
select b.DIACHITHAU, b.DIENTHOAI, b.MSCT, b.TENTHAU from CHUTHAU b
Where   b.MSCT In
      (Select  c.MSCT From CHUTHAU c Where c.TENTHAU like '%B%'

--10.2 Subquery trong mệnh đề From
select a.STTCT, a.MSCN, a.NGAYTG, a.SONGAY from THAMGIA a,
(select b.STTCT, sum(b.THULAO) [SUM] from THIETKE b
group by b.STTCT) c 
where a.STTCT=c.STTCT
select * from THIETKE 
 
--10.3 Subquery trong mệnh đề select
select a.STTCT, a.MSCN, a.NGAYTG, a.SONGAY,
(select sum(b.THULAO) from THIETKE b 
where a.STTCT=b.STTCT) [MAX] 
from THAMGIA a





