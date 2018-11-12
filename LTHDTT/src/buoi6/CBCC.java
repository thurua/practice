package buoi6;

import java.util.Scanner;

public class CBCC {
	// Cán bộ công chức
	private String masocb; // Mã số cán bộ
	private String hoten; // Họ tên
	protected float hesoluong; // Hệ số lương
	int namsinh; // Năm sinh

	CBCC() {
		masocb = new String();
		hoten = new String();
		namsinh = hesoluong = 0;
	}

	void nhap() {
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap ma so can bo : ");
		masocb = sc.nextLine();
		System.out.print("Nhap hoten can bo : ");
		hoten = sc.nextLine();
		System.out.print("Nhap nam sinh : ");
		namsinh = sc.nextInt();
		System.out.print("Nhap he so luong : ");
		hesoluong = sc.nextFloat();
	}

	void in() {
		System.out.print(hoten + " co ma so la" + masocb + " sinh nam " + namsinh + " co he so luong " + hesoluong);
	}

	float tienLuong() {
		return hesoluong * 210000;
	}

	void in(String thongtin) {
		System.out.print(thongtin);
		in();
	}

	void nhap(thongtin) { Scanner sc =new Scanner(System.in) ; thongtin=sc.nextLine(); nhap(); }

	void tienLuong() {
		System.out.print(hesoluong * 210000 * 1.5);
	}

	void CBCC() {
		hoten = "";
		masocb = " ";
		namsinh = 1980;
		hesoluong = 1.92f;
	}

	// void tangLuong() { hesoluong + 0.33f; }

	float tangLuong() {
		return (hesoluong + 0.33f);
	}

	void tangLuong(float h) {
		hesoluong += h;
	}

	void tangLuong(int n) {
		hesoluong++;
	}

	//cbcc(String masocb, String hoten, float hesoluong, int namsinh) { 
 //}

	//CBCC() {
		//this.CBCC();
		//System.out.print("Goi phuong thuc xay dung");
	//}

	//CBCC(CBCC cb) {
	//}

	//PhuongThucXayDung() { System.out.print("Day la phuong thuc xay dung"); }

	//CBCC(CBCC a) {
	//	this = a;
	//}

	//CBCC(CBCC c) {
	//masocb = c.masocb; 
	//hoten = c.hoten;
	//namsinh = c.namsinh; 
	//hesoluong=c.hesoluong; 
	//}

	//CBCC(CBCC c) {
	//masocb = new String(c.masocb); hoten = new String(c.hoten);
  //namsinh = c.namsinh; hesoluong=c.hesoluong; 
  //}

	CBCC(CBCC a) { this(a); }
}
