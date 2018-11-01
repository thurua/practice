package buoi2;

import java.util.Scanner;

public class PhanSo {
	private static Scanner sc;

	private int tu;
	private int mau;

	public PhanSo() {
	}

	public PhanSo(int tu, int mau) {
		this.tu = tu;
		this.mau = mau;
	}

	public void nhap() {
		tu = input(false);
		mau = input(true);
	}

	public void hienThi() {
		if (tu == 0) {
			System.out.print("Phan so: 0");
		} else {
			if (mau == 1) {
				System.out.print("Phan so: " + tu);
			} else {
				System.out.println("Phan so: " + tu + "/" + mau);
			}
		}
	}

	public float giaTri() {
		float kq = (float) tu / mau;
		System.out.println("Phan so: " + kq);
		return kq;
	}

	public void nghichDao() {
		if (tu != 0) {
			int t = tu;
			tu = mau;
			mau = t;
		}
	}

	public PhanSo giaTriNghichDao() {
		PhanSo ps = new PhanSo(tu, mau);
		ps.nghichDao();
		return ps;
	}

	public boolean lonHon(PhanSo ps) {
		boolean kq = giaTri() > ps.giaTri();
		return kq;
	}

	public PhanSo cong(PhanSo ps) {
		int m = ps.mau * mau;
		int t1 = ps.mau * tu;
		int t2 = ps.tu * mau;

		PhanSo kq = new PhanSo(t1 + t2, m);
		return kq;
	}

	public PhanSo cong(int n) {
		int t = mau * n + tu;
		PhanSo kq = new PhanSo(t, mau);
		return kq;
	}

	public PhanSo tru(PhanSo ps) {
		int m = ps.mau * mau;
		int t1 = ps.mau * tu;
		int t2 = ps.tu * mau;

		PhanSo kq = new PhanSo(t1 - t2, m);
		return kq;
	}

	public PhanSo tru(int n) {
		int t = mau * n - tu;
		PhanSo kq = new PhanSo(t, mau);
		return kq;
	}

	public PhanSo nhan(PhanSo ps) {
		int m = ps.mau * mau;
		int t = ps.tu * tu;

		PhanSo kq = new PhanSo(t, m);
		return kq;
	}

	public PhanSo nhan(int n) {
		int t = tu * n;
		int m = mau * n;
		PhanSo kq = new PhanSo(t, m);
		return kq;
	}

	public PhanSo chia(PhanSo ps) {
		PhanSo t = ps.giaTriNghichDao();
		PhanSo kq = nhan(t);
		return kq;
	}

	public PhanSo chia(int n) {
		PhanSo t = new PhanSo(1, n);
		PhanSo kq = nhan(t);
		return kq;
	}

	private int input(boolean laMauSo) {
		sc = new Scanner(System.in);
		String s;
		int kq = 0;
		boolean coLoi = false;

		String noiDung = laMauSo ? "Nhap mau so: " : "Nhap tu so: ";

		do {
			if (coLoi) {
				System.out.print("Nhap lai " + noiDung);
			} else {
				System.out.print(noiDung);
			}

			s = sc.nextLine();
			try {
				kq = Integer.parseInt(s);
				if (kq == 0 && laMauSo) {
					coLoi = true;
				} else {
					coLoi = false;
				}
			} catch (Exception e) {
				coLoi = true;
			}
		} while (coLoi);
		return kq;
	}
}
