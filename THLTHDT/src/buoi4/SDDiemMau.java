package buoi4;

public class SDDiemMau {

	public static void main(String[] args) {
		DiemMau a = new DiemMau(5,10,"A");
		a.hienThi();

		DiemMau b = new DiemMau();
		b.nhapDiem();
		b.doiDiem(10,8);
		b.hienThi();
	}

}
