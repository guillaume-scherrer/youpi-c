#include "lettresXYZ.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h> 
#include <math.h>
#include "define.h"
void lettresXYZ(char* str, float* tx, float* ty, float * tz, int* ttr, int* np){
	int i,j,k, x;
	float z,t;
	

	for (i = 0; i < nb_point_lettre; ++i)
	{
		tx[i]=0;
		ty[i]=0;
		tz[i]=0;
	}
	
	for (i = 0; i < strlen(str); ++i)
	{
		/* z=z*i pour le décalage */
		switch(str[i])
		{
		    case 'X'  :
		       for (z = -128.5; z >= -139.5; --z)
		       {
		       	printf("%f\n",z );
					tx[j] = z+284.5;
					ty[j] = 50;
					tz[j] = z;
					(*np)++;
		   			printf("%f, %f, %f\n", tx[i], ty[i], tz[i] );
			   }
			   for (z = -139.5; z <= -128.5; z++)
		       {
		       	printf("%f\n",z );
					tx[j] = z+284.5;
					ty[j] = 50;
					tz[j] = z;
					(*np)++;
		   			printf("%f, %f, %f\n", tx[i], ty[i], tz[i] );
			   }
			   
		    break; 
		   case 'V'  :
		      	for (z = -128.5; z >= -139.5; --z)
		       {
		       	printf("%f\n",z );
					tx[j] = (z+284.5)*(4.5/11);
					ty[j] = 50;
					tz[j] = z;
					(*np)++;
		   			printf("%f, %f, %f\n", tx[i], ty[i], tz[i] );
			   }
			   for (z = -139.5; z <= -128.5; z++)
		       {
		       	printf("%f\n",z );
					tx[j] = (4.5/11)*(z+284.5);
					ty[j] = 50;
					tz[j] = z;
					(*np)++;
		   			printf("%f, %f, %f\n", tx[i], ty[i], tz[i] );
			   }
		       break; 
		    case 'M'  :
		    	for (z = -128.5; z >= -139.5; --z)
		       {
		       	printf("%f\n",z );
					tx[j] = (z+284.5)*(4.5/11);
					ty[j] = 50;
					tz[j] = z;
					(*np)++;
		   			printf("%f, %f, %f\n", tx[i], ty[i], tz[i] );
			   }
			   for (z = -139.5; z <= -128.5; z++)
		       {
		       	printf("%f\n",z );
					tx[j] = (4.5/11)*(z+284.5);
					ty[j] = 50;
					tz[j] = z;
					(*np)++;
		   			printf("%f, %f, %f\n", tx[i], ty[i], tz[i] );
			   }
			   for (x=145; x<=156; x++)
		       {
		       	printf("%f\n",z );
					tx[j] = x;
					ty[j] = 50;
					tz[j] = -139.5;
					(*np)++;
		   			printf("%f, %f, %f\n", tx[i], ty[i], tz[i] );
			   }
			   for (x=145; x<=156; x++)
		       {
		       	printf("%f\n",z );
					tx[j] = x;
					ty[j] = 50;
					tz[j] = -129.5;
					(*np)++;
		   			printf("%f, %f, %f\n", tx[i], ty[i], tz[i] );
			   }
		       break; 
		    
		    case 'L'  :
		       
			   for (z = -139.5; z <= -128.5; z++)
		       {
		       	printf("%f\n",z );
					tx[j] = 145;
					ty[j] = 50;
					tz[j] = z;
					(*np)++;
		   			printf("%f, %f, %f\n", tx[i], ty[i], tz[i] );
			   }
		       break; 
		  	case 'I'  :
				for (x=145; x<=156; x++)
		       {
		       	printf("%f\n",z );
					tx[j] = x;
					ty[j] = 50;
					tz[j] = -134;
					(*np)++;
		   			printf("%f, %f, %f\n", tx[i], ty[i], tz[i] );
			   }
			   for (z = -139.5; z <= -128.5; z++)
		       {
		       	printf("%f\n",z );
					tx[j] = 145;
					ty[j] = 50;
					tz[j] = z;
					(*np)++;
		   			printf("%f, %f, %f\n", tx[i], ty[i], tz[i] );
			   }
			   for (z = -139.5; z <= -128.5; z++)
		       {
		       	printf("%f\n",z );
					tx[j] = 154;
					ty[j] = 50;
					tz[j] = z;
					(*np)++;
		   			printf("%f, %f, %f\n", tx[i], ty[i], tz[i] );
			   }
			   break;
		    case 'D'  :
		   		for (t = 0; t <= 3; t=t+0.1)
		       {
		       		printf("%f\n",t );
					tx[j] = 145+5.5*sin(t);
					ty[j] = 50;
					tz[j] = -139.5+4.5*cos(t);
					(*np)++;
		   			printf("%f, %f, %f\n", tx[i], ty[i], tz[i] );
			   }

			   for (x=145; x<=156; x++)
		       {
		       	printf("%f\n",z );
					tx[j] = x;
					ty[j] = 50;
					tz[j] = -139.5;
					(*np)++;
		   			printf("%f, %f, %f\n", tx[i], ty[i], tz[i] );
			   }
		       break; 
		    case 'C'  :
		     	for (t = 0; t <= 3; t=t+0.1)
		       {
		       		printf("%f\n",t );
					tx[j] = 145+5.5*sin(t);
					ty[j] = 50;
					tz[j] = -139.5+4.5*cos(t);
					(*np)++;
		   			printf("%f, %f, %f\n", tx[i], ty[i], tz[i] );
			   }
		       break; 
		       
		       
		}
	}
}