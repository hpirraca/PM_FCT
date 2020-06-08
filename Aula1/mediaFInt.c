#include <stdio.h>

main() 
	{

const int NUMERO= 3;


unsigned long int val1=0, val2=0, val3=0;
unsigned long int total; 
unsigned long int media, resto;

	printf("introduza os tres valores:");

	scanf(" %lu %lu %lu", &val1, &val2, &val3);
	
	total= val1+val2+val3;
	media= total/NUMERO;
	resto= total%NUMERO;
	
	printf("\n");

	printf("A soma dos valores e %lu e a media e %lu e %lu/3\n", total, media, resto);
	}