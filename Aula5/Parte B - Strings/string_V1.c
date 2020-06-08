#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define bool int
#define TRUE 1
#define FALSE 0

#define MAX_WORD_LENGTH 81
#define MAX_WORD 10
#define MAX_TEXT_LENGTH 8000


int quantas_palavras ()
{
	int num;
	
	do
	{
		scanf(" %d", &num);
		if ((num < 1) || (num > MAX_WORD))
		printf("O número de palavras deve ser > 0 e < %d!\n", MAX_WORD);
	}
	while ((num < 1) || (num > MAX_WORD));
	
return num;
}

void ler_substituicoes (int num, char desaparecer[][MAX_WORD_LENGTH], char colocar[][MAX_WORD_LENGTH]) 
{
	int i;
	
	for(i = 0; i<num; i++)
	{
		printf("\nEscreva a palavra que quer substituir: ");
		scanf("%s", desaparecer[i]);
		printf("\nEscreva a novas palavra a colocar: ");
		scanf("%s", colocar[i]);	
	}
}

bool le_texto(char * text, int maximo) 
{
	char atual=' ';
	char anterior=' ';
	int i = -1 ;
	
	do
	{
		anterior = atual;
		scanf("%c", &text[i]);
		atual = text[i];
		//printf("%c%d\n", text[i], i);
		i++;
	}
	while(!(anterior=='.' && atual=='\n'));

	text[i-1]='\0';
}

void substitui_texto(int num, char desaparecer[][MAX_WORD_LENGTH], char colocar[][MAX_WORD_LENGTH], char * text, char * text_changed)
{	
	char palavra[MAX_WORD_LENGTH];
	char bufd[MAX_WORD_LENGTH];
	char bufc[MAX_WORD_LENGTH];
	
	int pos=0;
	int numero=0;
	int cont=0;
	int dif=0;
	int i=0;
	int j=0;
	int k=0;
	int l=0;
	int m, p_esp;
	
	while(j<num)
	{
		
		while(desaparecer[j][k]!='\0')
		{
				bufd[k]=desaparecer[j][k];
				k++;
		}
		bufd[k]=' ';
		bufd[k+1]='\0';
		printf("%s\n", bufd);
		
		k=0;
		
		while(colocar[j][k]!='\0')
		{
				bufc[k]=colocar[j][k];
				k++;
		}
		bufc[k]=' ';
		bufc[k+1]='\0';
		printf("%s\n", bufc);

		do
		{	
			while(text[i]!='\0')
			{
				i++;
			}		
			
			//printf("\n%d\n", i);		
			
			while((text[numero]!=' ' && text[numero]!='\0') && numero<=i)
			{
				palavra[cont]=text[numero];
				numero++;
				//printf("%c\n", palavra[cont]);
				cont++;
			}
			
			if(text[numero]==' ')
			{
				palavra[cont]=' ';
				palavra[cont+1]='\0';
				numero++;
				cont=0;
			}		
			else
			if(text[numero-1]=='.' && text[numero]=='\0')
			{
				palavra[cont]='\0';
				cont=0;
			}
			//printf("%s\n", palavra);
			
			
			while(palavra[l]!='\0' || bufd[l]!='\0')
			{
				dif=(palavra[l]-bufd[l]);
				//printf("%d", dif);
				if(dif!=0)
					break;
				l++;
			}
			
			if(dif!=0)
			{
				for (m=0; palavra[m]!='\0' ; m++)
				{
					text_changed[pos]=palavra[m];
					pos++;	
				}
				//printf("\n\n%s\n\n", palavra);
				//printf("\n\n%s\n\n", text_changed);
			}
			if(dif==0)
			{
				for (m=0; bufc[m]!='\0' ; m++)
				{
					text_changed[pos]=bufc[m];
					pos++;	
				}
				//printf("\n\n%s\n\n", bufc);
			}
			if(text[numero]=='\0')
			{
				text_changed[pos]='\0';
			}
		} 
		while(text[numero]!='\0');
	j++;
	}
}

main() 
{

int n_word= 0, i=0;
char desaparecer[MAX_WORD][MAX_WORD_LENGTH];
char colocar[MAX_WORD][MAX_WORD_LENGTH];
char text[MAX_TEXT_LENGTH];
char text_changed[MAX_TEXT_LENGTH];

printf("Quantas palavras tem a lista de substituicao: ");
	
	n_word = quantas_palavras ();

printf("\nIntroduza os textos a retirar e a colocar\n");
	
	ler_substituicoes(n_word, desaparecer, colocar);

printf("Introduza o texto inicial\n");

printf("Termine com uma linha apenas com um ponto final:\n\n");

	
	if (!le_texto(text, MAX_TEXT_LENGTH)) 
	{
	printf("Não foi introduzido texto\n");
	return;
	}
	
substitui_texto(n_word, desaparecer, colocar, text, text_changed);

printf("O texto inicial e:\n%s", text);

printf("\n\nO texto substituido e:\n%s\n", text_changed);
}
