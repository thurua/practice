/* CAY NHI PHAN.
Bai 3: chuong trinh thuc hien cac cong viec:
	Khoi tao cay nhi phan hoan toan cang bang.
	Them mot nut vao cay nhi phan can bang.
	Kiem tra cay nhi phan co can bang khong?

Ngay 09/07/2007, viet: Nguyen Van Toan, tai: KOS GRE.
Ngay 09/07/2007,  sua: Nguyen Van Toan, tai: KOS GRE.
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

typedef struct nhiphan
{
	int nut, sonut;
	nhiphan *trai, *phai;
} *ctnut;

ctnut nutla (int x); // tao nut la.
char them (ctnut *goc, int x); // them nut vao cay.
char ktr (ctnut goc); // kiem tra cay nhi phan can bang.

void LNR (ctnut goc); // duyet theo thu tu giua.

int main () /*- - - - - - - - - -*/
{
	//textmode (3);
	 char chon; int x;
	ctnut goc = NULL; // khoi tao cay.
	randomize (); // khoi dong che do ngau nhien.
	
	printf ("\t\t\t\t<CHUONG TRINH>\n");
	printf ("\t\tTAO CAY NHI PHAN HOAN TOAN CAN BANG CHUA CAC SO NGUYEN\n");
	
	for (int i = 0; i < 13; i++) them (&goc, random (35)); // them vao cay.
	printf ("\nDuyet: "); LNR (goc);
	
	if (ktr (goc)) printf ("\nCay nhi phan hoan toan can bang!");
	else printf ("\nCay nhi phan khong can bang!");
	getch (); return 0;
} /*- - - - - - - - - -*/

// Tao nut la.
ctnut nutla (int x)
{
	ctnut p = (ctnut) malloc (sizeof (nhiphan));
	p->nut = x;
	p->sonut = 1;
	p->trai = NULL;
	p->phai = NULL;
	return p;
}

// Them nut vao cay.
char them (ctnut *goc, int x)
{
	if (*goc == NULL) *goc = nutla (x);
	else
	{
		// So nut le thi them ben trai.
		ctnut p = *goc;
		while (p->sonut != 1 && p->sonut != 2)
		{
			p->sonut++; // tang so nut len.
			if (p->sonut%2 == 0) p = p->trai;
			else p = p->phai;
		}
		if (p->sonut == 1) p->trai = nutla (x);
		else p->phai = nutla (x);
		p->sonut++; // tang so nut len.
	}
}

// Kiem tra cay nhi phan can bang.
char ktr (ctnut goc)
{
	if (goc == NULL) return 1;
	ctnut T = goc->trai, P = goc->phai;
	if (abs (T->sonut-P->sonut) > 1) return 0;
	ktr (T); // kiem tra ben trai.
	ktr (P); // kiem tra ben trai.
}

// Duyet thu tu giua.
void LNR (ctnut goc)
{
	if (goc != NULL)
	{
		LNR (goc->trai);
		printf ("%d ", goc->nut);
		LNR (goc->phai);
	}
}
