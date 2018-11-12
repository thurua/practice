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

int clean_stdin()
{
    while (getchar()!='\n');
    return 1;
}

void convertHex(int so){
	printf("Ket qua chuyen %d thanh so he 16 = ", so);
	Stack S1;
	Make_Null_Stack(&S1);
  	while (so > 0) {
		int t = so % 16; // lay phan du
		
		switch(t){
			case 10:
				//printf("A");
				Push(65,&S1);
				break;
			case 11:
				//printf("B");
				Push(66,&S1);
				break;
			case 12:
				//printf("C");
				Push(67,&S1);
				break;
			case 13:
				//printf("D");
				Push(68,&S1);
				break;
			case 14:
				//printf("E");
				Push(69,&S1);
				break;
			case 15:
				//printf("F");
				Push(70,&S1);
				break;
			default:
				//printf("%d",t);
				Push(t+48,&S1);
		}										
	
		so = so / 16; // lay phan nguyen
	}

	int top = S1.Top_idx;	
    for (int i=MaxLength; i>top; i--){		
		printf("%c",Pop(&S1));
	}
	printf("\n");
}

void convertBin(int so){
	printf("Ket qua chuyen %d thanh so he 2 = ", so);
	Stack S1;
	Make_Null_Stack(&S1);
	
  	while (so > 0) {
		int t = so % 2; // lay phan du
		
		Push(t+48,&S1);										
	
		so = so / 2; // lay phan nguyen
	}

	int top = S1.Top_idx;
	
    for (int i=MaxLength; i>top; i--){		
		printf("%c",Pop(&S1));
	}
	printf("\n");
}

void convertOct(int so){
	printf("Ket qua chuyen %d thanh so he 8 = ", so);
	Stack S1;
	Make_Null_Stack(&S1);
	
  	while (so > 0) {
		int t = so % 8; // lay phan du
		
		Push(t+48,&S1);										
	
		so = so / 8; // lay phan nguyen
	}

	int top = S1.Top_idx;
	
    for (int i=MaxLength; i>top; i--){		
		printf("%c",Pop(&S1));
	}
	printf("\n");
}

int main(){	
	int so = 0; 
	int tam; 
	bool k_hople;
    char c;
    do
    {  
        printf("\nEnter an integer > 0: ");
      	tam=  scanf("%d%c", &so, &c);
       	k_hople = (tam!=2 || c!='\n');
      	//printf("tam = %d",tam);
    } while ((k_hople && clean_stdin()) || so <= 0);
    
    convertHex(so);
    convertOct(so);
	convertBin(so);
	
	/*Push(50,&S1);
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
	printf("z4=%c\n",z);*/
	
	/*int tuoi, lop;
    char ten[10];
    char hocluc[4];
    char kytu;
    printf("ban bao nhieu tuoi, lop may, ten gi, hoc luc gi, thich chu gi");
    scanf("%d %d", &tuoi, &lop);
    scanf("%s", ten);
    scanf("%s", hocluc);
    scanf("%c", &kytu);
    printf("ban %d tuoi, lop %d, ten %s, hoc luc %s, thich chu %c", tuoi, lop, ten, hocluc, kytu);*/
    
  
    
    
    
    
	
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
