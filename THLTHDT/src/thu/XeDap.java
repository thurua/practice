package thu;

public class XeDap extends PhuongTien {
	public XeDap(String ten) {
		this.ten = ten;
	}
	
	@Override
	public void diChuyen() {
		System.out.println("Chay tren lo");		
	}

	@Override
	public void bopCoi() {
		System.out.println("Ren ren");
	}

}
