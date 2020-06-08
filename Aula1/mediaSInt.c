#include <stdio.h>

main() 
	{

const int NUMERO= 3;


short int val1=0, val2=0, val3=0;
short int total; 
short int media;

	printf("introduza os tres valores:");

	scanf(" %hd %hd %hd", &val1, &val2, &val3);
	
	total= val1+val2+val3;
	media= total/NUMERO;

	printf("\n");

	printf("A soma dos valores e %hd e a media e %hd\n", total, media);
	}