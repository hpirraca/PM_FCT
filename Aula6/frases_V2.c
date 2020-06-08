/*
*      Ficheiro frases.c
*/

#include <stdio.h>
#include <string.h>

#define bool int

#define TRUE 1
#define FALSE 0

#define MAX_WORD_LENGTH 21
#define MAX_TEXT_LENGTH 81
#define MAX_WORD 20

void conta(int *pessoa, int valor)
{	
	*pessoa=*pessoa+valor;	
}

main() 
{
	int  joao,  ana,  mariana,  catarina,  pedro,  filipa,  margarida,  jose,  jorge, susana, cristina;
	int valor=0;
	
	joao = 1000;
	ana = 2500;
	mariana = 3000;
	catarina = 1200;
	pedro = 2500;
	filipa = 340;
	margarida = 3400;
	jose = 120;
	jorge = 340;
	susana = 120;
	cristina = 1290;
		
	printf("Que valor quer retirar da conta: ");
	scanf(" %d", &valor);
	
	printf("\nAntes: %d\n", ana);
	conta(&ana, valor);
	printf("\nDepois: %d\n", ana);
}