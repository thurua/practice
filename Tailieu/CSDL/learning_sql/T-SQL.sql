begin

declare @a integer;
declare @b integer;
declare @c integer;
declare @d integer;
declare @e varchar(20);
declare @f integer;



set  @a = 10;
set  @b = 15;
set  @c = 20;
set  @d = @a + @b - @c ;


print '@a = ' + cast(@a as varchar(20));
print '@b = ' + cast(@b as varchar(20));
print '@c = ' + cast(@c as varchar(20));
print '@d = ' + cast(@d as varchar(20));

set @f=0;
while (@a < @b)

begin

 set @f = @f + 1;
 set @a = @a + 1;
 set @b = @b - 1;

 print '@f = ' + cast(@f as varchar(20));
 print '@a = ' + cast(@a as varchar(20))
 print '@b = ' + cast(@c as varchar(20))

 if @f=3
 break;

 end;



if @a=10
  set @e='con heo';
  else 
  set @e='con bo';
 
 print '@e = '+ @e;


end;