/* Xen doan thang - thuat toan Conhen-Sutherland.
Phien ban A1.
Ngay 08/10/2007, viet: Nguyen Van Toan, tai: KOS GRE
Ngay 25/10/2007,  sua: Nguyen Van Toan, tai: KOS GRE
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
int wL, wR, wT, wB; // toa do khung nhin.

struct die {int x, y;}; // cau truc 1 diem.

char mav (die d); // tinh ma vung cua mot diem.
void csu (die d1, die d2, char mau); // xen doan thang.
void hvd (die &d1, die &d2); // hoan vi hai diem.
void huy (die d1, die d2, char mau); // huy doan thang.
die nghie (die d1, die d2); // tim nghiem cua duong thang voi cua so.

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
	die d1, d2;
	d1.x = 0, d1.y = 0;
	d2.x = xmax, d2.y = ymax;
	
	// Khoi tao khung nhin.
	wL = xmax/3; wR = xmax-xmax/3;
	wT = ymax/3; wB = ymax-ymax/3;
	
	setcolor (WHITE); rectangle (wL, wT, wR, wB);
	setcolor (LIGHTGREEN); line (d1.x, d1.y, d2.x, d2.y);
	getch (); csu (d1, d2, YELLOW);
	getch (); closegraph (); return;
} /*__________*/
/*--------------------------------------------------------------------------------*/

// Tinh ma vung cua mot diem.
char mav (die d)
{
	if (wL <=d.x && d.x <= wR && wT <= d.y && d.y <= wB) return 0; // diem nam vung trong.
	else if (d.x < wL) return 1; // nam ben trai.
	else if (d.x > wR) return 2; // nam ben phai.
	else if (d.y < wT) return 3; // nam ben tren.
	else if (d.y > wB) return 4; // nam ben duoi.
	else return 5; // khong xac dinh.
}

// Xen doan thang.
void csu (die d1, die d2, char mau)
{
	while (mav (d1) || mav (d2)) // khi 2 diem khong nam trong.
	{
		// Ca 2 nam ngoai, cung mot vung.
		if (mav (d1) == mav (d2))
		{
			huy (d1, d2, mau);
			break;
		}
		
		// Co 1 dinh nam o ben trong.
		else if (!mav (d1) || !mav (d2))
		{
			if (!mav (d1)) hvd (d1, d2); // dua d2 vao trong.
			die d; // gia tri nghiem.
			d = nghie (d1, d2); // tim nghiem.
			huy (d1, d, mau); // xen hinh di.
			circle (d.x, d.y, 3);
			d1 = d; // cap nhat lai d1.			
		}
		else // ca 2 deu nam ngoai, khac vung.
		{
			die d; // gia tri nghiem.
			d = nghie (d1, d2); // tim nghiem.
			huy (d1, d, mau); // xen hinh di.
			circle (d.x, d.y, 3);
			d1 = d; // cap nhat lai d1.			
		}
	}
	return;
}

// Hoan vi hai diem.
void hvd (die &d1, die &d2) {die d = d1; d1 = d2; d2 = d; return;}

// Huy doan thang.
void huy (die d1, die d2, char mau)
{
	char m = getcolor ();
	setcolor (mau);
	line (d1.x, d1.y, d2.x, d2.y);
	setcolor (m); // phuc hoi lai mau cu.
	return;
}

// Tim nghiem cua duong thang voi cua so.
die nghie (die d1, die d2)
{
	die d; // gia tri nghiem.
	if (mav (d1) == 1)
	{
		d.x = wL;
		d.y = (d.x-d1.x)*((float) d2.y-d1.y)/(d2.x-d1.x)+d1.y;
	}
	else if (mav (d1) == 2)
	{
		d.x = wR;
		d.y = (d.x-d1.x)*((float) d2.y-d1.y)/(d2.x-d1.x)+d1.y;
	}
	else if (mav (d1) == 3)
	{
		d.y = wT;
		d.x = (d.y-d1.y)*((float) d2.x-d1.x)/(d2.y-d1.y)+d1.x;
	}
	else if (mav (d1) == 4)
	{
		d.y = wB;
		d.x = (d.y-d1.y)*((float) d2.x-d1.x)/(d2.y-d1.y)+d1.x;
	}
	return d;
}