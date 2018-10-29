package thu;

public class MayBay extends PhuongTien {
	public MayBay(String ten) {
		this.ten = ten;
	}

	@Override
	public void diChuyen() {
		System.out.println("Bay tren khong");
	}

	@Override
	public void bopCoi() {
		System.out.println("....");
	}

}
