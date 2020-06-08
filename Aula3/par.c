#include <stdio.h>
#include <stdlib.h>
main () 
{
     int i, m=0, n=0;
	 
	 printf ("Introduza o limite de elementos pretendido: ");  
	   
	 if (scanf (" %d", &n) != 1) 
	 {      
	 printf ("Leitura do limite inválida\n");         
	 exit (1);     
	 }     
     
	 for (i = 0; i < n; i++) 
	 { 
	         if (!(i%2))
			 printf ("%d\n", i);
			 else 
			 m = m+i;
	  }  
	  printf("A soma e: %d", m);
} 