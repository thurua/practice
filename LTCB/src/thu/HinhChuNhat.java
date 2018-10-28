package thu;

public class HinhChuNhat {
	// Lap trinh huong cau truc (co dien)
	// PascalCase HinhChuNhat, DienTich, ChuVi (dat ten class, ten interface)
	// camelCase hinhChuNhat, dienTich, chuVi (ten phuong thuc (method), truong
	// (field) bien variable, object
	// snake_case chu_vi

	public static void main(String[] args) {
		// Tinh dien tich va chu vi dat nha bac 6 (dai = 4,6, rong 2.1)
		dienTich(4.6, 2.1, "Bac 6");
		chuVi(4.6, 2.1, "Bac 6");

		// Tinh dien tich va chu vi dat nha minh (dai = 14,6, rong 7.1)
		dienTich(14.6, 7.1, "Nha Thu");
		chuVi(14.6, 7.1, "Nha Thu");

		// Tinh dien tich va chu vi dat nha Dao (dai = 1,6, rong 0.1)
		dienTich(1.6, 0.1, "Nha Dao");
		chuVi(1.6, 0.1, "Nha Dao");

	}

	public static double dienTich(double dai, double rong, String ten) {
		double kq = dai * rong;
		System.out.println(ten + " dienTich = " + kq);
		return kq;
	}

	public static double chuVi(double dai, double rong, String ten) {
		double kq = (dai + rong) * 2;
		System.out.println(ten + " chuVi = " + kq);
		return kq;
	}
}