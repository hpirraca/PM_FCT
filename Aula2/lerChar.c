#include <stdio.h>
#include <stdlib.h>
main () 
{
	char c1;
	short int sucesso = 0;
	short int num;

	printf ("Escreva um 's': ");

	while (!sucesso) {
		scanf (" %c", &c1);
		if (c1 == 'f')
		exit (1);
		if (c1 == 's')
			sucesso = 1;
		else
			printf ("V� l�, escreva um 's': ");
	}
	
	printf ("Boa! Muito obrigado\n\n");
	printf ("Agora escreva um n�mero inteiro: ");
	scanf (" %d", &num);
	printf ("O n�mero foi %d\n", num);
}
