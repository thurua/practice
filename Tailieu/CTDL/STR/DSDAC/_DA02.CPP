/* DANH SACH DAC.
Bai 2: chuong trinh quan li sinh vien:
	Them, xoa, sap xep, hien thi, ...

Ngay 15/07/2007, viet: Nguyen Van Toan, tai: KOS GRE.
Ngay 15/07/2007,  sua: Nguyen Van Toan, tai: KOS GRE.
*/

#include <conio.h>
#include <string.h>
#include <stdio.h>

const int TD = 35; // suc chua toi da.

struct svien
{
	int ma; // ma sinh vien.
	char ho[22]; // ho cua sinh vien.
	char ten[8]; // ten cua sinh vien.
	int ns; // nam sinh cua sinh vien.
	float diem; // diem trung binh cua sinh vien.
};

typedef struct dac // danh sach dac.
{
	int sl; // so luong sinh vien.
	svien nut[TD];
} *dsa; // con tro danh sach.

void ktao (dsa ct); // khoi tao danh sach.
char rong (dsa ct); // kiem tra danh sach rong.
char day (dsa ct); // kiem tra danh sach day.
void them (dsa ct, int vi_tri, svien gri); /* them sinh vien
vao danh sach tai vi tri chi dinh.*/
svien lay (dsa ct, int vi_tri); /* lay sinh vien ra tai vi tri
chi dinh.*/
void inn (dsa ct, int n); // in n sinh vien dau danh sach.
void sxtang (dsa ct, char theo); /* sap xep danh sach tang theo
loai chi dinh.*/
void sxgiam (dsa ct, char theo); /* sap xep danh sach giam theo
loai chi dinh.*/
int timsv (dsa ct, char theo); /* tim kiem sinh vien theo gia tri
chi dinh.*/

char vtlayhl (dsa ct, int vt); // vi tri lay hop le.
char vtnaphl (dsa ct, int vt); // vi tri nap hop le.


int main () /*-------------*/
{
	//textmode (3); clrscr (); 
    dsa lop; svien x;
	ktao (lop); // khoi tao danh sach.

	x.ma = 1;
	strcpy (x.ho, "Nguyen Van");
	strcpy (x.ten, "Toan");
	x.ns = 1987;
	x.diem = 7.5;
	them (lop, 1, x);

	x.ma = 2;
	strcpy (x.ho, "Nguyen Van");
	strcpy (x.ten, "Loi");
	x.ns = 1992;
	x.diem = 8.0;
	them (lop, 2, x);

	int i = 1;
	if (vtlayhl (lop, i))
	{
		x = lay (lop, i);
		printf ("MaSV : %d\n", x.ma);
		printf ("HoTen: %s %s\n", x.ho, x.ten);
		printf ("Nsinh: %d\n", x.ns);
		printf ("Diem : %3.1f", x.diem);
	}

	getch (); return 0;
} /*-------------*/


// Khoi tao danh sach.
void ktao (dsa ct)
{
	ct->sl = 0;
	return;
}

// Kiem tra danh sach rong.
char rong (dsa ct)
{
	if (ct->sl == 0) return 1;
	return 0;
}

// Kiem tra danh sach day.
char day (dsa ct)
{
	if (ct->sl == TD) return 1;
	return 0;
}

// Them sinh vien vao danh sach tai vi tri chi dinh.
void them (dsa ct, int vi_tri, svien gri)
{
	// Kiem tra xem vi tri them co hop le khong.
	if (day (ct)) printf ("Danh sach day!\n");
	else if (vi_tri <= 0 || vi_tri > ct->sl + 1)
		printf ("Vi tri khong hop le! Vi tri hop le:[1 - %d]\n", ct->sl + 1);
	else
	{
		for (int i = ct->sl; i >= vi_tri; i--)
			ct->nut[i] = ct->nut[i - 1];
		ct->nut[vi_tri - 1] = gri;
		ct->sl++; // tang so luong sinh vien len.
	}
}

// Lay sinh vien ra tai vi tri chi dinh.
svien lay (dsa ct, int vi_tri)
{
	svien tg;
	tg = ct->nut[vi_tri - 1]; // lay sinh vien ra.
	/*for (int i = vi_tri - 1; i < ct->sl; i++)
		ct->nut[i] = ct->nut[i + 1];
	ct->sl--; // giam so luong sinh vien xuong.*/
	//return tg;
}

// In n sinh vien day danh sach.
void inn (dsa ct, int n)
{
	if (rong (ct)) printf ("Danh sach rong!\n");
	else
	{
		printf ("-¯ %d sinh vien dau danh sach:\n", n);
		for (int i = 0; i < n; i++)
		{
			printf ("MaSV : %d\n", ct->nut[i].ma);
			printf ("HoTen: %s %s\n", ct->nut[i].ho, ct->nut[i].ten);
			printf ("Nsinh: %d\n", ct->nut[i].ns);
			printf ("Diem : %3.1f", ct->nut[i].diem);
			if (i < n - 1) printf ("\n\n");
		}
	}
}

// Sap xep danh sach tang theo loai chi dinh.
void sxtang (dsa ct, char theo)
{
}

// Sap xep danh sach giam theo loai chi dinh.
void sxgiam (dsa ct, char theo)
{
}

// Tim kiem sinh vien theo gia tri chi dinh.
int timsv (dsa ct, char theo)
{
}

// Vi tri lay hop le.
char vtlayhl (dsa ct, int vt)
{
	return vt >= 0 && vt <= ct->sl ? 1 : 0;
}

// Vi tri nap hop le.
char vtnaphl (dsa ct, int vt)
{
	return vt >= 0 && vt <= ct->sl+1 && vt < TD ? 1 : 0;
}
