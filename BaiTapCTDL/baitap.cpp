#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MaxLength 20

typedef int ElementType;
typedef int Position;
typedef struct Node{
  ElementType Element;
    struct Node *Next; 
	}; 
typedef struct{
	ElementType Elements[MaxLength];
	Position Last;
}List;
// TAO DANH SACH RONG
void Make_Null_List (List &L){
	L.Last=0;
}
// KIEM TRA DANH SACH RONG
int Empty_List (List &L){
	return L.Last==0;
}
//XAC DINH VI TRI DAU TIEN CUA DANH SACH
Position First(List L){
	return 1;
}
//XAC DINH VI TRI SAU VI TRI CUOI CUNG
Position End(List L){
	return L.Last-1;
}
//XAC DINH VI TRI SAU VI TRI P
Position Next(Position P, List L){
	return P+1;
}
//XAC DINH VI TRI TRUOC VI TRI P
Position Previous(Position P,List L){
	return P-1;
}
//XAC DINH GIA TRI VI TRI P
ElementType Retrieve(Position P, List L){
	return L.Elements[P-1];
}
//TIM VI TRI DAU TIEN CUA PHAN TU X TRONG DANH SACH
Position Locate(ElementType X, List L){
	Position P=First(L);
	int Found=0;
	while((P!=End(L))&&(!Found)){
		if(Retrieve (P,	L)==X){
			Found=1;
			}
		else {
		P=Next(P,L);	
		}
	}
	return P;
}
void Insert_List(ElementType x, Position  p,  List &L){
  if(L.Last==MaxLength)
     printf("Danh sach day");
	   else  if((p<1)||(p>L.Last+1))
	      printf("Vi tri  khong  hop le");
		     else{
			   Position q;
			   for(q=(L.Last-1)+1;q>p-1; q--) 
			        L.Elements[q]=L.Elements[q-1];
				L.Elements[p-1]=x;      
				L.Last++;   
				} 
}
void Read_List(List &L){
    ElementType x;
	    Position p=1;
		    printf("\nNhap vao 1 danh sach cac so nguyen, -1 de dung\n");
			    do{
				    printf("x=");
					scanf("%d",&x);
					Insert_List(x,p,L);
					p++;
				}while(x!=-1); 
 
}
 
/*In danh sach ra man hinh*/ 
void Print_List(List L){
    Position P;
	for(P=1;P!=End(L);P++){
		printf("%5d",Retrieve(P,L));
		}
	printf("\n");
 } 
int main(){
   List L;	
   ElementType X;
   Position P;
   Make_Null_List (L);
   Read_List (L);
   printf("danh sach vua nhap: ");
   Print_List(L);
   printf("vi tri phan tu dau tien:\n");
   First(L);
   printf("gia tri x can tim la:\n");
   printf("x=");
   scanf("%d",&X);
   printf("vi tri phan tu x:\n");
   Locate(X,L);
  
   getch();
}




