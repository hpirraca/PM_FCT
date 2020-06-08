#include <stdio.h>
main() 
{
unsigned int ano1, mes1, dia1;
unsigned int ano2, mes2, dia2;

	printf("Escreva para a data1 o dia mes ano como inteiros: ");
	scanf(" %d %d %d", &dia1, &mes1, &ano1);
	printf("Escreva para a data2 o dia mes ano como inteiros: ");
	scanf(" %d %d %d", &dia2, &mes2, &ano2);

		if(ano2==ano1 && mes2==mes1 && dia2==dia1)
		{
			printf("A data 1 e igual a data 2\n");
		}
		else if(ano2>ano1 || mes2>mes1 || dia2>dia1)
		{
			printf("A data 1 e anterior a data 2\n");
		}
		else
		{
			printf("A data 2 e anterior a data 1\n");
		}
}
