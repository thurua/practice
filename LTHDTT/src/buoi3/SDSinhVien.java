package buoi3;

import java.util.Scanner;

public class SDSinhVien {

	public static void main(String[] args) {
		/*SinhVien a = new SinhVien();
		a.nhap();		
		a.themHocPhan("Toan", "A");
		a.in();*/

		SinhVien ds[];
		Scanner sc = new Scanner(System.in);
		int n;
		System.out.print("Nhap so luong sinh vien: ");
		n = sc.nextInt();
		ds = new SinhVien[n];
		
		System.out.print("Nhap danh sach sinh vien: ");
		sc.nextLine();
		
		for (int i = 0; i < n; i++) {
			System.out.print("Nhap sinh vien thu " + (i + 1) + ": ");
			ds[i].nhap();

			for (SinhVien s : ds) {
				System.out.print("Thong tin sinh vien thu " + (i + 1) + ": " + ds[i]);
				ds[i].in();
			}
		}
		
		System.out.print("Nhap diem cho cac sinh vien:");
		for (int i = 0; i < ds.length; i++) {
			System.out.print("Nhap sinh vien thu " + (i + 1) + ": ");
			ds[i].nhapDiem();
		}
	}
}