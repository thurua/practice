/* PHAN DE QUI.
Bai 1: chuong trinh tinh to hop n chap k phan tu, n la so nguyen duong
nhap tu ban phim.

Ngay 01/07/2007, viet: Nguyen Van Toan, tai: KOS GRE.
Ngay 15/07/2007,  sua: Nguyen Van Toan, tai: KOS GRE.
*/

#include <stdio.h>
#include <conio.h>

double gt (int n); // ham giai thua cua n.
double th1 (int n, int k); // to hop n chap k phan tu theo ham gt ().

double dggt (int x, int y); // don gian x!/y!, x > y > 0.
double th2 (int n, int k); // to hop n chap k phan tu theo ham dggt ().

void main () /*----------*/
{
	int n, k; textmode (3); clrscr ();
	do
	{
		printf ("\t\t\t\t<CHUONG TRINH>\n");
		printf ("\t\tTINH TO HOP N CHAP K PHAN TU NHAP K=0 DE KET THUC\n");
		nhapn: printf ("Nhap n: "); scanf ("%d", &n);
		if (n < 0) goto nhapn;
		nhapk: printf ("Nhap k: "); scanf ("%d", &k);
		if (k > n) goto nhapk;
		printf ("Ket qua: %g\n\n", th2 (n, k));
	} while (k);
	return;
} /*----------*/

// Ham giai thua cua n.
double gt (int n)
{
	return n == 0 ? 1 : gt (n-1)*n;
}

// To hop n chap k phan tu theo ham gt ().
double th1 (int n, int k)
{
	return gt (n)/(gt (n-k)*gt (k));
}

// Don gian x!/y!, x > y.
double dggt (int x, int y)
{
	return x == y ? 1 : dggt (x-1, y)*x;
}


// To hop n chap k phan tu theo ham dggt ().
double th2 (int n, int k)
{
	return dggt (n, n-k)/dggt (k, 0);
}