#include "input.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int inputCheck(int* tabE1E2){
	if (tabE1E2[0] <=0 || tabE1E2[1] <= 0)
	{
		printf("%s\n", "Nombre positif seulement" );
		return 0;
	}
	else{
		printf("%s", "merci" );
		return 1;
	}
}


int add(int* tabE1E2){
	int somme;
	somme = tabE1E2[0]+tabE1E2[1];
	printf("%d\n", somme);
	return somme;
}

int* breakDown(int somme){
	int tab_somme[3];
	int* p_tab_somme;
	int i,j;
	p_tab_somme = tab_somme;
	for(i = 3; i >= 0; i--) // i représente la puissance de 10
	{
		tab_somme[i] = somme%(int)pow(10,i);
		somme -= tab_somme[i]*(int)pow(10,i);

	}
	
	for (j = 0; j < 3; ++j)
	{
		printf("%d\n", tab_somme[i] );	
	}
	return p_tab_somme;
}