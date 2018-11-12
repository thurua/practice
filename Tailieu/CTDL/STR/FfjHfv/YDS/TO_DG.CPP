/* To da giac - thuat toan tong quat.
Phien ban A1.
Ngay 06/10/2007, viet: Nguyen Van Toan, tai: KOS GRE
Ngay 11/12/2007,  sua: Nguyen Van Toan, tai: KOS GRE
*/

#include <iostream.h>
#include <stdio.h>
#include <math.h>
#include <dos.h>
#include <graphics.h>
#include <stdlib.h>
#include <conio.h>

const int MAX = 99; // so dinh toi da.
int cho = 0; // thoi gian bang mili giay.
int X, Y; // gia tri de tinh tien toa do.

struct dih {int x, y;}; // cau truc cua 1 dinh.
struct cah {dih d1, d2;}; // cau truc cua 1 canh.
struct dsc {cah c[MAX]; int n;}; // danh sach canh.
struct dsd {dih d[MAX]; int n;}; // danh sach dinh.
struct hdg {int x[MAX], n;}; // danh sach cac hoanh do giao diem.

void nhap (dsd &ds); // nhap cac dinh cua da giac.
char doc (char *tep, dsd &ds); // doc cac dinh cua da giac tu tep.
void maxmin (dsd ds, int &max, int &min); // tim dinh co tung do max va min.
void select (int *dso, char n); // sap xep tang bang thuat toan select sort.
void ttg (dsd ds, char mt); // thuat toan to da giac tong quat.
int yxc (cah c); // tung do lon nhat cua canh.
int ync (cah c); // tung do nho nhat cua canh.

void ve_da_giac (dsd ds); // ve da giac voi danh sach dinh da cho.

/*--------------------------------------------------------------------------------*/
void main () /*__________*/
{
	int mh = 0, af = 0, lgz;
	char n; textmode (3); clrscr ();
	dsd DIH; // danh sach cac dinh.
	if (!doc ("DUL.TXT", DIH)) exit (1); // khoi tao.
	
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
	ve_da_giac (DIH); ttg (DIH, LIGHTBLUE);
	getch (); closegraph (); return;
} /*__________*/
/*--------------------------------------------------------------------------------*/

// Nhap cac dinh cua da giac.
void nhap (dsd &ds)
{
	nhap: printf ("Nhap so dinh (3 <= n <= 10): "); scanf ("%d", &ds.n);
	if (ds.n < 3 || ds.n > 10)
	{
		printf ("Thong so khong phu hop...\n");
		printf ("Xin nhap lai...\n");
		goto nhap;
	}

	for (char i = 0; i < ds.n; i++)
	{
		printf ("Dinh thu %d: ", i+1);
		scanf ("%d %d", &ds.d[i].x, &ds.d[i].y);
	}
	return;
}

// Doc cac dinh cua da giac tu tep.
char doc (char *tep, dsd &ds)
{
	FILE *t; // con tro tep.
	if ((t = fopen (tep, "r")) == NULL)
	{
		printf ("Khong doc duoc tep %s", tep);
		getch (); return 0;
	}
	fscanf (t, "%d\n", &ds.n); // doc so dinh cua da giac.
	for (char i = 0; i < ds.n; i++)
	{
		fscanf (t, "%d %d\n", &ds.d[i].x, &ds.d[i].y);
		ds.d[i].x /= 2, ds.d[i].y /= 2;
		ds.d[i].x += 320, ds.d[i].y += 20;
	}
	return 1;
}

// Tim dinh co tung do max va min.
void maxmin (dsd ds, int &max, int &min)
{
	max = ds.d[0].y; // gia su max la dinh dau tien.
	min = ds.d[0].y; // gia su min la dinh dau tien.
	
	for (char i = 1; i < ds.n; i++)
	{
		if (max < ds.d[i].y) max = ds.d[i].y;
		if (min > ds.d[i].y) min = ds.d[i].y;
	}
}

// Sap xep tang bang thuat toan select sort.
void select (int *dso, char n)
{
	char vtr; // vi tri nho nhat.
	int tg; // bien trung gian.
	
	for (int i = 0; i < n-1; i++)
	{
		vtr = i;
		for (int j = i+1; j < n; j++)
			if (dso[vtr] > dso[j]) vtr = j;

		if (i != vtr)
		{
			tg = dso[i];
			dso[i] = dso[vtr];
			dso[vtr] = tg;
		}
	}
	return;
}

// Thuat toan to da giac tong quat.
void ttg (dsd ds, char mt)
{
	int x1, y1, x2, y2; char i;
	int min, max; // hoanh do cuc dai va cuc tieu.
	maxmin (ds, max, min); // tim max min cua y.
	dsc EL; EL.n = 0; // khoi tao ds cac canh thuong.
	dsc AL; AL.n = 0; // khoi tao ds canh kich hoat.
	hdg hd; hd.n = 0; // khoi tao ds cac hoanh do giao diem.

	// Nap cac canh, khong nap canh co cung tung do.
	for (i = 0; i < ds.n-1; i++) if (ds.d[i].y != ds.d[i+1].y)
	{
		EL.c[EL.n].d1 = ds.d[i];
		EL.c[EL.n].d2 = ds.d[i+1];
		EL.n++; // da nap 1 canh.
	}
	
	// Xu li pixel trong danh sach cac canh.
	for (i = 0; i < EL.n-1; i++) for (char j = i+1; j < EL.n; j++)
		if (EL.c[i].d2.y == EL.c[j].d1.y)
		{
			y1 = EL.c[j].d1.y; // y dinh dau cua canh thu 2.
			if (y1 == yxc (EL.c[i]) && y1 == ync (EL.c[j])) EL.c[j].d1.y++;
			else if (y1 == ync (EL.c[i]) && y1 == yxc (EL.c[j])) EL.c[j].d1.y--;
		}
	
	while (min < max)
	{
		// Nap cac canh kich hoat (la cac canh ma dong quet min di qua).
		for (i = 0; i < EL.n; i++)
		{
			y1 = EL.c[i].d1.y; y2 = EL.c[i].d2.y;
			if ((y1 >= min && min >= y2) || (y1 <= min && min <= y2))
			{
				AL.c[AL.n++] = EL.c[i]; // da nap 1 canh.

				// Huy canh da nap trong danh sach.
				for (char j = i; j < EL.n-1; j++) EL.c[j] = EL.c[j+1];
				EL.n--; // da huy 1 canh.
			}
		}
		
		if (AL.n)
		{
			// Tim hoanh do giao diem.
			for (i = 0; i < AL.n; i++)
			{
				x1 = AL.c[i].d1.x; y1 = AL.c[i].d1.y; // dinh dau.
				x2 = AL.c[i].d2.x; y2 = AL.c[i].d2.y; // dinh cuoi.
				hd.x[hd.n++] = (x2-x1)*(min-y1)/(y2-y1)+x1; // nap giao diem x.
			}
			select (hd.x, hd.n); // sap xep cac hoanh do giao diem.
			
			//*/
			gotoxy (1, 1); printf ("EL.n = %d  DIH.n = %.2d\n", EL.n, ds.n);
			for (i = 0; i < EL.n; i++)
				printf ("CAH %.2d: (%.3d %.3d) -> (%.3d %.3d)\n", i+1, X+EL.c[i].d1.x, Y-EL.c[i].d1.y, X+EL.c[i].d2.x, Y-EL.c[i].d2.y);
			printf ("\nAL.n = %d\n", AL.n);
			for (i = 0; i < AL.n; i++)
				printf ("CAH %.2d: (%.3d %.3d) -> (%.3d %.3d)\n", i+1, X+AL.c[i].d1.x, Y-AL.c[i].d1.y, X+AL.c[i].d2.x, Y-AL.c[i].d2.y);
			printf ("Tung do hien tai Y = %.3d\n", min);
			printf ("Ds nghiem X = {");
			for (i = 0; i < hd.n; i++)
			{
				if (i == hd.n-1) printf ("%d}", hd.x[i]);
				else printf ("%d ", hd.x[i]);
			}
			//*/
			
			// To mau doan thang dua theo hoanh do da tim.
			for (i = 0; i < hd.n/2; i++)
			{
				x1 = hd.x[2*i]; x2 = hd.x[2*i+1];
				for (int k = x1; k <= x2; k++)
				{
					putpixel (X+k, Y-min, mt);
					delay (cho);
				}
			}
			hd.n = 0; // huy cac hoanh do da to roi.
			
			// Huy canh khong con gia tri o danh sach kich hoat.
			for (i = 0; i < AL.n; i++)
			{
				if (min >= yxc (AL.c[i]))
				{
					for (char j = i; j < AL.n-1; j++) AL.c[j] = AL.c[j+1];
					AL.n--; // da huy 1 canh.
				}
			}
			min++; // dong quet se di len.
			
			// Cap nhat lai danh sach canh kich hoat.
			for (i = 0; i < EL.n; i++)
			{
				y1 = EL.c[i].d1.y; y2 = EL.c[i].d2.y;
				if ((y1 >= min && min >= y2) || (y1 <= min && min <= y2))
				{
					AL.c[AL.n++] = EL.c[i]; // da nap 1 canh.
					
					// Huy canh da nap trong danh sach.
					for (char j = i; j < EL.n-1; j++) EL.c[j] = EL.c[j+1];
					EL.n--; // da huy 1 canh.
				}
			}
		}
		gotoxy (1, 1); getch ();
		for (i = 0; i < 17; i++) printf ("\t\t\t\t\n");
	}
	return;
}

// Tung do lon nhat cua canh.
int yxc (cah c) {return (c.d1.y > c.d2.y) ? c.d1.y : c.d2.y;}

// Tung do nho nhat cua canh.
int ync (cah c) {return (c.d1.y < c.d2.y) ? c.d1.y : c.d2.y;}

// Ve da giac voi danh sach dinh da cho.
void ve_da_giac (dsd ds)
{
	moveto (X+ds.d[ds.n-1].x, Y-ds.d[ds.n-1].y);
	for (int i = 0; i < ds.n; i++)
		lineto (X+ds.d[i].x, Y-ds.d[i].y);
	return;
}