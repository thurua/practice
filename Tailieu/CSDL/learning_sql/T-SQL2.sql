begin
 --declare @CMNDD integer = 3478;

declare @TABLE table(
	HOTEN varchar(20),
	DIACHI varchar(20),
	TUOI integer
	)

insert into @TABLE(HOTEN, DIACHI, TUOI)
select HOTEN, DIACHI, 20
from Hoctap2
where CMND=3478;

update @TABLE
set TUOI=TUOI+2
where HOTEN = 'NguyenThiNgoc'

delete @TABLE
where TUOI=20+2 

insert into @TABLE(HOTEN, DIACHI, TUOI)
select HOTEN, DIACHI, 23
from Hoctap2
where CMND=2841;

select * from @TABLE
where TUOI=23
order by HOTEN

end;