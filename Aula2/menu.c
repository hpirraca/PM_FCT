#include <stdio.h>
#include <stdlib.h>
main() 
{

char op, x='0', opant, y ='0';
int i=1;

  do
  {
	do 
	{
		printf ("MENU para broncos\n\n\n");
		printf ("1 – A opção que escolheu foi 1\n");
		printf ("2 – Escolheu a segunda opção\n");
		printf ("3 – Agora escreveu um três\n");
		printf ("4 – A tecla que carregou foi um quatro\n");
		printf ("s – Escreveu um ‘s’\n");
		printf ("t – Esta foi a opção do ‘t’\n");
		printf ("f – Sair\n");
		printf ("Escolha uma opcao: ");
		scanf(" %c", &op);
	} 
	while((op!='1') && (op!='2') && (op!='3') && (op!='4') && (op!='s') && (op!='t') && (op!='f'));
	
	switch(op)
	{
		case '1': printf ("1 – A opção que escolheu foi 1\n"); break;
		case '2': printf ("2 – Escolheu a segunda opção\n"); break;
		case '3': printf ("3 – Agora escreveu um três\n"); break;
		case '4': printf ("4 – A tecla que carregou foi um quatro\n"); break;
		case 's': printf ("s – Escreveu um ‘s’\n"); break;
		case 't': printf ("t – Esta foi a opção do ‘t’\n"); break;
		case 'f': exit(i); break;
		default: printf("A opcao escolhida nao e valida.\n\n");exit(1); break;
	}
	printf ("\nQual foi a opcao escolhida anteriormente? ");
    scanf (" %c", &opant);
    
    if(x == opant)
		printf("\nMuito bem!\n");
	else
	{	
		printf("Errado! A opcao escolhida foi %c\n", x);
		exit(i);		
	}
	
	
	printf ("\nQual foi a opcao escolhida antes desta? ");
	scanf (" %c", &opant);
	
	if(y == opant)
		printf("\nMuito bem!\n");
	else
	{
		printf("Errado! A opcao escolhida foi %c\n", y);
		exit(i);
	}
	
	y = x;
	x = op;
  }
  while(i);
}
