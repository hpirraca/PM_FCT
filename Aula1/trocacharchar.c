#include <stdio.h>

main()
	{

 	char caracter1=' ';
 	char caracter2=' ';
 	char caracter3=' ';
 
 	printf("Introduza 3 caracteres: ");
 	caracter1 = getchar();
 	caracter2 = getchar();
 	caracter3 = getchar();
 
 	printf("\n Invertendo a ordem dos caracteres obtemos: ");
 	printf(" '%c' '%c' '%c'\n", caracter3, caracter2, caracter1);
 	}