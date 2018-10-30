package buoi1;

public class Bai3 {

	public static void main(String[] args) {
		System.out.println("Buoi 1 Bai 3");
		float tong = 0;
		float max = 0;

		for (String s : args) {
			// System.out.println(s);
			if (isNumeric(s)) {
				float kq = Float.parseFloat(s);

				if (kq > max) {
					max = kq;
				}

				tong += kq;
				// tong = tong + kq;
				System.out.println(kq);
			}
		}

		System.out.println("Tong: " + tong);
		System.out.println("Max: " + max);

	}

	public static boolean isNumeric(String str) {
		try {
			Float d = Float.parseFloat(str);
		} catch (NumberFormatException nfe) {
			return false;
		}
		return true;
	}

}
