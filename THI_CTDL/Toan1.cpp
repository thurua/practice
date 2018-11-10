#include <stdio.h>
#include <conio.h>
#define MaxLength 30

typedef float ElementType;

typedef struct{
	ElementType Elements[MaxLength];
	int Top_idx;
}Stack;

void Make_Null_Stack(Stack *S){
	(*S).Top_idx=MaxLength;
	
	printf("Top_idx 111  %d \n",S->Top_idx);
}

int main(){
	Stack  i, *p;	
	p = &i;
	
	Make_Null_Stack();
	printf("Top_idx 222  %d \n",(*p).Top_idx);
	
	
	
	
	
	
	printf("Kich thuoc i %d \n", sizeof(i));
	printf("Kich thuoc p %d \n", sizeof(p));
	
	int  i1, *p1;
	printf("Kich thuoc i1 %d \n", sizeof(i1));
	printf("Kich thuoc p1 %d \n", sizeof(p1));

	double  i2, *p2;
	printf("Kich thuoc i2 %d \n", sizeof(i2));
	printf("Kich thuoc p2 %d \n", sizeof(p2));

	}
