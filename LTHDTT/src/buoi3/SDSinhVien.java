package buoi3;

import java.util.Scanner;

public class SDSinhVien {

	public static void main(String[] args) {
		SinhVien a = new SinhVien();
		a.nhap();
		a.themHocPhan("Toan", "A");
		a.in();

		SinhVien ds[];
		Scanner sc = new Scanner(System.in);
		int n;
		System.out.print("Nhap so luong sinh vien: ");
		n = sc.nextInt();
		ds = new SinhVien[n];

		System.out.println("Nhap danh sach sinh vien: ");
		sc.nextLine();

		// Nhap sinh vien
		for (int i = 0; i < n; i++) {
			System.out.println("Nhap sinh vien thu " + (i + 1) + ": ");
			ds[i] = new SinhVien();
			ds[i].nhap();
		}

		System.out.println("Nhap diem cho cac sinh vien:");
		for (int i = 0; i < ds.length; i++) {
			System.out.println("Nhap sinh vien thu " + (i + 1) + ": ");
			ds[i].nhapDiem();
		}

		int i = 0;
		for (SinhVien s : ds) {
			System.out.print("Thong tin sinh vien thu " + (++i) + ": ");
			s.in();
			System.out.println();
		}
	}
}