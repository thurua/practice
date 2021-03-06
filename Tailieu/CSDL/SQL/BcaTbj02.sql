/* Bca tbj cso dul sfi 2 - Bai tap co so du lieu so 2.
Ica 26/11/2006, Tbs: Zng Tfy, Tcc: Kos Gre.
Mha ads teh seo lec hcr alxkhi@yahoo.com - Moi chi tiet xin lien he alxkhi@yahoo.com.
*/
--> Sfs, tbs lcc cso dul ALXKHI - Xoa, tao lai co so du lieu ALXKHI.
USE MASTER
GO

IF EXISTS (SELECT * FROM SYSDATABASES WHERE NAME = 'ALXKHI')
DROP DATABASE ALXKHI
GO

CREATE DATABASE ALXKHI
GO

--> Dka ALXKHI, tbs cbk bau dul - Dung ALXKHI, tao cac bang du lieu.
USE ALXKHI
GO

--> Bau SVIEN
CREATE TABLE SVIEN
(
	TENSV	VARCHAR (12)	NULL,
	MASV	VARCHAR (12)	NOT NULL,
	NAM	INT		NULL,
	KHOA	VARCHAR (12)	NULL,
CONSTRAINT PK_SVIEN PRIMARY KEY (MASV)
)
GO

--> Bau MHOC
CREATE TABLE MHOC
(
	TEN_MH	VARCHAR (50)	NULL,
	MAMH	VARCHAR (12)	NOT NULL,
	TINCHI	INT		NULL,
	KHOA	VARCHAR (12)	NULL,
CONSTRAINT PK_MHOC PRIMARY KEY (MAMH)
)
GO

--> Bau DKIEN
CREATE TABLE DKIEN
(
	MAMH		VARCHAR (12)	NOT NULL,
	MAMH_TRUOC	VARCHAR (12)	NOT NULL,
CONSTRAINT PK_DKIEN PRIMARY KEY (MAMH, MAMH_TRUOC)
)
GO

--> Bau K_HOC
CREATE TABLE K_HOC
(
	MAKH	VARCHAR (12)	NOT NULL,
	MAMH	VARCHAR (12)	NULL,
	HOCKY	INT		NULL,
	NAM	INT		NULL,
	GV	VARCHAR (12)	NULL,
CONSTRAINT PK_K_HOC PRIMARY KEY (MAKH)
)
GO

--> Bau KQUA
CREATE TABLE KQUA
(
	MASV	VARCHAR (12)	NOT NULL,
	MAKH	VARCHAR (12)	NOT NULL,
	DIEM	INT		NULL,
CONSTRAINT PK_KQUA PRIMARY KEY (MASV, MAKH)
)
GO

--> Tbs cbk efs igo - Tao cac khoa ngoai.
--> Bau DKIEN
ALTER TABLE DKIEN ADD
CONSTRAINT FK_DKIEN_MAMH FOREIGN KEY (MAMH)
REFERENCES MHOC (MAMH),
CONSTRAINT FK_DKIEN_MAMH_TRUOC FOREIGN KEY (MAMH_TRUOC)
REFERENCES MHOC (MAMH)
GO

--> Bau K_HOC
ALTER TABLE K_HOC ADD
CONSTRAINT FK_K_HOC_MAMH FOREIGN KEY (MAMH)
REFERENCES MHOC (MAMH)
GO

--> Bau KQUA
ALTER TABLE  KQUA ADD
CONSTRAINT FK_KQUA_MASV FOREIGN KEY (MASV)
REFERENCES SVIEN (MASV),
CONSTRAINT FK_KQUA_MAKH FOREIGN KEY (MAKH)
REFERENCES K_HOC (MAKH)
GO

--> Obj dul afc cbk bau - Nhap du lieu cho cac bang.
--> Bau SVIEN
INSERT INTO SVIEN
VALUES ('SON', '17', 1, 'CNTT')
GO

INSERT INTO SVIEN
VALUES ('BAO', '8', 2, 'CNTT')
GO

INSERT INTO SVIEN
VALUES ('NAM', '7', 1, 'TOAN')
GO

INSERT INTO SVIEN
VALUES ('TUNG', '2', 1, 'TOAN')
GO

INSERT INTO SVIEN
VALUES ('NU', '1', 2, 'CNTT')
GO

INSERT INTO SVIEN
VALUES ('HANH', '16', 2, 'TOAN')
GO

INSERT INTO SVIEN
VALUES ('HANG', '15', 2, 'CNTT')
GO

--> Bau MHOC
INSERT INTO MHOC
VALUES ('NHAP MON TIN HOC', 'COSC1310', 4, 'CNTT')
GO

INSERT INTO MHOC
VALUES ('CAU TRUC DU LIEU', 'COSC3320', 4, 'CNTT')
GO

INSERT INTO MHOC
VALUES ('TOAN ROI RAC', 'MATH2410', 3, 'TOAN')
GO

INSERT INTO MHOC
VALUES ('CO SO DU LIEU', 'COSC3380', 3, 'CNTT')
GO

--> Bau DKIEN
INSERT INTO DKIEN
VALUES ('COSC3380', 'COSC3320')
GO

INSERT INTO DKIEN
VALUES ('COSC3380', 'MATH2410')
GO

INSERT INTO DKIEN
VALUES ('COSC3320', 'COSC1310')
GO

--> Bau K_HOC
INSERT INTO K_HOC
VALUES ('85', 'MATH2410', 1, 86, 'KIM')
GO

INSERT INTO K_HOC
VALUES ('92', 'COSC1310', 1, 86, 'AN')
GO

INSERT INTO K_HOC
VALUES ('102', 'COSC3320', 2, 87, 'NIEN')
GO

INSERT INTO K_HOC
VALUES ('112', 'MATH2410', 1, 87, 'CHAN')
GO

INSERT INTO K_HOC
VALUES ('119', 'COSC1310', 1, 87, 'AN')
GO

INSERT INTO K_HOC
VALUES ('135', 'COSC3380', 1, 87, 'SON')
GO

--> Bau KQUA
INSERT INTO KQUA
VALUES ('17', '112', 8)
GO

INSERT INTO KQUA
VALUES ('17', '119', 6)
GO

INSERT INTO KQUA
VALUES ('8', '85', 10)
GO

INSERT INTO KQUA
VALUES ('8', '92', 10)
GO

INSERT INTO KQUA
VALUES ('8', '102', 8)
GO

INSERT INTO KQUA
VALUES ('8', '135', 10)
GO

--> Alo vax dul - Truy van du lieu.
--> Cbt 01
--| Q = SVIEN [TENSV]
SELECT TENSV FROM SVIEN
GO

--> Cbt 02
--| Q = MHOC [TEN_MH, TINCHI]
SELECT TEN_MH, TINCHI FROM MHOC
GO

--> Cbt 03
--| Q = KQUA: MASV = '8' [*]
SELECT * FROM KQUA
WHERE MASV = '8'
GO

--> Cbt 04
--| Q = DKIEN: MAMH = 'COSC3320' [MAMH_TRUOC]
SELECT MAMH_TRUOC FROM DKIEN
WHERE MAMH = 'COSC3320'
GO

--> Cbt 05
--| Q = DKIEN: MAMH_TRUOC = 'COSC3320' [MAMH]
SELECT MAMH FROM DKIEN
WHERE MAMH_TRUOC = 'COSC3320'
GO

--> Cbt 06
--|	   KHOA = KHOA
--| Q = SVIEN |><| MHOC: TEN_MH = 'TOAN ROI RAC' [TENSV]
SELECT TENSV FROM SVIEN, MHOC
WHERE TEN_MH = 'TOAN ROI RAC'
AND SVIEN. KHOA = MHOC. KHOA
GO

--> Cbt 07
--|	    MASV = MASV	MAKH = MAKH MAMH = MAMH
--| Q = ((SVIEN |><| KQUA) |><| K_HOC) |><| MHOC: DIEM >7 [TENSV, TEN_MH]
SELECT TENSV, TEN_MH FROM SVIEN, MHOC, KQUA, K_HOC
WHERE DIEM > 7
AND SVIEN. MASV = KQUA. MASV
AND KQUA. MAKH = K_HOC. MAKH
AND K_HOC. MAMH = MHOC. MAMH
GO

--> Cbt 08
--> Caf 1
--|	   MAMH = MAMH
--| Q1 = DKIEN |><| MHOC: TEN_MH = 'CO SO DU LIEU' [MAMH_TRUOC]
--| Q = MHOC: MAMH IN Q1 [TEN_MH]
SELECT TEN_MH FROM MHOC
WHERE MAMH IN
	(SELECT MAMH_TRUOC FROM DKIEN, MHOC
	WHERE DKIEN. MAMH = MHOC. MAMH
	AND TEN_MH = 'CO SO DU LIEU')
GO

--> Caf 2
--| Q1 = MHOC: TEN_MH = 'CO SO DU LIEU' [MAMH]
--|	MAMH_TRUOC = MAMH
--| Q = DKIEN |><| MHOC: DKIEN. MAMH = Q1 [TEN_MH]
SELECT TEN_MH FROM DKIEN, MHOC
WHERE DKIEN. MAMH =
	(SELECT MAMH FROM MHOC
	WHERE TEN_MH = 'CO SO DU LIEU')
AND DKIEN. MAMH_TRUOC = MHOC. MAMH
GO

--> Cbt 09
--> Caf 1
--|	 MAMH_TRUOC = MAMH
--| Q1 = DKIEN |><| MHOC: TEN_MH = 'CO SO DU LIEU' [DKIEN. MAMH]
--| Q = MHOC: MAMH IN Q1 [TEN_MH]
SELECT TEN_MH FROM MHOC
WHERE MAMH IN
	(SELECT DKIEN. MAMH FROM DKIEN, MHOC
	WHERE DKIEN. MAMH_TRUOC = MHOC. MAMH
	AND TEN_MH LIKE 'CO SO DU LIEU')
GO

--> Caf 2
--| Q1 = MHOC: TEN_MH = 'CO SO DU LIEU' [MAMH]
--|	   MAMH = MAMH
--| Q = DKIEN |><| MHOC: MAMH_TRUOC = Q1 [TEN_MH]
SELECT TEN_MH FROM MHOC, DKIEN
WHERE MAMH_TRUOC =
	(SELECT MAMH FROM MHOC
	WHERE TEN_MH LIKE 'CO SO DU LIEU')
AND DKIEN. MAMH = MHOC. MAMH
GO

--> Dul fcq yiq cbt 09 - Du lieu de thu cau 09.
INSERT INTO DKIEN
VALUES ('COSC1310', 'COSC3380')
GO

--> Cbt 10
--|	   MASV = MASV	MAKH = MAKH MAMH = MAMH
--| Q = ((SVIEN |><| KQUA) |><| K_HOC) |><| MHOC: GV = 'AN' [TEN_MH, TENSV]
SELECT TEN_MH, TENSV FROM SVIEN, MHOC, K_HOC, KQUA
WHERE GV = 'AN'
AND SVIEN. MASV = KQUA. MASV
AND KQUA. MAKH = K_HOC. MAKH
AND K_HOC. MAMH = MHOC. MAMH
GO

--> Cbt 11
ALTER TABLE SVIEN
ADD DCHI	VARCHAR (50)
GO

--> Cbt 12
UPDATE SVIEN
SET DCHI = '12 NGUYEN TRAI, Q1, TPHCM'
WHERE TENSV = 'SON'
GO

--> Cbt 13
INSERT INTO KQUA
VALUES ('18', '135', 8)
--> Sby vdu ahv SVIEN ehv cfd MASV = 18 - Sai vi trong SVIEN khong co MASV = 18.
GO

--> Cbt 14
DELETE FROM SVIEN
WHERE MASV = '17'
--> Ehv sfs flh vdu cfd lec cdq tco KQUA - Khong xoa duoc vi co lien ket toi KQUA.
GO

--> Cbt 15
UPDATE SVIEN
SET NAM = 2
WHERE TENSV = 'SON'
GO

--> Cbt 16
DELETE FROM KQUA
GO

DELETE FROM K_HOC
GO

DELETE FROM SVIEN
GO

DELETE FROM DKIEN
GO

DELETE FROM MHOC
GO

--> Cbt 17
DROP TABLE KQUA
GO

DROP TABLE K_HOC
GO

DROP TABLE SVIEN
GO

DROP TABLE DKIEN
GO

DROP TABLE MHOC
GO

--> Alk bav hgq tie! - Chuc ban hoc tot!