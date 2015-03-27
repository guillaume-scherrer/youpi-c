#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "calcul.h"
#include "conversion.h"
#include "lettresXYZ.h"
#include "define.h"
#include "ecritureTraj.h"
#include "lettresTheta.h"
#include "lettresMoteur.h"

int main(int argc, char** argv)
{
    // ihm(NULL, NULL);
    
  //  conversion(atoi(argv[1]));
	int i, nb_point;
	int* ttr;
	int* np;
	char* str;
	str = malloc(16*sizeof(char));
	 for (i = 0; i < 1; ++i)
	 {
		str[i] = 'V';
	 }
	float* tx = NULL;
	float* ty = NULL;
	float* tz = NULL;
	float* tt1 = NULL;
	float* tt2 = NULL;
	float* tt3 = NULL;
	tx = malloc(sizeof(float)*nb_point_lettre);
	ty = malloc(sizeof(float)*nb_point_lettre);
	tz = malloc(sizeof(float)*nb_point_lettre);

	tt1 = malloc(sizeof(float)*nb_point_lettre);
	tt2 = malloc(sizeof(float)*nb_point_lettre);
	tt3= malloc(sizeof(float)*nb_point_lettre);
	ttr= malloc(sizeof(int)*nb_point_lettre);
	np = malloc(sizeof(int)*strlen(str));
	(*np)=2;
	for (i = 0; i < (*np); ++i)
	{
		tx[i]=200;
		ty[i]=50;
		tz[i]=154;
	}
	
  //  lettresXYZ(str, tx, ty, tz, ttr, np);
    lettresMoteur(tx, ty, tz, ttr, *np);
    return 0;
}