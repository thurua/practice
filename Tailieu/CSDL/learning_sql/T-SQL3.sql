begin

select
	HOTEN ,
	DIACHI ,
	20 TUOI into #TABLE1
from Hoctap2
where CMND=3478;

update #TABLE1
set TUOI=TUOI+2
where HOTEN = 'NguyenThiNgoc'

select * from #TABLE1

end;
	