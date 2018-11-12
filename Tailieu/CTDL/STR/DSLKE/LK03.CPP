/* DANH SACH LIEN KET.
Bai 3: tach danh sach lien ket tai vi tri.

Ngay 15/07/2007, viet: Nguyen Van Toan, tai: KOS GRE.
Ngay 19/07/2008,  sua: Nguyen Van Toan, tai: KOS GRE.
*/

#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include <stdlib.h>

typedef struct ds
{
	int nut;
	ds *tiep;
} *ctds;

void tach (ctds *ds1, ctds *ds2, int vt); // tach ds1 ra thanh 2 ds
// mot luu o ds1 (tinh tu dau den vt) con cai kia luu o ds2.

ctds nutmoi (int x); // tao nut moi.
void themdau (ctds *dau, int x); // them dau danh sach.
void themcuo (ctds *dau, int x); // them cuoi danh sach.
void duyet (ctds *dau); // duyet danh sach.
ctds tim (ctds *dau, int vt); // tim con tro tai vi tri.

void main () /*- - - - - - - - - -*/
{
	textmode (3); clrscr ();
	ctds ds1 = NULL; // khoi tao danh sach.
	ctds ds2 = NULL; // khoi tao danh sach.
	randomize ();
	int nn = random (10) + 1;

	for (int i = 0; i < nn; i++)
		themdau (&ds1, random (35) - random (35));

	printf ("Danh sach 1 luc dau: "); duyet (&ds1); // duyet danh sach.
	int x = random (nn); tach (&ds1, &ds2, x);
	printf ("\nDanh sach 1 bi tach tai vi tri %d\n", x);
	printf ("Danh sach a: "); duyet (&ds1); // duyet danh sach.
	printf ("\nDanh sach b: "); duyet (&ds2); // duyet danh sach.
	getch (); return;
} /*- - - - - - - - - -*/

// Tach ds1 ra thanh 2 ds mot luu o ds1 (tinh tu dau den vt) con cai kia luu o ds2.
void tach (ctds *ds1, ctds *ds2, int vt)
{
	ctds p = tim (ds1, vt);
	if (p != NULL)
	{
		*ds2 = p->tiep;
		p->tiep = NULL;
	}
}

// Tao nut moi.
ctds nutmoi (int x)
{
	ctds p = (ctds) malloc (sizeof (ds));
	p->nut = x;	
	return p;
}

// Them dau danh sach.
void themdau (ctds *dau, int x)
{
	ctds p = nutmoi (x);
	p->tiep = *dau; // nut moi chi toi dau.
	*dau = p; // thiet lap dau con tro dau.
}

// Them cuoi danh sach.
void themcuo (ctds *dau, int x)
{
	if (*dau == NULL) *dau = nutmoi (x);
	else
	{
		ctds p = *dau, q = nutmoi (x);
		while (p->tiep != NULL) p = p->tiep;
		p->tiep = q; // thiet lap lien ket.
	}
}

// Duyet danh sach
void duyet (ctds *dau)
{
	ctds p = *dau;
	while (p != NULL)
	{
		printf ("%d ", p->nut);
		p = p->tiep;
	}
}

// Tim con tro tai vi tri.
ctds tim (ctds *dau, int vt)
{
	int i = 0;
	ctds p = *dau;
	while (p != NULL && i != vt)
	{
		i++;
		p = p->tiep;
	}
	return p;
}