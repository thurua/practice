BEGIN
 
-- Khai báo một biến @v_Emp_ID
DECLARE @v_CMND integer = 3478;
 
DECLARE @v_HOTEN varchar(30);
DECLARE @v_DIACHI varchar(30);
 
-- Gán giá trị cho các biến lấy từ câu lệnh Select.
SELECT
 @v_HOTEN = emp.HOTEN,
 @v_DIACHI = emp.DIACHI
FROM Hoctap2 Emp
WHERE Emp.CMND = @v_CMND;
 
-- In ra các giá trị:
PRINT '@v_HOTEN = ' + @v_HOTEN;
PRINT '@v_DIACHI = ' + @v_DIACHI;
 
END;