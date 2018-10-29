package toan;

public class HinhChuNhat extends Hinh  {
	private float a;
	private float b;

	public HinhChuNhat(String ten, float a, float b) {
		this.ten = ten;
		this.a = a;
		this.b = b;
	}

	@Override
	public float dienTich() {
		float kq = a * b;
		return kq;
	}

	@Override
	public float chuVi() {
		float kq = (a + b) * 2;
		return kq;
	}

	@Override
	public void in() {
		System.out.print("Ten: " + ten);
		System.out.print(" Dai: " + a);
		System.out.print(" Rong: " + b);
		System.out.print(" Dien tich: " + dienTich());
		System.out.println(" | Chu vi: " + chuVi());
	}
}
