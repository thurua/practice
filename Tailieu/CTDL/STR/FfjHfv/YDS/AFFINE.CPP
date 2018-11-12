/* Cac phep bien_doin doi affine.
Phien ban A1.
Ngay 17/11/2007, viet: Nguyen Van Toan, tai: KOS GRE
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
struct dinh {int x, y;}; // cau truc cua mot dinh.
struct dsd {dinh d[MAX]; int n;}; // danh sach dinh.
dinh T; // gia tri de tinh tien.

class matrix
{
	float x[3][3];
public:
	matrix (); // ma tran cua phep dong nhat (ma tran don vi).
	void nhan (matrix); // nhan ma tran voi ma tran.
	dinh nhan (dinh); // nhan ma tran voi mot dinh.
	void tinhtien (float, float); // ma tran cua phep tinh tien.
	void quay (float); // ma tran cua phep quay.
	void tile (float, float); // ma tran cua phep ti le.
	void dx_OX (); // ma tran cua phep doi xung qua Ox.
	void dx_OY (); // ma tran cua phep doi xung qua Oy.
	void dx_O (); // ma tran cua phep doi xung qua goc toa do.
	void xuat (); // xuat ma tran ra man hinh.
};

void bien_doi (dsd &ds, matrix m); // thuat toan bien doi.
void ve_da_giac (dsd ds); // ve da giac voi danh sach dinh da cho.

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
	T.x = 0, T.y = ymax; // khoi tao gia tri tinh tien.
	dsd ngnha, vuong, chnhat;
	
	// Thiet lap thong tin ngoi nha.
	ngnha.n = 5; // tong so dinh bang 5.
	ngnha.d[0].x = 0, ngnha.d[0].y = 0; // dinh so 1.
	ngnha.d[1].x = 0, ngnha.d[1].y = 20; // dinh so 2.
	ngnha.d[2].x = 25, ngnha.d[2].y = 25; // dinh so 3.
	ngnha.d[3].x = 50, ngnha.d[3].y = 20; // dinh so 4.
	ngnha.d[4].x = 50, ngnha.d[4].y = 0; // dinh so 5.
	
	// Thiet lap thong tin hinh chu nhat.
	chnhat.n = 4; // tong so dinh bang 5.
	chnhat.d[0].x = 30, chnhat.d[0].y = 0; // dinh so 1.
	chnhat.d[1].x = 30, chnhat.d[1].y = 15; // dinh so 2.
	chnhat.d[2].x = 40, chnhat.d[2].y = 15; // dinh so 3.
	chnhat.d[3].x = 40, chnhat.d[3].y = 0; // dinh so 4.
	
	// Thiet lap thong tin hinh vuong.
	vuong.n = 4; // tong so dinh bang 5.
	vuong.d[0].x = 10, vuong.d[0].y = 5; // dinh so 1.
	vuong.d[1].x = 10, vuong.d[1].y = 15; // dinh so 2.
	vuong.d[2].x = 20, vuong.d[2].y = 15; // dinh so 3.
	vuong.d[3].x = 20, vuong.d[3].y = 5; // dinh so 4.

	ve_da_giac (ngnha); ve_da_giac (vuong); ve_da_giac (chnhat); // ve doi tuong luc dau.
	
	// Bat dau bien doi.
	matrix mt;
	mt.tinhtien (350, 170); mt.tile (5, 5); mt.quay (M_PI/6);
	
	bien_doi (ngnha, mt); bien_doi (vuong, mt); bien_doi (chnhat, mt);
	ve_da_giac (ngnha); ve_da_giac (vuong); ve_da_giac (chnhat); // ve doi tuong.
	getch (); closegraph (); return;
} /*__________*/
/*--------------------------------------------------------------------------------*/

// Ma tran cua phep dong nhat (ma tran don vi).
matrix::matrix ()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			x[i][j] = (i == j);
}

// Nhan ma tran voi ma tran.
void matrix::nhan (matrix a)
{
	matrix b; // ma tran hien tai.
	for (int k = 0; k < 3; k++)
		for (int i = 0; i < 3; i++)
			b.x[k][i] = x[k][i];
			
	// Thuc hien phep nhan ma tran.
	for (k = 0; k < 3; k++)
		for (int i = 0; i < 3; i++)
		{
			x[k][i] = 0;
			for (int j = 0; j < 3; j++)
				x[k][i] += a.x[k][j] * b.x[j][i];
		}
	return;
}

// Nhan ma tran voi mot dinh.
dinh matrix::nhan (dinh d)
{
	float tg[2][3];
	tg[0][0] = d.x; tg[0][1] = d.y; tg[0][2] = 1;
	for (int i = 0; i < 3; i++)
	{
		tg[1][i] = 0;
		for (int j = 0; j < 3; j++)
			tg[1][i] += tg[0][j] * x[j][i];
	}
	d.x = tg[1][0]; d.y = tg[1][1];
	return d;
}

// Ma tran cua phep tinh tien.
void matrix::tinhtien (float tx, float ty)
{
	matrix a;
	a.x[2][0] = tx;	a.x[2][1] = ty;
	nhan (a); return;
}

// Ma tran cua phep quay.
void matrix::quay (float goc)
{
	matrix a;
	a.x[0][0] = cos (goc); a.x[0][1] = sin (goc);
	a.x[1][0] = -sin (goc); a.x[1][1] = cos (goc);
	nhan (a); return;
}

// Ma tran cua phep ti le.
void matrix::tile (float sx, float sy)
{
	matrix a;
	a.x[0][0] = sx; a.x[1][1] = sy;
	nhan (a); return;
}

// Ma tran cua phep doi xung qua Ox.
void matrix::dx_OX ()
{
	matrix a;
	a.x[1][1] = -1;
	nhan (a); return;
}

// Ma tran cua phep doi xung qua Oy.
void matrix::dx_OY ()
{
	matrix a;
	a.x[0][0] = -1;
	nhan (a); return;
}

// Ma tran cua phep doi xung qua goc toa do.
void matrix::dx_O () {dx_OX (); dx_OY (); return;}

// Xuat ma tran ra man hinh.
void matrix::xuat ()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j  = 0; j < 3; j++)
			printf ("%8.5f", x[i][j]);
		cout << endl;
	}
	return;
}

// Thuat toan bien doi.
void bien_doi (dsd &ds, matrix m)
{
	for (int i = 0; i < ds.n; i++)
		ds.d[i] = m.nhan(ds.d[i]);
	return;
}

// Ve da giac voi danh sach dinh da cho.
void ve_da_giac (dsd ds)
{
	moveto (T.x+ds.d[ds.n-1].x, T.y-ds.d[ds.n-1].y);
	for (int i = 0; i < ds.n; i++)
		lineto (T.x+ds.d[i].x, T.y-ds.d[i].y);
	return;
}