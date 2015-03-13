#include <stdlib.h>
#include "ihm.h"
#include "calcul.h"
#include "conversion.h"

#include <string.h> // test
#include <stdio.h>

int main(int argc, char** argv)
{
    char* nRom = NULL;
    
    ihm(NULL, NULL);
    
    nRom = conversion(atoi(argv[1]));
    printf("%s\n", nRom);
    
    if(nRom)
    {
        free(nRom);
    }
    
    return 0;
}