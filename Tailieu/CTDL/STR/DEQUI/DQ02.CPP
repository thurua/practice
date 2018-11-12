/* PHAN DE QUI.
Bai 2: chuong trinh tinh day Fibonasi F(n) = F(n-1)+F(n-2), F(0) = F(1) = 1.

Ngay 01/07/2007, viet: Nguyen Van Toan, tai: KOS GRE.
Ngay 15/07/2007,  sua: Nguyen Van Toan, tai: KOS GRE.
*/

#include <stdio.h>
#include <conio.h>

float fibo (int n); // tinh day Fibonasi.

void main () /*----------*/
{
	int n; textmode (3); clrscr ();
	do
	{
		printf ("\t\t\t\t<CHUONG TRINH>\n");
		printf ("\tTINH GIA TRI DAY FIBONASI F(n) = F(n-1)+F(n-2), NHAP 0 DE KET THUC\n");
		nhapn: printf ("Nhap n: "); scanf ("%d", &n);
		if (n < 0 || n > 35) goto nhapn;
		printf ("Ket qua: %g\n", fibo (n));
	} while (n);
	return;
} /*----------*/

// Tinh day Fibonasi.
float fibo (int n)
{
	return (n == 0 || n == 1) ? 1 : fibo (n-1)+fibo (n-2);
}