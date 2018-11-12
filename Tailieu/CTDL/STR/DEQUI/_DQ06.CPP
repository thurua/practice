/* PHAN DE QUI.
Bai 6: ma di tuan.

Ngay 03/07/2007, viet: Nguyen Van Toan, tai: KOS GRE.
Ngay 15/07/2007,  sua: Nguyen Van Toan, tai: KOS GRE.
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

const char kt = 8; // kich thuoc cua ban co.
int banco[kt][kt]; // to chuc ban co.

// Tam cach di cua con ma.
/*int a[] = {2, 2, 1, -1, -2, -2, -1, 1};
int b[] = {1, -1, -2, -2, -1, 1, 2, 2};*/
int a[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int b[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int slg; // so loi giai.

void nuocdi (char n, char x, char y); // nuoc di tai dong x cot y.
void innuoc (int banco[kt][kt]); // in nuoc di.
void inbaco (); // in ban co ra man hinh.

void main () /*----------*/
{
	textmode (3); clrscr (); inbaco ();

	// Chon nuoc di, va goi de qui.
	for (int i = 0; i < kt; i++)
		for (int j = 0; j < kt; j++)
		{
			for (int m = 0; m < kt; m++)
				for (int n = 0; n < kt; n++)
					banco[m][n] = 0;
			banco[i][j] = 1;
			nuocdi (2, i, j);
		}
	getch (); return;
} /*----------*/

// Nuoc di tai dong x cot y.
void nuocdi (char n, char x, char y)
{
	for (int i = 0; i < kt; i++)
	{
		if (banco[x+a[i]][y+b[i]] == 0 && x+a[i] >= 0 && x+a[i] < kt && y+b[i] >= 0 && y+b[i] < kt)
		{
			banco[x+a[i]][y+b[i]] = n;
			if (n == kt)
			{
				innuoc (banco);
				gotoxy (43, 3); printf ("Loi giai thu %d", ++slg);
				gotoxy (13, 25); printf ("An Enter de tiep tuc, ESC de thoat...");
				if (getch () == 27) exit (1);
			}
			else
			{
				nuocdi (n+1, x+a[i], y+b[i]);
				
				// Lan nguoc.
				banco[x+a[i]][y+b[i]] = 0;
				innuoc (banco);
				gotoxy (43, 4); printf ("Dang tim loi giai thu %d", slg+1);
				gotoxy (13, 25); printf ("Xin vui long cho, an Ctrl-Break de thoat...");
			}
		}		
	}
}

// In nuoc di.
void innuoc (int banco[kt][kt])
{
	randomize (); textcolor (1+random (15));
	for (int i = 0; i < kt; i++)
		for (int j = 0; j < kt; j++)
		{
			gotoxy (22+5*j, 8+2*i);
			if (banco[i][j] == 0) printf ("  ");
			else cprintf ("%.2d", banco[i][j]);
		}
}

// In ban co ra man hinh.
void inbaco ()
{
	printf ("\n\t\t\t   CHUONG TRINH MA DI TUAN\n");
	printf ("\n\tKich thuoc ban co la: %d x %d", kt, kt);
	printf ("\n\n\t\t     01   02   03   04   05   06   07   08");
	printf ("\n\t\t   +----+----+----+----+----+----+----+----+");
	printf ("\n\t\t01 |    |    |    |    |    |    |    |    | 01");
	printf ("\n\t\t   +----+----+----+----+----+----+----+----+");
	printf ("\n\t\t02 |    |    |    |    |    |    |    |    | 02");
	printf ("\n\t\t   +----+----+----+----+----+----+----+----+");
	printf ("\n\t\t03 |    |    |    |    |    |    |    |    | 03");
	printf ("\n\t\t   +----+----+----+----+----+----+----+----+");
	printf ("\n\t\t04 |    |    |    |    |    |    |    |    | 04");
	printf ("\n\t\t   +----+----+----+----+----+----+----+----+");
	printf ("\n\t\t05 |    |    |    |    |    |    |    |    | 05");
	printf ("\n\t\t   +----+----+----+----+----+----+----+----+");
	printf ("\n\t\t06 |    |    |    |    |    |    |    |    | 06");
	printf ("\n\t\t   +----+----+----+----+----+----+----+----+");
	printf ("\n\t\t07 |    |    |    |    |    |    |    |    | 07");
	printf ("\n\t\t   +----+----+----+----+----+----+----+----+");
	printf ("\n\t\t08 |    |    |    |    |    |    |    |    | 08");
	printf ("\n\t\t   +----+----+----+----+----+----+----+----+");
	printf ("\n\t\t     01   02   03   04   05   06   07   08");
}