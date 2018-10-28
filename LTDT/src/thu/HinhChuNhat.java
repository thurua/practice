package thu;

public class HinhChuNhat {
	// Lap trinh huong cau truc (co dien)
	// PascalCase HinhChuNhat, DienTich, ChuVi (dat ten class, ten interface)
	// camelCase hinhChuNhat, dienTich, chuVi (ten phuong thuc (method), truong
	// (field) bien variable, object
	// snake_case chu_vi
	
	public static void main(String[] args) {
		// Tinh dien tich va chu vi dat nha bac 6 (dai = 4,6, rong 2.1)
		HinhChuNhat bac6  = new HinhChuNhat(4.6,2.1);		
		double dtBac6 = bac6.dienTich();
		double cvBac6 = bac6.chuVi();
		System.out.println("dtBac6 = " + dtBac6);
		System.out.println("cvBac6 = " + cvBac6);

		// Tinh dien tich va chu vi dat nha minh (dai = 14,6, rong 7.1)
		HinhChuNhat minh  = new HinhChuNhat(14.6,7.1);
		double dtMinh = minh.dienTich();
		double cvMinh = minh.chuVi();
		System.out.println("dtMinh = " + dtMinh);
		System.out.println("cvMinh = " + cvMinh);

		// Tinh dien tich va chu vi dat nha Dao (dai = 1,6, rong 0.1)
		HinhChuNhat dao  = new HinhChuNhat(1.6,0.1);
		double dtDao = dao.dienTich();
		double cvDao = dao.chuVi();
		System.out.println("dtDao = " + dtDao);
		System.out.println("cvDao = " + cvDao);

	}
	
	
	/**
	 * Field
	 */
	public double dai;
	
	public double rong;
	
	/**
	 * Constructor
	 * @param dai
	 * @param rong
	 */
	public HinhChuNhat(double dai, double rong1) {
		this.dai=dai;
		rong=rong1;
	}
	
	/**
	 * Method
	 * @return
	 */
	public double dienTich() {
		double kq = dai * rong;
		return kq;
	}
	
	/**
	 * Method
	 * @return
	 */
	public double chuVi() {
		double kq = (dai + rong)*2;
		return kq;
	}

}
