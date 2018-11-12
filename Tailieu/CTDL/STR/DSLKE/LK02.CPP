/* DANH SACH LIEN KET.
Bai 2: tron 2 danh sach lien ket co thu tu tang thanh ds co thu tu tang.

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

void trontt (ctds *ds1, ctds *ds2, ctds *ds3); // tron ds1 voi ds2 thang ds3
// voi dieu kien ds1 va ds2 tang. Suy ra ds3 cung tang theo.

ctds nutmoi (int x); // tao nut moi.
void themdau (ctds *dau, int x); // them dau danh sach.
void themcuo (ctds *dau, int x); // them cuoi danh sach.
void duyet (ctds *dau); // duyet danh sach.
ctds tim (ctds *dau, int vt); // tim con tro tai vi tri.
void sxt (ctds *dau); // sap xep danh sach tang.

void main () /*- - - - - - - - - -*/
{
	textmode (3); clrscr ();
	ctds ds1 = NULL; // khoi tao danh sach.
	ctds ds2 = NULL; // khoi tao danh sach.
	ctds ds3 = NULL; // khoi tao danh sach.
	randomize ();

	for (int i = 0; i < random (10) + 1; i++)
	{
		themdau (&ds1, random (35) - random (35));
		themdau (&ds2, random (35) - random (35));
	}
	sxt (&ds1); sxt (&ds2); // sap xep ds.
	trontt (&ds1, &ds2, &ds3);
	printf ("Danh sach 1: "); duyet (&ds1); // duyet danh sach.
	printf ("\nDanh sach 2: "); duyet (&ds2); // duyet danh sach.
	printf ("\nDanh sach 3: "); duyet (&ds3); // duyet danh sach.
	getch (); return;
} /*- - - - - - - - - -*/

// Tron ds1 voi ds2 thang ds3 voi dieu kien ds1 va ds2 tang. Suy ra ds3 cung tang theo.
void trontt (ctds *ds1, ctds *ds2, ctds *ds3)
{
	ctds p1 = *ds1, p2 = *ds2, p;
	
	// Lay nut dau danh sach.
	if (p1 != NULL && p2 != NULL)
	{
		if (p1->nut < p2->nut)
		{
			*ds3 = nutmoi (p1->nut);
			p1 = p1->tiep;
			p = *ds3;
		}
		else
		{
			*ds3 = nutmoi (p2->nut);
			p2 = p2->tiep;
			p = *ds3;
		}
	}
	else if (p1 == NULL && p2 != NULL) *ds3 = *ds2;
	else if (p1 != NULL && p2 == NULL) *ds3 = *ds1;
	else *ds3 = NULL;
	
	// Lay nut tiep theo.
	while (p1 != NULL && p2 != NULL)
	{
		if (p1->nut < p2->nut)
		{
			p->tiep = nutmoi (p1->nut);
			p1 = p1->tiep;
			p = p->tiep;
		}
		else
		{
			p->tiep = nutmoi (p2->nut);
			p2 = p2->tiep;
			p = p->tiep;
		}
	}
	
	// Phan con lai la danh sach 2.
	if (p1 == NULL && p2 != NULL)
	{
		while (p2 != NULL)
		{
			p->tiep = nutmoi (p2->nut);
			p2 = p2->tiep;
			p = p->tiep;
		}
	}
	else // phan con lai la danh sach 1.
	{
		while (p1 != NULL)
		{
			p->tiep = nutmoi (p1->nut);
			p1 = p1->tiep;
			p = p->tiep;
		}
	}
	return;
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

// Sap xep danh sach tang.
void sxt (ctds *dau)
{
	ctds p = *dau;
	ctds q = p->tiep;
	while (p->tiep != NULL)
	{
		while (q != NULL)
		{
			if (p->nut > q->nut)
			{
				int tg = p->nut;
				p->nut = q->nut;
				q->nut = p->nut;
			}
			q = q->tiep;
		}
		p = p->tiep;
	}
	return;
}