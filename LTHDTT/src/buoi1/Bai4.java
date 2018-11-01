package buoi1;

import java.util.Scanner;

public class Bai4 {
	private static Scanner sc;

	float nhap() {
		sc = new Scanner(System.in);
		String s;
		float kq = 0.0f;
		boolean b = true;

		do {
			System.out.print("Nhap vao mot so thuc: ");
			s = sc.nextLine();
			try {
				kq = Float.parseFloat(s);
				b = true;
			} catch (Exception e) {
				b = false;
			}
		} while (!b); // while (b == false)
		
		return kq;
	}

	static float input() {
		sc = new Scanner(System.in);
		String s;
		float kq = 0f;
		boolean coLoi = false;

		do {
			if (coLoi) {
				System.out.print("Nhap lai: ");
			} else {
				System.out.print("Nhap vao mot so thuc: ");
			}

			s = sc.nextLine();
			try {
				kq = Float.parseFloat(s);
				coLoi = false;
			} catch (Exception e) {
				coLoi = true;
			}
		} while (coLoi); // while (coLoi == true)
		return kq;
	}

	public static void main(String[] args) {		
		float a, b;
		
		//Bai4 obj = new Bai4();
		//a = obj.nhap();
		// b = obj.nhap();
		
		a = Bai4.input();
		b = Bai4.input();
		System.out.print("tonghaiso=" + (a + b));
	}

}
