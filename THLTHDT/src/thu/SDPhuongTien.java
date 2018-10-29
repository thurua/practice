package thu;

import java.util.ArrayList;
import java.util.List;

public class SDPhuongTien {

	public static void main(String[] args) {
		PhuongTien pt1 = new MayBay("may bay boeing");
		PhuongTien pt2 = new TauThuy("tau thuy");
		PhuongTien pt3 = new XeDap("xe dap");
		PhuongTien pt4 = new XeLua("xe lua");

		List<PhuongTien> ds = new ArrayList<PhuongTien>();
		ds.add(pt1);
		ds.add(pt2);
		ds.add(pt3);
		ds.add(pt4);

		for (PhuongTien pt : ds) {
			pt.in();
			pt.diChuyen();
			pt.bopCoi();
		}

		System.out.println("*******************************");
		
		List<HienThi> ds1 = new ArrayList<HienThi>();
		ds1.add(pt1);
		ds1.add(pt2);
		ds1.add(pt3);
		ds1.add(pt4);

		for (HienThi pt : ds) {
			pt.in();			
		}
	}

}
