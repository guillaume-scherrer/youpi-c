#include <stdlib.h>
#include "calcul.h"
#include "define.h"

int calcul(int e1, int e2)
{
    if(e1 + e2 < MAX_ROMAN_NUMBER)
        return e1 + e2;
    else
        exit(1);
}