#include <stdio.h>
#include <conio.h>
int main(){
    int num =235;
	//char kq[40];
	int index = 0;

		while (num > 0) {
			int t = num % 16; // lay phan du
			
			switch(t){
				case 10:
					printf("A");
					break;
				case 11:
					printf("B");
					break;
				case 12:
					printf("C");
					break;
				case 13:
					printf("D");
					break;
				case 14:
					printf("E");
					break;
				case 15:
					printf("F");
					break;
				default:
					printf("%d",t);
			}
					
					
			
		
			num = num / 16; // lay phan nguyen
		}
		
		/*for (int i = index - 1; i >= 0; i--) {
			printf("%s",kq[i]);
		}*/
}


