/* Ve duong thang (y=mx+b) bang thuat toan Bresenham.
Phien ban A1.
Ngay 16/09/2007, viet: Nguyen Van Toan, tai: KOS GRE
Ngay 24/10/2007,  sua: Nguyen Van Toan, tai: KOS GRE
*/

#include <iostream.h>
#include <stdio.h>
#include <math.h>
#include <dos.h>
#include <graphics.h>
#include <stdlib.h>
#include <conio.h>

int X, Y; // gia tri de tinh tien toa do.
int cho = 5; // thoi gian bang mili giay.

void brs (int x1, int y1, int x2, int y2, char mau); // thuat toan Bresenham.
void br1 (int x1, int y1, int x2, int y2, char mau); // y tang cham, x lap.
void br2 (int x1, int y1, int x2, int y2, char mau); // y giam cham, x lap.
void br3 (int x1, int y1, int x2, int y2, char mau); // x tang cham, y lap.
void br4 (int x1, int y1, int x2, int y2, char mau); // x giam cham, y lap.

void hv2 (int &x, int &y); // hoan vi 2 phan tu.

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
	int m, x1, y1, x2, y2;
	
	// Lam xuat hien cac duong thang ngau nhien tren man hinh.
	while (!kbhit ())
	{
		x1 = random (xmax); y1 = random (ymax);
		x2 = random (xmax); y2 = random (ymax);
		m = random (15)+1;
		brs (x1, y1, x2, y2, m);
		if (m == 15) m--; else m++;
	}
	getch (); closegraph (); return;
} /*__________*/
/*--------------------------------------------------------------------------------*/

// Thuat toan Bresenham.
void brs (int x1, int y1, int x2, int y2, char mau)
{
	// Diem dau trung voi diem cuoi.
	if (x1 == x2 && y1 == y2)
	{
		putpixel (X+x1, Y-y1, mau);
		return; // ket thuc.
	}
	
	int dx = x2-x1, dy = y2-y1;
	if (abs (dx) > abs (dy))
	{
		if (x1 > x2) {hv2 (x1, x2); hv2 (y1, y2);}
		dx = x2-x1, dy = y2-y1;
		if (dy > 0) br1 (x1, y1, x2, y2, mau);
		else br2 (x1, y1, x2, y2, mau);
	}
	else
	{
		if (y1 > y2) {hv2 (y1, y2); hv2 (x1, x2);}
		dx = x2-x1, dy = y2-y1;
		if (dx > 0) br3 (x1, y1, x2, y2, mau);
		else br4 (x1, y1, x2, y2, mau);
	}
	return;
}

// y tang cham, x lap.
void br1 (int x1, int y1, int x2, int y2, char mau)
{
	int dy = y2-y1, dx = x2-x1;
	int p = 2*dy-dx, x = x1, y = y1;
	while (x <= x2)
	{
		putpixel (X+x, Y-y, mau); delay (cho);
		if (p < 0) p += 2*dy;
		else
		{
			p += 2*(dy-dx);
			y++;
		}
		x++;
	}
	return;
}

// y giam cham, x lap.
void br2 (int x1, int y1, int x2, int y2, char mau)
{
	int dy = y2-y1, dx = x2-x1;
	int p = 2*dy+dx, x = x1, y = y1;
	while (x <= x2)
	{
		putpixel (X+x, Y-y, mau); delay (cho);
		if (p >= 0) p += 2*dy;
		else
		{
			p += 2*(dy+dx);
			y--;
		}
		x++;
	}
	return;
}

// x tang cham, y lap.
void br3 (int x1, int y1, int x2, int y2, char mau)
{
	int dy = y2-y1, dx = x2-x1;
	int p = 2*dx-dy, x = x1, y = y1;
	while (y <= y2)
	{
		putpixel (X+x, Y-y, mau); delay (cho);
		if (p < 0) p += 2*dx;
		else
		{
			p += 2*(dx-dy);
			x++;
		}
		y++;
	}
	return;
}

// x giam cham, y lap.
void br4 (int x1, int y1, int x2, int y2, char mau)
{
	int dy = y2-y1, dx = x2-x1;
	int p = 2*dx+dy, x = x1, y = y1;
	while (y <= y2)
	{
		putpixel (X+x, Y-y, mau); delay (cho);
		if (p >= 0) p += 2*dx;
		else
		{
			p += 2*(dx+dy);
			x--;
		}
		y++;
	}
	return;
}

// Hoan vi 2 phan tu.
void hv2 (int &x, int &y) {int ad = x; x = y; y = ad; return;}