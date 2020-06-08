#include <stdio.h>
#include <stdlib.h>
main () 
{
	int checkh = 0, checkm = 0, checks = 0;
    int hora=0, min=0, seg=0, total;
	char ch;
	
	printf("Introduza o tempo no formato h(hora) m(minuto) s(segundo): ");
	
	do
	{
	ch = getchar();
	
		if(ch == 'h')
			{
				scanf(" %d", &hora);                
                if(checkh == 1)
				{
					printf("Erro: Nao pode introduzir caracteres iguais.\n");
					exit(1);
				}	
                checkh=1;
				if(hora > 24)
				{
					printf("Erro: numero de horas invalidas.\n");
					exit(1);
				}
			}
		else if(ch == 'm')
			{
				scanf(" %d", &min);
                if(checkm == 1)
				{
					printf("Erro: Nao pode introduzir caracteres iguais.\n");
					exit(1);
				}	
				checkm=1;
				if(min > 59)
				{
					printf("Erro: numero de minutos invalidos.\n");
					exit(1);
				}
			}
		else if(ch == 's')
			{
				scanf(" %d", &seg);
                if(checks == 1)
				{
					printf("Erro: Nao pode introduzir caracteres iguais.\n");
					exit(1);
				}					
                checks=1;
				if(seg > 59)
				{
					printf("Erro: numero de segundos invalidos.\n");
					exit(1);
				}
			}
	}
	while(ch != 'x');
	
	total = (hora*60*60 + min*60 + seg);
	
	printf("Leu %dh %dm %ds = %d\n", hora, min, seg, total);	
}
