#include <stdio.h>

main() 
	{
	unsigned long int dia, hora, min, seg, dia1, dia2, hor1, hor2, min1, min2, seg1, seg2, seg_tot;
	
	printf("Introduza o tempo no.1 (dia)d (hora)h (minuto)m (segundo)s: ");
	scanf(" %lud %luh %lum %lus", &dia1, &hor1, &min1, &seg1);
	
	printf("Introduza o tempo no.2 (dia)d (hora)h (minuto)m (segundo)s: ");
	scanf(" %lud %luh %lum %lus", &dia2, &hor2, &min2, &seg2);
	
	seg_tot = abs((dia2*24*60*60 + hor2*60*60 + min2*60 + seg2) - (dia1*24*60*60 + hor1*60*60 + min1*60 + seg1));
	dia = seg_tot/86400;
	hora = (seg_tot%86400)/(3600);
	min = ((seg_tot%86400)%(3600))/60;
	seg = ((seg_tot%86400)%(3600))%60;
	
	printf("A diferenca entre os dois tempos e de %lu = %lud %luh %lum %lus", seg_tot, dia, hora, min, seg);
	}