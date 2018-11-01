package buoi1;

import java.util.Scanner;

public class Bai7 {
	private static Scanner sc;

	public static void main(String[] args) {
		boolean ketThuc = false;
		System.out.println("** CHUONG TRINH NHAP HO TEN **");
		System.out.println("De ket thuc chuong trinh, KHONG NHAP VA AN ENTER");

		do {
			if (ketThuc) {
				System.out.println("Good bye!!!");
			} else {
				System.out.println("Nhap tiep --> ");
			}

			String kq = input();
			
			/*if (kq .equals( "A")) { // khong duoc viet kieu nay
				System.out.print("Ban da nhap A");
			}*/
			
			if ("A" .equals(kq)) {
				System.out.print("Ban da nhap A");
			}
			
			ketThuc = kq.isEmpty();
		} while (!ketThuc);
	}

	static String input() {
		sc = new Scanner(System.in);
		String s;
		System.out.print("Nhap ho ten: ");
		s = sc.nextLine();

		String[] arr = s.split(" ");
		int len = arr.length;
		System.out.println("To ten: " + arr[len - 1]);

		System.out.print("Ho lot: ");
		for (int i = 1; i < len - 1; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();

		return s;
	}
}