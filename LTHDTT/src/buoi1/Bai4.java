package buoi1;

import java.util.Scanner;

public class Bai4 {
	private static Scanner sc;
	float nhap(){

		sc= new Scanner (System.in);
		String s; float f=0.0f;
		boolean b=true;
		do{
			System.out.print("nhap vao mot so thuc:");
			s=sc.nextLine();
			try {
				f=Float.parseFloat(s); 
				b=true;
			}
			catch(Exception e){
				b=false;}
		} while (b==false);
		return f;
	}


	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Bai4 obj= new Bai4();
		float a,b;
		a=obj.nhap();
		b=obj.nhap();
		System.out.print ("tonghaiso="+(a+b));
	}

}


