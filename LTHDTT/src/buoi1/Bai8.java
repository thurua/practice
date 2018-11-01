package buoi1;

import java.util.Scanner;

public class Bai8 {
	private static int count;
	private static Scanner sc;

	public static void main(String[] args) {
		int a[], n;

		sc = new Scanner(System.in);
		System.out.print("Nhap so phan tu cua danh sach:");
		n = sc.nextInt();
		a = new int[n];

		for (int i = 0; i < a.length; i++) {
			System.out.print("Nhap phan tu thu " + (i + 1) + ":");
			a[i] = sc.nextInt();
		}

		int x;
		System.out.print("Ban muon tim so nao trong day so:");
		x = sc.nextInt();
		for (int e : a) {
			if (e == x) {
				count++;
			}
		}
		System.out.println("So phan tu duoc tim thay:" + count);
		
		// Sort - sap xep
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (a[i] > a[j]) {
					// Swap - hoan vi - doi cho
					int t = a[i];
					a[i] = a[j];
					a[j] = t;
				}				
			}
		}
		
		// In kq
		System.out.println("Hien thi danh sach sap xep:");
		for (int e : a) {
			System.out.println(e + "   ");
		}
	}
}
