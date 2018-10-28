package buoi4;

import java.util.Scanner;

public class SinhVienCNTT {

	private String mk,tk,email;
	public SinhVienCNTT(){
		super();
		tk=new String();
		mk=new String();
		email=new String();
	}
	public SinhVienCNTT(SinhVienCNTT s){

		tk=new String(s.tk);
		mk=new String(s.mk);
		email=new String(s.email);
	}
	public void nhap(){
		Scanner sc=new Scanner (System.in);
		System.out.print ("\n nhap tk");
		tk=sc.nextLine();
		System.out.print ("\n nhap mk");
		mk=sc.nextLine();
		System.out.print ("\n nhap email");
		email=sc.nextLine();
	}
	public void in(){

		System.out.print ("\n tk sinh vien:"+tk);

		System.out.print ("\n mk sinh vien:"+mk);

		System.out.print ("\n email sinh vien:"+email);

	}
	public void doimatkhau (String newpass){
		mk=new String (newpass);
	}
	public String getEmail(){
		return email;
	}
public static void main(String[] args){
	SinhVien ds[];
	int n;
	Scanner sc =new Scanner (System.in);
	System.out.print ("\n nhap so sinh vien:");
	n=sc.nextInt();
	ds=new SinhVien[n];
	int m;
	for (int i=0;i<n;i++){
		System.out.print ("\n nhapsinhvien thu" +(i=1)+ ":( 1: sinh vien, 2: sinh vien CNTT)");
		m=sc.nextInt();
		if(m==1) ds[i]=new SinhVien();
		else ds[i]=new SinhVienCNTT();
		ds[i].nhap();
	}
	for (int i=0; i<n;i++){
		System.out.print ("\n sinhvien thu" +(i=1)+":");
		ds[i].in();
	}
	String email="";
	System.out.print ("\n nhap email can tim: ");
	email=sc.nextLine;
	for (int i=0;i<n;i++){
		if (ds[i].getEmail().equals(email)){
			ds[i].in();
			System.out.print ("\n diem tb:" +ds[i].dtb());
		}
	}
}













































