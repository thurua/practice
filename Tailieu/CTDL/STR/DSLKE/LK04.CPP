/* DANH SACH LIEN KET.
Bai 4: dao danh sach lien ket.

Ngay 14/07/2007, viet: Nguyen Van Toan, tai: KOS GRE.
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

void dao (ctds *dau); // dao danh sach lien ket.

ctds nutmoi (int x); // tao nut moi.
void themdau (ctds *dau, int x); // them dau danh sach.
void themcuo (ctds *dau, int x); // them cuoi danh sach.
void duyet (ctds *dau); // duyet danh sach.

void main () /*- - - - - - - - - -*/
{
	textmode (3); clrscr ();
	ctds ds1 = NULL; // khoi tao danh sach.
	randomize ();
	int nn = random (10) + 1;

	for (int i = 0; i < nn; i++)
		themdau (&ds1, random (35) - random (35));
	printf ("Danh sach 1 luc dau: "); duyet (&ds1); // duyet danh sach.
	dao (&ds1);
	printf ("\nDanh sach 1 luc sau: "); duyet (&ds1); // duyet danh sach.
	getch (); return;
} /*- - - - - - - - - -*/

// Dao danh sach lien ket.
void dao (ctds *dau)
{
	if (*dau != NULL)
	{
		ctds gi, sa = *dau, tr = sa->tiep;
		sa->tiep = NULL; // dau thanh cuoi.
		while (tr !=NULL)
		{
			gi = tr; // giua chay len truoc.
			tr = tr->tiep;
			gi->tiep = sa;
			sa = gi; // sau chay len giua.
		}
		*dau = sa; // dau danh sach.
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