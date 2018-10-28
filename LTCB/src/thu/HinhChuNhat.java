package thu;

public class HinhChuNhat {
	// Lap trinh huong cau truc (co dien)
	// PascalCase HinhChuNhat, DienTich, ChuVi (dat ten class, ten interface)
	// camelCase hinhChuNhat, dienTich, chuVi (ten phuong thuc (method), truong
	// (field) bien variable, object
	// snake_case chu_vi

	public static void main(String[] args) {
		// Tinh dien tich va chu vi dat nha bac 6 (dai = 4,6, rong 2.1)
		double dtBac6 = dienTich(4.6, 2.1);
		double cvBac6 = chuVi(4.6, 2.1);
		System.out.println("dtBac6 = " + dtBac6);
		System.out.println("cvBac6 = " + cvBac6);

		// Tinh dien tich va chu vi dat nha minh (dai = 14,6, rong 7.1)
		double dtMinh = dienTich(14.6, 7.1);
		double cvMinh = chuVi(14.6, 7.1);
		System.out.println("dtMinh = " + dtMinh);
		System.out.println("cvMinh = " + cvMinh);

		// Tinh dien tich va chu vi dat nha Dao (dai = 1,6, rong 0.1)
		double dtDao = dienTich(1.6, 0.1);
		double cvDao = chuVi(1.6, 0.1);
		System.out.println("dtDao = " + dtDao);
		System.out.println("cvDao = " + cvDao);

	}

	public static double dienTich(double dai, double rong) {
		double kq = dai * rong;
		return kq;
	}

	public static double chuVi(double dai, double rong) {
		double kq = (dai + rong) * 2;
		return kq;
	}

}
