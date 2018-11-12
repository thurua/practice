/* DANH SACH DAC.
Bai 1: cac tac vung tren danh sach dac.

Ngay 15/07/2007, viet: Nguyen Van Toan, tai: KOS GRE.
Ngay 15/07/2007,  sua: Nguyen Van Toan, tai: KOS GRE.
*/

#include <stdio.h>
#include <conio.h>

const int TD = 35; // so nut toi da.

struct dsd // danh sach dac
{
	int so;
	int nut[TD];
};

void kt (dsd *ct); // khoi tao danh sach.
char rong (dsd *ct); // kiem tra danh sach rong.
char day (dsd *ct); // kiem tra danh sach day.
void tdau (dsd *ct, int x); // them vao dau danh sach.
void tcuo (dsd *ct, int x); // them vao cuoi danh sach.
void thvt (dsd *ct, int vt, int x); // them tai vi tri chi dinh (vi tri phai hop le).

int laydau (dsd *ct); // lay tai vi tri dau (ds khong rong).
int laycuo (dsd *ct); // lay tai vi tri cuoi (ds khong rong).
int laytaivt (dsd *ct, int vt); // lay tai vi tri chi dinh (vi tri phai hop le).

char vtlayhl (dsd *ct, int vt); // vi tri lay hop le.
char vtnaphl (dsd *ct, int vt); // vi tri nap hop le.
void thaythe (dsd *ct, int vt, int x); // thay the tai vt chi dinh (vi tri phai hop le).

void copyds (dsd *ds1, dsd *ds2); // sao chep ds1 sang ds2.
int ktds (dsd *ct); // kich thuoc danh sach.
void duyet (dsd *ct); // duyet danh sach.

void sxt (dsd *ct); // sap xep tang.
void sxg (dsd *ct); // sap xep giam.

int main () /*- - - - - - - - - -*/
{
	//textmode (3); clrscr ();
	dsd ds1; kt (&ds1); // khoi tao danh sach.
	dsd ds2; kt (&ds2); // khoi tao danh sach.
	for (int i = 0; i < 13; i++) tcuo (&ds1, i+1);
	copyds (&ds1, &ds2);
	thvt (&ds1, 5, 135);
	sxt (&ds1); sxg (&ds2);
	printf ("Ds1: "); duyet (&ds1);
	printf ("\nDs2: "); duyet (&ds2);
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
void tdau (dsd *ct, int x)
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
void tcuo (dsd *ct, int x)
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
void thvt (dsd *ct, int vt, int x)
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
int laydau (dsd *ct)
{
	
	int x = ct->nut[0];
	for (int i = 0; i < ct->so-1; i++)
		ct->nut[i] = ct->nut[i+1]; // chuyen nut len xuong.
	ct->so--;
	return x;
}

// Lay tai vi tri cuoi (ds khong rong).
int laycuo (dsd *ct)
{
	ct->so--;
	return ct->nut[ct->so];
}

// Lay tai vi tri chi dinh (vi tri phai hop le).
int laytaivt (dsd *ct, int vt)
{
	int x = ct->nut[vt];
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
void thaythe (dsd *ct, int vt, int x)
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
	int tg; // bien trung gian.
	
	for (int i = 0; i < ct->so-1; i++)
	{
		vtr = i;
		for (int j = i+1; j < ct->so; j++)
			if (ct->nut[vtr] > ct->nut[j]) vtr = j;

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
	int tg; // bien trung gian.
	
	for (int i = 0; i < ct->so-1; i++)
	{
		vtr = i;
		for (int j = i+1; j < ct->so; j++)
			if (ct->nut[vtr] < ct->nut[j]) vtr = j;

		if (i != vtr)
		{
			tg = ct->nut[i];
			ct->nut[i] = ct->nut[vtr];
			ct->nut[vtr] = tg;
		}
	}
}
