package thu;

public class TauThuy extends PhuongTien {
public TauThuy(String ten) {
		this.ten = ten;
	}

	@Override
	public void diChuyen() {
		System.out.println("Chay tren mat nuoc");		
	}

	@Override
	public void bopCoi() {
		System.out.println("Phone phone");
	}

}
