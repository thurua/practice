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
		System.out.println("nhap x:");
		x = sc.nextInt();
		System.out.println("nhap y:");
		y = sc.nextInt();

	}
	public void hienThi() {
		System.out.println("("+ x +"," + y +")");
	}
	public void doiDiem(int dx, int dy) {
		x+=dx;
		y+=dy;
	}
	public int giaTriX
}
