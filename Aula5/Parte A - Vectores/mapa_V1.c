#include <stdio.h>
#include <stdlib.h>

void limpar_vector(int mapa[]) 
{
	int i;
	
	printf("\nVector:");
	
	for(i=0; i<4; i++)
	{
		mapa[i] = 0;
		printf(" %d", mapa[i]);
	}
	printf("\n");
	return;
}

void insere_vector(int mapa[])
{
	int i, pos, val;
	
	for(i=0; i<4; i++)
	{
		do
		{
		printf("Posicao: ");
		scanf(" %d", &pos);
		}
		while(pos < 0 || pos > 3);
		
		printf("Valor: ");
		scanf(" %d", &mapa[pos]);
	}
	
	printf("\n");
	return;	
}

void imprimir_vector(int mapa[]) 
{
	int i;
	
	printf("\nVector:");
	
	for(i=0; i<4; i++)
		printf(" %d", mapa[i]);
		
	printf("\n");
	return;
}

void substitui_valor(int mapa[])
{
	int num_original, num_novo, i, x=0;
	
	printf("Qual o numero que quer alterar: ");
	scanf(" %d", &num_original);
	printf("Por que numero quer alterar: ");
	scanf(" %d", &num_novo);
	
	printf("Vector:");
	
	for(i=0; i<4; i++)
	{
		if(mapa[i] == num_original)
		{
			x++;
			mapa[i] = num_novo;
		}
	printf(" %d", mapa[i]);
	}
	printf("\nFez-se %d substituicoes.\n", x);	
	
	return;
}

void conta_caracter(int mapa[])
{
	int val, i, conta=0;
	
	printf("Qual o valor que quer contar: ");
	scanf(" %d", &val);
	
	for(i=0; i<4; i++)
	{
		if(mapa[i] == val)
			conta++;
	}
	
	printf("\nO numero %d aparece %d vezes.\n", val, conta);
}

main()
{
	char esc;
	int mapa[4] = {9, 8, 7, 6};

    printf("\n\n*********Mapa**********\n\n\n");
	
	while(1)
		{
	
	printf("\n1- Limpar o Vector.\n2- Insere no Vector.\n3- Mostrar o Vector.\n4- Substituir o Valor.\n5- Contar Ocorrencia.\ns- Sair.\n");
	printf("\nO que deseja fazer: ");
	scanf(" %c", &esc);	
	
		switch (esc)
			{
			case '1': limpar_vector(mapa); break;
			case '2': insere_vector(mapa); break;
			case '3': imprimir_vector(mapa); break;
			case '4': substitui_valor(mapa); break;
			case '5': conta_caracter(mapa); break;
			case 's':printf("Adeus!\n\n"); exit(1);
			default: break;
			}
		}
}
