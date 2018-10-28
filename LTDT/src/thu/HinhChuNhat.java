package thu;

public class HinhChuNhat {
	// Lap trinh huong cau truc (co dien)
	// PascalCase HinhChuNhat, DienTich, ChuVi (dat ten class, ten interface)
	// camelCase hinhChuNhat, dienTich, chuVi (ten phuong thuc (method), truong
	// (field) bien variable, object
	// snake_case chu_vi

	public static void main(String[] args) {
		// Tinh dien tich va chu vi dat nha bac 6 (dai = 4,6, rong 2.1)
		HinhChuNhat bac6 = new HinhChuNhat(-4.6, -2.1, "Bac 6");
		bac6.dienTich();
		bac6.chuVi();

		// Tinh dien tich va chu vi dat nha minh (dai = 14,6, rong 7.1)
		HinhChuNhat minh = new HinhChuNhat(14.6, 7.1, "Nha Thu");
		minh.dienTich();
		minh.chuVi();

		// Tinh dien tich va chu vi dat nha Dao (dai = 1,6, rong 0.1)
		HinhChuNhat dao = new HinhChuNhat(1.6, 0.1, "Nha Dao");
		dao.dienTich();
		dao.chuVi();
	}

	/**
	 * Field
	 */
	private double dai;

	private double rong;

	private String ten;

	/**
	 * xxxx
	 * 
	 * @param dai   1
	 * @param rong1 2
	 * @param ten   3
	 */
	public HinhChuNhat(double dai, double rong1, String ten) {
		if (dai <= 0) {
			System.out.println("Chieu dai phai > 0");
			dai = 1;
		}
		if (rong1 <= 0) {
			System.out.println("Chieu dai rong > 0");
			dai = 1;
		}

		this.dai = dai;
		rong = rong1;
		this.ten = ten;
	}

	/**
	 * Method
	 * 
	 * @return
	 */
	public void dienTich() {
		double kq = dai * rong;
		System.out.println(ten + " dienTich = " + kq);
	}

	/**
	 * Method
	 * 
	 * @return
	 */
	public void chuVi() {
		double kq = (dai + rong) * 2;
		System.out.println(ten + " chuVi = " + kq);
	}
}