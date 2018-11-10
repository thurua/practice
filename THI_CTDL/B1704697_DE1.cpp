#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MaxLength 30

typedef float ElementType;

typedef struct{
	ElementType Elements[MaxLength];
	int Top_idx;
}Stack;

void Make_Null_Stack(Stack *S){
	S->Top_idx=MaxLength;
}
int Empty_Stack(Stack *S){
	return (S.Top_idx==MaxLength);
}
int Full_Stack(Stack *S){
	return (S.Top_idx==0);
}

int main(){
	printf("Hello\n");
	int n=5, i, s=0;
	int a[n];
	for (i=0; i<n; i++){
		printf("Nhap a[%d]=",i);
		scanf("%d", &a[i]);
		
	}
	printf("\n Mang da nhap");
	for (i=0; i<n; i++){
		printf(" %d ",a[i]);
	}
}
