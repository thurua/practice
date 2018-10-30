package buoi2;

public class SDDiem {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Diem a = new Diem(3, 4);
		System.out.print("toa do diem A: ");
		a.hienThi();

		Diem b = new Diem();
		b.nhapDiem();
		System.out.print("toa do diem B: ");
		b.hienThi();
		int x = 0 - b.giaTriX();
		int y = 0 - b.giaTriY();
		Diem c = new Diem(x, y);
		System.out.print("toa do diem C: ");
		c.hienThi();
		
		float kc1 = b.khoangCach();
		System.out.println("Khoang cach tu B den O: " + kc1);
		float kc2 = b.khoangCach();
		System.out.println("Khoang cach tu A den B:" + kc2);

	}

}
