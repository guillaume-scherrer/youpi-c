#include <stdlib.h>
#include "ihm.h"
#include "calcul.h"
#include "conversion.h"

#include <string.h> // test
#include <stdio.h>
#include "lettresXYZ.h"
#include "define.h"

int main(int argc, char** argv)
{
    int e1 = 0;
    int e2 = 0;
    char* nRom = NULL;
    
    ihm(&e1, &e2);
    
    nRom = conversion(calcul(e1, e2));
    printf("nRom: %s\ne1: %d\ne2: %d\n", nRom, e1, e2);
    
    if(nRom)
    {
        free(nRom);
    }
    
    // char str[] = "MDCLXVI";
    // float* tx = malloc(MAX_XYZ * sizeof(float));
    // float* ty = malloc(MAX_XYZ * sizeof(float));
    // float* tz = malloc(MAX_XYZ * sizeof(float));
    // int* ttr = malloc(MAX_XYZ * sizeof(int));
    // int np;
    //
    // lettresXYZ(str, tx, ty, tz, ttr, &np);
    //
    // free(tx);
    // free(ty);
    // free(tz);
    // free(ttr);
    
    return 0;
}