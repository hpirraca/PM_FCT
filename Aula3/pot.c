#include <stdio.h>
#include <stdlib.h>
main () 
{
     int i, n=0;
	 
	 printf ("Introduza o limite de elementos pretendido: "); 
	    
	 if (scanf (" %d", &n) != 1) 
	 {      
	 printf ("Leitura do limite inválida\n");         
	 exit (1);     
	 }     
	  
	 for (i = 0; i < n; i++) 
	 {    
			 printf ("%d %d\n", i, i*i);
	 }  
} 