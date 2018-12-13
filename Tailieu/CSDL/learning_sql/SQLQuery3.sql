begin
-- Sử dụng SELECT INTO để trèn dữ liệu vào #v_My_Table.  
SELECT
 emp.First_Name,
 emp.Last_Name,
 emp.Dept_Id,
 1000 Salary INTO #v_My_Table
FROM Employee Emp
WHERE Emp.Emp_ID < 4;
end;

select * from #v_My_Table