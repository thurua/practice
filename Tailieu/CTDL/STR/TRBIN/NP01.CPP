/* CAY NHI PHAN.
Bai 1: tao cay nhi phan cho truoc, roi hien thi theo thu tu truoc, giua, sau.

Ngay 08/07/2007, viet: Nguyen Van Toan, tai: KOS GRE.
Ngay 19/07/2008,  sua: Nguyen Van Toan, tai: KOS GRE.
*/

#include <stdio.h>
#include <conio.h>
#include <alloc.h>

typedef struct np
{
	int nut;
	np *trai, *phai;
} *ct;

ct cay (int x, ct T, ct P); // tao cay nhi phan.
void NLR (ct goc); // duyet thu tu truoc.
void LNR (ct goc); // duyet thu tu giua.
void LRN (ct goc); // duyet thu tu sau.

void main () /*- - - - - - - - - -*/
{
	textmode (3); clrscr ();
	ct goc = NULL; // khoi tao cay.
	goc = cay (12, cay (4, cay (32, NULL, NULL), cay (8, cay (37, NULL, NULL), NULL)), cay (9, cay (14, cay (4, NULL, NULL), cay (3, NULL, NULL)), NULL));
	printf ("\t\t\t\t<CHUONG TRINH>\n");
	printf ("\tTAO CAY NHI PHAN CHO TRUOC VA XUAT KET QUA DUYET THEO 3 CACH\n");
	printf ("\nThu tu truoc:"); NLR (goc);
	printf ("\nThu  tu giua:"); LNR (goc);
	printf ("\nThu  tu  sau:"); LRN (goc);
	getch (); return;
} /*- - - - - - - - - -*/

// Tao cay nhi phan.
ct cay (int x, ct T, ct P)
{
	ct p = (ct) malloc (sizeof (np));
	p->nut = x;
	p->trai = T;
	p->phai = P;
	return p;
}

// Duyet thu tu truoc.
void NLR (ct goc)
{
	if (goc != NULL)
	{
		printf ("%3d", goc->nut);
		NLR (goc->trai);
		NLR (goc->phai);
	}
}

// Duyet thu tu giua.
void LNR (ct goc)
{
	if (goc != NULL)
	{
		LNR (goc->trai);
		printf ("%3d", goc->nut);
		LNR (goc->phai);
	}
}

// Duyet thu tu sau.
void LRN (ct goc)
{
	if (goc != NULL)
	{
		LRN (goc->trai);
		LRN (goc->phai);
		printf ("%3d", goc->nut);
	}
}