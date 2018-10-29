package thu;

import java.util.ArrayList;
import java.util.List;

import toan.Hinh;
import toan.HinhChuNhat;
import toan.HinhTron;

public class Vidu {

	public static void main(String[] args) {
		Hinh h1 = new HinhTron("Cai lu", 5);
		Hinh h2 = new HinhChuNhat("Cai ban", 5, 7);

		h1.in();
		h2.in();
		// h1.ten="xx";

		List<Hinh> ds = new ArrayList<Hinh>();
		ds.add(h1);
		ds.add(h2);

		for (Hinh hinh : ds) {
			hinh.in();
		}

		// --------------------------------------------------
		System.out.println("*******************************");

		HinhTron h3 = new HinhTron("Cai lu", 5);
		HinhTron h4 = new HinhTron("Cai lu", 5);
		HinhTron h5 = new HinhTron("Cai lu", 5);
		// h3.ten="xx7777";
		// h3.in();
		// h4.in();
		// h5.in();

		HinhChuNhat h6 = new HinhChuNhat("Cai ban", 5, 7);
		HinhChuNhat h7 = new HinhChuNhat("Cai ban", 5, 7);

		List<HinhTron> ds1 = new ArrayList<HinhTron>();
		ds1.add(h3);
		ds1.add(h4);
		ds1.add(h5);

		List<HinhChuNhat> ds2 = new ArrayList<HinhChuNhat>();
		ds2.add(h6);
		ds2.add(h7);

		for (HinhTron hinh : ds1) {
			hinh.in();
		}
		System.out.println("*******************************");
		for (HinhChuNhat hinh : ds2) {
			hinh.in();
		}

	}

}
