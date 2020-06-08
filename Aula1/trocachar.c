#include <stdio.h>

main()
	{

 	char caracter1=' ';
 	char caracter2=' ';
 	char caracter3=' ';
 
 	printf("Introduza 3 caracteres: ");
 	scanf(" %c", &caracter1);
 	scanf(" %c", &caracter2);
 	scanf(" %c", &caracter3);
 
 	printf("\n Invertendo a ordem dos caracteres obtemos: ");
 	printf(" '%c' '%c' '%c'\n", caracter3, caracter2, caracter1);
 	}