/*
Ica 16/07/2008, veh: ILW VAW TFY @ KOS GRE
Ica 16/07/2008, sja: ILW VAW TFY @ KOS GRE

Danh sach lien ket
1. Tach ds so nguyen -> ds so am & ds so duong.
2. Tach ds so nguyen -> ds so chan & ds so le.
3. Tach ds so nguyen -> ds so nguyen to & ds so thuong.
*/

#include <stdio.h>
#include <conio.h>
#include <alloc.h>

#include <stdlib.h>
#include <math.h>

typedef struct ds
{
	int nut;
	ds *tip;
} *ctds;

ctds nutmoi (int x); // tao nut moi.
void themdau (ctds *dau, int x); // them dau danh sach.
void duyet (ctds *dau); // duyet danh sach.
void tao (ctds *dau); // khoi tao danh sach lien ket.

void tach_al (ctds *ds, ctds *am, ctds *duong); // tach am duong.
void tach_cl (ctds *ds, ctds *chan, ctds *le); // tach chan le.

// Neu tach co lien quan den so nguyen to thi dung
void tach_ngto (ctds *ds, ctds *ngto, ctds *bthuong); // tach nguyen to.
char so_ngto (int so); // kiem tra so nguyen to.

void main () /*- - - - - - - - - -*/
{
	textmode (3); clrscr ();
	printf ("\t\t\tCHAO MUNG BAN DEN VOI BORLAND C++ 3.1\n");
	printf ("SKG\n\n");
	printf ("Chuong trinh thao tach tren danh sach co ban.\n");

	// Tao danh sach so nguyen ngau nhien 10 phan tu.
	ctds so; tao (&so); // khoi tao danh sach.
	randomize (); // khoi dong che do ngau nhien.
	for (int i = 0; i < 10; i++)
		themdau (&so, random (35) - random (35));
	printf ("Danh sach  so nguyen: "); duyet (&so); // duyet danh sach.

	// Tach am duong
	ctds a; tao (&a); // khoi tao ds chua so am.
	ctds d; tao (&d); // khoi tao ds chua so duong.
	tach_al (&so, &a, &d);
	printf ("\n\nDanh  sach  so  am: "); duyet (&a);
	printf ("\nDanh sach so duong: "); duyet (&d);

	// Tach chan le
	ctds c; tao (&c); // khoi tao ds chua so chan.
	ctds l; tao (&l); // khoi tao ds chua so le.
	tach_cl (&so, &c, &l);
	printf ("\n\nDanh sach so chan: "); duyet (&c);
	printf ("\nDanh  sach  so le: "); duyet (&l);

	// Tach nguyen to, khong nguyen to
	ctds x; tao (&x); // khoi tao ds chua so nguyen to.
	ctds y; tao (&y); // khoi tao ds chua so khong nguyen to.
	tach_cl (&so, &x, &y);
	printf ("\n\nDanh   sach  so  nguyen   to: "); duyet (&x);
	printf ("\nDanh  sach  so khong nguyen to: "); duyet (&y);
	getch (); return;
} /*- - - - - - - - - -*/

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
	p->tip = *dau; // nut moi chi toi dau.
	*dau = p; // thiet lap dau con tro dau.
}

// Duyet danh sach
void duyet (ctds *dau)
{
	ctds p = *dau;
	while (p != NULL)
	{
		printf ("%d ", p->nut);
		p = p->tip;
	}
}

// Khoi tao danh sach lien ket.
void tao (ctds *dau)
{
	*dau = NULL;
	return;
}

// Tach am duong.
void tach_al (ctds *ds, ctds *am, ctds *duong)
{
	ctds p = *ds;
	while (p != NULL)
	{
		if (p->nut > 0) themdau (duong, p->nut);
		else themdau (am, p->nut);
		p = p->tip;
	}
	return;
}

// Tach chan le.
void tach_cl (ctds *ds, ctds *chan, ctds *le)
{
	ctds p = *ds;
	while (p != NULL)
	{
		if (p->nut % 2 == 0) themdau (chan, p->nut);
		else themdau (le, p->nut);
		p = p->tip;
	}
	return;
}

// Tach nguyen to.
void tach_ngto (ctds *ds, ctds *ngto, ctds *bthuong)
{
	ctds p = *ds;
	while (p != NULL)
	{
		if (so_ngto(p->nut)) themdau (ngto, p->nut);
		else themdau (bthuong, p->nut);
		p = p->tip;
	}
	return;
}

// Kiem tra so nguyen to.
char so_ngto (int so)
{
	for (int i = 2; i <= sqrt (so); i++)
		if (so % i == 0) return 0;
	return 1;
}