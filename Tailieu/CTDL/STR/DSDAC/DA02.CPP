/* DANH SACH DAC.
Bai 1: cac tac vung tren danh sach dac.

Ngay 15/07/2007, viet: Nguyen Van Toan, tai: KOS GRE.
Ngay 15/07/2007,  sua: Nguyen Van Toan, tai: KOS GRE.
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>

const int TD = 35; // so nut toi da.

struct svien
{
	int ma; // ma sinh vien.
	char ho[22]; // ho cua sinh vien.
	char ten[8]; // ten cua sinh vien.
	int ns; // nam sinh cua sinh vien.
	float diem; // diem trung binh cua sinh vien.
};

struct dsd // danh sach dac
{
	int so; // so luong sinh vien.
	svien nut[TD];
};

void kt (dsd *ct); // khoi tao danh sach.
char rong (dsd *ct); // kiem tra danh sach rong.
char day (dsd *ct); // kiem tra danh sach day.
void tdau (dsd *ct, svien x); // them vao dau danh sach.
void tcuo (dsd *ct, svien x); // them vao cuoi danh sach.
void thvt (dsd *ct, int vt, svien x); // them tai vi tri chi dinh (vi tri phai hop le).

svien laydau (dsd *ct); // lay tai vi tri dau (ds khong rong).
svien laycuo (dsd *ct); // lay tai vi tri cuoi (ds khong rong).
svien laytaivt (dsd *ct, int vt); // lay tai vi tri chi dinh (vi tri phai hop le).

char vtlayhl (dsd *ct, int vt); // vi tri lay hop le.
char vtnaphl (dsd *ct, int vt); // vi tri nap hop le.
void thaythe (dsd *ct, int vt, svien x); // thay the tai vt chi dinh (vi tri phai hop le).

void copyds (dsd *ds1, dsd *ds2); // sao chep ds1 sang ds2.
int ktds (dsd *ct); // kich thuoc danh sach.
void duyet (dsd *ct); // duyet danh sach.

void sxt (dsd *ct); // sap xep tang.
void sxg (dsd *ct); // sap xep giam.

int main () /*- - - - - - - - - -*/
{
	//textmode (3); clrscr (); 
    svien x;
	dsd lop; kt (&lop); // khoi tao danh sach lop.
	
	// Sinh vien 1.
	x.ma = 1;
	strcpy (x.ho, "Nguyen Van");
	strcpy (x.ten, "Toan");
	x.ns = 1987;
	x.diem = 11;
	tdau (&lop, x);
	
	// Sinh vien 2.
	x.ma = 2;
	strcpy (x.ho, "Nguyen Thi Diem");
	strcpy (x.ten, "Trinh");
	x.ns = 1987;
	x.diem = 7.5;
	thvt (&lop, 1, x);
	
	// Sinh vien 3.
	x.ma = 3;
	strcpy (x.ho, "Nguyen Van");
	strcpy (x.ten, "Huong");
	x.ns = 1982;
	x.diem = 8.0;
	thvt (&lop, 2, x);
	
	// Sinh vien 4.
	x.ma = 4;
	strcpy (x.ho, "Le Van");
	strcpy (x.ten, "Anh");
	x.ns = 1985;
	x.diem = 6.0;
	tcuo (&lop, x);
	
	// Sinh vien 5.
	x.ma = 5;
	strcpy (x.ho, "Nguyen Hoang");
	strcpy (x.ten, "Sang");
	x.ns = 1986;
	x.diem = 5.0;
	tcuo (&lop, x);

	sxg (&lop); int tssv = ktds (&lop);
	for (int i = 0; i < tssv; i++)
	{
		if (!rong (&lop))
		{
			x = laydau (&lop);
			printf ("MaSV : %d\n", x.ma);
			printf ("HoTen: %s %s\n", x.ho, x.ten);
			printf ("Nsinh: %d\n", x.ns);
			printf ("Diem : %3.1f", x.diem);
			if (i != tssv-1) printf ("\n\n");
		}
	}
	getch (); return 0;
} /*- - - - - - - - - -*/

// Khoi tao danh sach.
void kt (dsd *ct)
{
	ct->so = 0;
}


// Kiem tra danh sach rong.
char rong (dsd *ct)
{
	return ct->so == 0 ? 1 : 0;
}

// Kiem tra danh sach day.
char day (dsd *ct)
{
	return ct->so == TD ? 1 : 0;
}

// Them vao dau danh sach.
void tdau (dsd *ct, svien x)
{
	if (rong (ct))
	{
		ct->nut[0] = x;
		ct->so++;
	}
	else
	{
		if (!day (ct))
		{
			for (int i = ct->so; i > 0; i--)
				ct->nut[i] = ct->nut[i-1]; // chuyen nut len tren.
			ct->nut[0] = x;
			ct->so++;
		}
	}
}

// Them vao cuoi danh sach.
void tcuo (dsd *ct, svien x)
{
	if (rong (ct))
	{
		ct->nut[0] = x;
		ct->so++;
	}
	else
	{
		if (!day (ct))
		{
			ct->nut[ct->so] = x;
			ct->so++;
		}
	}
}

// Them tai vi tri chi dinh (vi tri phai hop le).
void thvt (dsd *ct, int vt, svien x)
{
	if (!day (ct))
	{
		for (int i = ct->so; i > vt; i--)
			ct->nut[i] = ct->nut[i-1]; // chuyen nut len tren.
		ct->nut[vt] = x;
		ct->so++;
	}
}

// Lay tai vi tri dau (ds khong rong).
svien laydau (dsd *ct)
{
	
	svien x = ct->nut[0];
	for (int i = 0; i < ct->so-1; i++)
		ct->nut[i] = ct->nut[i+1]; // chuyen nut len xuong.
	ct->so--;
	return x;
}

// Lay tai vi tri cuoi (ds khong rong).
svien laycuo (dsd *ct)
{
	ct->so--;
	return ct->nut[ct->so];
}

// Lay tai vi tri chi dinh (vi tri phai hop le).
svien laytaivt (dsd *ct, int vt)
{
	svien x = ct->nut[vt];
	for (int i = vt; i < ct->so-1; i++)
		ct->nut[i] = ct->nut[i+1]; // chuyen nut len xuong.
	ct->so--;
	return x;
}

// Vi tri lay hop le.
char vtlayhl (dsd *ct, int vt)
{
	return vt >= 0 && vt < ct->so ? 1 : 0;
}

// Vi tri nap hop le.
char vtnaphl (dsd *ct, int vt)
{
	return vt >= 0 && vt <= ct->so && vt < TD ? 1 : 0;
}

// Thay the tai vt chi dinh (vi tri phai hop le).
void thaythe (dsd *ct, int vt, svien x)
{
	ct->nut[vt] = x;
}

// Sao chep ds1 sang ds2.
void copyds (dsd *ds1, dsd *ds2)
{
	ds2->so = ds1->so;
	if (!rong (ds1))
	{
		for (int i = 0; i < ds1->so; i++)
			ds2->nut[i] = ds1->nut[i];
	}
}

// Kich thuoc danh sach.
int ktds (dsd *ct)
{
	return ct->so;
}

// Duyet danh sach.
void duyet (dsd *ct)
{
	if (!rong (ct))
	{
		for (int i = 0; i < ct->so; i++)
			printf ("%d ", ct->nut[i]);
	}
}

// Sap xep tang.
void sxt (dsd *ct)
{
	char vtr; // vi tri nho nhat.
	svien tg; // bien trung gian.
	
	for (int i = 0; i < ct->so-1; i++)
	{
		vtr = i;
		for (int j = i+1; j < ct->so; j++)
			if (ct->nut[vtr].ma > ct->nut[j].ma) vtr = j;

		if (i != vtr)
		{
			tg = ct->nut[i];
			ct->nut[i] = ct->nut[vtr];
			ct->nut[vtr] = tg;
		}
	}
}

// Sap xep giam.
void sxg (dsd *ct)
{
	char vtr; // vi tri lon nhat.
	svien tg; // bien trung gian.
	
	for (int i = 0; i < ct->so-1; i++)
	{
		vtr = i;
		for (int j = i+1; j < ct->so; j++)
			if (ct->nut[vtr].ma < ct->nut[j].ma) vtr = j;

		if (i != vtr)
		{
			tg = ct->nut[i];
			ct->nut[i] = ct->nut[vtr];
			ct->nut[vtr] = tg;
		}
	}
}
