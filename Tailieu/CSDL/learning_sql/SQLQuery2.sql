Begin
 
  -- Khai báo một biến
  Declare @v_Result Int;
  -- Khai báo một biến có giá trị 50
  Declare @v_a Int = 50;
  -- Khai báo một biến có giá trị 100
  Declare @v_b Int = 100;
 
 
  -- In ra màn hình Console (Dùng cho lập trình viên).
  -- Sử dụng Cast để ép kiểu Int về kiểu chuỗi.
  -- Sử dụng toán tử + để nối 2 chuỗi.
  Print 'v_a= [' + Cast(@v_a as varchar(3)) +']';
  Print 'v_a= [' + Cast(@v_a as char(3)) +']';
 
  -- In ra màn hình Console
  Print 'v_b= ' + Cast(@v_b as varchar(15));
 
  -- Tính tổng
  Set @v_Result = @v_a + @v_b;
 
  -- In ra màn hình Console
  Print 'v_Result= ' + Cast(@v_Result as varchar(15));
 
End;

BEGIN
 
-- Khai báo một biến
DECLARE @v_Option integer;
DECLARE @v_Action varchar(30);
 
SET @v_Option = 344;
 
IF @v_Option = 1
  SET @v_Action = 'Run';
ELSE IF @v_Option = 2
    BEGIN
      PRINT 'In block else if @v_Option = 2';
      SET @v_Action = 'Backup';
    END;
ELSE IF @v_Option = 3
  SET @v_Action = 'Stop';
ELSE
  SET @v_Action = 'Invalid';
 
 
-- Ghi ra log
PRINT '@v_Action= ' + @v_Action;
 
END;

BEGIN
 
 -- Khai báo 2 biến x và y.
 DECLARE @x integer = 0;
 DECLARE @y integer = 10;
 
 -- Bước
 DECLARE @step integer = 0;
 
 -- Trong khi @x < @y
 WHILE (@x < @y)
 BEGIN
 
   SET @step = @step + 1;
 
   -- Mỗi lần vòng lặp chạy giá trị của x tăng lên 1
   SET @x = @x + 1;
   -- Mỗi lần vòng lặp chạy giá trị của y giảm đi 2
   SET @y = @y - 2;
 
   PRINT 'Step =' + CAST(@step AS varchar(10));
   PRINT '@x =' + CAST(@x AS varchar(10)) + ' / @y = ' + CAST(@y AS varchar(10));
 
 END;
 
 -- Ghi ra log
 PRINT 'x,y = ' + CAST(@x AS varchar(10)) + ', ' + CAST(@y AS varchar(10));
 
END;

BEGIN
 
-- Khai báo một biến @v_Emp_ID
DECLARE @v_Emp_ID integer = 4;
 
DECLARE @v_First_Name varchar(30);
DECLARE @v_Last_Name varchar(30);
DECLARE @v_Dept_ID integer;
 
-- Gán giá trị cho các biến lấy từ câu lệnh Select.
SELECT
 @v_First_Name = emp.First_Name,
 @v_Last_Name = emp.Last_Name,
 @v_Dept_Id = emp.Dept_Id
FROM Employee Emp
WHERE Emp.Emp_ID = @v_Emp_Id;

SELECT
  emp.First_Name,
  emp.Last_Name,
  emp.Dept_Id
FROM Employee Emp
WHERE Emp.Emp_ID = @v_Emp_Id;

if @v_Dept_Id = 3 begin
	select * from BRANCH
end;
else begin
	select * from PRODUCT
end;
 
-- In ra các giá trị:
PRINT '@v_First_Name = ' + @v_First_Name;
PRINT '@v_Last_Name = ' + @v_Last_Name;
PRINT '@v_Dept_Id = ' + CAST(@v_Dept_ID AS varchar(15));
 
END;