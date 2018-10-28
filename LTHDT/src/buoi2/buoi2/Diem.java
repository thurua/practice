package buoi2;
import java.util.Scanner
public class Diem {
	private int x,y;
	public Diem ()
	public Diem (int x1, int y1){
		x=x1;
		y=y1;
	}
	public Diem (Diem obj){
		x=obj.x;
		y=obj.y;
	}
	public void nhap(){
		Scanner sc=new Scanner (System.in);
		System.out.print ("nhap x");
		x=sc.nextInt ();
		System.out.print ("nhap y");
		y=sc.nextInt();
	}
	public void in (){
		System.out.print ("("+x+","+y+")");
	}
	public String to String(){
		return ("("+x+","+y+")");

	}
	public static void main(){
		Diem A=new Diem();
		Diem B=new Diem(5,3);
		Diem C=new Diem(B);
		System.out.print("toa do A:");
		A.in();
		System.out.print("toa do B:" +B);
	}}

