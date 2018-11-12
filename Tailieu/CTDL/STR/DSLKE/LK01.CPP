/* DANH SACH LIEN KET.
Bai 1: cho danh sach lien ket chua cac so nguyen.
	Hien thi phan giao cua 2 danh sach.
	Hien thi phan hoi cua 2 danh sach.
	Hieu cua danh sach 1 voi danh sach 2.
	(Ghi chu: khong tao danh sach moi.)
	
Ngay 11/07/2007, viet: Nguyen Van Toan, tai: KOS GRE.
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

void giao (ctds *ds1, ctds *ds2); // tim phan giao cua ds1 voi ds2 dat o ds1.
void hoi (ctds *ds1, ctds *ds2); // tim phan hoi cua ds1 voi ds2 dat o ds1.
void hieu (ctds *ds1, ctds *ds2); // tim phan hieu cua ds1 voi ds2 dat o ds1.

ctds nutmoi (int x); // tao nut moi.
void themdau (ctds *dau, int x); // them dau danh sach.
void themcuo (ctds *dau, int x); // them cuoi danh sach.
void duyet (ctds *dau); // duyet danh sach.
void tao (ctds *dau); // khoi tao danh sach lien ket.
void khutrung (ctds *dau); // khu gia tri trung.
char tim (ctds *dau, int x); // tim x co trong danh sach.

void main () /*- - - - - - - - - -*/
{
	textmode (3); clrscr ();
	ctds ds1 = NULL; // khoi tao danh sach.
	ctds ds2 = NULL; // khoi tao danh sach.
	randomize ();

	for (int i = 0; i < random (10) + 1; i++)
	{
		themdau (&ds1, random (35) - random (35));
		themdau (&ds2, random (35) - random (35));
	}

	printf ("Danh sach 1 luc dau: "); duyet (&ds1); // duyet danh sach.
	printf ("\nDanh sach 2 luc dau: "); duyet (&ds2); // duyet danh sach.

	printf ("\nGiao cua ds1 va ds2: "); giao (&ds1, &ds2);
	printf ("\nHoi  cua ds1 va ds2: "); hoi (&ds1, &ds2);
	printf ("\nHieu cua ds1 va ds2: "); hieu (&ds1, &ds2);
	getch (); return;
} /*- - - - - - - - - -*/

// Tim phan giao cua ds1 voi ds2 dat o ds1.
void giao (ctds *ds1, ctds *ds2)
{
	ctds p = *ds1;
	while (p != NULL)
	{
		if (tim (ds2, p->nut)) printf ("%d ", p->nut);
		p = p->tiep;
	}
}

// Tim phan hoi cua ds1 voi ds2 dat o ds1.
void hoi (ctds *ds1, ctds *ds2)
{
	ctds p = *ds2;
	while (p != NULL)
	{
		printf ("%d ", p->nut);
		p = p->tiep;
	}
	p = *ds1;
	while (p != NULL)
	{
		if (!tim (ds2, p->nut)) printf ("%d ", p->nut);
		p = p->tiep;
	}
}

// Tim phan hieu cua ds1 voi ds2 dat o ds1.
void hieu (ctds *ds1, ctds *ds2)
{
	ctds p = *ds1;
	while (p != NULL)
	{
		if (!tim (ds2, p->nut)) printf ("%d ", p->nut);
		p = p->tiep;
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
// Khoi tao danh sach lien ket.
void tao (ctds *dau)
{
	*dau = NULL;
}

// Khu gia tri trung.
void khutrung (ctds *dau)
{
}

// Tim x co trong danh sach.
char tim (ctds *dau, int x)
{
	ctds p = *dau;
	while (p != NULL)
	{
		if (p->nut == x) return 1;
		p = p->tiep;
	}
	return 0; // tim khong thay.
}