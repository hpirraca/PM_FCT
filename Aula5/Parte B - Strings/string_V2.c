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

void subst_texto(int num, char desaparecer[], char colocar[], char * text, char * text_changed)
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
	int m;
		
		
		while(desaparecer[k]!='\0')
		{
				bufd[k]=desaparecer[k];
				k++;
		}
		bufd[k]=' ';
		bufd[k+1]='\0';
		
		k=0;
		
		while(colocar[k]!='\0')
		{
				bufc[k]=colocar[k];
				k++;
		}
		bufc[k]=' ';
		bufc[k+1]='\0';

		do
		{	
			while(text[i]!='\0')
			{
				i++;
			}			
			
			while((text[numero]!=' ' && text[numero]!='.') && numero<=i)
			{
				palavra[cont]=text[numero];
				numero++;
				cont++;
			}
	
			
			if(text[numero]==' ')
			{
				palavra[cont]=' ';
				cont++;
				palavra[cont]='\0';
				numero++;
				cont=0;
			}		
			else
			if(text[numero]=='.')
			{
				palavra[cont]=' ';
				cont++;
				palavra[cont]='\0';
				numero++;
				cont=0;
			}
			
			
			while(palavra[l]!='\0' || bufd[l]!='\0')
			{
				dif=(palavra[l]-bufd[l]);
				if(dif!=0)
					break;
				else
				if(dif==0)
					l++;
			}
			l=0;
			//printf("\n3 - palavra a desaparecer: %s", bufd);
			//printf("\n4 - palavra: %s", palavra);
			
			if(dif!=0)
			{
				for (m=0; palavra[m]!='\0' ; m++)
				{
					text_changed[pos]=palavra[m];
					pos++;	
				}
			}
			
			if(dif==0)
			{
				for (m=0; bufc[m]!='\0' ; m++)
				{
					text_changed[pos]=bufc[m];
					pos++;	
				}
				//printf("\n2 - %s", bufc);
				//printf("\n8 - %s", text_changed);
			}
			
			//printf("\n5 - diferenca: %d", dif);
			
			if(text[numero]=='\0' && palavra[m-1]==' ')
			{
				text_changed[pos-1]='.';
				text_changed[pos]='\0';
			}
		} 
		while(text[numero]!='\0');
		//printf("\n10 - %s\n", text_changed);
}

void substitui_texto(int num, char desaparecer[][MAX_WORD_LENGTH], char colocar[][MAX_WORD_LENGTH], char * text, char * text_changed)
{
	int i=0, j=0;
	
	for(i=0; i<num; i++)
	{
		if(i>0)
		{
			while(text_changed[j]!='\0')
			{
				text[j]=text_changed[j];
				text_changed[j]='\0';
				j++;
			}
			text[j]='\0';
			j=0;
			//printf("\n1 - %s\n", text);
		}
		subst_texto(num, desaparecer[i], colocar[i], text, text_changed);
	}
}


main() 
{

int n_word=0, i=0, j=0;
char desaparecer[MAX_WORD][MAX_WORD_LENGTH];
char colocar[MAX_WORD][MAX_WORD_LENGTH];
char text[MAX_TEXT_LENGTH];
char text_buf[MAX_TEXT_LENGTH];
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

	while(text[j]!='\0')
	{
		text_buf[j]=text[j];
		j++;
	}
	text_buf[j]='\0';

substitui_texto(n_word, desaparecer, colocar, text, text_changed);

printf("\n\nO texto inicial e:\n%s", text_buf);

printf("\n\nO texto substituido e:\n%s\n", text_changed);
}
