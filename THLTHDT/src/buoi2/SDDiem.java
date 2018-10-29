package buoi2;

/**
 * 
 * @author AnhThu
 *
 */
public class SDDiem {

	public static void main(String[] args) {
		Diem a = new Diem(3, 4);
		System.out.print("A");
		a.hienThi();

		Diem b = new Diem();
		b.nhapDiem();
		System.out.print("B");
		b.hienThi();

		int x = 0 - b.giaTriX();
		int y = 0 - b.giaTriY();
		Diem c = new Diem(x, y);
		System.out.print("C");
		c.hienThi();

		float kc1 = b.khoangCach();
		System.out.println("Khoang cach tu diem B den tam O: " + kc1);

		float kc2 = b.khoangCach(a);
		System.out.println("Khoang cach tu diem A den tam B: " + kc2);
	}
}