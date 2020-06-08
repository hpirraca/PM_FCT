#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inic_random()
{
	srand (time(NULL));
}

int menu()
{
	int esc;

	printf("\n\n**********Jogo do Sobe e Desce**********\n\n");
	printf("Escolha o modo de jogo - Sorteio(1) ou Manual(2): ");
	scanf(" %d", &esc);
	
	if(esc == 2)
		manual();
	if(esc == 1)
		sorteio();
	if(esc != 2 || esc != 1)
		exit(1);
		
}

int manual(int l)
{

		printf("\nJogo do Sobe e Desce\n\nNível 1: número mistério entre 1 e 100\nNível 2: número mistério entre 1 e 1000\nNível 3: número mistério entre 1 e 10000\n\nEscolha um nível de dificuldade: ");
		scanf(" %d",&l);
	
		if(l==1) 
			jogo(1);
		else
		if(l==2) 
			jogo(2);
		else
		if(l==3) 
			jogo(3);
		else
		{
		printf("Erro na introdução do nível de dificuldade.\n");
		exit(1);
		}
}

int sorteio()
{
	int s;
	
	s = (rand()%(3 - 1 + 1)) + 1;
	jogo(s);
}

int jogo(int j)
{
	unsigned int numero_misterio = 0, tentativas = 0, tentativas_total, num, i;
	char novamente;
	
	if (j == 1)
	{
		numero_misterio = (rand()%100) + 1;
		tentativas = 10;
	}
	if (j == 2)
	{
		numero_misterio = (rand()%1000) + 1;
		tentativas = 15;
	}
	if (j == 3)
	{
		numero_misterio = (rand()%10000) + 1;
		tentativas = 20;
	}
	
	tentativas_total = tentativas;
	
	do
	{
		
		for(i = tentativas; i>=0; i--)
		{
		printf("\nQual é o número mistério: ");
		scanf(" %u", &num);
			
			if(num == numero_misterio)
			{
				printf("Parabens. Acertou no numero misterio em %d tentativas.\n", tentativas_total-tentativas);
				printf("Quer jogar novamente sim(s) ou nao(n): ");
				scanf(" %c", &novamente);
				
				if(novamente == 's')
					main();
				if(novamente == 'n')
					exit(1);
			}
			
			if(num != numero_misterio)
			{
				tentativas --;
				if(num>numero_misterio)
					printf("O numero misterio e inferior ao introduzido\n");
				else
					printf("O numero misterio e superior ao introduzido\n");
					
				printf("Tente novamente");
				printf("\nTem ainda %d tentativas\n", tentativas);
			}
			
			if(tentativas == 0)
			{
				printf("\nPerdeu, para a proxima corre melhor!!\n");
				printf("Quer jogar novamente sim(s) ou nao(n): ");
				scanf(" %c", &novamente);
				
				if(novamente == 's')
					main();
				if(novamente == 'n')
					exit(1);
			}
		}
		
	}
	while(num != numero_misterio);	
}

main()
{
	int escolha;
	inic_random();
	escolha=menu();
}
