/* CAY NHI PHAN.
Bai 2: chuong trinh thuc hien cac cong viec:
	Tao cay nhi phan tim kiem chua cac so nguyen.
	Them mot nut.
	Xoa mot nut.
	Hien thi theo thu tu giua.
	Kiem tra co phai cay nhi phan tim kiem khong?

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

ct nutla (int x); // tao nut la.
char them (ct *goc, int x); // them nut vao cay.
ct xoa (ct goc, ct p); /* xoa nut p. Nut p phai ton tai,
tra ve nut the mang cua nut p.*/
void LNR (ct goc); // duyet theo thu tu giua.
char ktr (ct goc); // kiem tra cay nhi phan tim kiem.

ct tim (ct goc, int x); // tim nut x trong cay.
ct cha (ct goc, ct p); /* tim nut cha cua nut p. Nut p
phai khac nut goc va nut p phai ton tai.*/

void main () /*- - - - - - - - - -*/
{
	textmode (3); char chon; int x;
	ct c, p; // nut cha va nut con.
	ct goc = NULL; // khoi tao cay.

	batdau: printf ("\t\t\t\t<CHUONG TRINH>\n");
	printf ("\tTAO CAY NHI PHAN TIM KIEM CHUA CAC SO NGUYEN NHAP TU BAN PHIM\n");
	printf ("1. Them mot nut\n");
	printf ("2. Xoa mot nut\n");
	printf ("3. Thu tu giua\n");
	printf ("4. Kiem tra cay\n");
	printf ("0. Ket thuc\n");

	printf ("Chon cong viec: "); chon = getche ();
	if (chon == '0') return; // ket thuc.
	if (chon < '0' || chon > '4')
	{
		printf ("\n\n");
		goto batdau;
	}
	printf ("\n");
	switch (chon)
	{
		case '1':
			printf ("Nhap gia tri nut can them: "); scanf ("%d", &x);
			if (them (&goc, x) == 0) printf ("Khong the them %d duoc!\n", x);
			break;
		case '2':
			printf ("Nhap gia tri nut can xoa: "); scanf ("%d", &x);
			p = tim (goc, x);
			if (p == NULL) printf ("Khong xoa duoc, tim khong thay %d...\n", x);
			else
			{
				if (p == goc) goc = xoa (goc, p);
				else
				{
					c = cha (goc, p);
					if (c->trai == p) c->trai = xoa (goc, p);
					if (c->phai == p) c->phai = xoa (goc, p);
				}
			}
			break;
		case '3':
			if (goc == NULL) printf ("Cay nhi phan rong!\n");
			else
			{
				printf ("Duyet thu tu giua:\n");
				LNR (goc); printf ("\n");
			}
			break;
		case '4':
			if (ktr (goc)) printf ("Day la cay nhi phan tim kiem!\n");
			else printf ("Khong phai la cay nhi phan tim kiem!\n");
	}
	printf ("\n"); goto batdau;
} /*- - - - - - - - - -*/

// Tao nut la.
ct nutla (int x)
{
	ct p = (ct) malloc (sizeof (np));
	p->nut = x;
	p->trai = NULL;
	p->phai = NULL;
	return p;
}

// Them nut vao cay.
char them (ct *goc, int x)
{
	if (*goc == NULL)
	{
		*goc = nutla (x);
		return 2; // them tai nut goc.
	}
	else
	{
		ct p, q = *goc;
		do
		{
			p = q; // chay theo sau nut q.
			if (x == p->nut) return 0; // them khong duoc.
			if (x < p->nut) q = p->trai; else q = p->phai;
		} while (q != NULL);
		
		if (x < p->nut)
		{
			p->trai = nutla (x);
			return 1; // them ben trai.
		}
		else
		{
			p->phai = nutla (x);
			return 3; // them ben phai.
		}
	}
}

// Xoa nut p. Nut p phai ton tai, tra ve nut the mang cua nut p.
ct xoa (ct goc, ct p)
{
	ct tm; // nut the mang.
	if (p->trai == NULL) tm = p->phai; // nut the mang nam ben phai.
	else if (p->phai == NULL) tm = p->trai; // nut the mang nam ben trai.
	else // nut la hoac nut co 2 con.
	{
		// Nut the mang la nut trai nhat cua cay ben phai.
		tm = p->phai; // di sang phai.
		ct ch = p; // nut cha cua nut tm.
		
		// Tim nut trai nhat.
		while (tm->trai != NULL)
		{
			ch = tm;
			tm = tm->trai;
		}

		if (ch != p)
		{
			tm->trai = p->trai;
			ch->trai = tm->phai;
			tm->phai = p->phai;
		}
		else tm->trai = p->trai;
	}
	free (p); return tm;
}

// Duyet thu tu giua.
void LNR (ct goc)
{
	if (goc != NULL)
	{
		LNR (goc->trai);
		printf ("%d ", goc->nut);
		LNR (goc->phai);
	}
}

// Kiem tra cay nhi phan tim kiem.
char ktr (ct goc)
{
	char ok = 1;
	ct T = goc->trai, P = goc->phai;
	if (T != NULL && P != NULL)
	{
		if (goc->nut <= T->nut) ok = 0;
		if (goc->nut >= P->nut) ok = 0;

		if (goc->nut > T->nut) ktr (T);
		if (goc->nut < P->nut) ktr (P);
	}
	return ok; // (?).
}

// Tim nut x trong cay.
ct tim (ct goc, int x)
{
	ct p = goc;
	while (p != NULL)
	{
		if (x == p->nut) return p;
		else if (x < p->nut) p = p->trai;
		else p = p->phai;
	}
	return NULL; // khong tim thay.
}

// Tim nut cha cua nut p. Nut p phai khac nut goc va nut p phai ton tai.
ct cha (ct goc, ct p)
{
	ct sau, truoc = goc;
	do
	{
		sau = truoc; // chay theo bien truoc.
		if (p->nut < sau->nut) truoc = sau->trai; else truoc = sau->phai;
	} while (truoc != p);
	return sau; // da tim thay.
}