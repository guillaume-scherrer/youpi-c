#include "lettresMoteur.h"
#include "math.h"
#include "stdio.h"
void lettresMoteur(float* tt1, float* tt2, float* tt3, int* ttr, int np){
	char trame_usb1[9];
	int i, nb_demipas1;
	float angle_abs1;
	for (i = 0; i < np; ++i)
	{
		trame_usb1[0]='1';
		trame_usb1[1]=';';
		angle_abs1 = /*tt1[i+1]-*/tt1[i];
		if (angle_abs1 >=0)
		{
			trame_usb1[2] = '+';
		}
		else
		{
		 	trame_usb1[2] = '-';
		}

		nb_demipas1 = (int)(angle_abs1/0.032);
		printf("demi_pas: %d\n", nb_demipas1 );
		//printf("%f\n", floor(nb_demipas1/1000));
		//sprintf(trame_usb1[3], "%d", (int)floor(nb_demipas1/1000));
		 trame_usb1[3] =floor(nb_demipas1/1000)+'0';
		 // printf("trame: %c\n", trame_usb1[3] );
		 nb_demipas1 = nb_demipas1%1000;
		 // printf("demi_pas: %d\n", nb_demipas1 );
		 trame_usb1[4] = floor(nb_demipas1/100)+'0';
		 // printf("trame: %c\n", trame_usb1[4] );
		 nb_demipas1 = nb_demipas1%100;
		 // printf("demi_pas: %d\n", nb_demipas1 );
		 trame_usb1[5] = floor(nb_demipas1/10)+'0';
		 // printf("trame: %c\n", trame_usb1[5] );
		 nb_demipas1 = nb_demipas1%10;
		 // printf("demi_pas: %d\n", nb_demipas1 );
		 trame_usb1[6] = floor(nb_demipas1)+'0';
		 // printf("trame: %c\n", trame_usb1[6] );
		 nb_demipas1 = nb_demipas1%1;
		 // printf("demi_pas: %d\n", nb_demipas1 );
		 trame_usb1[7]='\r';
		 trame_usb1[8]='\n';
		}
		for ( i = 0; i <=8; ++i)
		{
			printf("trame: %c\n", trame_usb1[i] );
		}
}