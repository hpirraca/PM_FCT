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

void escolha(int *num_frase, int *num_palavra)
{
	printf("Escolha a frase(numeros de 1 a 7) e a palavra(numeros de 1 a 6): ");
	scanf(" %d %d", num_frase, num_palavra);
}

void ver_se_contem(char *frase, char *palavra)
{
	printf("A frase escolhida foi: \n\n%s\n\nE a palavra escolhida foi: \n\n%s\n\n", frase, palavra); //SE ESTIVERMOS A ACEDER À VARIAVEL NO MAIN PRECISAMOS DO *
	
	if(strstr(frase, palavra)!= NULL)
		printf("\n\nSIM\n\n");
	else
		printf("\n\nNAO\n\n");
}

main() 
{
	char frase1 [MAX_TEXT_LENGTH] = "A string that contains a dog and a cat";
	char frase2 [MAX_TEXT_LENGTH] = "A string that contains camel and mouse";
	char frase3 [MAX_TEXT_LENGTH] = "The dog was eating with the horse";
	char frase4 [MAX_TEXT_LENGTH] = "The camel drunk all the water";
	char frase5 [MAX_TEXT_LENGTH] = "The mouse entered into the pipe";
	char frase6 [MAX_TEXT_LENGTH] = "Uma string que pode conter dog ou camel";
	char frase7 [MAX_TEXT_LENGTH] = "The horse is bigger than the dog";
	char palavra1 [MAX_WORD_LENGTH] = "dog";
	char palavra2 [MAX_WORD_LENGTH] = "horse";
	char palavra3 [MAX_WORD_LENGTH] = "cat";
	char palavra4 [MAX_WORD_LENGTH] = "mouse";
	char palavra5 [MAX_WORD_LENGTH] = "camel";
	char palavra6 [MAX_WORD_LENGTH] = "pig";
	
	char *frase_ptr [MAX_WORD];   // para apontar a frases
	char *pal_ptr [MAX_WORD];    // para apontar a palavras
	char ** frase, ** palavra;
	int num_frase, num_palavra;     // para conter a escolha do util.
	
	frase_ptr [0] = frase1;
	frase_ptr [1] = frase2;
	frase_ptr [2] = frase3;
	frase_ptr [3] = frase4;
	frase_ptr [4] = frase5;
	frase_ptr [5] = frase6;
	frase_ptr [6] = frase7;
	pal_ptr [0] = palavra1;
	pal_ptr [1] = palavra2;
	pal_ptr [2] = palavra3;
	pal_ptr [3] = palavra4;
	pal_ptr [4] = palavra5;
	pal_ptr [5] = palavra6;
	
	while (1) 
	{
	escolha (&num_frase, &num_palavra);
	
	frase = &frase_ptr[num_frase-1];
	palavra = &pal_ptr[num_palavra-1];
	
	ver_se_contem (*frase, *palavra);
	}
}