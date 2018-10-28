package buoi2;

public class SDDiem {

	public static void main(String[] args) {
		Diem a = new Diem(3, 4);
		a.hienThi();

		Diem b = new Diem();
		b.nhapDiem();
		b.hienThi();

		int x = 0 - b.giaTriX();
		int y = 0 - b.giaTriY();
		Diem c = new Diem(x, y);
		c.hienThi();

		float kc1 = b.khoangCach();
		System.out.println("Khoảng cách từ điểm B đến tâm O: " + kc1);

		float kc2 = b.khoangCach(a);
		System.out.println("Khoảng cách từ điểm A đến điểm B: " + kc2);
	}
}