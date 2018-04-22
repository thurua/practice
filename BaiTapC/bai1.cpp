#include <stdio.h>
#include <conio.h>
#include <string.h>

int cong(int a, int b); // cai nay goi la prototype
float chia(float a, int b);
	
int main (){
	char holot[20], ten[10]; 
	printf ("nhap ho lot: ");gets(holot);
	printf ("nhap ten: "); gets(ten);
	
	// char src[5];

  // strcpy(src,  " ");
   
	strcat(holot, " ");
	strcat(holot, ten);
	printf("ho va ten la: "); 
	puts(holot); 
	//printf("--"); 
	//puts(ten);
	getch ();
	
/*	int  bb;	
	float aa;
	//float* p = &aa;

    printf("Nhap so a: ");
    scanf("%f", &aa);
    printf("You entered: %f\n", aa);
    
    printf("Nhap so b: ");
    scanf("%d", &bb);
    printf("You entered: %d\n", bb);
    
    float kq = chia(aa, bb);
    printf("Ket qua: %f\n", kq);
    
       kq = chia(8, 2);
    printf("Ket qua: %f\n", kq);*/
	
	return 0;
	}
	
	int cong(int a, int b){			
		return a+b;
	}
	
	float chia(float a, int b){			
	 if(b==0){
		return 0;
	}
//	float tam=(float)a;
		return a/b;
	}
