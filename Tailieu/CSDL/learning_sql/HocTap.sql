use HOCTAP
go
create table Hoctap2
(
     CMND int primary key,
	 HOTEN nvarchar(20) not null,
	 DIACHI nvarchar(20) not null
)
go

select * from Hoctap2

insert into Hoctap2(CMND, HOTEN, DIACHI) values (3478, 'NguyenThiNgoc', 'DongThap'), (2841, 'TranThiLan', 'LongAn')

select * from Hoctap2

create table Hoctap3 
(
     NAMSINH int primary key,
	 GIOITINH nvarchar(5) not null,
	 NGHENGHIEP nvarchar(20) not null
)
go

select * from Hoctap3

insert into Hoctap3(NAMSINH, GIOITINH, NGHENGHIEP ) values (1999, 'Nu', 'SinhVien'), (1990, 'Nu', 'GiaoVien'), (2000, 'Nam', 'HocSinh')

select * from Hoctap3



