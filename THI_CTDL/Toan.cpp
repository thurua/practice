#include <stdio.h>
#include <conio.h>



int main(){
	double   i;
	double *p;
	printf ("i = %x",i);
	printf (" @ %x\n",&i);
	
	i=100;
	printf ("i = %x",i);
	printf (" @ %x\n",&i);
	
	printf("*****************************\n");
	printf ("p = %x",p);
	printf (" @ %x\n",&p);
	//printf (" * %x\n",*p);
	
	p=&i;
	printf ("p = %x",p);
	printf (" @ %x \n",&p);
	
	//printf (" * %x\n",*p);
	printf("*****************************\n");
	*p=126;
	printf ("i = %x",i);
	printf (" @ %x\n",&i);
	
	p++;
	*p=877;
	
	printf("*****************************\n");
	
	printf ("p = %x",p);
	printf (" @ %x\n",*p);
	
	}
