package buoi2;

import java.util.Scanner;

public class Date {
	private int ngay;
	private int thang;
	private int nam;
	public Date() {
		ngay=thang=nam=0;
	}
	public Date(int ng, int t, int n) {
		ngay=ng;
		thang=t;
		nam=n;
	}
	public void in() {
		System.out.print(ngay +"/"+ thang +"/" + nam);
		
	}
	public void nhap() {
		Scanner sc=new Scanner(System.in);
		do {
			System.out.print("nhap ngay:");	
			ngay=sc.nextInt();
			System.out.print("nhap thang");
			thang=sc.nextInt();
			System.out.print("nhap nam");
			nam=sc.nextInt();
		} while (!hopLe());
	}
	public boolean hopLe() {
		boolean h=false;
		int max[]= {0,1,2,3,4,5,6,7,8,9,10,11,12};
		int max1[]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
		if(nam%4==0) {
			max1[2]=29;}
		if (nam>0&&thang>0&&thang<13&&ngay<=max1[thang]&&ngay>0) {
			h=true;}
		return h;
	}}