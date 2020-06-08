#include <stdio.h>
#include <stdlib.h>
main () 
{
     int i, n=0, k, a=1, b=3;
	 
	 printf ("Introduza o limite de elementos pretendido: "); 
	    
	 if (scanf (" %d", &n) != 1) 
	 {      
	 printf ("Leitura do limite inválida\n");         
	 exit (1);     
	 }     
	 
	 printf("%d %d", a, b);
	  
	 for (i = 3; i <= n; i++) 
	 {     
		 k = a + b;
		 printf (" %d", k);
		 a = b;
		 b = k;
	 }  
} 