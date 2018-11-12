/* Ve duong tron (x^2+y^2=R^2) ban thuat toan MidPoint.
Phien ban A1.
Ngay 05/10/2007, viet: Nguyen Van Toan, tai: KOS GRE
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

void mid (int xt, int yt, int r, int mau); // thuat toan MidPoint.

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
	int i = 0, r, x, y;
	
	// Lam xuat hien cac duong tron ngau nhien tren man hinh.
	while (!kbhit ())
	{
		r = 50+random (50);
		x = r+random (xmax-2*r);
		y = r+random (ymax-2*r);
		mid (x, y, r, 1+random (15));

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
void mid (int xt, int yt, int r, int mau)
{
	int x = 0, y = r, d = 1-r;
	while (x <= y)
	{
		putpixel (X+xt+x, Y-(yt+y), mau);
		putpixel (X+xt-x, Y-(yt+y), mau);
		putpixel (X+xt+x, Y-(yt-y), mau);
		putpixel (X+xt-x, Y-(yt-y), mau);

		putpixel (X+xt+y, Y-(yt+x), mau);
		putpixel (X+xt-y, Y-(yt+x), mau);
		putpixel (X+xt+y, Y-(yt-x), mau);
		putpixel (X+xt-y, Y-(yt-x), mau);

		if (d < 0) d += 2*x+3;
		else
		{
			d += 2*(x-y)+5;
			y--;
		}
		x++;
		delay (cho);
	}
	return;
}