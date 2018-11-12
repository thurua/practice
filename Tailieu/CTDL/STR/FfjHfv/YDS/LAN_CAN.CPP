/* To mau lan can, thuat toan cai tien.
Phien ban A1.
Ngay 05/10/2007, viet: Nguyen Van Toan, tai: KOS GRE
Ngay 11/12/2007,  sua: Nguyen Van Toan, tai: KOS GRE
*/

#include <iostream.h>
#include <stdio.h>
#include <math.h>
#include <dos.h>
#include <graphics.h>
#include <stdlib.h>
#include <conio.h>

const int MAX = 100; // do rong toi da cua stack.
int cho = 0; // thoi gian bang mili giay.
int X, Y; // gia tri de tinh tien toa do.

struct diem {int x, y;};

typedef struct stack
{
	int so;
	diem nut[MAX];
} *stk;

stk kho; // kho chua hat giong.

void cat (stk ct, diem d); // them vao stack.
diem lay (stk ct); // lay ra khoi stack.
char rog (stk ct); // kiem tra stack rong.
char day (stk ct); // kiem tra stack day.

void tlc (int x, int y, char mt, char mb); // to lan can cai tien.
char khg (int x, int y, char mt, char mb); // kiem tra diem hat giong.

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
	kho->so = 0; // khoi tao kho.
	rectangle (0, 35, xmax, ymax);
	
	// Ve cac hinh tron.
	for (char j = 1; j <= 4; j++)
		for (char i = 1; i <= 3; i++)
		{
			circle (i*80, j*85, 39); // hinh ben trai.
			circle (xmax-i*80, j*85, 39); // hinh ben phai.
		}

	moveto (xmax/2, 100); lineto (xmax/2, 150);
	moveto (xmax/2-40, 250); lineto (xmax/2, 200);
	lineto (xmax/2+40, 250); lineto (xmax/2+30, 400);
	lineto (xmax/2+25,370); lineto (xmax/2-25,370);
	lineto (xmax/2-30, 400); lineto (xmax/2-40, 250);
	rectangle (0, 400, xmax, ymax); j = 5;

	for (int i = 1; i <= 3; i++)
	{
		circle (i*80, j*85, 39); // hinh ben trai.
		circle (xmax-i*80, j*85, 39); // hinh ben phai.
	}

	tlc (101, 130, RED, 15);
	tlc (xmax/2, 201, GREEN, 15);
	tlc (xmax/2, 409, BLUE, 15);

	delay (1000); cleardevice ();
	setcolor (12); line (0, 35, xmax, 35);
	settextstyle (10, 0, 6); settextjustify (1, 1);
	outtextxy (xmax/2, ymax/2, "SEO ALK MKF");

	tlc (xmax/2, 36, LIGHTGREEN, 12);
	tlc (xmax/2-155, ymax/2, LIGHTGREEN, 12);
	tlc (xmax/2-65,ymax/2+15, LIGHTGREEN, 12);
	cout << " ->> XIN CHUC MUNG! BAN DA TO HOAN TAT <<::>>";
	getch (); closegraph (); return;
} /*__________*/
/*--------------------------------------------------------------------------------*/

// Them vao stack.
void cat (stk ct, diem d) {ct->nut[++ct->so] = d; return;}

// Lay ra khoi stack.
diem lay (stk ct) {return ct->nut[ct->so--];}

// Kiem tra stack rong.
char rog (stk ct) {return ct->so == 0;}

// Kiem tra stack day.
char day (stk ct) {return ct->so == MAX;}

// To lan can cai tien.
void tlc (int x, int y, char mt, char mb)
{
	int mau = getpixel (x, y);
	if (mau == mb) return; // khong to.
	
	register int i;
	diem d; d.x = x, d.y = y;
	diem hg; // diem hat giong.
	cat (kho, d); // cat hat giong vao kho
	
	while (!rog (kho))
	{
		hg = lay (kho); // lay hat giong ra.
		gotoxy (1, 1); printf ("  So hat giong con trong kho: %.2d", kho->so);
		
		// To diem hat giong va to qua trai.
		for (i = 0; getpixel (hg.x-i, hg.y) != mb && hg.x-i >= 0; i++)
		{
			putpixel (hg.x-i, hg.y, mt); delay (cho);
			
			// Tim diem hat giong o phia tren.
			d.x = hg.x-i; d.y = hg.y+1;
			if (khg (d.x, d.y, mt, mb) == 1) cat (kho, d);

			// Tim diem hat giong o phia duoi.
			d.x = hg.x-i; d.y = hg.y-1;
			if (khg (d.x, d.y, mt, mb) == 1) cat (kho, d);
		}

		// Tim diem hat giong ben trai dau tien.
		--i; // dich sang phai 1 pixel.

		// Diem hat giong phia tren.
		d.x = hg.x-i; d.y = hg.y+1;
		if (khg (d.x, d.y, mt, mb) == 2) cat (kho, d);

		// Diem hat giong phia duoi.
		d.x = hg.x-i; d.y = hg.y-1;
		if (khg (d.x, d.y, mt, mb) == 2) cat (kho, d);

		// To sang phai.
		for (i = 1; getpixel (hg.x+i, hg.y) != mb && hg.x+i <= getmaxx (); i++)
		{
			putpixel (hg.x+i, hg.y, mt); delay (cho);
			
			// Tim diem hat giong o phia tren.
			d.x = hg.x+i; d.y = hg.y+1;
			if (khg (d.x, d.y, mt, mb) == 1) cat (kho, d);
			
			// Tim diem hat giong o phia duoi.
			d.x = hg.x+i; d.y = hg.y-1;
			if (khg (d.x, d.y, mt, mb) == 1) cat (kho, d);
		}
	}
	return;
}

// Kiem tra diem hat giong.
char khg (int x, int y, char mt, char mb)
{
	if (y < 0 || y > getmaxy ()) return 0; // khong to.
	char mau = getpixel (x, y);
	if (mau != mt && mau != mb) // diem hat giong.
	{
		if (getpixel (x-1, y) == mb) return 1; // ben trai la diem bien.
		if (getpixel (x-1, y) != mb) return 2; // diem trai dau tien.
	}
	return 0; // khong la diem hat giong.
}