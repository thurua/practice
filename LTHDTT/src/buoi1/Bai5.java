package buoi1;

public class Bai5 {
	public static void main(String[] args) {
		// Test case - unit test
		gptBac1(4, 5);
		gptBac1(0, 0);
		gptBac1(0, 1);
		gptBac1(1, 0);
		gptBac1(-11, 8);
		
		gptBac2(1, -11, 8);
		gptBac2(0, -11, 8);

		boolean a = true;
		boolean b = false;

		boolean c = a && b;
		boolean d = !c;

		boolean e = !(a && b);
		boolean f = !a || !b;

		boolean g = !(!a && !b);
		boolean h = a || b; // OR AND
	}

	/**
	 * ax + b = 0
	 * 
	 * @param a
	 * @param b
	 */
	public static void gptBac1(float a, float b) {
		System.out.println("Phuong trinh bac 1 co dang : " + a + "x + " + b + " = 0");

		if (a == 0) {
			if (b == 0) {
				System.out.println("PT co vo so nghiem");
			} else {
				System.out.println("PT vo nghiem");
			}
		} else {
			float kq = -b / a;
			System.out.println("KQ = " + kq);
		}
		System.out.println("-------------------------------------");
	}

	/**
	 * ax^2 + bx + c = 0
	 * 
	 * @param a
	 * @param b
	 * @param c
	 */
	public static void gptBac2(float a, float b, float c) {
		System.out.println("Phuong trinh bac 2 co dang : " + a + "x^2 + " + b + "x + " + c + " = 0");
		if (a == 0) {
			System.out.println("Pt bac 2 tro thanh pt bac 1");
			gptBac1(b, c);
		} else {
			float d = b * b - 4 * a * c;
			if (d == 0) {
				float kq = -b / 2 * a;
				System.out.println("PT co nghiem kep: " + kq);
			} else if (d > 0) {
				float x1 = 0;
				float x2 = 0;

				System.out.println("PT co nghiem phan biet: ");
				System.out.println("x1: " + x1);
				System.out.println("x2: " + x2);
			} else {
				System.out.println("PT vo nghiem");
			}
		}
		
		System.out.println("-------------------------------------");
	}
}