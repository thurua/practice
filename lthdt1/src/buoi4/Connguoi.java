package buoi4;

import java.util.Scanner;

public class Connguoi {
	private String cmnd, hoten, diachi;
	class Date{
		public Date (){
			ngay=thang=nam=1;
			public Date (int ngay, int thang, int nam){
				public Date (Date d){
					ngay=d.ngay;
					thang=d.thang;
					nam=d.nam;
				}
			}
		}

		private Date ngaysinh;
		private String nghe;
		private Boolean gioitinh;
		public void Congnuoi (){
			cmnd=new String();
			hoten=new String();
			diachi=" ";
			ngaysinh=new Date();
			nghe=new String ();
			gioitinh=true;
		}
		public Connguoi (String cmnd1, String hoten1, String diachi1, Date ngaysinh, String nghe1, String gioitinh1){

			cmnd=new String (cmnd1);
			hoten=new String (hoten1);
			diachi=new String (diachi1);
			ngaysinh =new Date (ngaysinh1);
			nghe=new String (nghe1);
			gioitinh = gioitinh1;
			public Connguoi(Connguoi c){
				cmnd=new String (c.cmnd);
				hoten=new String (c.hoten);
				diachi=new String (c.diachi);
				ngaysinh =new Date (c.ngaysinh);
				nghe=new String (c.nghe);
				gioitinh=new String (c.gioitinh);
		public void nhap(){
			Scanner Sc=new Scanner(System.in);
			System.out.print("nhap cmnd:");
			cmnd=Sc.nextLine();
			System.out.print("nhap ho ten:");
			hoten=Sc.nextLine();
			System.out.print("nhap dia chi:");
			diachi=Sc.nextLine();
			System.out.print("nhap ngay sinh:");
			ngaysinh.nhap();
			System.out.print("nhap nghe nghiep:");
			nghe=Sc.nextLine();
			System.out.print("nhap gioi tinh:");
			gioitinh=Sc.nextBoolean();
		}
		public void in(){
			System.out.print();
		}

					

			}




			public static void main(String[] args) {
				// TODO Auto-generated method stub

			}

		}
