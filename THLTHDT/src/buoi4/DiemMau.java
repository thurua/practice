package buoi4;

import buoi2.Diem;

public class DiemMau extends Diem {
	private String mau; // field

	public DiemMau() {
		//super(-1, -1);
		//mau=""; //empty blank
		
		this(-1,-1,"");
	}

	public DiemMau(int x, int y, String mau) {
		super(x, y);

		this.mau = mau;
	}

	public void ganMau(String mau) { // parameter argument
		this.mau = mau;
	}

	public void hienThi() {
		System.out.println(toString());
	}

	public String toString() {
		String t = super.toString();
		return t + " mau " + mau;
	}
}
