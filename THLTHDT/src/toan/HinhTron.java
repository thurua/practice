package toan;

public class HinhTron extends Hinh  {
	private float r;

	public HinhTron(String ten, float r) {
		this.ten = ten;
		this.r = r;
	}

	@Override
	public float dienTich() {
		double kq = r * r * Math.PI;
		return (float) kq;
	}

	@Override
	public float chuVi() {
		double kq = 2 * r * Math.PI;
		return (float) kq;
	}

	@Override
	public void in() {
		System.out.print("Ten: " + ten);
		System.out.print(" Ban kinh: " + r);
		System.out.print(" Dien tich: " + dienTich());
		System.out.println(" | Chu vi: " + chuVi());
	}
}