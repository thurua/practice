package buoi4;

import java.util.Scanner;

public class SDDiemMau {

	public static void main(String[] args) {
		DiemMau a = new DiemMau(5, 10, "Trang");
		a.hienThi();

		DiemMau b = new DiemMau();
		b.nhapDiem();
		b.doiDiem(10, 8);

		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap mau: ");
		String mau = sc.nextLine();
		b.ganMau(mau);
		sc.close();

		b.hienThi();
	}
}
