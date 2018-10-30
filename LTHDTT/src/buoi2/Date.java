package buoi2;

import java.util.Scanner;

public class Date {
	private int ngay;
	private int thang;
	private int nam;

	int mangThang[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	int mangNgay[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	public Date() {
		ngay = thang = nam = 0;
	}

	public Date(int ng, int t, int n) {
		ngay = ng;
		thang = t;
		nam = n;
	}

	public void in() {
		System.out.print(ngay + "/" + thang + "/" + nam);

	}

	public void nhap() {
		Scanner sc = new Scanner(System.in);
		do {
			System.out.print("nhap ngay:");
			ngay = sc.nextInt();
			System.out.print("nhap thang");
			thang = sc.nextInt();
			System.out.print("nhap nam");
			nam = sc.nextInt();
		} while (!hopLe());
	}

	public boolean hopLe() {
		boolean kq = false;

		if (nam % 4 == 0) {
			mangNgay[2] = 29;
		}
		if (nam > 0 && thang > 0 && thang < 13 && ngay <= mangNgay[thang] && ngay > 0) {
			kq = true;
		}
		return kq;
	}

	public Date ngHomSau() {
//31/01/2018 -> 01/02/2018
		int maxNgay = mangNgay[thang];

		// Sao chep thong tin
		int newNgay = ngay + 1; // ngay hom sau
		int newThang = thang;
		int newNam = nam;

		if (newNgay > maxNgay) {
			// Tang them 1 thang
			// thang = thang + 1;
			// or viet ngan gon
			newThang++;

			// Chon ngay dau tien cua thang
			newNgay = 1;
		}
		if (newThang > 12) {
			// Tang them 1 nam
			newNam++;

			// Chon thang dau tien cua nam
			newThang = 1;
		}

		Date kq = new Date(newNgay, newThang, newNam);
		return kq;
	}
}