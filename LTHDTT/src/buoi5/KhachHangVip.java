package buoi5;

public class KhachHangVip extends KhachHang {
	private MyDate ngayDangKi;

	public KhachHangVip() {

	}

	public KhachHangVip(String ten, String diaChi, MyDate ngayDangKi) {
		super(ten, diaChi);
		this.ngayDangKi = ngayDangKi;

	}
}
