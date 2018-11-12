/* PHAN HANG DOI.
Bai 4: cai dat chuong trinh thuc hien tac vu trong hang doi.

Ngay 05/07/2007, viet: Nguyen Van Toan, tai: KOS GRE.
Ngay 15/07/2007,  sua: Nguyen Van Toan, tai: KOS GRE.
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>

const int TD = 35; // do rong toi da cua hang doi.

typedef struct queue
{
	int dau, cuoi;
	int nut[TD];
} *que;

void khoitao (que ct); // khoi tao hang doi.
char rong (que ct); // kiem tra rong.
char day (que ct); // kiem tra day.
void insert (que ct, int x); // them vao hang doi.
int remove (que ct); // lay ra khoi hang doi.
int truydau (que ct); // truy xuat dau.
int truycuoi (que ct); // truy xuat cuoi.
int size (que ct); // kich thuoc cua hang doi.
void copyque (queue ct1, que ct2); // copy queue ct1 sang ct2.

void tao (queue &hd); // khoi tao hang doi.

void main () /*----------*/
{
	textmode (3); clrscr ();
	queue h1, h2; //khoitao (&h1); khoitao (&h2);
	tao (h1); tao (h2);

	printf ("Kich thuoc H1 = %d, H2 = %d", sizeof (h1), sizeof (h2));

	insert (&h1, 4); insert (&h1, 3); insert (&h1, 2); insert (&h1, 1);

	for (int i = 0; i < 4; i++) insert (&h2, i+1);

	//printf ("\nHang doi H1: "); while (!rong (&h1)) printf ("%d ", remove (&h1));
	printf ("\nHang doi H2: "); while (!rong (&h2)) printf ("%d ", remove (&h2));
	getch (); return;
} /*----------*/

// Khoi tao hang doi.
void khoitao (que ct)
{
	ct->dau = ct->cuoi = TD-1;
}

// Kiem tra rong.
char rong (que ct)
{
	return ct->dau == ct->cuoi ? 1 : 0;
}

// Kiem tra day.
char day (que ct)
{
	return ct->dau == ct->cuoi+1 ? 1 : 0;
}

// Them vao hang doi.
void insert (que ct, int x)
{
	if (ct->cuoi == TD) ct->cuoi = 0; else ct->cuoi++;
	ct->nut[ct->cuoi] = x;
}

// Lay ra khoi hang doi.
int remove (que ct)
{
	if (ct->dau == TD) ct->dau = 0; else ct->dau++;
	return ct->nut[ct->dau];
}

// Truy xuat dau.
int truydau (que ct)
{
	int tg;
	if (ct->dau == TD) tg = 0; else tg = ct->dau+1;
	return ct->nut[tg];
}

// Truy xuat cuoi.
int truycuoi (que ct)
{
	return ct->nut[ct->cuoi];
}

// Kich thuoc cua hang doi.
int size (que ct)
{
	if (ct->cuoi > ct->dau) return ct->cuoi-ct->dau;
	return TD-ct->dau+ct->cuoi+1;
}

// Copy queue ct1 sang ct2.
void copyque (queue ct1, que ct2)
{
	while (!rong (&ct1)) insert (ct2, remove (&ct1));
	return;
}

// Khoi tao hang doi.
void tao (queue &hd)
{
	hd.dau = hd.cuoi = TD-1;
}