/* PHAN HANG DOI.
Bai 1: chuong trinh kiem tra chuoi co tinh doi xung.

Ngay 05/07/2007, viet: Nguyen Van Toan, tai: KOS GRE.
Ngay 15/07/2007,  sua: Nguyen Van Toan, tai: KOS GRE.
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>

const int TD = 35; // do rong toi da cua hang doi.

typedef struct queue
{
	int dau, cuoi;
	char nut[TD];
} *que;

void khoitao (que ct); // khoi tao hang doi.
void insert (que ct, char x); // them vao hang doi.
char remove (que ct); // lay ra khoi hang doi.

void main () /*----------*/
{
	char *chu; // bien chua chuoi can kiem tra.
	int dai; // do  dai cua chuoi.
	char dung = 1; // bao dung.
	queue qu; textmode (3); clrscr ();
	do
	{
		khoitao (&qu);
		printf ("\t\t\t\t<CHUONG TRINH>\n");
		printf ("\tKIEM TRA CHUOI DOI XUNG DUNG HANG DOI, NHAP CHUOI RONG DE KET THUC\n");
		printf ("Nhap chuoi: "); gets (chu); dai = strlen (chu);
		
		// Nap vao tung ki tu vao hang doi (chi co nua chuoi).
		for (int i = 0; i < dai/2; i++) insert (&qu, chu[i]);

		// Lay tat ca cac ki tu trong hang doi ra de kiem tra.
		for (i = 0; i < dai/2; i++)
		{
			if (chu[dai-i-1] == remove (&qu)) dung = 1;
			else
			{
				dung = 0;
				break;
			}
		}

		if (dung) printf ("Chuoi nay doi xung!\n\n");
		else printf ("Chuoi khong doi xung!\n\n");
	} while (dai);
	return;
} /*----------*/

// Khoi tao hang doi.
void khoitao (que ct)
{
	ct->dau = ct->cuoi = TD-1;
}

// Them vao hang doi.
void insert (que ct, char x)
{
	if (ct->cuoi == TD) ct->cuoi = 0; else ct->cuoi++;
    ct->nut[ct->cuoi] = x;
}

// Lay ra khoi hang doi.
char remove (que ct)
{
	if (ct->dau == TD) ct->dau = 0; else ct->dau++;
	return ct->nut[ct->dau];
}