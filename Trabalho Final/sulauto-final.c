#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PECAS 13
#define MAX_CARROS 11

//Estruturas

typedef struct est_carros
{
	char marca[20];
	char modelo[20];
	int ano;
}base_carros;

typedef struct est_stock_rep
{
	char n_rep[15];
	float p_rep;
	int id_rep;
	float l_rep;
}base_stock_rep;

typedef struct est_stock
{
	int valor;
	char nome[15];
	float preco;
	int id;
	float lucro;
}base_stock;

typedef struct est_cliente
{
	char primeiro_nome[15];
	char ultimo_nome[15];
	unsigned int idade;
	unsigned long int contribuinte;
}base_cliente;

typedef struct est_lista_espera
{
	char nome[15];
	char apelido[15];
	unsigned long int contribuinte;
	char marca[15];
	char modelo[15];
	char avaria[15];
}base_espera;

typedef struct est_historico_factura
{
	char primeiro_nome[15];
	char apelido[15];
	unsigned long int contribuinte;
	char marca[15];
	char modelo[15];
	char avaria[15];
	float preco;
	float lucro;
}base_fatura;

//Funcoes de verificacao

void verifica_id(int id_aux, int *feito)
{
	if(id_aux>0 && id_aux<14)
	{
		(*feito)++;
	}
}

void verifica_lucro(int lucro_aux, int *feito)
{
	if(lucro_aux>0&&lucro_aux<100)
	{
		(*feito)++;
	}
}

void verifica_peca(char nome_aux[], int *feito)
{
	char controlo[150]="Pastilhas Discos Rolamento Disco Prensa Triangulos Topos Amortecedor Radiador Bomba Liquido Botoes Elevador";
	
	if(strstr(controlo, nome_aux)!=NULL)
	{
		(*feito)++;
	}
}

void verifica_preco(float preco_aux, int *feito)
{
	if(preco_aux>0)
	{
		(*feito)++;
	}
}

int verifica_produto(char *nome_aux, float preco_aux, int id_aux, float lucro_aux)
{
	int feito=0;
	verifica_peca(nome_aux, &feito);
	verifica_preco(preco_aux, &feito);
	verifica_id(id_aux, &feito);
	verifica_lucro(lucro_aux, &feito);
	if(feito==4)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int verifica_carro(char *m_carro, char *mdl_carro, int ano_carro, base_carros *carro)
{	
	int i=0;
	
	while(i<MAX_CARROS)
	{
		if(strcmp(carro[i].marca, m_carro)==0 && strcmp(carro[i].modelo, mdl_carro)==0 && ano_carro==carro[i].ano) // Garante que verifica a existencia do carro todo ao mesmo tempo
		{
			return 1;
		}
		i++;
	}
	return 0;
}

//Funcoes de copia e de remocao

void copiar_fatura(int i, int con, int p1, int p2, int p3, char *palavra, base_cliente *cliente, base_stock *stock, base_carros *carro, base_fatura *fatura) //CONCLUIDA
{
	int j=0;
	
	float preco1=0, preco2=0, preco3=0, preco_total=0;
	float lucro1=0, lucro2=0, lucro3=0, lucro_total=0;

	const time_t timer = time(NULL); //Vem da biblio time.h e serva para podermos colocar o dia e a hora no ecrã

	preco1 = stock[p1].preco;
	lucro1 = stock[p1].lucro;
	preco2 = stock[p2].preco;
	lucro2 = stock[p2].lucro;
	
	if(p3>=0 && p3<13)
	{
		preco3 = stock[p3].preco;
		lucro3 = stock[p3].lucro;
	}
	else
		preco3=0;

	lucro_total = (preco1*(lucro1/100)) + (preco2*(lucro2/100)) + (preco3*(lucro3/100));
			
	preco1 = preco1 + preco1*(lucro1/100);
	preco2 = preco2 + preco2*(lucro2/100);
	preco3 = preco3 + preco3*(lucro3/100);
	
	preco_total = preco1 + preco2 + preco3;
	
	while(fatura[j].contribuinte!=0)
	{
		j++;
	}
	
	strcpy(fatura[j].primeiro_nome, cliente[i].primeiro_nome);
	strcpy(fatura[j].apelido, cliente[i].ultimo_nome);
	fatura[j].contribuinte = cliente[i].contribuinte;
	strcpy(fatura[j].marca, carro[con].marca);
	strcpy(fatura[j].modelo, carro[con].modelo);
	strcpy(fatura[j].avaria, palavra);
	fatura[j].preco = preco_total;
	fatura[j].lucro = lucro_total;
	
	printf("\nReparacao concluida com sucesso.\n");	
	
	printf("\n\n*************FATURA***************\n");
	printf("*            SulAuto             *\n");
	printf("*                                *\n");
	printf(" Nome: %s %s\n",  cliente[i].primeiro_nome, cliente[i].ultimo_nome);
	printf(" NIF:  %lu\n", cliente[i].contribuinte);
	printf(" Data: %s", ctime(&timer));
	printf("**********************************\n");
	printf("**********************************\n");
	printf("**********************************\n");				
	printf(" Pecas:\n");
	printf(" %s - %.2f€\n", stock[p1].nome, preco1);
	printf(" %s - %.2f€\n", stock[p2].nome, preco2);
	if(p3>=0 && p3<13)
		printf(" %s - %.2f€\n", stock[p3].nome, preco3);
	printf("*                                *\n");
	printf(" Total: %.2f€\n", preco_total);
	printf("*                                *\n");
	printf("*                                *\n");
	printf("***********VOLTE SEMPRE***********\n");
	printf("*                                *\n");
	printf("**********************************\n");
}

void copiar_stock_encomenda(int j, int i, base_stock *stock, base_stock_rep *stock_rep) //CONCLUIDA
{
int m;
int k=0;
int c=0;

	while(stock_rep[k].id_rep!=0)
	{
		k++;
	}
	
	strcpy(stock_rep[k].n_rep, stock[j].nome);
	stock_rep[k].id_rep = stock[j].id;
	stock_rep[k].p_rep = stock[j].preco;	
	stock_rep[k].l_rep = stock[j].lucro;	
	
	//printf("%d\n", k);
	//printf("%s %.2f %d %.2f\n", stock_rep[k].n_rep, stock_rep[k].p_rep, stock_rep[k].id_rep, stock_rep[k].l_rep);
}

void apagar_linha(base_espera *espera, int aux) //CONCLUIDA
{
		strcpy(espera[aux].nome, "\0");
		strcpy(espera[aux].apelido, "\0");
		espera[aux].contribuinte = 0;
		strcpy(espera[aux].marca, "\0");
		strcpy(espera[aux].modelo, "\0");
		strcpy(espera[aux].avaria, "\0");
}

//Funcoes

void ler_ficheiro(char *nome_ficheiro, base_carros *carro, base_cliente *cliente, base_stock *stock) //CONCLUIDA
{
	char ficheiro1[20]= "carros.txt";
	char ficheiro2[20]= "clientes.txt";
	char ficheiro3[20]= "pecas.txt";
	char aux[200];
	char nome_aux[15];
	float preco_aux, lucro_aux;
	int id_aux;
	int sucesso; 
	int invalidos=0; 
	int total_lidos=0; 
	int stock_total=0; 
	int j=0; 
	int contar=0;
	int l, k, comparar;

	FILE *fp;

	fp = fopen(nome_ficheiro,"r");
	
	if(fp == NULL)
	{
		printf("Impossivel abrir o ficheiro!\n");
	}

	if(strcmp(nome_ficheiro, ficheiro1) == 0) //carro
	{
		while(fscanf(fp,"%s %s %d", carro[j].marca, carro[j].modelo, &carro[j].ano)!=EOF)
		{
			//printf("\n%s %s %d", carro[j].marca, carro[j].modelo, carro[j].ano); 
			j++;
		}
		
		//printf("\n");
	}

	if(strcmp(nome_ficheiro, ficheiro2) == 0) //cliente
	{
		while(fscanf(fp,"%s %s %u %lu", cliente[j].primeiro_nome, cliente[j].ultimo_nome, &cliente[j].idade, &cliente[j].contribuinte)!=EOF)
		{
			//printf("\n%s %s %u %lu", cliente[j].primeiro_nome, cliente[j].ultimo_nome, cliente[j].idade, cliente[j].contribuinte);
			j++;
		}
		
		//printf("\n");
	}

	if(strcmp(nome_ficheiro, ficheiro3) == 0) //stock
	{
		while(fgets(aux, sizeof(aux), fp) != NULL)
		{
    		sucesso=0;
    		sscanf(aux,"%s %f %d %f", nome_aux, &preco_aux, &id_aux, &lucro_aux); //Le uma linha e passa para dentro das variaveis auxiliares
    		sucesso=verifica_produto(nome_aux, preco_aux, id_aux, lucro_aux);
		
    		if(sucesso==1)
    		{
				stock_total++;
				
				for (k=0;k<13;k++)
				{
					if(strcmp(nome_aux, stock[k].nome) == 0 || stock[k].id==0)
					{
						stock[k].valor++;
						strcpy(stock[k].nome, nome_aux);
						stock[k].preco=preco_aux;
						stock[k].id=id_aux;
						stock[k].lucro=lucro_aux;
						break;
					}
				}  
  	
    		}
    		else
    		{
    			invalidos++;
    		}
    		total_lidos++;
    	}	
		printf("\nTotal de Pecas lidas do ficheiro pecas.txt: %d tendo havido %d leituras invalidas e %d leituras com sucesso\n", total_lidos, invalidos, stock_total);
	}
}

void le(int p1, int p2, int p3, base_stock *stock, base_stock_rep *stock_rep) //CONCLUIDA
{
	int controlo = 0;

	while(controlo<MAX_PECAS)
	{
		
		if(strcmp(stock[controlo].nome, stock[p1].nome)==0)
		{
			copiar_stock_encomenda(p1, controlo, stock, stock_rep);
			break;
		}
		controlo++;
	}
	
	controlo=0;
	
	while(controlo<MAX_PECAS)
	{
		
		if(strcmp(stock[controlo].nome, stock[p2].nome)==0)
		{
			copiar_stock_encomenda(p2, controlo, stock, stock_rep);
			break;
		}
		controlo++;
	}
	controlo=0;
		
	if(p3>=0 && p3<13)
	{	
		while(controlo<MAX_PECAS)
		{
			
			if(strcmp(stock[controlo].nome, stock[p3].nome)==0)
			{
				copiar_stock_encomenda(p3, controlo, stock, stock_rep);
				break;
			}
			controlo++;
		}
	}
		
	stock[p1].valor = stock[p1].valor - 1;
	stock[p2].valor = stock[p2].valor - 1;
		
	if(p3>=0 && p3<13)	
		stock[p3].valor = stock[p3].valor - 1;
}

    //    /|
    //    _|_

void ver_cat_peca(base_stock *stock) //CONCLUIDA
{
	int i=0;
	float lucro, preco;
	
	
	printf("\n***** Catalogo de Pecas *****\n\n");
	
	do
	{		
		preco = stock[i].preco;
		lucro = stock[i].lucro;
		
		preco = preco + preco*(lucro/100);
		if(stock[i].id!=0)
		{
			printf ("%s - Preco: %.2f€\n", stock[i].nome, preco);
		}
		i++;
	}
	while(i<MAX_PECAS);
	
	printf("\n");
}

    //    /''\
    //     __/
    //    /___

void reparar(base_carros *carro, base_cliente *cliente, base_stock *stock, base_fatura *fatura, base_espera *espera, base_stock_rep *stock_rep) //EM PROCESSAMENTO
{
	int k=1, j=0; //Variaveis de controlo para cliente
	int control1=0, control2=0, control3=0; //Variaveis de controlo para peças
	int verifica=1;
	char ch='n';
	char resp[15];
	int h=0;	
	int i, m, p1, p2, p3;
	int n=0;
	int e=0;
	int con=0; 
	int aux=0; 
	
	unsigned long int n_cont; //Variaveis de escrita	
	char avaria[15]; 
	char m_carro[15];
	char mdl_carro[15];
	int ano_carro;
	
	do
	{
		printf("\nQuer iniciar uma reparacao (s- sim ou n- nao): ");
		scanf("%s", resp);
		if(resp[1]!='\0')
			puts("\nOpcao Invalida\n");
	}
	while((resp[0]!='s' || resp[0]!='S' || resp[0]!='n' || resp[0]!='N') && resp[1]!='\0');
	
	if(resp[0]=='n' || resp[0]=='N')
		return;
	
		while(e<200) // Tem um maximo de 200 clientes em lista de espera
		{
			if(espera[e].contribuinte != 0)
			{
				printf("\nJa há pessoas em lista de espera! Quer comecar por reparar esses (s- repara os da lista de espera; n- inicia uma nova reparacao): ");
				scanf(" %c", &ch);
				break;
			}
			e++;
		}	
		
		e=0;
	
		if((ch == 's' || ch == 'S'))
		{
			while(espera[e].contribuinte >= 0 || e<200)
			{
				if(espera[e].contribuinte != 0)
				{
					break;
				}
				e++;
				aux++;
			}
			strcpy(avaria, espera[aux].avaria);
		}
		
		
		if(ch == 'n' || ch == 'N')
		{
			if((resp[0] == 's' || resp[0] == 'S'))
			{	
				do
				{
					printf("\nIntroduza o numero de contribuinte: ");
					scanf(" %lu", &n_cont);
				}
				while(n_cont<=0);
				
				for(i=0; cliente[i].contribuinte!=0; i++)
				{
					if(n_cont==cliente[i].contribuinte)
					{
						printf("\n%s %s %u %lu\n", cliente[i].primeiro_nome, cliente[i].ultimo_nome, cliente[i].idade, cliente[i].contribuinte);
						j=1;
						break;
					}

				}

				printf("\nAvarias que a SulAuto se encontra autorizada a reparar:\n\tTravoes\n\tEmbraiagem\n\tSuspensao\n\tRefrigeracao\n\tVidro\n");				
				printf("\nIntroduza a avaria (como foi escrita acima): ");
				scanf("%s", avaria);
				
				if(!(strcmp(avaria,"Travoes")==0 || strcmp(avaria,"Embraiagem")==0 || strcmp(avaria,"Suspensao")==0 || strcmp(avaria,"Refrigeracao")==0 || strcmp(avaria,"Vidro")==0  || strcmp(avaria,"travoes")==0 || strcmp(avaria,"embraiagem")==0 || strcmp(avaria,"suspensao")==0 || strcmp(avaria,"refrigeracao")==0 || strcmp(avaria,"vidro")==0))
				{
					printf("\nInfelizmente nao estamos habilitados para resolver essa avaria. Pedimos desculpa pelo incomodo causado.\n\n");
					return;
				}
				else
					k=0;
				
				printf("\nIntroduza a marca do carro: ");
				scanf("%s", m_carro);
				printf("Introduza o modelo do carro: ");
				scanf("%s", mdl_carro);
				printf("Introduza o ano do carro: ");
				scanf(" %d", &ano_carro);
				
				verifica = verifica_carro(m_carro, mdl_carro, ano_carro, carro);
				
				if(verifica==0)
				{
					printf("\nInfelizmente nao estamos habilitados para resolver avarias neste carro. Pedimos desculpa pelo incomodo causado.\n\n");		
					return;
				}
			}

		}
		
		if(j==0 && k==0)
		{
			printf("\nInfelizmente ainda nao se encontra na nossa base de dados, vamos iniciar um novo registo.\n");			
			printf("\nIntroduza o primeiro nome: ");
			scanf("%s", cliente[i].primeiro_nome);
			printf("Introduza o apelido: ");
			scanf("%s", cliente[i].ultimo_nome);
			printf("Introduza o idade: ");
			scanf(" %d", &cliente[i].idade);
			cliente[i].contribuinte = n_cont;
			
			printf("\n%s %s %u %lu\n", cliente[i].primeiro_nome, cliente[i].ultimo_nome, cliente[i].idade, cliente[i].contribuinte);
			//printf("%d\n", i);
		}
	
	if(strcmp(avaria,"Travoes")==0  || strcmp(avaria,"travoes")==0)
	{
		for(m=0; m<MAX_PECAS; m++)
		{
			if(strcmp(stock[m].nome, "Pastilhas")==0)
			{
				if(stock[m].valor > 0)
				{
					control1 = 1;
					p1 = m;
				}
			}
			if(strcmp(stock[m].nome, "Discos")==0)
			{
				if(stock[m].valor > 0)
				{
					control2 = 1;
					p2 = m;
				}
			}
		}
		
		if(strcmp(avaria,"travoes")==0)
		{
			strcpy(avaria, "Travoes");
		}
		
		if(control1 && control2 && ((ch == 'S' || ch == 's') && (resp[0] == 's' || resp[0] == 'S')))
		{
			for(i=0; cliente[i].contribuinte!=0; i++)
			{
				if(espera[aux].contribuinte==cliente[i].contribuinte)
				{
					printf("\n%s %s %u %lu\n\n", cliente[i].primeiro_nome, cliente[i].ultimo_nome, cliente[i].idade, cliente[i].contribuinte);
					break;
				}
			}
	
			strcpy(m_carro, espera[aux].marca);
			strcpy(mdl_carro, espera[aux].modelo);		

			while(con<MAX_CARROS)
			{	
				if((strcmp(carro[con].marca, m_carro)==0) && (strcmp(carro[con].modelo, mdl_carro)==0))
					break;
				else
				con++;
			}

			p3=13;
			
			copiar_fatura(i, con, p1, p2, p3, avaria, cliente, stock, carro, fatura);
						
			le(p1, p2, p3, stock, stock_rep);
			
			apagar_linha(espera, aux);				
		}
		else
		if(control1 && control2 && ((ch == 'n' || ch == 'N') && (resp[0] == 's' || resp[0] == 'S')))
		{
			p3=13;
	
			while(con<MAX_CARROS)
			{	
				if((strcmp(carro[con].marca, m_carro)==0) && (strcmp(carro[con].modelo, mdl_carro)==0))
					break;
				else
				con++;
			}
			
			copiar_fatura(i, con, p1, p2, p3, avaria, cliente, stock, carro, fatura);
			
			le(p1, p2, p3, stock, stock_rep);

		}
		else
		{

			if((control1==0 || control2==0) && (ch=='s' || ch=='S'))
			{
				printf("\nContinuamos a nao ter stock, pedimos imensas desculpas pela demora!\n");
				return;
			}

			
			printf("\nInfelizmente nao temos as pecas necessarias para o arranjo, ficara em lista de espera e quando tivermos pecas sera arranjado. Pedimos desculpas pelo incomodo.\n");
	
				while(espera[h].contribuinte!=0)
				{
					h++;
				}
				
				while(con<MAX_CARROS)
				{	
					if((strcmp(carro[con].marca, m_carro)==0) && (strcmp(carro[con].modelo, mdl_carro)==0))
						break;
					else
					con++;
				}
				
			if(h>=200)
				printf("Infelizmente nao podemos aceitar o seu veiculo por falta de espaco");
			else
			{
				strcpy(espera[h].nome, cliente[i].primeiro_nome);
				strcpy(espera[h].apelido, cliente[i].ultimo_nome);
				espera[h].contribuinte = cliente[i].contribuinte;
				strcpy(espera[h].marca, carro[con].marca);
				strcpy(espera[h].modelo, carro[con].modelo);
				strcpy(espera[h].avaria, avaria);
			}
		}
	}
	
	if(strcmp(avaria,"Embraiagem")==0  || strcmp(avaria,"embraiagem")==0)
	{
		for(m=0; m<MAX_PECAS; m++)
		{
			if(strcmp(stock[m].nome, "Rolamento")==0)
			{
				if(stock[m].valor > 0)
				{
					control1 = 1;
					p1 = m;
				}
			}
			if(strcmp(stock[m].nome, "Disco")==0)
			{
				if(stock[m].valor > 0)
				{
					control2 = 1;
					p2 = m;
				}
			}
			if(strcmp(stock[m].nome, "Prensa")==0)
			{
				if(stock[m].valor > 0)
				{
					control3 = 1;
					p3 = m;
				}
			}
		}
		
		if(strcmp(avaria,"embraiagem")==0)
		{
			strcpy(avaria, "Embraiagem");
		}
		
		if(control1 && control2 && control3 && ((ch == 's' || ch == 'S') && (resp[0] == 's' || resp[0] == 'S')))
		{			
			for(i=0; cliente[i].contribuinte!=0; i++)
			{
				if(espera[aux].contribuinte==cliente[i].contribuinte)
				{
					printf("\n%s %s %u %lu\n\n", cliente[i].primeiro_nome, cliente[i].ultimo_nome, cliente[i].idade, cliente[i].contribuinte);
					break;
				}

			}
		
		strcpy(m_carro, espera[aux].marca);
		strcpy(mdl_carro, espera[aux].modelo);	
		
			while(con<MAX_CARROS)
			{	
				if((strcmp(carro[con].marca, m_carro)==0) && (strcmp(carro[con].modelo, mdl_carro)==0))
					break;
				else
				con++;
			}
			
		copiar_fatura(i, con, p1, p2, p3, avaria, cliente, stock, carro, fatura);	
			
		le(p1, p2, p3, stock, stock_rep);	
		
		apagar_linha(espera, aux);
		}
		else
		if(control1 && control2 && control3 && ((ch == 'n' || ch == 'N') || (resp[0] == 's' || resp[0] == 'S')))
		{
			while(con<MAX_CARROS)
			{	
				if((strcmp(carro[con].marca, m_carro)==0) && (strcmp(carro[con].modelo, mdl_carro)==0))
					break;
				else
				con++;
			}
			
		copiar_fatura(i, con, p1, p2, p3, avaria, cliente, stock, carro, fatura);	
			
		le(p1, p2, p3, stock, stock_rep);	
				
		}
		else
		{
			if((control1==0 || control2==0) && (ch=='s' || ch=='S'))
			{
				printf("\nContinuamos a nao ter stock, pedimos imensas desculpas pela demora!\n");
				return;
			}

			
			printf("\nInfelizmente nao temos as pecas necessarias para o arranjo, ficara em lista de espera e quando tivermos pecas sera arranjado. Pedimos desculpas pelo incomodo.\n");

				while(con<MAX_CARROS)
				{	
					if((strcmp(carro[con].marca, m_carro)==0) && (strcmp(carro[con].modelo, mdl_carro)==0))
						break;
					else
					con++;
				}
			
			if(h>=200)
				printf("Infelizmente nao podemos aceitar o seu veiculo por falta de espaco");
			else
			{
				strcpy(espera[h].nome, cliente[i].primeiro_nome);
				strcpy(espera[h].apelido, cliente[i].ultimo_nome);
				espera[h].contribuinte = cliente[i].contribuinte;
				strcpy(espera[h].marca, carro[con].marca);
				strcpy(espera[h].modelo, carro[con].modelo);
				strcpy(espera[h].avaria, avaria);
			}
		}			
	}
	
	if(strcmp(avaria,"Suspensao")==0 || strcmp(avaria,"suspensao")==0)
	{
		for(m=0; m<MAX_PECAS; m++)
		{
			if(strcmp(stock[m].nome, "Triangulos")==0)
			{
				if(stock[m].valor > 0)
				{
					control1 = 1;
					p1 = m;
				}
			}
			if(strcmp(stock[m].nome, "Topos")==0)
			{
				if(stock[m].valor > 0)
				{
					control2 = 1;
					p2 = m;
				}
			}
			if(strcmp(stock[m].nome, "Amortecedor")==0)
			{
				if(stock[m].valor > 0)
				{
					control3 = 1;
					p3 = m;
				}
			}
		}
		
		if(strcmp(avaria,"suspensao")==0)
		{
			strcpy(avaria, "Suspensao");
		}
		
		if(control1 && control2 && control3 && ((ch == 's' || ch == 'S') && (resp[0] == 's' || resp[0] == 'S')))
		{	
			for(i=0; cliente[i].contribuinte!=0; i++)
			{
				if(espera[aux].contribuinte==cliente[i].contribuinte)
				{
					printf("\n%s %s %u %lu\n\n", cliente[i].primeiro_nome, cliente[i].ultimo_nome, cliente[i].idade, cliente[i].contribuinte);
					break;
				}

			}
		
		strcpy(m_carro, espera[aux].marca);
		strcpy(mdl_carro, espera[aux].modelo);
		
			while(con<MAX_CARROS)
			{	
				if((strcmp(carro[con].marca, m_carro)==0) && (strcmp(carro[con].modelo, mdl_carro)==0))
					break;
				else
				con++;
			}
			
		copiar_fatura(i, con, p1, p2, p3, avaria, cliente, stock, carro, fatura);		
			
		le(p1, p2, p3, stock, stock_rep);	

		apagar_linha(espera, aux);	
		}
		else
		if(control1 && control2 && control3 && ((ch == 'n' || ch == 'N') && (resp[0] == 's' || resp[0] == 'S')))
		{
			while(con<MAX_CARROS)
			{	
				if((strcmp(carro[con].marca, m_carro)==0) && (strcmp(carro[con].modelo, mdl_carro)==0))
					break;
				else
				con++;
			}
			
		copiar_fatura(i, con, p1, p2, p3, avaria, cliente, stock, carro, fatura);
			
		le(p1, p2, p3, stock, stock_rep);	
							
		}
		else
		{
			if((control1==0 || control2==0) && (ch=='s' || ch=='S'))
			{
				printf("\nContinuamos a nao ter stock, pedimos imensas desculpas pela demora!\n");
				return;
			}

			
			printf("\nInfelizmente nao temos as pecas necessarias para o arranjo, ficara em lista de espera e quando tivermos pecas sera arranjado. Pedimos desculpas pelo incomodo.\n");

				while(con<MAX_CARROS)
				{	
					if((strcmp(carro[con].marca, m_carro)==0) && (strcmp(carro[con].modelo, mdl_carro)==0))
						break;
					else
					con++;
				}
			
			if(h>=200)
				printf("Infelizmente nao podemos aceitar o seu veiculo por falta de espaco");
			else
			{
				strcpy(espera[h].nome, cliente[i].primeiro_nome);
				strcpy(espera[h].apelido, cliente[i].ultimo_nome);
				espera[h].contribuinte = cliente[i].contribuinte;
				strcpy(espera[h].marca, carro[con].marca);
				strcpy(espera[h].modelo, carro[con].modelo);
				strcpy(espera[h].avaria, avaria);
			}
		}		
	}
	
	if(strcmp(avaria,"Refrigeracao")==0 || strcmp(avaria,"refrigeracao")==0)
	{
		for(m=0; m<MAX_PECAS; m++)
		{
			if(strcmp(stock[m].nome, "Radiador")==0)
			{
				if(stock[m].valor > 0)
				{
					control1 = 1;
					p1 = m;
				}
			}
			if(strcmp(stock[m].nome, "Bomba")==0)
			{
				if(stock[m].valor > 0)
				{
					control2 = 1;
					p2 = m;
				}
			}
			if(strcmp(stock[m].nome, "Liquido")==0)
			{
				if(stock[m].valor > 0)
				{
					control3 = 1;
					p3 = m;
				}
			}
		}
		
		if(strcmp(avaria,"refrigeracao")==0)
		{
			strcpy(avaria, "Refrigeracao");
		}
		
		if(control1 && control2 && control3 && ((ch == 's' || ch == 'S') && (resp[0] == 's' || resp[0] == 'S')))
		{			
			for(i=0; cliente[i].contribuinte!=0; i++)
			{
				if(espera[aux].contribuinte==cliente[i].contribuinte)
				{
					printf("\n%s %s %u %lu\n\n", cliente[i].primeiro_nome, cliente[i].ultimo_nome, cliente[i].idade, cliente[i].contribuinte);
					break;
				}

			}
		
		strcpy(m_carro, espera[aux].marca);
		strcpy(mdl_carro, espera[aux].modelo);
		
			while(con<MAX_CARROS)
			{	
				if((strcmp(carro[con].marca, m_carro)==0) && (strcmp(carro[con].modelo, mdl_carro)==0))
					break;
				else
				con++;
			}
			
		copiar_fatura(i, con, p1, p2, p3, avaria, cliente, stock, carro, fatura);	
			
		le(p1, p2, p3, stock, stock_rep);	
		
		apagar_linha(espera, aux);		
		}
		else
		if(control1 && control2 && control3 && ((ch == 'n' || ch == 'N') || (resp[0] == 's' || resp[0] == 'S')))
		{		
			while(con<MAX_CARROS)
			{	
				if((strcmp(carro[con].marca, m_carro)==0) && (strcmp(carro[con].modelo, mdl_carro)==0))
					break;
				else
				con++;
			}
			
		copiar_fatura(i, con, p1, p2, p3, avaria, cliente, stock, carro, fatura);		
			
		le(p1, p2, p3, stock, stock_rep);	
		
		}
		else
		{
			if((control1==0 || control2==0) && (ch=='s' || ch=='S'))
			{
				printf("\nContinuamos a nao ter stock, pedimos imensas desculpas pela demora!\n");
				return;
			}

			
			printf("\nInfelizmente nao temos as pecas necessarias para o arranjo, ficara em lista de espera e quando tivermos pecas sera arranjado. Pedimos desculpas pelo incomodo.\n");

				while(con<MAX_CARROS)
				{	
					if((strcmp(carro[con].marca, m_carro)==0) && (strcmp(carro[con].modelo, mdl_carro)==0))
						break;
					else
					con++;
				}
			
			if(h>=200)
				printf("Infelizmente nao podemos aceitar o seu veiculo por falta de espaco");
			else
			{
				strcpy(espera[h].nome, cliente[i].primeiro_nome);
				strcpy(espera[h].apelido, cliente[i].ultimo_nome);
				espera[h].contribuinte = cliente[i].contribuinte;
				strcpy(espera[h].marca, carro[con].marca);
				strcpy(espera[h].modelo, carro[con].modelo);
				strcpy(espera[h].avaria, avaria);
			}
		}
	}
	
	if(strcmp(avaria,"Vidro")==0 || strcmp(avaria,"vidro")==0)
	{
		for(m=0; m<MAX_PECAS; m++)
		{
			if(strcmp(stock[m].nome, "Elevador")==0)
			{
				if(stock[m].valor > 0)
				{
					control1 = 1;
					p1 = m;
				}
			}
			if(strcmp(stock[m].nome, "Botoes")==0)
			{
				if(stock[m].valor > 0)
				{
					control2 = 1;
					p2 = m;
				}
			}
		}
		
		if(strcmp(avaria,"vidro")==0)
		{
			strcpy(avaria, "Vidro");
		}

		if(control1 && control2 && ((ch == 'S' || ch == 's') && (resp[0] == 's' || resp[0] == 'S')))
		{
			for(i=0; cliente[i].contribuinte!=0; i++)
			{
				if(espera[aux].contribuinte==cliente[i].contribuinte)
				{
					printf("\n%s %s %u %lu\n\n", cliente[i].primeiro_nome, cliente[i].ultimo_nome, cliente[i].idade, cliente[i].contribuinte);
					break;
				}
			}
			strcpy(m_carro, espera[aux].marca);
			strcpy(mdl_carro, espera[aux].modelo);		

			while(con<MAX_CARROS)
			{	
				if((strcmp(carro[con].marca, m_carro)==0) && (strcmp(carro[con].modelo, mdl_carro)==0))
					break;
				else
				con++;
			}

			p3=13;
			
			copiar_fatura(i, con, p1, p2, p3, avaria, cliente, stock, carro, fatura);
						
			le(p1, p2, p3, stock, stock_rep);
			
			apagar_linha(espera, aux);			
		}
		else
		if(control1 && control2 && ((ch == 'n' || ch == 'N') && (resp[0] == 's' || resp[0] == 'S')))
		{
			p3=13;
	
			while(con<MAX_CARROS)
			{	
				if((strcmp(carro[con].marca, m_carro)==0) && (strcmp(carro[con].modelo, mdl_carro)==0))
					break;
				else
				con++;
			}
			
			copiar_fatura(i, con, p1, p2, p3, avaria, cliente, stock, carro, fatura);
			
			le(p1, p2, p3, stock, stock_rep);
	
		}
		else
		{
			if((control1==0 || control2==0) && (ch=='s' || ch=='S'))
			{
				printf("\nContinuamos a nao ter stock, pedimos imensas desculpas pela demora!\n");
				return;
			}

			
			printf("\nInfelizmente nao temos as pecas necessarias para o arranjo, ficara em lista de espera e quando tivermos pecas sera arranjado. Pedimos desculpas pelo incomodo.\n");
	
			while(espera[h].contribuinte!=0)
			{
				h++;
			}
			
			while(con<MAX_CARROS)
			{	
				if((strcmp(carro[con].marca, m_carro)==0) && (strcmp(carro[con].modelo, mdl_carro)==0))
					break;
				else
				con++;
			}
			
			if(h>=200)
				printf("Infelizmente nao podemos aceitar o seu veiculo por falta de espaco");
			else
			{
				strcpy(espera[h].nome, cliente[i].primeiro_nome);
				strcpy(espera[h].apelido, cliente[i].ultimo_nome);
				espera[h].contribuinte = cliente[i].contribuinte;
				strcpy(espera[h].marca, carro[con].marca);
				strcpy(espera[h].modelo, carro[con].modelo);
				strcpy(espera[h].avaria, avaria);
			}
		}
	}
}

	//     __
	//    |  |	
	// 	    <
	//	  |__|

void hist_cliente(base_fatura *fatura) //CONCLUIDA
{
	unsigned long int n_cont;
	int j=0;
	int i=0;
	int k=0;
	float preco_total=0;
	char nome[20];
	char apelido[20];
	long unsigned int contr; 
	float preco;
	const time_t timer = time(NULL); //Vem da biblio time.h e serva para podermos colocar o dia e a hora no ecrã	
	
	printf("Introduza o numero de contribuinte: ");
	scanf(" %lu", &n_cont);
	
	printf("\n");
	
	while(fatura[i].contribuinte!=0)
	{
		if(fatura[i].contribuinte==n_cont)
		{
			printf("%3s %3s %3lu %3s %s %s %3.2f\n", fatura[i].primeiro_nome, fatura[i].apelido, fatura[i].contribuinte, fatura[i].marca, fatura[i].modelo, fatura[i].avaria, fatura[i].preco);
			preco = fatura[i].preco;
			preco_total = preco + preco_total;
			strcpy(nome, fatura[i].primeiro_nome);
			strcpy(apelido, fatura[i].apelido);
			contr = fatura[i].contribuinte;
			i++;
		}
		else
			i++;
	}
	
	for(i=0; i<2000; i++)
	{
		if(fatura[i].contribuinte==n_cont)
			k++;
	}
	
	if(k==0)
	{
		strcpy(nome, "0");
		strcpy(apelido, "0");
		contr = 0;
		printf("Nao existe historico de reparacoes deste cliente.\n");
	}	
	
	printf("\n\n***********HISTORICO**************\n");
	printf("*            SulAuto             *\n");
	printf("*                                *\n");
	printf(" Nome: %s %s\n",  nome, apelido);
	printf(" NIF:  %lu\n", contr);
	printf(" Data: %s", ctime(&timer));
	printf("**********************************\n");
	printf("**********************************\n");
	printf("**********************************\n");				
	printf("*                                *\n");
	printf(" Total: %.2f€\n", preco_total);
	printf("*                                *\n");
	printf("*                                *\n");
	printf("***********VOLTE SEMPRE***********\n");
	printf("*                                *\n");
	printf("**********************************\n");
}

	//     //||
	//    //_||
	//       ||

void ver_stock(base_carros *carro, base_cliente *cliente, base_stock *stock) //CONCLUIDA
{
	int i=0;
	int j=1;
	
	printf("\n***** Stock de Pecas *****\n\n");
	
	do
	{		
		if(stock[i].id==j)
		{
			printf("ID: %3d - %3s - Em Stock: %d - Preco: %.2f€ - %c de Lucro: %.0f%c\n", stock[i].id, stock[i].nome, stock[i].valor, stock[i].preco, 37, stock[i].lucro, 37);
			j++;
			i=0;
		}
		else
			i++;
		
		if(i==12 && stock[i].id!=j)
		{
			j++;
			i=0;
		}
	}
	while(i<MAX_PECAS && j<=MAX_PECAS);
	
	printf("\n");
}

	//      ___ 
	//    ||___
	//     ___||

void alterar_peca(base_carros *carro, base_cliente *cliente, base_stock *stock, base_stock_rep *stock_rep) //CONCLUIDA
{
	unsigned int id_esc; 
	int i, k, novo_lucro;
	int n=0;
	int p=1;
	int h=0;
	int j=1;
	int l=0;
	int m=0;
	char ch;

	do
	{	
		printf("\n      0 - Retroceder\n\n");
		do
		{		
			if(stock[n].id==p)
			{
				printf("ID: %3d - %3s - %c de Lucro: %.0f%c\n", stock[n].id, stock[n].nome, 37, stock[n].lucro, 37);
				p++;
				n=0;
			}
			else
				n++;
			
			if(n==12 && stock[n].id!=p)
			{
				p++;
				n=0;
			}
		}
		while(n<MAX_PECAS && p<=MAX_PECAS);
		
		p=0;
		n=0;
		//l=0;

		do
		{
			printf("\nIntroduza o id da peca que quer alterar (0 - 13): ");
			scanf(" %d", &id_esc);
		}
		while(id_esc<0 || id_esc>MAX_PECAS);
		
		if(id_esc==0)
			return;
		
		while(id_esc!=stock[l].id)
		{
			l++;
		}
		
		printf("\nID: %3d - %3s - Em Stock: %d - Preco: %.2f€ - %c de Lucro: %.0f%c\n", stock[l].id, stock[l].nome, stock[l].valor, stock[l].preco, 37, stock[l].lucro, 37);
		
		do
		{
			printf("\nIntroduza o novo valor de lucro (sem casa decimais, valor de 0 - 100 sem o simbolo de %c): ", 37);
			scanf(" %d", &novo_lucro);
		}
		while(novo_lucro<0 || novo_lucro>100);
		
		printf("\n");
		  
	    for(i=0; i<MAX_PECAS; i++) 
	    {
			if(stock[i].id==id_esc)
				stock[i].lucro=novo_lucro;
	    }
		
		printf("\n****Stock Alterado****\n\n");
		do
		{
			if(stock[h].id!=0 && stock[h].id==j)
			{
				printf("ID: %3d - %3s - Em Stock: %d - Preco: %.2f€ - %c de Lucro: %.0f%c\n", stock[h].id, stock[h].nome, stock[h].valor, stock[h].preco, 37, stock[h].lucro, 37);
				j++;
				h=0;
			}
			else
				h++;
		}
		while(h<MAX_PECAS && j<=MAX_PECAS);
		
		h=0;
		j=1;
			
		printf("\n\nQuer fazer mais alguma alteracao(n- nao): ");
		scanf(" %c", &ch);
		if(ch=='N' || ch=='n')
			return;
	}
	while(ch!='n' || ch!='N');
}

	//      ___ 
	//    ||___
	//    ||___||

void repor_stock(base_stock_rep *stock_rep, base_stock *stock) //CONCLUIDA
{
	int i=0;
	int j=0;
	int k=0;
	int l=0;
	char ch;
	char aux[200];
	FILE *db; 
	FILE *fp;
	char nome_aux[20];
	float preco_aux, lucro_aux;
	int id_aux;
	
	printf("Que ficheiro quer abrir (R-Reposicoes ou E-Encomendas): ");
	scanf(" %c", &ch);
	
	if(ch=='E' || ch=='e')
		fp=fopen("encomendas.txt", "r");
		
	if((ch=='E' || ch=='e') && fp!=NULL)
	{	
		while(fgets(aux, sizeof(aux), fp) != NULL)
		{
    		sscanf(aux,"%s %f %d %f", nome_aux, &preco_aux, &id_aux, &lucro_aux);
			for (l=0;l<13;l++)
			{
				if(strcmp(nome_aux, stock[l].nome) == 0 || stock[l].id==0)
				{
					stock[l].valor++;
					strcpy(stock[l].nome, nome_aux);
					stock[l].preco=preco_aux;
					stock[l].id=id_aux;
					if(stock[l].lucro == 0)
						stock[l].lucro = lucro_aux;
						
					break;
				}
			} 
		}
	printf("\nEncomenda recebida com sucesso!\n");
	fclose(fp);
	remove("encomendas.txt");	
	}

	if((ch=='E' || ch=='e') && fp==NULL)
	{	
		printf("\nNao recebeu nenhuma encomenda nova!\n");
	}
	
	if(ch=='R' || ch=='r')
		db=fopen("reposicao.txt", "r+");
	
	if((ch=='R' || ch=='r') && db!=NULL)
	{
		while(fgets(aux, sizeof(aux), db) != NULL)
		{
    		sscanf(aux,"%s %f %d %f", nome_aux, &preco_aux, &id_aux, &lucro_aux);

			for (k=0;k<13;k++)
			{
				if(strcmp(nome_aux, stock[k].nome) == 0 || stock[k].id==0)
				{
					stock[k].valor++;
					strcpy(stock[k].nome, nome_aux);
					stock[k].preco=preco_aux;
					stock[k].id=id_aux;
					break;
				}
			}  
		}
		printf("\nStock reposto com sucesso!\n");	
		fclose(db);
	}

	if((ch=='R'|| ch=='r') && db==NULL)
	{
		printf("\nNao tem nada para repor!\n");	
	}
}

	//    _____ 
	//     ___//
	//       //

void estatistica(base_fatura *fatura) //CONCLUIDA
{
	unsigned long int n_cont;
	int i=0;
	int j=0;
	int k=0;
	int l, m;
	int valor[4];
	int t1=0, t2=0, t3=0, t4=0, t5=0;
	float val_lucro=0, val_preco=0, val_carros=0, preco=0, lucro=0;
	
	while(fatura[i].contribuinte!=0)
	{
		lucro = fatura[i].lucro;
		val_lucro = lucro + val_lucro;
		preco = fatura[i].preco;
		val_preco = preco + val_preco;
		i++;
	}
	
	printf("\n*****Histograma de Reparacoes*****");
	
	while(fatura[j].contribuinte!=0)
	{
		if(strcmp(fatura[j].avaria, "Travoes")==0)
			t1++;
		if(strcmp(fatura[j].avaria, "Embraiagem")==0)
			t2++;
		if(strcmp(fatura[j].avaria, "Refrigeracao")==0)
			t3++;
		if(strcmp(fatura[j].avaria, "Suspensao")==0)
			t4++;
		if(strcmp(fatura[j].avaria, "Vidro")==0)
			t5++;
		j++;
	}
	
	valor[0]=t1;
	valor[1]=t2;
	valor[2]=t3;
	valor[3]=t4;
	valor[4]=t5;
	
	printf("\n\nPor cada 2 reparacoes sera escrito *\n\n");
	
	for(l=0; l<5; l++)
	{	
		if(l==0)
			printf("Travoes      - %d Reparacoes - ", valor[0]);
		if(l==1)
			printf("Embraiagem   - %d Reparacoes - ", valor[1]);
		if(l==2)
			printf("Refrigeracao - %d Reparacoes - ", valor[2]);
		if(l==3)
			printf("Suspensao    - %d Reparacoes - ", valor[3]);
		if(l==4)
			printf("Vidro        - %d Reparacoes - ", valor[4]);	
			
		for(m=1; m<=valor[l]; m++)
		{
			if(m%2==0)
				printf("*");
		}
		printf("\n");
	}
		
	printf("\nO total de carros reparados foi de %d.\n", i);
	printf("O lucro total foi de %.2f euros.\n", val_lucro);
	printf("O preco total pago foi de %.2f euros.\n", val_preco-val_lucro);
}

	//      ___ 
	//    ||___||
	//    ||___||

void sair(base_carros *carro, base_cliente *cliente, base_stock *stock, base_fatura *fatura, base_espera *espera, base_stock_rep *stock_rep) //CONCLUIDA
{
	int i=0;
	int j=0;
	int k=0;
	int l=0;
	int m=0;
	int contar=1;
	FILE *db, *bd, *fp, *pf, *rp;
	
	if(stock_rep[0].id_rep!=0)
	{
		rp = fopen("encomendas.txt", "a+");
		while(m<MAX_PECAS) //ALTERAR
		{
			if(stock_rep[m].id_rep != 0)
				fprintf(rp,"%s %.2f %d %.0f\n", stock_rep[m].n_rep, stock_rep[m].p_rep, stock_rep[m].id_rep, stock_rep[m].l_rep);
			m++;		
		}
		fclose(rp);
	}
	
	pf = fopen("pecas.txt", "w+");
	while(l<MAX_PECAS)
	{
		if(stock[l].id!=0)
			while(contar<=stock[l].valor)
			{
				fprintf(pf,"%s %.2f %d %.0f\n", stock[l].nome, stock[l].preco, stock[l].id, stock[l].lucro);
				contar++;
			}
		l++;
		contar=1;
	}
	fclose(pf);
	
	fp = fopen("historico.txt", "w+");
	while(fatura[k].contribuinte!=0 && k<2000)
	{
		if(fatura[k].contribuinte==0)
			k++;
		else
		{
		fprintf(fp, "%s %s %lu %s %s %s %.2f %.2f\n", fatura[k].primeiro_nome, fatura[k].apelido, fatura[k].contribuinte, fatura[k].marca, fatura[k].modelo, fatura[k].avaria, fatura[k].preco, fatura[k].lucro);
		k++;
		}
	}	
	fclose(fp);
	
	db = fopen("lista_espera.txt", "w+");
	while(j<200)
	{
		if(espera[j].contribuinte!=0)
			fprintf(db,"%s %s %lu %s %s %s\n", espera[j].nome, espera[j].apelido, espera[j].contribuinte, espera[j].marca, espera[j].modelo, espera[j].avaria);
		j++;
	}
	fclose(db);
	
	bd = fopen("clientes.txt", "w+");
	while(cliente[i].contribuinte!=0)
	{
		fprintf(bd,"%s %s %d %lu\n", cliente[i].primeiro_nome, cliente[i].ultimo_nome, cliente[i].idade, cliente[i].contribuinte);
		i++;
	}
	fclose(bd);	

exit(1);
}      
     
	//      __    __     ____    __            ___
	//     /  \  /  \   |__     /  \   |   |  |___
	//    |    ||    |  |____  |    |  |___|   ___|  

void menu_admin(base_carros *carro, base_cliente *cliente, base_stock *stock, base_fatura *fatura, base_espera *espera, base_stock_rep *stock_rep) //CONCLUIDA
{
	char pal_pass_guard[10]="admin", utilizador_guard[10]="admin", utilizador[10], pal_pass[10];
	char esc[20];

	printf("\nEscreva o nome de utilizador: ");
	scanf("%s", utilizador);
	printf("\nEscreva a palavra passe: ");
	scanf("%s", pal_pass);
	
	if(strcmp(utilizador_guard,utilizador)==0 && strcmp(pal_pass_guard,pal_pass)==0)
	{	
		do
		{
			do
			{
				printf("\n******** Menu Administrador ********\n\n");
				printf("\n1 - Ver Stock de Pecas\n2 - Alterar Pecas\n3 - Repor Stock de Pecas\n4 - Estatistica\nS - Sair (Volta ao Menu Cliente)");
				printf("\n\nEscolha uma opcao: ");
				scanf(" %s", esc);
				if(esc[1]!='\0')
					puts("Opcao Invalida\n");
			}
			while(esc[1]!='\0');
			
			switch(esc[0])
			{
			case '1': ver_stock(carro, cliente, stock); break;
			case '2': alterar_peca(carro, cliente, stock, stock_rep); break;
			case '3': repor_stock(stock_rep, stock); break;
			case '4': estatistica(fatura); break;
			case 's':
			case 'S': return; break;
			default: puts("Opcao Invalida\n"); break;
			}
		} 
		while (esc[0] != ( '1' || '2' || '3' || 's' || 'S' || '4'));		
	}
	else
		printf("\n!Nao tem autorizacao para entrar no modo administrador!\n\n");
}

void menu(base_carros *carro, base_cliente *cliente, base_stock *stock, base_fatura *fatura, base_espera *espera, base_stock_rep *stock_rep) //CONCLUIDA
{
	char esc[20];	
	
	printf("\n******** Oficina - SulAuto ********\n\n");
	
	do
	{
		do
		{
			printf("\n******** Menu Cliente ********\n\n");
			printf("\n1 - Ver catalogo de Pecas\n2 - Reparar\n3 - Historico do Cliente\nA - Administrador\nS - Sair");
			printf("\n\nEscolha uma opcao: ");
			scanf("%s", esc);
			if(esc[1]!='\0')
				puts("Opcao Invalida\n");
		}
		while(esc[1]!='\0');
		
		switch(esc[0])
		{
		case '1': ver_cat_peca(stock); break;
		case '2': reparar(carro, cliente, stock, fatura, espera, stock_rep); break;
		case '3': hist_cliente(fatura); break;
		case 'a':
		case 'A': menu_admin(carro, cliente, stock, fatura, espera, stock_rep); break;
		case 's':
		case 'S': sair(carro, cliente, stock, fatura, espera, stock_rep); break;
		default: puts("Opcao Invalida\n"); break;
		}
	}
	while(esc[0] != ('1' || '2' || '3' || 'a' || 'A' || 's' || 'S'));
}

	//       __    __      __          __
	//      /  \  /  \    /__\   |    /  \
	//     |    ||    |  |    |  |   |    |

main(int argc, char *argv[])  //CONCLUIDA
{
	base_carros carro[20];
	base_cliente cliente[2000];
	base_stock stock[14];
	base_fatura fatura[2000];
	base_espera espera[200];
	base_stock_rep stock_rep[2000];
	
	FILE *dp;
	FILE *db;
	
	int i=0;
	int j=0;
	int k=0;
	int l=0;
	int m=0;
	int control1=1;
	int control2=1;
	int control3=1;
	char nome[20];
	char nome1[15]= "historico.txt";
	char nome2[20]= "lista_espera.txt";
	
	dp = fopen(nome1, "a+");
	db = fopen(nome2, "a+");

	fclose(dp);
	fclose(db);
	
	if(argc==4)
	{
		if(strcmp(argv[1], "clientes.txt")==0)
		{
			ler_ficheiro(argv[1], carro, cliente, stock);
		}
		else
		{
			printf("\nA ordem de introducao dos nomes de ficheiros e: clientes.txt carros.txt pecas.txt\n\n");
			exit(1);
		}

		if(strcmp(argv[2], "carros.txt")==0)
		{
			ler_ficheiro(argv[2], carro, cliente, stock);
		}
		else
		{
			printf("\nA ordem de introducao dos nomes de ficheiros e: clientes.txt carros.txt pecas.txt\n\n");
			exit(1);
		}

		if(strcmp(argv[3], "pecas.txt")==0)
		{
			ler_ficheiro(argv[3], carro, cliente, stock);
		}
		else
		{
			printf("\nA ordem de introducao dos nomes de ficheiros e: clientes.txt carros.txt pecas.txt\n\n");
			exit(1);
		}
	}
	else
	if(argc==1)
	{
		while(control1==1 || control2==1 || control3==1)
		{
			do
			{
				printf("\nIntroduza o nome do ficheiro (com extensao) que quer abrir: ");
				scanf(" %s", nome);
			}
			while(!((strcmp(nome,"carros.txt")==0) || (strcmp(nome,"pecas.txt")==0) || (strcmp(nome, "clientes.txt")==0)));
			
			if(strcmp(nome, "carros.txt")==0 && control1==1)
			{
				control1=0;
				ler_ficheiro(nome, carro, cliente, stock);
			}
			
			if(strcmp(nome, "clientes.txt")==0 && control2==1)
			{
				control2=0;
				ler_ficheiro(nome, carro, cliente, stock);
			}
			
			if(strcmp(nome, "pecas.txt")==0 && control3==1)
			{
				control3=0;
				ler_ficheiro(nome, carro, cliente, stock);
				
				while(k<MAX_PECAS)
				{
					if(stock[k].id !=0)
					{
						//printf("\n%d - %s %.2f %d %.0f", stock[k].valor, stock[k].nome, stock[k].preco, stock[k].id, stock[k].lucro);
						k++;
					}
					else
						k++;
				}
			}
		}
	}
	else
	if(argc!=1 || argc!=4)
	{
		printf("Erro na introducao dos ficheiros.\n");
		exit(1);
	}
	
	dp = fopen(nome1, "r+");

	while(fscanf(dp,"%s %s %lu %s %s %s %f %f", fatura[l].primeiro_nome, fatura[l].apelido, &fatura[l].contribuinte, fatura[l].marca, fatura[l].modelo, fatura[l].avaria, &fatura[l].preco, &fatura[l].lucro)!=EOF)
	{
		//printf("%s %s %lu %s %s %s %f %f\n", fatura[l].primeiro_nome, fatura[l].apelido, fatura[l].contribuinte, fatura[l].marca, fatura[l].modelo, fatura[l].avaria, fatura[l].preco, fatura[l].lucro);
		l++;
	}
	
	fclose(dp);
	
	db = fopen(nome2, "r+");	

	while(fscanf(db,"%s %s %lu %s %s %s\n", espera[j].nome, espera[j].apelido, &espera[j].contribuinte, espera[j].marca, espera[j].modelo, espera[j].avaria)!=EOF)
	{				
		//printf("%s %s %lu %s %s %s\n", espera[j].nome, espera[j].apelido, espera[j].contribuinte, espera[j].marca, espera[j].modelo, espera[j].avaria);
		j++;
	} 
	
	fclose(db);
	
	menu(carro, cliente, stock, fatura, espera, stock_rep);
}
