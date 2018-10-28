package buoi4;

import java.util.Scanner;

import buoi2.Diem;

public class DiemMau extends Diem {
	private String mau; // field
	public DiemMau() {}
	
	public DiemMau(int x, int y, String mau) {
		super(x,y);
	
		this.mau=mau;
		
	}
	
	public void ganMau(String mau) { // parameter argument
		this.mau=mau;
	}
	
	public void nhapDiem() {
		super.nhapDiem();
		Scanner sc = new Scanner(System.in);
		System.out.print("nhap mau");
		String mau  = sc.nextLine();
		ganMau(mau);
	}

	public void hienThi() {
		super.hienThi();
		System.out.print(" mau " +mau);
	}

	public String toString() {
		String t= super.toString();
		return t + "mau ="+mau;
	}



}
