package buoi1;
import java.util.Scanner;
public class daysonguyen {
	private static int count;
	private static Scanner sc;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int a[], n;
		sc=new Scanner (System.in);
		System .out.print("nhap so phan tu cua danh sach:");
		n=sc.nextInt();
		a=new int[n];
		for (int i=0;i<a.length;i++){
			System.out.print ("nhap phan tu thu " +(i+1)+":");
			a[i]=sc.nextInt();
		}
		int x;
		System.out.print("ban muon tim so nao trong day so:");
		x=sc.nextInt();
		for (int e:a)
			if (e==x) count ++;
		System.out.println("so phan tu duoc tim thay:" +count);
		for (int i=0;i<n-1;i++)
			for(int j=i+1;j<n;j++){
				if(a[i]<a[j]){
					int t=a[i];
					a[i]=a[j];
					a[j]=t;
				}
				System.out.println("hien thi danh sach sap xep:");
				for (int e:a)
					System.out.println (e+"   ");

			}





	}

}
