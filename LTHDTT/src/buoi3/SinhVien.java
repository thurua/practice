package buoi3;

import java.util.Scanner;

import buoi2.Date;

public class SinhVien {
	private String mssv;
	private String hoten;
	private Date ngaysinh;
	private int slhphan;
	private String hphan[];
	private String diem[];
	private int max = 55;

	public SinhVien() {
		mssv = new String();
		hoten = new String();
		ngaysinh = new Date();
		slhphan = 0;
		hphan = new String[max];
		diem = new String[max];

	}

	public SinhVien(String mssv1, String hoten1, Date ngaysinh1, int max1) {
		mssv = new String(mssv1);
		hoten = new String(hoten1);
		ngaysinh = new Date(ngaysinh1);
		max = max1;
	}

	public SinhVien(SinhVien obj) {
		mssv = new String(obj.mssv);
		hoten = new String(obj.hoten);
		ngaysinh = new Date(obj);
		slhphan = obj.slhphan;
		hphan = new String[obj.max];
		diem = new String[obj.max];

	}

	public void nhap() {
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap ma so sinh vien:");
		mssv = sc.nextLine();
		System.out.print("Nhap ho ten:");
		hoten = sc.nextLine();
		System.out.print("Nhap ngay sinh:");
		ngaysinh.nhap();
	}

	public void nhapDiem() {
		Scanner sc = new Scanner(System.in);
		System.out.print("so mon can nhap");
		slhphan = sc.nextInt();
		for (int i = 0; i < slhphan; i++) {
			hphan[i] = new String();
			diem[i] = new String();
			System.out.print("Nhap ten mon thu" + (i + 1) + ":");
			hphan[i] = sc.nextLine();
			System.out.print("Nhap diem mon hoc:");
			diem[i] = sc.nextLine();
		}

	}

	public void in() {
		System.out.print("mssv:" + mssv);
		System.out.print("hoten:" + hoten);
		System.out.print("ngaysinh:" + ngaysinh);
		for (int i = 0; i < slhphan; i++) {
			System.out.print(hphan[i] + ":" + diem[i]);

		}
	}

	public String toString() {
		String s = " ";
		s = ("mssv:" + mssv + "ho ten:" + hoten + "ngaysinh:" + ngaysinh);
		for (int i = 0; i < slhphan; i++) {
			s = s + hphan[i] + diem[i];

		}
		return s;

	}

	public void themHocPhan(String mon, String d) {
		if(slhphan<max-1) {// em khong hieu
			for (int i = 0; i < slhphan; i++) {
			hphan[i]=new String(mon);
			diem[i]=new String(d);
			}
		}
		else System.out.print(" loi! khong the dang ki them hoc phan");
	}
	public void xoaHocPhan(String mon) {
		for (int i = 0; i < slhphan; i++) {
		    if(mon.compareTo(hphan[i]==0) {// 2 cai nay deu kieu String ma sao no bao loi la k ss duoc
			   break;
		       }
		    if(i<slhphan)	{
			   for (int j=i; j<slhphan-1; j++) {
				hphan[i]= hphan[j-1];
				diem[i]= diem[j-1];
			   }
			   slhphan--;
		    }  
		}
	}
	public float tinhDiemTB() {
		float dtb=0.0f;
		for (int i = 0; i < slhphan; i++) {
		    if(diem[i].compareTo("A")) {
		    	dtb=dtb+4;
		    }
		    else if (diem[i].compareTo("B")) {
		    	dtb=dtb+3;
		    }
		    else if (diem[i].compareTo("B+")) {
		    	dtb=dtb+3.5;
		    }
		    else if (diem[i].compareTo("C")) {
		    	dtb=dtb+2.5;
		    }
		    else if((diem[i].compareTo("D")) {
		    	dtb=dtb+2;
		    }
		    return dtb;
		
	}
}
}
