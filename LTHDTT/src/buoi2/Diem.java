package buoi2;

import java.util.Scanner;

public class Diem {
	private int x;
	private int y;

	public Diem() {
		x = y = 0;
	}

	public Diem(int x, int y) {
		this.x = x;
		this.y = y;
	}

	public void nhapDiem() {
		Scanner sc = new Scanner(System.in);
		System.out.print("nhap x:");
		x = sc.nextInt();
		System.out.print("nhap y:");
		y = sc.nextInt();

	}

	public void hienThi() {
		System.out.println("(" + x + "," + y + ")");
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
		float t = x * x + y * y;
		double kq = Math.sqrt(t);
		return (float) kq;

	}

	public float khoangCach(Diem d) {
		int x1 = d.giaTriX();
		int y1 = d.giaTriY();
		float t = (x - x1) * (x - x1) + (y - y1) * (y - y1);
		double kq1 = Math.sqrt(t);
		return (float) kq1;

	}
}