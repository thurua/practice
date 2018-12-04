#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define Maxlength 30
typedef int ElementType;
typedef int Position;
typedef struct{
	ElementType Elements [Maxlength];
	Position Last;
}List;

void MakeNullList(List *L){
	L->Last=0;
}

int EmptyList(List L){
	return L.Last==0;
}

int FullList (List L){
	return L.Last==Maxlength;
}

int FirstList (List L){
	return 1;
}

int EndList (List L){
	return L.Last+1;
}

Position Next (Position p, List L){
	return p+1;
}

Position Previous (Position p, List L){
	return p-1;
}

ElementType Retrieve (Position p, List L){
	return L.Elements[p-1];
}

void InsertList (ElementType x, Position p,  List &L){
	if(L.Last==Maxlength){
		printf("Danh sach day");
	}
	else if(p<1 || p>L.Last+1){
		printf("Vi tri khong hop le");
	}
	else{
		for (int i=L.Last; i>p; i--){
			L.Elements[i]=L.Elements[i-1];			
		}
		L.Elements[p-1]=x;
		L.Last++;
	}
	
}
void Delete (Position p,  List &L){
	if(p<1 || p>L.Last+1){
		printf("Vi tri khong hop le");
	}
	else {
		for (int i=1; i<=L.Last; i++){
			L.Elements[i]=L.Elements[i+1];
	 }
		L.Last--;
	}
}
void ReadList (List &L){
	int n;
	int a;
	printf("Nhap so phan tu: ");
	scanf("%d",&n);
	for (int i=1; i<=n; i++){
		printf("Phan tu thu %d: ",i);
		scanf("%d",&a);
		InsertList(a, i, L);
	}
}

void PrintList (List &L){
	for (int i=1; i<=L.Last; i++){
		printf("%5d", Retrieve(i,L));
	}
}

int main(){
	Position p;
	List L;
    ElementType x;
	MakeNullList(&L);
	ReadList (L);
	printf ("Danh sach vua nhap:");
	PrintList (L);
	printf("\nThem phan tu: ");
	scanf("%d",&x);
	printf("\nVi tri them: ");
	scanf("%d",&p);
    InsertList(x, p, L);
	printf ("\nDanh sach sau khi them: ");
	PrintList (L);
	printf("\nVi tri can xoa: ");
	scanf("%d",&p);
	FirstList (L);
	Delete (p, L);
	printf ("Danh sach sau khi xoa: ");
	PrintList (L);



}


