/* CAY NHI PHAN.
Bai 4: chuong trinh thuc hien cac cong viec:
	Tao cay nhi phan.
	Xac dinh so nut tren cay.
	Xac dinh so nut la tren cay.
	Xac dinh so nut co mot con.
	Xac dinh so nut co 2 con.
	So nut tren tung muc.
	So nut co noi dung lon hon x.

Ngay 09/07/2007, viet: Nguyen Van Toan, tai: KOS GRE.
Ngay 12/07/2007,  sua: Nguyen Van Toan, tai: KOS GRE.
*/

#include <stdio.h>
#include <conio.h>
#include <alloc.h>

const int TD = 35; // do rong toi da cua hang doi.

typedef struct nhiphan
{
	int nut;
	nhiphan *trai, *phai;
} *ctnut;

typedef struct queue
{
	int dau, cuoi;
	nhiphan nut[TD];
} *que;

que hd; // hang doi dung de dem nut o tung muc.

ctnut nutla (int x); // tao nut la.
int demsnut (ctnut goc); // dem so nut tren cay.
int sonutla (ctnut goc); // dem so nut la tren cay.
int sonut1c (ctnut goc); // dem so nut co 1 con.
int sonut2c (ctnut goc); // dem so nut co 2 con.
void nutomuc (ctnut goc); // dem so nut o tung muc.
int sonutlx (ctnut goc, int x); // dem so nut lon hon x.

void LNR (ctnut goc); // duyet theo thu tu giua.
void khoitao (que ct); // khoi tao hang doi.
void insert (que ct, nhiphan x); // them vao hang doi.
nhiphan remove (que ct); // lay ra khoi hang doi.
int size (que ct); // kich thuoc cua hang doi.
char cao (ctnut goc); // chieu cao cua cay.

void main () /*- - - - - - - - - -*/
{
	textmode (3); clrscr ();
	ctnut p, goc = NULL; // khoi tao cay.
	khoitao (hd); // khoi tao hang doi.
	goc = nutla (13); // nut goc.
	
	goc->trai = nutla (11); // nut ben trai nut 13.
	goc->phai = nutla (10); // nut ben trai nut 13.
	
	(goc->trai)->trai = nutla (6); // nut ben trai nut 11.
	(goc->trai)->phai = nutla (16); // nut ben phai nut 11.

	(goc->phai)->trai = nutla (7); // nut ben trai nut 10.
	(goc->phai)->phai = nutla (12); // nut ben phai nut 10.

	((goc->phai)->phai)->trai = nutla (4); // nut ben trai nut 12.
	((goc->phai)->phai)->phai = nutla (5); // nut ben phai nut 12.

	((goc->trai)->trai)->phai = nutla (9); // nut ben phai nut 6.

	printf ("Duyet cay theo thu tu giua: "); LNR (goc);
	printf ("\nTong   so     nut: %d\n", demsnut (goc));
	printf ("Tong  so  nut  la: %d\n", sonutla (goc));
	printf ("Tong so nut 1 con: %d\n", sonut1c (goc));
	printf ("Tong so nut 2 con: %d\n", sonut2c (goc));
	int x = 7;
	printf ("Tong so  nut > %d: %d", x, sonutlx (goc, x));
	printf ("\n\n"); nutomuc (goc);
	printf ("Chuong trinh viet boi Nguyen Van Toan (KOS GRE).");
	getch (); return;
} /*- - - - - - - - - -*/

// Tao nut la.
ctnut nutla (int x)
{
	ctnut p = (ctnut) malloc (sizeof (nhiphan));
	p->nut = x;
	p->trai = NULL;
	p->phai = NULL;
	return p;
}

// Dem so nut tren cay.
int demsnut (ctnut goc)
{
	if (goc == NULL) return 0;
	return demsnut (goc->trai)+demsnut (goc->phai)+1;
}

// Dem so nut la tren cay.
int sonutla (ctnut goc)
{
	if (goc == NULL) return 0;
	if (goc->trai == NULL && goc->phai == NULL) return 1;
	return sonutla (goc->trai)+sonutla (goc->phai);
}

// Dem so nut co 1 con.
int sonut1c (ctnut goc)
{
	if (goc == NULL) return 0;
	if (goc->trai != NULL && goc->phai == NULL) return 1;
	if (goc->trai == NULL && goc->phai != NULL) return 1;
	return sonut1c (goc->trai)+sonut1c (goc->phai);
}

// Dem so nut co 2 con.
int sonut2c (ctnut goc)
{
	if (goc == NULL) return 0;
	if (goc->trai == NULL && goc->phai == NULL) return 0;
	if (goc->trai != NULL && goc->phai == NULL) return 0;
	if (goc->trai == NULL && goc->phai != NULL) return 0;
	return sonut2c (goc->trai)+sonut2c (goc->phai)+1;
}

// Dem so nut o tung muc.
void nutomuc (ctnut goc)
{
	static int muc, sn;
	nhiphan p;
	if (goc != NULL) insert (hd, *goc);
	for (int n = 0; n < cao (goc); n++)
	{
		sn = size (hd);
		printf ("Muc %d tong so nut: %d\n", muc++, sn);
		for (int i = 0; i < sn; i++)
		{
			p = remove (hd);
			if (p.trai != NULL) insert (hd, *(p.trai));
			if (p.phai != NULL) insert (hd, *(p.phai));
		}
	}
}

// Dem so nut lon hon x.
int sonutlx (ctnut goc, int x)
{
	if (goc == NULL) return 0;
	if (goc->nut > x)	return sonutlx (goc->trai, x)+sonutlx (goc->phai, x)+1;
	return sonutlx (goc->trai, x)+sonutlx (goc->phai, x);
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

// Khoi tao hang doi.
void khoitao (que ct)
{
	ct->dau = ct->cuoi = TD-1;
}

// Them vao hang doi.
void insert (que ct, nhiphan x)
{
	if (ct->cuoi == TD) ct->cuoi = 0; else ct->cuoi++;
	ct->nut[ct->cuoi] = x;
}

// Lay ra khoi hang doi.
nhiphan remove (que ct)
{
	if (ct->dau == TD) ct->dau = 0; else ct->dau++;
	return ct->nut[ct->dau];
}

// Kich thuoc cua hang doi.
int size (que ct)
{
	if (ct->cuoi > ct->dau) return ct->cuoi-ct->dau;
	return TD-ct->dau+ct->cuoi+1;
}

// Chieu cao cua cay.
char cao (ctnut goc)
{
	if (goc == NULL) return 0;
	if (cao (goc->trai) > cao (goc->phai)) return cao (goc->trai)+1;
	else return cao (goc->phai)+1;
}