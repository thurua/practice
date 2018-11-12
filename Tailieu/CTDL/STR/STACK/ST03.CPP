/* PHAN STACK.
Bai 3: cai dat chuong trinh thuc hien tac vu trong stack.

Ngay 05/07/2007, viet: Nguyen Van Toan, tai: KOS GRE.
Ngay 15/07/2007,  sua: Nguyen Van Toan, tai: KOS GRE.
*/

#include <stdio.h>
#include <conio.h>

const int TD = 35; // kich thuoc toi da cua stack.

typedef struct stack
{
	int top;
	int nut[TD];
} *stk;

void khoitao (stk ct); // khoi tao stack.
char rong (stk ct); // kiem tra rong.
char day (stk ct); // kiem tra day.
void push (stk ct, int x); // nap vao stack.
int pop (stk ct); // lay noi dung ra.
void duyet (stk ct); // duyet stack.
int stacktop (stk ct); // truy xuat nut dinh.
int stacksize (stk ct); // kich thuoc stack.
void copystack (stk ct1, stk ct2); // copy stack ct1 sang ct2.

void main () /*----------*/
{
	stack st1; khoitao (&st1);
	stack st2; khoitao (&st2);
	textmode (3); clrscr ();
	for (int i = 0; i < TD+20; i++)
		if (day (&st1))
		{
			printf ("Stack day roi!\n");
			break;
		}
		else push (&st1, i);
	printf ("Noi dung thuc cua stack1:\n"); duyet (&st1);

	copystack (&st1, &st2);
	printf ("\nNoi dung thuc cua stack1:\n"); duyet (&st2);
	getch (); return;
} /*----------*/

// Khoi tao stack.
void khoitao (stk ct)
{
	ct->top = -1;
}

// Kiem tra rong.
char rong (stk ct)
{
	return ct->top == -1 ? 1 : 0;
}

// Kiem tra day.
char day (stk ct)
{
	return ct->top == TD ? 1 : 0;
}

// Nap vao stack.
void push (stk ct, int x)
{
	ct->nut[++ct->top] = x;
}

// Lay noi dung ra.
int pop (stk ct)
{
	return ct->nut[ct->top--];
}

// Duyet stack.
void duyet (stk ct)
{
	int tg = ct->top;
	while (!rong (ct)) printf ("%d ", pop (ct));
	ct->top = tg; return;
}

// Truy xuat nut dinh.
int stacktop (stk ct)
{
	return ct->nut[ct->top];
}

// Kich thuoc stack.
int stacksize (stk ct)
{
	return ct->top+1;
}

// Copy stack ct1 sang ct2.
void copystack (stk ct1, stk ct2)
{
	for (int i = 0; i <= ct1->top; i++) push (ct2, ct1->nut[i]);
	return;
}