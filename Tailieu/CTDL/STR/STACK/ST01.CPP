/* PHAN STACK.
Bai 1: chuong trinh kiem tra chuoi co tinh doi xung.

Ngay 04/07/2007, viet: Nguyen Van Toan, tai: KOS GRE.
Ngay 15/07/2007,  sua: Nguyen Van Toan, tai: KOS GRE.
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>

const int TD = 35; // do rong toi da cua stack.

typedef struct stack
{
    int top;
    char nut[TD];
} *stk;

void push (stk ct, char x); // them vao stack.
char pop (stk ct); // lay ra khoi stack.

void main () /*----------*/
{
	char *chu; // bien chua chuoi can kiem tra.
	int dai; // do  dai cua chuoi.
	char dv; // dinh vi chuoi.
	char dung = 1; // bao dung.
	stack st; textmode (3); clrscr ();
	do
	{
		st.top = -1; // khoi tao stack;
		printf ("\t\t\t\t<CHUONG TRINH>\n");
		printf ("\tKIEM TRA CHUOI DOI XUNG DUNG STACK, NHAP CHUOI RONG DE KET THUC\n");
		printf ("Nhap chuoi: "); gets (chu); dai = strlen (chu);
		if (dai%2 == 0) dv = dai/2; else dv = dai/2+1;

		// Nap vao tung ki tu vao stack (chi co nua chuoi).
		for (int i = 0; i < dai/2; i++) push (&st, chu[i]);

		// Lay tat ca cac ki tu trong stack ra de kiem tra.
		for (i = 0; i < dai/2; i++)
		{
			if (chu[dv+i] == pop (&st)) dung = 1;
			else
			{
				dung = 0;
				break;
			}
		}

		if (dung) printf ("Chuoi nay doi xung!\n\n");
		else printf ("Chuoi khong doi xung!\n\n");
	} while (dai);
	return;
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