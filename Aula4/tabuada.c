#include <stdio.h>
#include <stdlib.h>

int mult (int a, int b) 
{ 
  return a*b;	 
}

int tabuada (int c)
{
    int x, tab;    
    
      for(x=1; x<=10; x++)
      {
         tab = mult(c,x);
         printf("%d * %d = %d\n", c, x, tab);
      }
    return;
}

main()
{ 
	int n;

      do
      {
	      printf ("Que tabuada quer (1 a 9): ");

	      if (scanf (" %d", &n) != 1) 
	      { 
	         printf ("Leitura do limite inválida\n"); 
	         exit (1);
	      }

	      if ((n < 1) || (n > 9))
	      {
	         printf ("Número incorrecto. Tente outra vez\n");
	         exit (1);
	      }

          tabuada (n);
      }
      while(n!=0);
}
