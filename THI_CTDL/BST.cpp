#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MaxLength 30

typedef int ElementType;

typedef struct Node{
	ElementType Key;
	Node *Left, *Right;
};

void Insert_Node(ElementType x,Node *Root ){
	if (Root == NULL) { 
		Root=(Node*)malloc(sizeof(Node));
		Root->Key = x;
		Root->Left = NULL;
		Root->Right = NULL;
	}
	else if (x < Root->Key) {
		Insert_Node(x, Root->Left);
	}	
	else if (x>Root->Key){
		Insert_Node(x, Root->Right);
	}	
}

void Pos_Order(Node *T){
	if(T!=NULL){
		printf("%d ",T->Key);
	//	Pos_Order(T->Left);
	//	Pos_Order(T->Right);		
	}
}

int main(){
	Node toan;
	Insert_Node(254, &toan);
	Insert_Node(9, &toan);
	Insert_Node(255, &toan);
	printf("%d ",toan.Key);
	Pos_Order(&toan);
	return 0;
}
