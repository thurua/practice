package thu;

public class XeMoTo extends PhuongTien {
	public XeMoTo(String ten) {
		this.ten = ten;
	}
	
	@Override
	public void diChuyen() {
		System.out.println("Chay tren lo");		
	}

	@Override
	public void bopCoi() {
		System.out.println("Tin tin");
	}

}
