#include "lettres_xyz.h"

void lettresXYZ(char* str, float*tx, float*ty, float *tz, int* ttr, int*np){
	int i,z
	for (i = 0; i < strlan(str); ++i)
	{
		/* x=x*i pour le décalage */
		switch(str[i]){
		    case X  :
		       for (z = -139.5; z <= -130.5; ++z)
		       {
		       		tx[i] = z
		       }
		       break; /* optional */
		    case V  :
		       statement(s);
		       break; /* optional */
		    case M  :
		       statement(s);
		       break; /*optional */
		    case D  :
		       statement(s);
		       break; /* optional */
		    case C  :
		       statement(s);
		       break; /* optional */
		    case L  :
		       statement(s);
		       break; /* optional */
		  	case I  :
		       statement(s);
		       break; /* optional */
		    /* you can have any number of case statements */
		    default : /* Optional */
		       statement(s);
		}
	}
}