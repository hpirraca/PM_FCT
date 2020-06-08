#include <stdio.h>
#include <stdlib.h>
main () 
{
     int num, alg, i;
     
	 do
	 {
     	 printf("Introduza um numero com 3 algarismos: ");
	     scanf(" %d", &num);
	     if(num<100 || num>999)
	     	printf("Erro! Nao tem 3 algarismos");
	 }    
     while(num<100 || num>999);
     	
     for(i=1; i<=3; i++)
     {
	    if(i==1)
	    {
		    printf("O algarismo das centenas ");
		    alg = num/100;
		}
		if(i==2)
	    {
		    printf("O algarismo das dezenas ");
		    alg = (num%100)/10;
		}
		if(i==3)
	    {
		    printf("O algarismo das unidades ");
		    alg = (num%100)%10;
		}
	    
		switch(alg)
     	{
     	case 1: printf("e o um\n");break;
     	case 2: printf("e o dois\n");break;
     	case 3: printf("e o tres\n");break;
     	case 4: printf("e o quatro\n");break;
     	case 5: printf("e o cinco\n");break;
     	case 6: printf("e o seis\n");break;
     	case 7: printf("e o sete\n");break;
     	case 8: printf("e o oito\n");break;
     	case 9: printf("e o nove\n");break;
     	case 0: printf("e o zero\n");break; 
	 	default: exit(0); break;
	 	}     
     	
 	}
	
} 