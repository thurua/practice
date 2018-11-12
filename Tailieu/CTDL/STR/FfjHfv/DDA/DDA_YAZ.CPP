/* Ve duong thang (y=mx+b) bang thuat toan dda (Digital Differential Analyzer).
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

void dda (int x1, int y1, int x2, int y2, char mau); // tong quat.
void d13 (int x1, int y1, int x2, int y2, char mau); // tang giam cham.
void d24 (int x1, int y1, int x2, int y2, char mau); // tang giam nhanh.

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
		dda (x1, y1, x2, y2, m);
		if (m == 15) m--; else m++;
	}
	getch (); closegraph (); return;
} /*__________*/
/*--------------------------------------------------------------------------------*/

// Tong quat.
void dda (int x1, int y1, int x2, int y2, char mau)
{
	// Diem dau trung voi diem cuoi.
	if (x1 == x2 && y1 == y2)
	{
		putpixel (X+x1, Y-y1, mau);
		return; // ket thuc.
	}

	// Tim su bien thien phu hop.
	int dx = x2-x1, dy = y2-y1;
	if (abs (dx) > abs (dy))
	{
		if (x1 > x2) {hv2 (x1, x2); hv2 (y1, y2);}
		d13 (x1, y1, x2, y2, mau); // bien thien cham.
	}
	else
	{
		if (y1 > y2) {hv2 (y1, y2); hv2 (x1, x2);}
		d24 (x1, y1, x2, y2, mau); // bien thien nhanh.
	}
	return;
}

// Tang giam cham.
void d13 (int x1, int y1, int x2, int y2, char mau)
{
	float m = (float) (y2-y1)/(x2-x1);
	int x = x1; float y = y1;
	while (x <= x2)
	{
		putpixel (X+x, Y-ceil (y), mau); delay (cho);
		x++; y += m;
	}
	return;
}

// Tang giam nhanh.
void d24 (int x1, int y1, int x2, int y2, char mau)
{
	float k = (float) (x2-x1)/(y2-y1);
	int y = y1; float x = x1;
	while (y <= y2)
	{
		putpixel (X+ceil (x), Y-y, mau); delay (cho);
		y++; x += k;
	}
	return;
}

// Hoan vi 2 phan tu.
void hv2 (int &x, int &y) {int ad = x; x = y; y = ad; return;}