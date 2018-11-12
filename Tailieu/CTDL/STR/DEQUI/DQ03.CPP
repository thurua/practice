/* PHAN DE QUI.
Bai 3: chuong trinh kiem tra mot so nguyen nhap vao co doi xung khong.

Ngay 01/07/2007, viet: Nguyen Van Toan, tai: KOS GRE.
Ngay 15/07/2007,  sua: Nguyen Van Toan, tai: KOS GRE.
*/

#include <stdio.h>
#include <conio.h>
#include <math.h>

char dem (long n); // dem so kit tu so co trong n.
long dxu (long so, char n); // tim so doi xung cua n.

void main () /*----------*/
{
	long n; textmode (3); clrscr ();
	do
	{
		printf ("\t\t\t\t<CHUONG TRINH>\n");
		printf ("\t\tKIEM TRA SO CO TINH DOI XUNG KHONG, NHAP 0 DE KET THUC\n");
		nhapn: printf ("Nhap n: "); scanf ("%ld", &n);
		if (n < 0) goto nhapn;
		if (n == dxu (n, dem (n))) printf ("So %ld co tinh doi xung...\n\n", n);
		else printf ("So %ld khong co tinh doi xung...\n\n", n);
	} while (n);
	return;
} /*----------*/

// Dem so kit tu so co trong n.
char dem (long n)
{
	return n == 0 ? 0 : dem (n/10)+1;
}


// Tim so doi xung cua n.
long dxu (long so, char n)
{
	char du = so%10;
	return so == 0 ? 0 : dxu (so/10, n-1)+du*pow10 (n-1);
}