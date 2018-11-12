/* To da giac loi - thuat toan dong quet (scanline).
Phien ban A1.
Ngay 27/09/2007, viet: Nguyen Van Toan, tai: KOS GRE
Ngay 25/10/2007,  sua: Nguyen Van Toan, tai: KOS GRE
*/

#include <iostream.h>
#include <stdio.h>
#include <math.h>
#include <dos.h>
#include <graphics.h>
#include <stdlib.h>
#include <conio.h>

const int MAX = 99; // so dinh toi da.
int cho = 3; // thoi gian bang mili giay.
int X, Y; // gia tri de tinh tien toa do.

struct dih {int x, y;}; // cau truc cua 1 dinh.
struct dsd {dih d[MAX]; int n;}; // danh sach dinh.

void sln (dih d1, dih d2, dih d3, char mau); // thuat toan to tong quat.
void sl1 (dih d1, dih d2, dih d3, char mau); // truong hop 1.
void sl2 (dih d1, dih d2, dih d3, char mau); // truong hop 2.
void sl3 (dih d1, dih d2, dih d3, char mau); // truong hop 3.
void sl4 (dih d1, dih d2, dih d3, char mau); // truong hop 4.

void sxd (dih &d1, dih &d2, dih &d3); // sap xep cac dinh theo y.
void hvd (dih &d1, dih &d2); // hoan vi 2 dinh.
void tdg (dsd ds, char mau); // to da giac voi danh sach dinh.

void doc (char *tep, dsd &ds); // doc cac dinh cua da giac tu tep.

/*--------------------------------------------------------------------------------*/
void main () /*__________*/
{
	int mh = 0, af = 0, lgz;
	dsd DIH; // danh sach cac dinh.
	doc ("FER.TXT", DIH); // khoi tao.
	
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
	dih s1, s2, s3; // 3 dinh cua tam giac.
	s1.x = 100; s1.y = 50;
	s2.x = 200; s2.y = 50;
	s3.x = 150; s3.y = 100;
	sln (s1, s2, s3, BLUE);
	tdg (DIH, CYAN);
	getch (); closegraph (); return;
} /*__________*/
/*--------------------------------------------------------------------------------*/

// Thuat toan to tong quat.
void sln (dih d1, dih d2, dih d3, char mau)
{
	sxd (d1, d2, d3); // chuan hoa 3 dinh.
	if (d1.y == d2.y && d2.y == d3.y) sl1 (d1, d2, d3, mau);
	else if (d1.y == d2.y) sl3 (d1, d2, d3, mau);
	else if (d3.y == d2.y) sl2 (d1, d2, d3, mau);
	else sl4 (d1, d2, d3, mau);
	return;
}

// Truong hop 1.
void sl1 (dih d1, dih d2, dih d3, char mau)
{
	int xmax = ((d1.x > d2.x) ? d1.x : d2.x) < d3.x ? d3.x : ((d1.x > d2.x) ? d1.x : d2.x);
	int xmin = ((d1.x < d2.x) ? d1.x : d2.x) > d3.x ? d3.x : ((d1.x < d2.x) ? d1.x : d2.x);
	while (xmin <= xmax) {putpixel (X+xmin++, Y-d1.y, mau); delay (cho);}
	return;
}

// Truong hop 2.
void sl2 (dih d1, dih d2, dih d3, char mau)
{
	if (d2.x > d3.x) hvd (d2, d3);
	float kl = (float) (d1.x-d2.x)/(d1.y-d3.y);
	float kr = (float) (d1.x-d3.x)/(d1.y-d3.y);
	float xl = d1.x, xr = d1.x;

	for (int y = d1.y; y <= d3.y; y++)
	{
		for (int x = xl; x <= xr; x++)
		{
			putpixel (X+x, Y-y, mau);
			delay (cho);
		}
		xl += kl; xr += kr;
	}
	return;
}

// Truong hop 3.
void sl3 (dih d1, dih d2, dih d3, char mau)
{
	if (d2.x > d1.x) hvd (d2, d1);
	float kl = (float) (d2.x-d3.x)/(d1.y-d3.y);
	float kr = (float) (d1.x-d3.x)/(d1.y-d3.y);
	float xl = d2.x, xr = d1.x;

	for (int y = d1.y; y <= d3.y; y++)
	{
		for (int x = xl; x <= xr; x++)
		{
			putpixel (X+x, Y-y, mau);
			delay (cho);
		}
		xl += kl; xr += kr;
	}
	return;
}

// Truong hop 4.
void sl4 (dih d1, dih d2, dih d3, char mau)
{
	dih d4; d4.y = d2.y; // hoanh do giao diem moi.
	d4.x = (d3.x-d1.x)*(d2.y-d1.y)/(d3.y-d1.y)+d1.x;

	if (d2.x < d4.x)
	{
		sl2 (d1, d2, d4, mau);
		sl3 (d4, d2, d3, mau);
	}
	else
	{
		sl2 (d1, d4, d2, mau);
		sl3 (d2, d4, d3, mau);
	}
	return;
}

// Sap xep cac dinh theo y.
void sxd (dih &d1, dih &d2, dih &d3)
{
	if (d1.y > d2.y) hvd (d1, d2);
	if (d1.y > d3.y) hvd (d1, d3);
	if (d2.y > d3.y) hvd (d2, d3);
	return;
}

// Hoan vi 2 dinh.
void hvd (dih &d1, dih &d2) {dih d = d1; d1 = d2; d2 = d; return;}

// To da giac voi danh sach dinh.
void tdg (dsd ds, char mau)
{
	for (char i = 0; i < ds.n-3; i++)
	{
		sln (ds.d[0], ds.d[i+1], ds.d[i+2], mau);
		delay (2000);
	}
	return;
}

// Doc cac dinh cua da giac tu tep.
void doc (char *tep, dsd &ds)
{
	FILE *t; // con tro tep.
	if ((t = fopen (tep, "r")) == NULL)
	{
		printf ("Khong doc duoc tep %s", tep);
		getch (); return;
	}
	fscanf (t, "%d\n", &ds.n); // doc so dinh cua da giac.
	for (char i = 0; i < ds.n; i++)
		fscanf (t, "%d %d\n", &ds.d[i].x, &ds.d[i].y);
	return;
}