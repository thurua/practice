/* SAP XEP.
Chuong trinh thuc hien cac cong viec:
	Nhap vao mot day so.
	Sap xep bang thuat toan Bubble Sort.
	Sap xep bang thuat toan Select Sort.
	Sap xep bang thuat toan Quick Sort.
	Tim kiem mot phan tu co gia tri x trong day bat ki.
	Tim kiem nhi phan trong day co thu tu tang.
	
Ngay 10/07/2007, viet: Nguyen Van Toan, tai: KOS GRE.
Ngay 19/07/2008,  sua: Nguyen Van Toan, tai: KOS GRE.
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void bubble (int *dso, int n); // sap xep tang bang thuat toan Bubble Sort.
void select (int *dso, int n); // sap xep tang bang thuat toan Select Sort.
void quicks (int *dso, int thp, int cao); // sap xep tang bang thuat toan Quicks Sort.
char timx (int *dso, int n, int x); // tim x trong day so.
char tim2 (int *dso, int n, int x); // tim kiem nhi phan.

void pvung (int *dso, int thp, int cao, int *hg); // phan vung sap xep.

void main () /*- - - - - - - - - -*/
{
	const int TD = 13; int so[TD], s1[TD], s2[TD], s3[TD];
	textmode (3); clrscr (); randomize ();

	// Nhap so vao mang.
	for (int i = 0; i < TD; i++) so[i] = random (100);

	// In mang da nhap.
	printf ("Day so ban dau: ");
	for (i = 0; i < TD; i++) printf ("%d ", so[i]);
	
	// Sao chep sang mang khac.
	for (i = 0; i < TD; i++)
	{
		s1[i] = so[i];
		s2[i] = so[i];
		s3[i] = so[i];
	}
	

	// Sap xep va in ket qua.
	bubble (s1, TD); printf ("\nThuat toan Bubble Sort: ");
	for (i = 0; i < TD; i++) printf ("%d ", s1[i]);

	select (s2, TD); printf ("\nThuat toan Select Sort: ");
	for (i = 0; i < TD; i++) printf ("%d ", s2[i]);

	quicks (s3, 0, TD-1); printf ("\nThuat toan Quicks Sort: ");
	for (i = 0; i < TD; i++) printf ("%d ", s3[i]);
	
	int x, t;

	// Tim kiem theo cach thong thuong.
	printf ("\nGia tri can tim o mang ban dau: "); scanf ("%d", &x);
	t = timx (so, TD, x);
	if (t == -1) printf ("Tim khong thay %d", x);
	else printf ("Tim thay %d o vi tri %d", x, t);

	// Tim kiem nhi phan.
	printf ("\nGia tri can tim o mang thu 2: "); scanf ("%d", &x);
	t = tim2 (s1, TD, x);
	if (t == -1) printf ("Tim khong thay %d", x);
	else printf ("Tim thay %d o vi tri %d", x, t);
	
	getch (); return;
} /*- - - - - - - - - -*/

// Sap xep tang bang thuat toan Bubble Sort.
void bubble (int *dso, int n)
{
	int tg; char doi = 1;
	for (int i = 1; i < n && doi == 1; i++)
	{
		doi = 0;
		for (int j = 0; j < n-i; j++)
			if (dso[j] > dso[j+1])
			{
				doi = 1;
				tg = dso[j];
				dso[j] = dso[j+1];
				dso[j+1] = tg;
			}
	}
}

// Sap xep tang bang thuat toan Select Sort.
void select (int *dso, int n)
{
	char vtr; // vi tri nho nhat.
	int tg; // bien trung gian.
	
	for (int i = 0; i < n-1; i++)
	{
		vtr = i;
		for (int j = i+1; j < n; j++)
			if (dso[vtr] > dso[j]) vtr = j;

		if (i != vtr)
		{
			tg = dso[i];
			dso[i] = dso[vtr];
			dso[vtr] = tg;
		}
	}
}

// Sap xep tang bang thuat toan Quicks Sort.
void quicks (int *dso, int thp, int cao)
{
	int hg;
	if (cao <= thp) return;
	pvung (dso, thp, cao, &hg);
	quicks (dso, thp, hg-1);
	quicks (dso, hg+1, cao);
}

// Tim x trong day so.
char timx (int *dso, int n, int x)
{
	for (int i = 0; i < n && dso[i] != x;) i++;
	if (i == n) return -1; // tim khong thay.
	return i; // tim thay o vi tri i.
}

// Tim kiem nhi phan.
char tim2 (int *dso, int n, int x)
{
	int trai = 0, phai = n-1;
	int giua;
	while (trai <= phai)
	{
		giua = (trai+phai)/2;
		if (dso[giua] == x) return giua;
		else if (x > dso[giua]) trai = giua+1;
		else phai = giua-1;
	}
	return -1; // tim khong thay.
}

// Phan vung sap xep.
void pvung (int *dso, int thp, int cao, int *hg)
{
	int truc = dso[thp], t = thp, c = cao, tg;
	while (t < c)
	{
		while (dso[t] <= truc && t < cao) t++;
		while (dso[c] > truc) c--;
		if (t < c)
		{
			tg = dso[t];
			dso[t] = dso[c];
			dso[c] = tg;
		}
	}
	dso[thp] = dso[c];
	dso[c] = truc;
	*hg = c;
}