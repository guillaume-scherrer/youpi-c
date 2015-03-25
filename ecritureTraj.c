#include <stdio.h>
#include "ecritureTraj.h"

void ecritureTraj(float* tt1, float* tt2, float* tt3, int* ttr, int np)
{
    int i;
    FILE* out = fopen("traj.dat", "w");
    
    for(i = 0; i < np; ++i)
    {
        fprintf(out, "%f %f %f %d\r\n", tt1[i], tt2[i], tt3[i], ttr[i]);
    }
    
    fclose(out);
}