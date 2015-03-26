#include "lettresMoteur.h"
#include "math.h"
#include "stdio.h" // Test
#include "ftd2xx.h"

void lettresMoteur(float* tt1, float* tt2, float* tt3, int* ttr, int np){
	char trame_usb1[9] = { 0 };
	float* tab_var[3]={tt1,tt2,tt3};//tableau de theta
	int i, j, nb_demipas1;
	float angle_abs1;
	
	FT_HANDLE ftHandle;
    FT_STATUS ftStatus;
    DWORD BytesWritten;
	
    ftStatus = FT_Open(0, &ftHandle);
	
	if(ftStatus != FT_OK) {
        printf("Rien de branché...\n");
		
        return;
    }
	
	FT_Write(ftHandle, trame_usb1, sizeof(trame_usb1), &BytesWritten);
	
	//Pour chaque point
	for (i = 1; i < np; i++)
	{
		//On parcours les trois theta, selon l'angle , le numéro du moteur et le sens on crée la trame usb.
		for(j = 0; j < 3; j++)
		{
			trame_usb1[0] = j+1;//numéro du moteur
			trame_usb1[1] = ';';//séparateur
			angle_abs1 = tab_var[j][i+1]-tab_var[j][i];//Différence entre l'angle présent et l'angle à venir,
			//afin de déterminer le sens et le nombre de pas du prochain mouvement.
			if (angle_abs1 >= 0)
			{
				trame_usb1[2] = '+';
			}
			else
			{
				trame_usb1[2] = '-';
			}
			
			nb_demipas1 = (int)(fabs(angle_abs1/0.032));//On détermine le nombre de pas à effectuer selon l'angle.
			// sprintf(trame_usb1[3], "%d", (int)floor(nb_demipas1/1000));
			trame_usb1[3] =floor(nb_demipas1/1000)+'0';
			printf("%c\n", trame_usb1[3]);
			nb_demipas1 = nb_demipas1%1000;
			trame_usb1[4] = floor(nb_demipas1/100)+'0';
			printf("%c\n", trame_usb1[4]);
			nb_demipas1 = nb_demipas1%100;
			trame_usb1[5] = floor(nb_demipas1/10)+'0';
			printf("%c\n", trame_usb1[5]);
			nb_demipas1 = nb_demipas1%10;
			trame_usb1[6] = floor(nb_demipas1)+'0';
			printf("%c\n", trame_usb1[6]);
			nb_demipas1 = nb_demipas1%1;
			trame_usb1[7]='\r';
			trame_usb1[8]='\n';
			
			FT_Write(ftHandle, trame_usb1, sizeof(trame_usb1), &BytesWritten);
		}
	}
	
	FT_Close(ftHandle);
}