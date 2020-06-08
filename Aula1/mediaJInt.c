#include <stdio.h>

main() 
	{

const int NUMERO= 3;


float val1=0, val2=0, val3=0;
long int total; 
long int media, resto;
float totalf, mediaf;

	printf("introduza os tres valores:");

	scanf(" %f %f %f", &val1, &val2, &val3);
	
	total= val1+val2+val3;
	totalf = val1+ val2+ val3;
	media= total/NUMERO;
	resto= total%NUMERO;
	mediaf = totalf/3;
	
	printf("\n");

	printf("A soma dos valores e %lu e a media e %f e %lu e %lu/3\n", total, mediaf, media, resto);
	}