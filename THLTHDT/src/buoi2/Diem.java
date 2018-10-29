package buoi2;

import java.util.Scanner;

/**
 * 
 * @author AnhThu
 *
 */
public class Diem {
	private int x;

	private int y;

	public Diem() {
		x = y = 0;
	}

	public Diem(int x1, int y1) {
		x = x1;
		y = y1;
	}

	public Diem(Diem obj) {
		x = obj.x;
		y = obj.y;
	}

	@SuppressWarnings("resource")
	public void nhapDiem() {
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap x: ");
		x = sc.nextInt();
		System.out.print("Nhap y: ");
		y = sc.nextInt();
	}

	public void hienThi() {
		String tg = toString();
		System.out.println(tg);
	}

	public void doiDiem(int dx, int dy) {
		x += dx;
		y += dy;
	}

	public int giaTriX() {
		return x;
	}

	public int giaTriY() {
		return y;
	}

	public float khoangCach() {
		float tg = x * x + y * y;// expressions
		double kq = Math.sqrt(tg);

		return (float) kq;
	}

	public float khoangCach(Diem d) {
		// scope variable
		int x1 = d.giaTriX();
		int y1 = d.giaTriY();

		float tg = (x - x1) * (x - x1) + (y - y1) * (y - y1);
		Double kq = Math.sqrt(tg);

		return kq.floatValue();
	}

	public String toString() {
		return "(" + x + ", " + y + ")";
	}
}