#include <stdio.h>
#include <stdlib.h>

#define DIM 4

void iniciar_mapa(int mapa[DIM][DIM])
{
	int i, j;
	
	for(j=0; j<4; j++)
	{
		for(i=0; i<4; i++)
		{
		mapa[i][j] = 0;
		printf(" %d", mapa[i][j]);
		
		}
	printf("\n");
	}
	
	return;
}

void inserir_barco(int mapa[DIM][DIM])
{
	int i, j, barco, fragata=0, p_avioes=0, x, y;
	
	for(j=0; j<4; j++)
	{
		for(i=0; i<4; i++)
		{
			if(mapa[i][j] == 1 || mapa[i][j] == 2)
			{
				printf("\nJa introduziu o numero maximo de barcos permitidos\n");
				printf("\nPara poder alterar, tem de reiniciar o mapa (1)\n");
				return;
			}
		}
	}
	
	do
	{
		do
		{
			printf("Qual a coordenada X onde quer por o valor (entre 0 e 3): ");
			scanf(" %d", &i);
			
			if(i<0 || i>3)
				printf("Erro! Tem de colocar valores entre 0 e 3\n");
		}
		while(i<0 || i>3);
		
		do
		{
			printf("\nQual a coordenada Y onde quer por o valor (entre 0 e 3): ");
			scanf(" %d", &j);
			
			if(j<0 || j>3)
				printf("\nErro! Tem de colocar valores entre 0 e 3.\n");
		}
		while(j<0 || j>3);


			printf("\nQual o valor (1 - Fragata ou 2 - Porta-Aviões) que quer colocar no jogo: ");
			scanf(" %d", &barco);
			
			x=barco;
			
			if(barco!=1 && barco!=2)
				printf("\nErro! Tem de colocar valor 1 ou 2.\n");
			
			if(barco == 1)
			{
					if(fragata == 1)
					{
						printf("\nNao pode introduzir outra Fragata\n\n");
						continue;
					}
					fragata = 1;
			}
			if(barco == 2)
			{
					if(p_avioes == 1)
					{	
						printf("\nNao pode introduzir outro Porta-Avioes\n\n");
						continue;
					}
					p_avioes = 1;
			}
			
            mapa[i][j] = barco;
	}
	while(fragata != p_avioes);

	return;
}

void imprimir_mapa(int mapa[DIM][DIM])
{
	int i, j;
	
	for(j=0; j<4; j++)
	{
		for(i=0; i<4; i++)
		{
		printf(" %d", mapa[i][j]);
		}
	printf("\n");
	}
	
	return;
}

void disparar_tiro(int mapa[DIM][DIM])
{
	int i, j, vencer1=0, vencer2=2;
	char escolha;

	do
	{
		do
		{
			printf("\nQual o valor da coordenada X que quer (entre 0 e 3): ");
			scanf(" %d", &i);
		}
		while(i>3 || i<0);
		
		do
		{
			printf("\nQual o valor da coordenada Y que quer (entre 0 e 3): ");
			scanf(" %d", &j);
		}
		while(j>3 || j<0);
		
		if(mapa[i][j] == 0)
			{
				printf("\nAgua!\n");
			}
		if(mapa[i][j] == 1)
			{
				printf("\nTiro na Fragata!\n");
				vencer1 = 1;
				mapa[i][j] = 0;
			}
		if(mapa[i][j] == 2)
			{
				printf("\nTiro no Porta-Avioes!\n");
				vencer2 = 1;
				mapa[i][j] = 0;
			}
	}
	while(vencer1 != vencer2);
	
	printf("\nVenceu!\n\n");
	printf("Quer jogar outra vez (s-sim): ");
	scanf(" %c", &escolha);
	
	if(escolha == 's' || escolha == 'S')
		return;
	else
		exit(1);
}

main()
{
	char esc;
	int mapa[DIM][DIM] = {{0, 1, 2, 3},{10, 11, 12, 13},{20, 21, 22, 23},{30, 31, 32, 33}};

    printf("\n\n*********Batalha Naval**********\n\n\n");
	
	while(1)
		{
	
	printf("\n1- Iniciar o mapa.\n2- Inserir Barco.\n3- Mostrar o mapa.\n4- Disparar tiro.\ns- Sair.\n");
	printf("\nO que deseja fazer: ");
	scanf(" %c", &esc);	
	
		switch (esc)
			{
			case '1': iniciar_mapa(mapa); break;
			case '2': inserir_barco(mapa); break;
			case '3': imprimir_mapa(mapa); break;
			case '4': disparar_tiro(mapa); break;
			case 's':printf("Adeus!\n\n"); exit(1);
			default: break;
			}
		}
}
