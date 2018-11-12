/* PHAN DE QUI.
Bai 4: nhap so nguyen duong, hien thi theo thu tu nguoc lai.

Ngay 01/07/2007, viet: Nguyen Van Toan, tai: KOS GRE.
Ngay 15/07/2007,  sua: Nguyen Van Toan, tai: KOS GRE.
*/

#include <stdio.h>
#include <conio.h>

void daoso (long n); // hien so theo thu tu nguoc lai.

void main () /*----------*/
{	
	long n; textmode (3); clrscr ();
	do
	{
		printf ("\t\t\t\t<CHUONG TRINH>\n");
		printf ("\tHIEN THI THEO THU TU NGUOC LAI CUA SO DA NHAP, NHAP 0 DE KET THUC\n");
		nhapn: printf ("Nhap n: "); scanf ("%ld", &n);
		if (n < 0) goto nhapn;
		printf ("Ket qua dao nguoc: ");
		daoso (n); printf ("\n\n");
	} while (n);
	return;
} /*----------*/

// Hien so theo thu tu nguoc lai.
void daoso (long n)
{
	char du = n%10;
	if (n == 0) return;
	else
	{
		printf ("%d", du);
		daoso (n/10);
	}
}