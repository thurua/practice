package buoi5;

public class SuDung {

	public static void main(String[] args) {
		KhachHangVip vip1 = new KhachHangVip();		
		
		KhachHangVip vip2 = new KhachHangVip("Thu", "Dong Thap", new MyDate());
		
		MyDate d3 = new MyDate();
		KhachHangVip vip3 = new KhachHangVip("Toan", "Dong Thap", d3);
		KhachHangVip vip4 = new KhachHangVip("Ten", "Dong Thap", d3);
	}
}
