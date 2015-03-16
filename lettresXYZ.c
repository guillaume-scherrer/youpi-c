#include "lettresXYZ.h"
#include <stdlib.h>
#include <string.h>

void lettresXYZ(char* str, float* tx, float* ty, float * tz, int* ttr, int* np){
	int i,j,k, nb_point_x;
	float z;
	nb_point_x = 20;
	
	for (i = 0; i < strlen(str); ++i)
	{
		/* z=z*i pour le décalage */
		switch(str[i]){
		    case 'X'  :
		       for (z = -139.5; z <= -130.5; ++z)
		       {
				   for(j=0; j<(nb_point_x/2); j++){
						tx[j] = z;
						ty[j] = 50;
						tz[j] = z;
						np++;
					}
					for(k=(nb_point_x/2); k<nb_point_x; k++){
						tx[k] = z;
						ty[k] = 50;
						tz[k] = z;
						np++;
					}
			   }
		    break; 
		  /*  case 'V'  :
		      
		       break; 
		    case 'M'  :
		    
		       break; 
		    case 'D'  :
		   
		       break; 
		    case 'C'  :
		       
		       break;
		    case 'L'  :
		       
		       break; 
		  	case 'I'  :
		       */
		      
		    /* you can have any number of case statements */
		    
		       
		}
	}
}