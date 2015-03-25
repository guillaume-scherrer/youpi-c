#include <stdlib.h>
#include <string.h> 
#include <stdio.h> 
#include "calcul.h"
#include "conversion.h"
#include "lettresXYZ.h"
#include "define.h"


int main(int argc, char** argv)
{
    // ihm(NULL, NULL);
    
  //  conversion(atoi(argv[1]));
	int i, nb_point;
	int* ttr;
	int* np;
	char* str;
	str = malloc(16*sizeof(char));
	// for (i = 0; i < 1; ++i)
	// {
		//str[0] = 'X';
		//str[0] = 'V';
		str[0] = 'I';
	// }
	float* tx =NULL;
	float* ty = NULL;
	float* tz = NULL;
	tx = malloc(sizeof(float)*nb_point_lettre);
	ty = malloc(sizeof(float)*nb_point_lettre);
	tz = malloc(sizeof(float)*nb_point_lettre);
	np = malloc(sizeof(int)*strlen(str));
    lettresXYZ(str, tx, ty, tz, ttr, np);
    nb_point = *np;
     
    printf("%d\n", *np );
    return 0;
}