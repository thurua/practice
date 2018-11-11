#include <stdio.h>
#include <conio.h>
#define MaxLength 30

typedef float ElementType;

typedef struct{
	ElementType Elements[MaxLength];
	int Top_idx;
}Stack;

void Make_Null_Stack(Stack *S){
	S->Top_idx=MaxLength;
	printf("Top_idx Make_Null_Stack  %d \n",S->Top_idx);
}

void Make_Null_Stack2(Stack &S){
	S.Top_idx=MaxLength;
	printf("Top_idx Make_Null_Stack2  %d \n",S.Top_idx);
}

int Empty_Stack(Stack S){
	return (S.Top_idx==MaxLength);
}

int main(){
	Stack  i, j;	
	
	Make_Null_Stack(&i);
	Make_Null_Stack2(j);
	printf("Top_idx i  %d \n",i.Top_idx);
	printf("Top_idx j  %d \n",j.Top_idx);
	
	int x=	Empty_Stack(i);
	printf("Empty_Stack i  %d \n",x);
	
	int y=	Empty_Stack(j);
	printf("Empty_Stack j  %d \n",y);
}
