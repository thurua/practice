package thu;

public class XeLua extends PhuongTien {
	public XeLua(String ten) {
		this.ten = ten;
	}
	
	@Override
	public void diChuyen() {
		System.out.println("Chay tren duong ray");		
	}

	@Override
	public void bopCoi() {
		System.out.println("Phon phon");
	}

}
