#include <stdio.h>
main() {

unsigned int nota_teorica= 0, nota_pratica= 0, faltas= 0;
float media;
unsigned int nota_final;

	printf("Calculo da nota final a PM\n\n");
	printf("Introduza os seguintes dados:\n");
	printf("\tNumero de faltas nos trabalhos praticos: ");
		scanf("%d", &faltas);
	printf("\tNota dos trabalhos praticos: ");
		scanf(" %d", &nota_pratica);
	printf("\tNota dos testes e exames: ");
		scanf(" %d", &nota_teorica);	
	
			
	if(nota_teorica<10 || nota_pratica<10 || faltas>3) 
	{
		printf("Reprovou a disciplina por faltas\n");
	}
	 
	media= 0.5*nota_pratica + 0.5*nota_teorica;
	nota_final= (int)(media+0.5);
	
	if(faltas == 3 && nota_final >= 12 && nota_pratica >=14)
	{
		nota_final=12;
		printf("Aprovado com a nota final de %d valores (%.1f)\n",nota_final, media);
	}
	else if(faltas == 2 && nota_pratica>14)
	{
		nota_pratica = 14;
		media= 0.5*nota_pratica + 0.5*nota_teorica;
		nota_final= (int)(media+0.5);
		printf("Aprovado com a nota final de %d valores (%.1f)\n",nota_final, media);
	}
	else if(faltas < 2 && nota_pratica>14)
	{
		nota_pratica = 14;
		media= 0.5*nota_pratica + 0.5*nota_teorica;
		nota_final= (int)(media+0.5);
		printf("Aprovado com a nota final de %d valores (%.1f)\n",nota_final, media);
	}
	else
	{	
		media= 0.5*nota_pratica + 0.5*nota_teorica;
		nota_final= (int)(media+0.5);
		printf("Aprovado com a nota final de %d valores (%.1f)\n",nota_final, media);	
	}
}