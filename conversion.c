#include <stdlib.h>
#include <string.h>
#include "conversion.h"

char* conversion(int somme)
{
	static const int nums[] = { 1000, 500, 100, 50, 10, 5, 1 };
	static const char* ref[] = { "M", "D", "C", "L", "X", "V", "I" };
	int i;
	int j;
	
	if(somme <= 0)
		return NULL;
	
	char* nRom = malloc(sizeof(char));
	
	nRom[0] = '\0';
	
	for(i = 0; i < 7; ++i)
	{
		if((i < 6) && (i % 2) && (somme / nums[i + 1] == 9))
		{
			strcat(nRom, ref[i + 1]);
			strcat(nRom, ref[i - 1]);
			
			somme %= nums[i + 1];
		} else
		{
			if(somme / nums[i] == 4)
			{
				strcat(nRom, ref[i]);
				strcat(nRom, ref[i - 1]);
			} else
			{
				for(j = 0; j < somme / nums[i]; ++j)
				{
					strcat(nRom, ref[i]);
				}
			}
			
			somme %= nums[i];
		}
	}
	
	return nRom;
}