/* Ve duong parabol (x^2 = 2py) bang thuat toan MidPoint.
Phien ban A1.
Ngay 24/10/2007, viet: Nguyen Van Toan, tai: KOS GRE
Ngay 24/10/2007,  sua: Nguyen Van Toan, tai: KOS GRE
*/

#include <iostream.h>
#include <stdio.h>
#include <math.h>
#include <dos.h>
#include <graphics.h>
#include <stdlib.h>
#include <conio.h>

int cho = 5; // thoi gian bang mili giay.
int X, Y; // gia tri de tinh tien toa do.

void mid (int xt, int yt, int p, int xD, int mau); // thuat toan MidPoint.

/*--------------------------------------------------------------------------------*/
void main () /*__________*/
{
	int mh = 0, af = 0, lgz;
	initgraph (&mh, &af, "D:\\BorLac\\BGI");
	lgz = graphresult ();
	if (lgz != grOk)
	{
		printf ("Loi do hoa: %s", grapherrormsg (lgz));
		printf ("An phim bat ki de ket thuc...");
		getch (); exit (1);
	}
	int xmax = getmaxx (), ymax = getmaxy ();
	X = 0, Y = ymax; // toa do (0, 0) o goc trai duoi.
	int i = 0, p, x, y;

	// Lam xuat hien cac duong parabol ngau nhien tren man hinh.
	while (!kbhit ())
	{
		p = 3+random (7);
		x = p+random (xmax-2*p);
		y = p+random (ymax-2*p);
		mid (x, y, p, 35, 1+random (15));

		if (i > 100)
		{
			cleardevice ();
			i = 0;
		}
		else
		{
			i++;
			delay (87);
		}
	}
	getch (); closegraph (); return;
} /*__________*/
/*--------------------------------------------------------------------------------*/

// Thuat toan MidPoint.
void mid (int xt, int yt, int p, int xD, int mau)
{
	// Thuat toan 1.
	int x = 0, y = 0, p1 = 1-p;
	while (x <= p && x <= xD)
	{
		putpixel (X+xt+x, Y-(yt+y), mau);
		putpixel (X+xt-x, Y-(yt+y), mau);

		if (p1 < 0) p1 += 2*x+3;
		else
		{
			p1 += 2*x+3-2*p;
			y++;
		}
		x++;
		delay (cho);
	}
	
	// Thuat toan 2.
	p1 = 4*p-1;
	while (x <= xD)
	{
		putpixel (X+xt+x, Y-(yt+y), mau);
		putpixel (X+xt-x, Y-(yt+y), mau);

		if (p1 < 0) p1 += 8*p;
		else
		{
			p1 += 8*p-8*x-8;
			x++;
		}
		y++;
		delay (cho);
	}
	return;
}