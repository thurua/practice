package thu;

public abstract class PhuongTien implements HienThi {
protected String ten;	
	public void in() {
		System.out.println("Ten: "+ten);
	}
	
	public abstract void diChuyen();

	public abstract void bopCoi();
}
