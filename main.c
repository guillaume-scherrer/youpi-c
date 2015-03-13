#include <stdlib.h>
#include "ihm.h"
#include "calcul.h"
#include "conversion.h"

#include <string.h> // test

int main(int argc, char** argv)
{
    // ihm(NULL, NULL);
    
    conversion(atoi(argv[1]));
    
    return 0;
}