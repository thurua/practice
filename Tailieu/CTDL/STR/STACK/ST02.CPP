/* PHAN STACK.
Bai 2: chuong trinh doi so thap phan sang he co so khac.

Ngay 04/07/2007, viet: Nguyen Van Toan, tai: KOS GRE.
Ngay 15/07/2007,  sua: Nguyen Van Toan, tai: KOS GRE.
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>

const int TD = 35; // do rong toi da cua stack.

typedef struct stack
{
    char top;
    char nut[TD];
} *stk;

void push (stk ct, char x); // them vao stack.
char pop (stk ct); // lay ra khoi stack.

void main () /*----------*/
{
	char co; // co so.
	long so; // so can doi.
	stack st; textmode (3); clrscr ();
	while (1)
	{
		st.top = -1; // khoi tao stack;
		printf ("\t\t\t\t<CHUONG TRINH>\n");
		printf ("\tDOI SO THAP PHAN SANG HE CO SO KHAC DUNG STACK, NHAP 0 DE KET THUC\n");
		printf ("Nhap so: "); scanf ("%ld", &so);
		if (!so) return; // ket thuc chuong trinh.
		nhapco: printf ("Co so  : "); scanf ("%d", &co);
		if (co < 2) goto nhapco;

		// Thuc hien doi so.
		while (so)
		{
			push (&st, so%co);
			so /= co;
		}

		printf ("Ket qua doi: ");
		while (st.top != -1) printf ("%X", pop (&st));
		printf ("\n\n");
	}
} /*----------*/

// Them vao stack.
void push (stk ct, char x)
{
    ct->nut[++ct->top] = x;
}

// Lay ra khoi stack.
char pop (stk ct)
{
	return ct->nut[ct->top--];
}