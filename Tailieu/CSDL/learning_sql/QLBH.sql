USE QLBH
GO
CREATE TABLE KHACHHANG
(
   MSKH INT PRIMARY KEY,
   HOTEN NVARCHAR(30) NOT NULL,
   NGAYSINH DATE NOT NULL,
   DIACHI NVARCHAR(30) NOT NULL,
   SODT NVARCHAR(20) NOT NULL,
   DOANHSO INT,
   NGAYDK DATE
)
GO
SELECT * FROM KHACHHANG

INSERT INTO KHACHHANG(MSKH, HOTEN, NGAYSINH, DIACHI, SODT, DOANHSO, NGAYDK) VALUES 
(101, 'NGUYEN THI ANH THU', '1999-09-19', '34 LI TU TRONG', '0164758380',1080000, '2018-08-12'),
(102, 'LA THI MY TU', '1999-11-13', '76 NGO QUYEN', '0163387122', 1260000, '2016-09-24'),
(103, 'LE THI THUY VY', '1999-09-08', '15 LI TU TRONG', '0265879446', 1040000, '2017-05-18'),
(104, 'TRAN NAM', '1996-03-18', '167 NGUYEN TRAI', '01472891285', 1200000, '2018-11-20'),
(105, 'TRAN NGOC LAN VY', '1997-02-04', '3 MAU THAN', '0167478322', 1190000, '2018-10-11'),
(106, 'NNGUYEN HA', '1990-12-24', '34 LI TU TRONG', '0164758380', 1680000, '2016-07-16')

SELECT * FROM KHACHHANG

CREATE TABLE NHANVIEN
(
   MANV INT PRIMARY KEY,
   HOTEN NVARCHAR(30) NOT NULL,
   NGAYVL DATE,
   SODT NVARCHAR(20) NOT NULL, 
)
GO
SELECT * FROM NHANVIEN

INSERT INTO NHANVIEN(MANV, HOTEN, NGAYVL, SODT) VALUES 
(201, 'NGUYEN NGOC NHI', '2015-03-11', '0122748576'),
(202, 'LE THI NGOC', '2017-09-25', '0334768552'),
(203, 'NGUYEN YEN', '2016-08-18', '0367839212'),
(204, 'TRAN LAM ANH', '2017-06-28', '0375560114')

SELECT * FROM NHANVIEN

CREATE TABLE SANPHAM
(
   MASP INT PRIMARY KEY,
   TENSP NVARCHAR(30) NOT NULL,
   DVT NVARCHAR(10) NOT NULL,
   NUOCSX NVARCHAR(20) NOT NULL, 
   GIA INT
)
GO
SELECT * FROM SANPHAM

INSERT INTO SANPHAM(MASP, TENSP, DVT, NUOCSX, GIA) VALUES 
(301, 'AO BABY DOLL', 'DONG', 'VIET NAM', 160000),
(302, 'CHAN VAY TENNIS', 'DONG', 'VIET NAM', 150000),
(303, 'AO NHUN TAY BEO', 'DONG', 'VIET NAM', 270000),
(304, 'AO KHOAT KAKI', 'DONG', 'VIET NAM', 300000),
(305, 'QUAN JEAN DEN','DONG' ,'VIET NAM', 220000),
(306, 'AO KHOAT JEAN', 'DONG', 'VIET NAM', 350000 ),
(307, 'QUAN SORT KAKI', 'DONG', 'VIET NAM', 250000),
(308, 'AO CROPTOP', 'DONG', 'VIET NAM', 150000),
(309, 'AO THUN TAY NGAN', 'DONG', 'VIET NAM', 100000),
(310, 'QUAN BAGGY JEAN', 'DONG', 'VIET NAM', 260000),
(311, 'AO SO MI', 'DONG', 'VIET NAM', 440000)

SELECT * FROM SANPHAM
IF EXISTS (SELECT * FROM SYSOBJECTS WHERE NAME = 'HOADON')
drop table HOADON;
CREATE TABLE HOADON
(
   SOHD INT PRIMARY KEY,
   NGHD NVARCHAR(30) NOT NULL,
   MAKH NVARCHAR(30) NOT NULL,
   MANV INT,
   TRIGIA INT
)
GO
alter table HOADON
add toan NVARCHAR(30) NOT NULL

alter table HOADON
ALTER  column toan NVARCHAR(90) NOT NULL

alter table HOADON
drop  column toan

alter table HOADON
add  THU NVARCHAR(90) NOT NULL

SELECT * FROM HOADON

INSERT INTO HOADON(SOHD, NGHD, MAKH, MANV, TRIGIA) VALUES
(401, '2018-09-19', 101, 201, 480000),
(402, '2018-11-03', 101, 202, 600000),
(403, '2017-12-05', 102, 201, 810000),
(404, '2018-06-15', 103, 203, 600000),
(405, '2018-08-25', 103, 204, 440000),
(406, '2017-11-23', 104, 202, 700000),
(407, '2018-07-04', 104, 203, 500000),
(408, '2018-10-12', 105, 203, 750000),
(409, '2018-05-30', 106, 203, 900000),
(410, '2018-01-04', 106, 204, 780000),
(411, '2017-02-17', 105, 202, 440000),
(412, '2017-02-17', 102, 204, 450000),
(413, '2017-02-17', NULL, 201, 1000000),
(414, '2017-02-17', NULL, 202, 1100000)

SELECT * FROM HOADON

CREATE TABLE CTHD
(
   SOHD INT PRIMARY KEY,
   MASP INT,
   SOLUONG INT
)
GO
SELECT * FROM CTHD

INSERT INTO CTHD(SOHD, MASP, SOLUONG) VALUES
(401, 301, 3),
(402, 302, 4),
(403, 303, 3),
(404, 304, 2),
(405, 305, 2),
(406, 306, 2),
(407, 307, 2),
(408, 308, 5),
(409, 309, 9),
(410, 310, 3),
(411, 311, 1),
(412, 302, 3),
(413, 307, 4),
(414, 305, 5)
SELECT * FROM CTHD