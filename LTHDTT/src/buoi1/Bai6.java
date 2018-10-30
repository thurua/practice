package buoi1;

public class Bai6 {
	public static void main(String[] args) {
		boolean ketThuc = false;
		System.out.println("** CHUONG TRINH KIEM TRA SO NGUYEN TO **");
		System.out.println("De ket thuc chuong trinh, nhap 0 or 1");

		do {
			if (ketThuc) {
				System.out.println("Good bye!!!");
			} else {
				System.out.println("Kiem tra tiep --> ");
			}

			float a = Bai4.intput();
			int b = (int) a;

			ketThuc = b == 0 || b == 1;

			System.out.print("So nguyen ban nhap la " + b);
			boolean kq = ktSoNguyenTo(b);
			String tg = kq ? " LA" : " KHONG la";
			System.out.println(tg + " so nguyen to");
		} while (!ketThuc);
	}

	public static boolean ktSoNguyenTo(int n) {
		int dem = 0;

		for (int i = 1; i < n; i++) {
			int tg = n % i;
			if (tg == 0) {
				dem++;
			}

			if (dem == 2) {
				return false;
			}
		}

		return dem == 1;
	}
}