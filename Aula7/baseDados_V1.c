#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct num_serv_sec
{
	int num_serie;
};
	
struct info_pessoal
{
	char nome [100];
	int dia_nasc;
	int mes_nasc;
	int ano_nasc;
	int altura;
	char olhos [100];
	char cabelo [100];
};

struct info_numer
{
	int bi;
	int contribuinte;
	int seg_social;
	int carta_cond;
};

struct morada
{
	char rua [100];
	int cod_postal1;
	int cod_postal2;
	char cod_postal3 [100];
};

struct confid
{
	char partido [100];
	char clube [100];
};

typedef struct cidadao
{
	struct num_serv_sec nss;
	struct info_pessoal infp;
	struct info_numer infn;
	struct morada address;
	struct confid clubes;
} BASEDADOS;

void flush_in() //Funçao de limpeza
{ 
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

int verifica_numeros(int min, int max, int *num)
{
	do
	{
		scanf(" %d", &(*num));
		if(*num<min || *num>max)
			printf("Numero invalido - Introduza novamente\n");
	}
	while(*num<min || *num>max);
}

int verifica_caracteres(char *ch) //So escreve uma palavra
{
    char palavra[100];
    int i=0;    
    
    flush_in();

    do
    {
        scanf("%c", &palavra[i]);
        i++;
    }while(palavra[i-1]!='.');

    palavra[i-1]='\0';
    
    strcpy(ch, palavra);
}

void le_nss(BASEDADOS PESSOA[], int i)
{
	printf("Introduza o valor de numero secreto: ");
	verifica_numeros(1, 99999, &PESSOA[i].nss.num_serie);
}

void le_info_pessoal(BASEDADOS PESSOA[], int i)
{
	printf("Introduza o nome: ");
	verifica_caracteres(PESSOA[i].infp.nome);
	printf("Introduza o dia de nascimento: ");
	verifica_numeros(1, 31, &PESSOA[i].infp.dia_nasc);
	printf("Introduza o mes de nascimento: ");
	verifica_numeros(1, 12, &PESSOA[i].infp.mes_nasc);
	printf("Introduza o ano de nascimento: ");
	verifica_numeros(1900, 2015, &PESSOA[i].infp.ano_nasc);
	printf("Introduza a altura (cm): ");
	verifica_numeros(1, 250, &PESSOA[i].infp.altura);
	printf("Introduza a cor dos olhos: ");
	verifica_caracteres(PESSOA[i].infp.olhos);
	printf("Introduza a cor do cabelo: ");
	verifica_caracteres(PESSOA[i].infp.cabelo);
}

void le_info_numer(BASEDADOS PESSOA[], int i)
{
	printf("Introduza o numero do CC: ");
	verifica_numeros(1, 99999999, &PESSOA[i].infn.bi);
	printf("Introduza o numero da carta de conducao: ");
	verifica_numeros(1, 99999999, &PESSOA[i].infn.carta_cond);
	printf("Introduza o numero de contribuinte: ");
	verifica_numeros(1, 99999999, &PESSOA[i].infn.contribuinte);
	printf("Introduza o numero de seguranca social: ");
	verifica_numeros(1, 99999999, &PESSOA[i].infn.seg_social);
}

void le_morada(BASEDADOS PESSOA[], int i)
{
	printf("Introduza a morada(rua, praca, etc): ");
	verifica_caracteres(PESSOA[i].address.rua);
	printf("Introduza o Codigo Postal 1: ");
	verifica_numeros(1000, 9999, &PESSOA[i].address.cod_postal1);
	printf("Introduza o Codigo Postal 2: ");
	verifica_numeros(100, 999, &PESSOA[i].address.cod_postal2);
	printf("Introduza o Codigo Postal 3: ");
	verifica_caracteres(PESSOA[i].address.cod_postal3);
}

void le_confidencial(BASEDADOS PESSOA[], int i)
{
	printf("Introduza o partido politico(se nao tiver coloque X): ");
	verifica_caracteres(PESSOA[i].clubes.clube);
	printf("Introduza o clube(se nao tiver coloque X): ");
	verifica_caracteres(PESSOA[i].clubes.partido);
}

void le_cidadao(BASEDADOS PESSOA[], int j)
{
	le_nss(PESSOA, j);
	le_info_pessoal(PESSOA, j);	
	le_info_numer(PESSOA, j);
	le_morada(PESSOA, j);
	le_confidencial(PESSOA, j);
}

void mostrar_serie(BASEDADOS PESSOA[], int j)
{
	int i;
	
	for(i=0; i<j; i++)
	{
		printf("De acordo com a posicao na base: %d - %d\n", i, PESSOA[i].nss.num_serie);
	}
    printf("\n");
}

void mostrar_cidadao(BASEDADOS PESSOA[], int k)
{
	int i, j; 
	
	printf("Qual o cidadao que quer visualizar: ");
	scanf(" %d", &i);
	
	for(j=0;j<k;j++)
	{
		if(i==PESSOA[j].nss.num_serie)
		{		
			printf("%d %s %d %d %d %d %s %s %d %d %d %d %s %d %d %s %s %s\n\n", PESSOA[j].nss.num_serie, PESSOA[j].infp.nome, PESSOA[j].infp.dia_nasc, PESSOA[j].infp.mes_nasc, PESSOA[j].infp.ano_nasc, PESSOA[j].infp.altura, PESSOA[j].infp.olhos, PESSOA[j].infp.cabelo, PESSOA[j].infn.bi, PESSOA[j].infn.carta_cond, PESSOA[j].infn.contribuinte, PESSOA[j].infn.seg_social, PESSOA[j].address.rua, PESSOA[j].address.cod_postal1, PESSOA[j].address.cod_postal2, PESSOA[j].address.cod_postal3, PESSOA[j].clubes.clube, PESSOA[j].clubes.partido);
			//printf("%d %d %d %d %d %d %d %d %d %d %d\n", PESSOA[j].nss.num_serie, PESSOA[j].infp.dia_nasc, PESSOA[j].infp.mes_nasc, PESSOA[j].infp.ano_nasc, PESSOA[j].infp.altura, PESSOA[j].infn.bi, PESSOA[j].infn.carta_cond, PESSOA[j].infn.contribuinte, PESSOA[j].infn.seg_social, PESSOA[j].address.cod_postal1, PESSOA[j].address.cod_postal2);
		}
	}
}

void modificar_cidadao(BASEDADOS PESSOA[], int l)
{
	int i, j, k, m=0;
	char car;
	
	printf("Qual o cidadao que quer visualizar: ");
	scanf(" %d", &i);
	
	for(j=0;j<l;j++)
	{
		if(i==PESSOA[j].nss.num_serie)
			break;
	}
	
	printf("%d %s %d %d %d %d %s %s %d %d %d %d %s %d %d %s %s %s\n\n", PESSOA[j].nss.num_serie, PESSOA[j].infp.nome, PESSOA[j].infp.dia_nasc, PESSOA[j].infp.mes_nasc, PESSOA[j].infp.ano_nasc, PESSOA[j].infp.altura, PESSOA[j].infp.olhos, PESSOA[j].infp.cabelo, PESSOA[j].infn.bi, PESSOA[j].infn.carta_cond, PESSOA[j].infn.contribuinte, PESSOA[j].infn.seg_social, PESSOA[j].address.rua, PESSOA[j].address.cod_postal1, PESSOA[j].address.cod_postal2, PESSOA[j].address.cod_postal3, PESSOA[j].clubes.clube, PESSOA[j].clubes.partido);
	//printf("%d %d %d %d %d %d %d %d %d %d %d\n", PESSOA[j].nss.num_serie, PESSOA[j].infp.dia_nasc, PESSOA[j].infp.mes_nasc, PESSOA[j].infp.ano_nasc, PESSOA[j].infp.altura, PESSOA[j].infn.bi, PESSOA[j].infn.carta_cond, PESSOA[j].infn.contribuinte, PESSOA[j].infn.seg_social, PESSOA[j].address.cod_postal1, PESSOA[j].address.cod_postal2);

	do
	{
		printf("Selecione o numero correspondente ha informacao que quer editar (1-numero serv_sec\n2-nome\n3-dia nascimento\n4-mes nascimento\n5-ano nascimento\n6-altura\n7-cor dos olhos\n8-cor cabelo\n9-CC\n10-carta de conducao\n11-contribuinte\n12-seguranca social\n13-morada\n14-codigo postal(primeiros 4 digitos)\n15-codigo postal(ultimos 3 digitos)\n16-codigo postal(freguesia)\n17-clube\n18-partido)\n: ");
		scanf(" %d", &k);
		
		do
		{
			if(k==1)
			{
				printf("Introduza o valor de numero secreto: ");
				verifica_numeros(1, 99999, &PESSOA[j].nss.num_serie);				
			}	
			else
			if(k==2)
			{
				printf("Introduza o nome: ");
				verifica_caracteres(PESSOA[j].infp.nome);
			}
			else
			if(k==3)
			{
				printf("Introduza o dia de nascimento: ");
				verifica_numeros(1, 31, &PESSOA[j].infp.dia_nasc);
			}
			else
			if(k==4)
			{
				printf("Introduza o mes de nascimento: ");
				verifica_numeros(1, 12, &PESSOA[j].infp.mes_nasc);
			}
			else
			if(k==5)
			{
				printf("Introduza o ano de nascimento: ");
				verifica_numeros(1900, 2015, &PESSOA[j].infp.ano_nasc);
			}
			else
			if(k==6)
			{
				printf("Introduza a altura (cm): ");
				verifica_numeros(1, 250, &PESSOA[j].infp.altura);
			}
			else
			if(k==7)
			{
				printf("Introduza a cor dos olhos: ");
				verifica_caracteres(PESSOA[j].infp.olhos);
			}
			else
			if(k==8)
			{
				printf("Introduza a cor do cabelo: ");
				verifica_caracteres(PESSOA[j].infp.cabelo);
			}
			else
			if(k==9)
			{
				printf("Introduza o numero do CC: ");
				verifica_numeros(1, 99999999, &PESSOA[i].infn.bi);
			}
			else
			if(k==10)
			{
				printf("Introduza o numero da carta de conducao: ");
				verifica_numeros(1, 99999999, &PESSOA[i].infn.carta_cond);
			}
			else
			if(k==11)
			{
				printf("Introduza o numero de contribuinte: ");
				verifica_numeros(1, 99999999, &PESSOA[i].infn.contribuinte);
			}
			else
			if(k==12)
			{
				printf("Introduza o numero de seguranca social: ");
				verifica_numeros(1, 99999999, &PESSOA[i].infn.seg_social);
			}
			else
			if(k==13)
			{
				printf("Introduza a morada(rua, praca, etc): ");
				verifica_caracteres(PESSOA[i].address.rua);	
			}
			else
			if(k==14)
			{
				printf("Introduza o Codigo Postal 1: ");
				verifica_numeros(1000, 9999, &PESSOA[i].address.cod_postal1);
			}
			else
			if(k==15)
			{
				printf("Introduza o Codigo Postal 2: ");
				verifica_numeros(100, 999, &PESSOA[i].address.cod_postal2);
			}
			else
			if(k==16)
			{
				printf("Introduza o Codigo Postal 3: ");
				verifica_caracteres(PESSOA[i].address.cod_postal3);
			}
			else
			if(k==17)
			{
				printf("Introduza o partido politico(se nao tiver coloque X): ");
				verifica_caracteres(PESSOA[i].clubes.clube);
			}
			else
			if(k==18)
			{
				printf("Introduza o clube(se nao tiver coloque X): ");
				verifica_caracteres(PESSOA[i].clubes.partido);
			}
			else
				printf("Tente novamente\n");
			
		}while(k<0 || k>19);
		
		printf("Quer efectuar mais alguma alteraçao(s-sim ou n-nao): ");
		scanf(" %c", &car);
		
		if(car=='n')
			m=1;
			
	}while(m==0);
	
	
}

void criar_registo(BASEDADOS PESSOA[], int j)
{
	int i;
	
	for(i=0; i<j; i++)
	{
		if(PESSOA[j].nss.num_serie == 0)
			break;
	}
	
	if(PESSOA[j].nss.num_serie == 0)
			le_cidadao(PESSOA, j);
}

void apagar_registo(BASEDADOS PESSOA[], int k)
{
		int i, j; 
	
	printf("Qual o cidadao que quer eliminar: ");
	scanf(" %d", &i);
	
	for(j=0;j<k;j++)
	{
		if(i==PESSOA[j].nss.num_serie)
		{		
			PESSOA[j].nss.num_serie = 0;
			*PESSOA[j].infp.nome = '\0';
			PESSOA[j].infp.dia_nasc = 0;
			PESSOA[j].infp.mes_nasc = 0;
			PESSOA[j].infp.ano_nasc = 0;
			PESSOA[j].infp.altura = 0;
			*PESSOA[j].infp.olhos = '\0';
			*PESSOA[j].infp.cabelo = '\0';
			PESSOA[j].infn.bi = 0;
			PESSOA[j].infn.carta_cond = 0;
			PESSOA[j].infn.contribuinte = 0; 
			PESSOA[j].infn.seg_social = 0;
			*PESSOA[j].address.rua = '\0';
			PESSOA[j].address.cod_postal1 = 0;
			PESSOA[j].address.cod_postal2 = 0;
			*PESSOA[j].address.cod_postal3 = '\0'; 
			*PESSOA[j].clubes.clube = '\0';
			*PESSOA[j].clubes.partido = '\0';
			
			//printf("%d %d %d %d %d %d %d %d %d %d %d\n", PESSOA[j].nss.num_serie, PESSOA[j].infp.dia_nasc, PESSOA[j].infp.mes_nasc, PESSOA[j].infp.ano_nasc, PESSOA[j].infp.altura, PESSOA[j].infn.bi, PESSOA[j].infn.carta_cond, PESSOA[j].infn.contribuinte, PESSOA[j].infn.seg_social, PESSOA[j].address.cod_postal1, PESSOA[j].address.cod_postal2);
			printf("%d %s %d %d %d %d %s %s %d %d %d %d %s %d %d %s %s %s\n\n", PESSOA[j].nss.num_serie, PESSOA[j].infp.nome, PESSOA[j].infp.dia_nasc, PESSOA[j].infp.mes_nasc, PESSOA[j].infp.ano_nasc, PESSOA[j].infp.altura, PESSOA[j].infp.olhos, PESSOA[j].infp.cabelo, PESSOA[j].infn.bi, PESSOA[j].infn.carta_cond, PESSOA[j].infn.contribuinte, PESSOA[j].infn.seg_social, PESSOA[j].address.rua, PESSOA[j].address.cod_postal1, PESSOA[j].address.cod_postal2, PESSOA[j].address.cod_postal3, PESSOA[j].clubes.clube, PESSOA[j].clubes.partido);
		}
	}
}

main()
{		
	int i=0, j=0;
	char ch;
	BASEDADOS PESSOA[50];
	
	do
	{
	printf("Quantos registos quer criar (numero menor que 50): ");
	scanf(" %d", &j);
	}while(j>50);

	for(i=0; i<j; i++)
	{
	le_cidadao(PESSOA, i);
	}
	
	for(i=0; i<j; i++)
	{
	printf("\n%d %s %d %d %d %d %s %s %d %d %d %d %s %d %d %s %s %s\n", PESSOA[i].nss.num_serie, PESSOA[i].infp.nome, PESSOA[i].infp.dia_nasc, PESSOA[i].infp.mes_nasc, PESSOA[i].infp.ano_nasc, PESSOA[i].infp.altura, PESSOA[i].infp.olhos, PESSOA[i].infp.cabelo, PESSOA[i].infn.bi, PESSOA[i].infn.carta_cond, PESSOA[i].infn.contribuinte, PESSOA[i].infn.seg_social, PESSOA[i].address.rua, PESSOA[i].address.cod_postal1, PESSOA[i].address.cod_postal2, PESSOA[i].address.cod_postal3, PESSOA[i].clubes.clube, PESSOA[i].clubes.partido);
	}	
	
    printf("\n");
	
	printf("\n/*********** PROGRAMA SIRP - Registo dos cidadaos **********/\n");
		
	do
	{
	printf("a - Mostrar os numero de serie de todos os elementos da base de dados\nb - Mostrar toda a informacao do cidadao com um certo numero\nc - Modificar a informacao do cidadao com um certo numero\nd - Criar um novo registo para um novo cidadao\ne - Apagar o registo com um certo numero\n\ns - Sair do programa\n");
	printf("\n\nEscolha uma opcao: ");
	scanf(" %c", &ch);	
		switch(ch)
		{
		case 'a': mostrar_serie(PESSOA, i); break;
		case 'b': mostrar_cidadao(PESSOA, i); break;
		case 'c': modificar_cidadao(PESSOA, i); break;
		case 'd': criar_registo(PESSOA, i); break;
		case 'e': apagar_registo(PESSOA, i); break;
		case 's': exit(1); break;
		default: puts("Opcao Invalida\n"); break;
		}
	}
	while(ch != ('a' ||'b'||'c'||'d'||'e'||'s'));
}
