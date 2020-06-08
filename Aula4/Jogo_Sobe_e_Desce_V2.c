#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void wait()
{
	int i=1000;
	for(i; i=0; i--)
	{
		i;
	}
}

void menu()
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

int manual()
{
	int l, num;
	
		printf("\nJogo do Sobe e Desce\n\nNível 1: número mistério entre 1 e 100\nNível 2: número mistério entre 1 e 1000\nNível 3: número mistério entre 1 e 10000\n\nEscolha um nível de dificuldade: ");
		scanf(" %d",&l);
	
		if(l==1)
		{			
			printf("Introduza o numero misterio: ");
			scanf(" %d", &num);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			
			if (num<1 || num>100)
				{
					printf("Erro!\n");
					exit(1);
				}
			jogo(1,num);
		}
		else
		if(l==2) 
		{
			printf("Introduza o numero misterio: ");
			scanf(" %d", &num);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			if (num<1 || num>1000)
				{
					printf("Erro!\n");
					exit(1);
				}
			jogo(2,num);
		}
		else
		if(l==3) 
		{
			printf("Introduza o numero misterio: ");
			scanf(" %d", &num);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			if (num<1 || num>1000)
				{
					printf("Erro!\n");
					exit(1);
				}
			jogo(3,num);
		}
		else
		{
		printf("Erro na introdução do nível de dificuldade.\n");
		exit(1);
		}
}

int sorteio()
{
	int s, k=0;
	srand (time(NULL));
	s = (rand()%(3 - 1 + 1)) + 1;
	jogo(s,k);
}

int jogo(int j, int k)
{
	unsigned int numero_misterio = 0, tentativas = 0, tentativas_total, num, i;
	char novamente;
	
	if (j == 1 && k == 0 )
	{	
		wait();
		srand (time(NULL));
		numero_misterio = (rand()%100) + 1;
		tentativas = 10;
	}
	else if (j == 1 && k != 0 )
	{
		numero_misterio = k;
		tentativas = 10;
	}
	if (j == 2 && k == 0)
	{	
		wait();
		srand (time(NULL));
		numero_misterio = (rand()%1000) + 1;
		tentativas = 15;
	}
	else if (j == 2 && k != 0 )
	{
		numero_misterio = k;
		tentativas = 15;
	}
	if (j == 3 && k == 0)
	{	
		wait();
		srand (time(NULL));
		numero_misterio = (rand()%10000) + 1;
		tentativas = 20;
	}
		else if (j == 3 && k != 0 )
	{
		numero_misterio = k;
		tentativas = 20;
	}
	
	tentativas_total = tentativas;
	
	printf("Esta a jogar no nivel %d e tem no total %d", j, tentativas);
	
	do
	{
	
		for(i = tentativas; i>=0; i--)
		{
		printf("\nQual é o número mistério: ");
		scanf(" %u", &num);
			
			if(num == numero_misterio)
			{
				printf("Parabens. Acertou no numero misterio em %d tentativas.\n", tentativas_total-tentativas+1);
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
	menu();
}
