package buoi4;

import buoi2.Diem;

public class DiemMau extends Diem {
	private String mau;

	public DiemMau(int x, int y, String mau) {
		super(x, y);
		this.mau = mau;
	}

	public void ganMau(String mau) {
		this.mau = mau;
	}
	public void nhapMau() {
		System.out.println("Nhap mau:");
	}
	public void hienThi() {
		System.out.println(toString());// sao chua viet ham toString
	}
}
