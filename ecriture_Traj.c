#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ecriture_Traj.h"
void ecritureTraj(float* tt1, float* tt2, float* tt3, int* ttr, int np)
{
	int i;
	FILE* out = fopen("trajectoire.dat", "w");
	
	if (out != NULL)
    {
    	for(i = 0; i < np-1; ++i)
		{
			
			fprintf(out, "%f %f %f %d\r\n", tt1[i], tt2[i], tt3[i], ttr[i]);
			//printf("%d\n", np);
			printf("%f %f %f %d\r\n", tt1[i], tt2[i], tt3[i], ttr[i]);
		}
		
    }
    else
    {
        printf("Impossible d'ouvrir le fichier test.txt");
    }
	fclose(out);
}