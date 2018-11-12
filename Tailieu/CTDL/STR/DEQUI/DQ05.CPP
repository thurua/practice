/* PHAN DE QUI.
Bai 5: bai toan thap Ha Noi.

Ngay 01/07/2007, viet: Nguyen Van Toan, tai: KOS GRE.
Ngay 15/07/2007,  sua: Nguyen Van Toan, tai: KOS GRE.
*/

#include <stdio.h>
#include <conio.h>

void hanoi (char n, char a, char b, char c); // chuyen n dia tu cot a sang c lay
// cot b lam trung gian.

void main () /*----------*/
{	
	char n; textmode (3); clrscr ();
	do
	{
		printf ("\t\t\t\t<CHUONG TRINH>\n");
		printf ("\t\tBAI TOAN THAP HA NOI, NHAP 0 DE KET THUC\n");
		nhapn: printf ("Nhap n: "); scanf ("%d", &n);
		if (n < 0 || n > 9)
		{
			printf ("Gia tri 0 < n < 10\n");
			goto nhapn;
		}
		if (n) hanoi (n, 'A', 'B', 'C');
		printf ("\n");
	} while (n);
	return;
} /*----------*/

// Chuyen n dia tu cot a sang c lay cot b lam trung gian.
void hanoi (char n, char a, char b, char c)
{
	if (n == 1) printf ("Chuyen dia %d tu cot %c sang cot %c\n", n, a, c);
	else
	{
		hanoi (n-1, a, c, b); // chuyen n-1 dia tu cot a sang b lay c lam trung gian.
		printf ("Chuyen dia %d tu cot %c sang cot %c\n", n, a, c);
		hanoi (n-1, b, a, c); // chuyen n-1 dia tu cot b sang c lay a lam trung gian.
	}
}