#include <stdlib.h>
#include "ihm.h"
#include "calcul.h"
#include "conversion.h"

#include <string.h> // test
#include <stdio.h>

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
    
    return 0;
}