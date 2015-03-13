#include <string.h>
#include "conversion.h"

#include <stdio.h>

char* conversion(int somme)
{
	static int nums[] = {1000, 500, 100, 50, 10, 5, 1};
	static char* ref[] = {"M", "D", "C", "L", "X", "V", "I"};
	
	char nRom[] = "\0";
	
	for(int i = 0; i < 7; ++i)
	{
		if((i < 6) && (somme / nums[i + 1] == 9))
		{
			strcat(nRom, ref[i + 1]);
			strcat(nRom, ref[i - 1]);
			
			somme %= nums[i + 1];
		} else if(somme / nums[i] == 4)
		{
			strcat(nRom, ref[i]);
			strcat(nRom, ref[i - 1]);
			
			somme %= nums[i];
		} else
		{
			for(int j = 0; j < somme / nums[i]; ++j)
			{
				strcat(nRom, ref[i]);
			}
			
			somme %= nums[i];
		}
	}
	
	printf("%s\n", nRom);
	
	return nRom;
}