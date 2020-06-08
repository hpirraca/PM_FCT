#include <stdio.h>
#include <stdlib.h>

	main () 
	{
		char c1;
		int sucesso = 0, algarismo = 6, iteracao = 0;
		float numero = 0, numero_final = 0, unidade = 100;
		
		printf ("Escreva um número (CCC,cc): ");

			while (iteracao < 5)
			{
				scanf (" %c", &c1);

				if (!((c1 >= '0' && c1 <= '9') || (c1 == ',' || c1 == '.')))
				{
					printf ("Introduza um número, por favor.\n\t");
					exit (0);
				}

				if ((c1 == ',' || c1 == '.') && iteracao != 3)
				{
					printf ("Introduza um número da forma CCC,cc.\n\t");
					exit (0);
				}
				
				if ((c1 == ',' || c1 == '.') && iteracao == 3)
				{
					algarismo--;
					continue;
				}

				numero = (c1 - 48);
				numero_final = numero_final + numero*unidade;
				unidade = unidade/10;

				iteracao++;
			}
	
		printf ("O número inserido é %.2f %e\n\t", numero_final, numero_final);
	}
