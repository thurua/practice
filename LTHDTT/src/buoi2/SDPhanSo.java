package buoi2;

public class SDPhanSo {

	public static void main(String[] args) {
		PhanSo ps1 = new PhanSo();
		ps1.nhap();
		ps1.hienThi();
		ps1.nghichDao();
		System.out.print("ps1 ");
		ps1.hienThi();

		System.out.println("**************************");

		PhanSo ps2 = ps1.giaTriNghichDao();
		System.out.print("ps1 ");
		ps1.hienThi();
		System.out.print("ps2 ");
		ps2.hienThi();
		ps2.giaTri();

		boolean ok = ps1.lonHon(ps2);
		System.out.print("ps1 > ps2 " + ok);

		System.out.println("**************************");

		PhanSo ps3 = ps1.cong(ps2);
		PhanSo ps4 = ps1.tru(ps2);
		PhanSo ps5 = ps1.nhan(ps2);
		PhanSo ps6 = ps1.chia(ps2);
		ps3.hienThi();
		ps4.hienThi();
		ps5.hienThi();
		ps6.hienThi();

		System.out.println("**************************");
		PhanSo ps7 = ps1.cong(7);
		PhanSo ps8 = ps1.tru(7);
		PhanSo ps9 = ps1.nhan(7);
		PhanSo ps10 = ps1.chia(7);

		ps7.hienThi();
		ps8.hienThi();
		ps9.hienThi();
		ps10.hienThi();

	}
}
