/*
Ica 16/07/2008, veh: ILW VAW TFY @ KOS GRE
Ica 16/07/2008, sja: ILW VAW TFY @ KOS GRE

Bai toan tri tue nhan tao GA & CHO
*/

#include <stdio.h>
#include <conio.h>

void main () /*- - - - - - - - - -*/
{
	textmode (3); clrscr ();
	printf ("\t\t\tCHAO MUNG BAN DEN VOI BORLAND C++ 3.1\n");
	printf ("SKG\n\n");
	printf ("Bai toan Ga & Cho.\n");

	/*
	N: tong so chan ga + chan cho.
	M: so ga hon so cho.
	x: so ga.
	y: so cho.
	Tu do ta suy ra he phuong trinh la:
		2*x + 4*y = N
		x - y = M
	-> Giai he phuong trinh nay:
		y = (N - 2*M)/6
		x = y + M
	*/

	int N, M, x, y;

	printf ("Nhap N: "); scanf ("%d", &N);
	printf ("Nhap M: "); scanf ("%d", &M);
	y = (N - 2*M)/6;
	x = y + M;
	if ((2*x + 4*y == N) && (x - y == M))
	{
		printf ("\nSo  ga = %d", x);
		printf ("\nSo cho = %d", y);
	}
	else printf ("Khong co loi giai");
	getch (); return;
} /*- - - - - - - - - -*/