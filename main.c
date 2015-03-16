#include <stdlib.h>
#include <string.h> 
#include "calcul.h"
#include "conversion.h"
#include "lettresXYZ.h"


int main(int argc, char** argv)
{
    // ihm(NULL, NULL);
    
  //  conversion(atoi(argv[1]));
	int* ttr;
	int* np=0;
	char* str;
	str[0] = 'X';
	float* tx;
	float* ty;
	float* tz;
    lettresXYZ(str, tx, ty, tz, ttr, np);
    return 0;
}