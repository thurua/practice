package thu2;

import java.util.ArrayList;
import java.util.List;

public class SDDienThoai {

	public static void main(String[] args) {
		DienThoai dt1 = new SamSung("Samsung Galaxy A5");
		DienThoai dt2 = new ViVo("ViVo J3");
		DienThoai dt3 = new Oppo("Oppo J7 plus");
		List<DienThoai> ds = new ArrayList<DienThoai>();
		ds.add(dt1);
		ds.add(dt2);
		ds.add(dt3);
		for (DienThoai dt : ds) {
			dt.in();
			dt.mau();
			dt.gia();
		}
	}

}
