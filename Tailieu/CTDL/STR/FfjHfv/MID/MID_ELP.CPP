/* Ve duong elip (x^2/a^2+y^2/b^2=1) bang thuat toan MidPoint.
Phien ban A1.
Ngay 19/10/2007, viet: Nguyen Van Toan, tai: KOS GRE
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

void mid (int xt, int yt, int a, int b, int mau); // thuat toan MidPoint.

// Thuat toan MidPoint.
void mid (int xt, int yt, int a, int b, int mau)
{
	// Thuat toan 1.
	int x = 0, y = b;
	long b2 = (long) b*b;
	long a2 = (long) a*a;
	long p = -b2+a2*b-a2/4;
	while (a2*y >= b2*x)
	{
		putpixel (X+xt+x, Y-(yt+y), mau);
		putpixel (X+xt-x, Y-(yt+y), mau);
		putpixel (X+xt+x, Y-(yt-y), mau);
		putpixel (X+xt-x, Y-(yt-y), mau);
		
		if (p >= 0) p += -2*b2*x+3*b2;
		else
		{
			p += -2*b2*x+3*b2+2*a2*y-2*a2;
			y--;
		}
		x++;
		delay (cho);
	}
	
	// Thuat toan 2.
	y = 0, x = a;
	p = -a2+b2*a-b2/4;
	while (b2*x >= a2*y)
	{
		putpixel (X+xt+x, Y-(yt+y), mau);
		putpixel (X+xt-x, Y-(yt+y), mau);
		putpixel (X+xt+x, Y-(yt-y), mau);
		putpixel (X+xt-x, Y-(yt-y), mau);
		
		if (p >= 0) p += -2*a2*y+3*a2;
		else
		{
			p += -2*a2*y+3*a2+2*b2*x-2*b2;
			x--;
		}
		y++;
		delay (cho);
	}
	return;
}

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
	int i = 0, a, b, x, y;
	
	// Lam xuat hien cac duong elip ngau nhien tren man hinh.
	while (!kbhit ())
	{
		a = 50+random (50);
		b = 50+random (50);
		x = a+random (xmax-2*a);
		y = b+random (ymax-2*b);
		mid (x, y, a, b, 1+random (15));

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