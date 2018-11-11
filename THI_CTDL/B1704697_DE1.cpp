#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MaxLength 30

typedef char ElementType;

typedef struct{
	ElementType Elements[MaxLength];
	int Top_idx;
}Stack;

void Make_Null_Stack(Stack *S){
	S->Top_idx=MaxLength;
}

int Empty_Stack(Stack S){
	return (S.Top_idx==MaxLength);
}

int Full_Stack(Stack S){
	return (S.Top_idx==0);
}

ElementType Top(Stack S){
	return S.Elements[S.Top_idx];
}

ElementType Pop(Stack *S){
	return S->Elements[S->Top_idx++];
}

ElementType Pop2(Stack *S){
	ElementType t= S->Elements[S->Top_idx];
	S->Top_idx = S->Top_idx +1;
	return t;
}

ElementType Pop22(Stack *S){
	ElementType t= S->Elements[S->Top_idx];
	S->Top_idx++;
	return t;
}

void Push(ElementType x, Stack *S){
	S->Top_idx--;
	S->Elements[S->Top_idx]=x;
}

void Push2(ElementType x, Stack *S){
	S->Elements[--S->Top_idx]=x;
}

/*ElementType Pop3(Stack *S){
	
	S->Top_idx = S->Top_idx +1;
	return S->Elements[S->Top_idx];
}

ElementType Pop4(Stack *S){
	
	return S->Elements[++S->Top_idx];
}*/

int main(){
	Stack S1;
	Make_Null_Stack(&S1);
	Push(50,&S1);
	Push(48,&S1);
	Push(67,&S1);
	Push(53,&S1);
	ElementType z;
	
	z=Pop(&S1); 
	printf("z1=%c\n",z);
	
	z=Pop(&S1); 
	printf("z2=%c\n",z);
	
	z=Pop(&S1); 
	printf("z3=%c\n",z);
	
	z=Pop(&S1); 
	printf("z4=%c\n",z);
	
	for (int i=0; i<MaxLength; i++){
	//	printf("s[%d] = %c\n",i,S1.Elements[i]);
		
	}
	
	//ElementType z=Pop(&S1); 

	/*printf("Hello\n");
	int n=5, i, s=0;
	int a[n];
	for (i=0; i<n; i++){
		printf("Nhap a[%d]=",i);
		scanf("%d", &a[i]);
		
	}
	printf("\n Mang da nhap");
	for (i=0; i<n; i++){
		printf(" %d ",a[i]);
	}*/
}
