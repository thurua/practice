package buoi2;

import java.util.Scanner;

public class Diem {
	private int x, y;

	public Diem() {
	}

	public Diem(int x1, int y1) {
		x = x1;
		y = y1;
	}

	public Diem(Diem obj) {
		x = obj.x;
		y = obj.y;
	}

	public void nhap() {
		Scanner sc = new Scanner(System.in);
		System.out.print("nhap x");
		x = sc.nextInt();
		System.out.print("nhap y");
		y = sc.nextInt();
	}

	public void in() {
		System.out.print("(" + x + "," + y + ")");
	}

	public String toString() {
		return ("(" + x + "," + y + ")");
	}

	public static void main(String[] args) {
		Diem a = new Diem();
		Diem b = new Diem(5, 3);
		Diem c = new Diem(b);
		System.out.print("toa do A:");
		a.in();
		System.out.print("toa do B:" + b);
		System.out.print("toa do C:" + c);
	}
}
