#include <stdio.h>

main() 
	{

const int NUMERO= 3;


double val1=0, val2=0, val3=0;
double totalf, mediaf;

	printf("introduza os tres valores:");

	scanf(" %f %f %f", &val1, &val2, &val3);
	
	totalf = val1+ val2+ val3;
	mediaf = totalf/3;
	
	printf("\n");

	printf("A soma dos valores e %f e a media e %f ou %e\n", totalf, mediaf, mediaf);
	}