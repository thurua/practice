package thu1;

import java.util.List;

import java.util.ArrayList;

public class SDDongVat {

	public static void main(String[] args) {
		DongVat dv1 = new ConNguoi("Nguyen Thi Anh Thu");
		DongVat dv2 = new ConHeo("Con heo hong");
		DongVat dv3 = new ConBo("Con bo vang de thuong");

		List<DongVat> ds = new ArrayList<DongVat>();

		ds.add(dv1);
		ds.add(dv2);
		ds.add(dv3);
		for (DongVat dv : ds) {
			dv.in();
			dv.an();
			dv.diChuyen();
			dv.keu();

		}
	}
}
