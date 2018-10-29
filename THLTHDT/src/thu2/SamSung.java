package thu2;

public class SamSung extends DienThoai {
public SamSung (String ten) {
	this.ten=ten;
}
	@Override
	public void mau() {
		System.out.println("mau: xanh");		
	}

	@Override
	public void gia() {
		System.out.println("gia:3tr5");		
	}

}
