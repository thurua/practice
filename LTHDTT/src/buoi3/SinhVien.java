package buoi3;

import java.util.Scanner;

import buoi2.Date;

public class SinhVien {
	private String mssv;
	private String hoTen;
	private Date ngaySinh;
	private int slHocPhan;
	private String hocPhan[];
	private String diem[];
	private int max = 55;

	public SinhVien() {
		mssv = new String();
		hoTen = new String();
		ngaySinh = new Date();
		slHocPhan = 0;
		hocPhan = new String[max];
		diem = new String[max];
	}

	public SinhVien(String mssv, String hoTen, Date ngaySinh, int max) {
		this.mssv = new String(mssv);
		this.hoTen = new String(hoTen);
		this.ngaySinh = new Date(ngaySinh);
		this.max = max;
	}

	public SinhVien(SinhVien obj) {
		this.mssv = new String(obj.mssv);
		this.hoTen = new String(obj.hoTen);
		this.ngaySinh = new Date(obj.ngaySinh);
		this.slHocPhan = obj.slHocPhan;
		this.hocPhan = new String[obj.max];
		this.diem = new String[obj.max];
	}

	public void nhap() {
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap ma so sinh vien: ");
		mssv = sc.nextLine();
		System.out.print("Nhap ho ten: ");
		hoTen = sc.nextLine();
		System.out.print("Nhap ngay sinh: ");
		ngaySinh.nhap();
	}

	public void nhapDiem() {
		Scanner sc = new Scanner(System.in);
		System.out.print("So mon can nhap: ");
		slHocPhan = sc.nextInt();
		sc.nextLine();

		for (int i = 0; i < slHocPhan; i++) {
			hocPhan[i] = new String();
			diem[i] = new String();			
			
			System.out.print("Nhap ten mon thu " + (i + 1) + ": ");
			hocPhan[i] = sc.nextLine();
			
			System.out.print("Nhap diem mon hoc: ");
			diem[i] = sc.nextLine();
		}
	}

	public void in() {
		System.out.print(toString());
	}

	public String toString() {
		String s = " ";
		s = "MSSV: " + mssv + " Ho ten: " + hoTen + " Ngay sinh: " + ngaySinh.toString() + " -- ";

		for (int i = 0; i < slHocPhan; i++) {
			s = s + hocPhan[i] + ": " +diem[i] +"  ";			
		}

		return s;
	}

	public void themHocPhan(String mon, String d) {
		if (slHocPhan <= max) {// em khong hieu
			for (int i = 0; i < slHocPhan; i++) {
				hocPhan[i] = new String(mon);
				diem[i] = new String(d);
			}
		} else {
			System.out.print("Loi! Khong the dang ki them hoc phan");
		}
	}

	public void xoaHocPhan(String mon) {
		for (int i = 0; i < slHocPhan; i++) {
			if (mon.compareTo(hocPhan[i]) == 0) {// 2 cai nay deu kieu String ma sao no bao loi la k ss duoc
				break;
			}

			if (i < slHocPhan) {
				for (int j = i; j < slHocPhan - 1; j++) {
					hocPhan[i] = hocPhan[j - 1];
					diem[i] = diem[j - 1];
				}
				slHocPhan--;
			}
		}
	}

	public float tinhDiemTB() {
		float dtb = 0.0f;

		for (int i = 0; i < slHocPhan; i++) {
			if (diem[i].compareTo("A") == 0) {
				dtb = dtb + 4;
			} else if (diem[i].compareTo("B") == 0) {
				dtb = dtb + 3;
			} else if (diem[i].compareTo("B+") == 0) {
				dtb = dtb + 3.5f;
			} else if (diem[i].compareTo("C") == 0) {
				dtb = dtb + 2.5f;
			} else if (diem[i].compareTo("D") == 0) {
				dtb = dtb + 2;
			}
		}

		return dtb;
	}
}
