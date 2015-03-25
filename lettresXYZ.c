#include "lettresXYZ.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h> 
#include <math.h>
#include "define.h"
void lettresXYZ(char* str, float* tx, float* ty, float * tz, int* ttr, int* np){
// 	int i,j,k, x, nb_point_x;
// 	float  x0, z0,t, xf, zf, zhd, xhd, zhg, xhg, zbd, xbd;
// 	// FILE* fichier = NULL;
// 	// fichier = fopen("test_octave", "w+");
	
// 	j=0;
// //coordonnée de l'origin	
// 	zbd=-139.5;
// 	xbd=145;

// //coordonnée du point en haut à droite.
// 	zhd=-130.5;
// 	xhd=156;

// //En haut à gauche
// 	zhg = -139.5;
// 	xhg	= 156;

// //En bas à droite
// 	zbd= -130.5;
// 	xbd = 145;

// 	for (i = 0; i < nb_point_lettre; ++i)
// 	{
// 		tx[i]=0;
// 		ty[i]=50;
// 		tz[i]=0;
// 	}
	
// 	for (i = 0; i <=1/*strlen(str)*/; ++i)
// 	{
// 		/* z=z*i pour le décalage */
// 		switch(str[i])
// 		{
// 		    case 'X'  :
// 		    tx[0]=xbd;
// 		    tz[0]=zbd;
// 		    tx[nb_point_lettre/2]=xhg;
// 		    tz[nb_point_lettre/2]=zhg;

// 		    	for (j = 1;j < nb_point_lettre/2; ++j)
// 		    	{
// 		    		tx[j]=tx[j-1]+0.2;
// 		    		tz[j]=tz[j-1]+0.2;
// 		    		printf("%f, %f\n", tz[j], tx[j]);
// 		    		(*np)++;
// 		    	}
// 		    	//printf("%s\n", "--------" );
// 		    	for (j = nb_point_lettre/2; j <= nb_point_lettre; ++j)
// 		    	{
// 		    		tx[j]=tx[j-1]-0.2;
// 		    		tz[j]=tz[j-1]+0.2;
// 		    		printf("%f, %f\n", tz[j], tx[j]);
// 		    		(*np)++;
// 		    	}
// 		    break; 
// 		   case 'V'  :
// 		   		tx[0]=xhg;
// 		   		tz[0]=zhg;
// 		   		tx[nb_point_lettre/2]=xhd;
// 		    	tz[nb_point_lettre/2]=zhd;
// 		   		for (j = 1;j < nb_point_lettre/2; ++j)
// 		    	{
// 		    		tx[j]=tx[j-1]-0.1;
// 		    		tz[j]=tz[j-1]+0.01;
// 		    		printf("%f, %f\n", tz[j], tx[j]);
// 		    		(*np)++;
// 		    	}

// 		    	for (j = nb_point_lettre/2; j <= nb_point_lettre; ++j)
// 		    	{
// 		    		tx[j]=tx[j-1]-0.1;
// 		    		tz[j]=tz[j-1]-0.01;
// 		    		printf("%f, %f\n", tz[j], tx[j]);
// 		    		(*np)++;
// 		    	}
// 		       break; 
// 		//     case 'M'  :
// 		//     	for (z = -128.5; z >= -139.5; --z)
// 		//        {
// 		//    //     	printf("%f\n",z );
// 		// 			// tx[j] = (z+284.5)*(4.5/11);
// 		// 			ty[j] = 50;
// 		// 			tz[j] = z;
// 		// 			(*np)++;
// 		//    			// printf("%f, %f, %f\n", tx[i], ty[i], tz[i] );
// 		// 	   }
// 		// 	   for (z = -139.5; z <= -128.5; z++)
// 		//        {
// 		//        	// printf("%f\n",z );
// 		// 			tx[j] = (4.5/11)*(z+284.5);
// 		// 			ty[j] = 50;
// 		// 			tz[j] = z;
// 		// 			(*np)++;
// 		//    			// printf("%f, %f, %f\n", tx[i], ty[i], tz[i] );
// 		// 	   }
// 		// 	   for (x=145; x<=156; x++)
// 		//        {
// 		//        	// printf("%f\n",z );
// 		// 			tx[j] = x;
// 		// 			ty[j] = 50;
// 		// 			tz[j] = -139.5;
// 		// 			(*np)++;
// 		//    			// printf("%f, %f, %f\n", tx[i], ty[i], tz[i] );
// 		// 	   }
// 		// 	   for (x=145; x<=156; x++)
// 		//        {
// 		//        	// printf("%f\n",z );
// 		// 			tx[j] = x;
// 		// 			ty[j] = 50;
// 		// 			tz[j] = -129.5;
// 		// 			(*np)++;
// 		//    			// printf("%f, %f, %f\n", tx[i], ty[i], tz[i] );
// 		// 	   }
// 		//        break; 
		    
// 		//     case 'L'  :
		       
// 		// 	   for (z = -139.5; z <= -128.5; z++)
// 		//        {
// 		//        	// printf("%f\n",z );
// 		// 			tx[j] = 145;
// 		// 			ty[j] = 50;
// 		// 			tz[j] = z;
// 		// 			(*np)++;
// 		//    			// printf("%f, %f, %f\n", tx[i], ty[i], tz[i] );
// 		// 	   }
// 		//        break; 
// 		//   	case 'I'  :
// 		// 		for (x=145; x<=156; x++)
// 		//        {
// 		//        	// printf("%f\n",z );
// 		// 			tx[j] = x;
// 		// 			ty[j] = 50;
// 		// 			tz[j] = -134;
// 		// 			(*np)++;
// 		//    			// printf("%f, %f, %f\n", tx[i], ty[i], tz[i] );
// 		// 	   }
// 		// 	   for (z = -139.5; z <= -128.5; z++)
// 		//        {
// 		//        	// printf("%f\n",z );
// 		// 			tx[j] = 145;
// 		// 			ty[j] = 50;
// 		// 			tz[j] = z;
// 		// 			(*np)++;
// 		//    			// printf("%f, %f, %f\n", tx[i], ty[i], tz[i] );
// 		// 	   }
// 		// 	   for (z = -139.5; z <= -128.5; z++)
// 		//        {
// 		//        	// printf("%f\n",z );
// 		// 			tx[j] = 154;
// 		// 			ty[j] = 50;
// 		// 			tz[j] = z;
// 		// 			(*np)++;
// 		//    			// printf("%f, %f, %f\n", tx[i], ty[i], tz[i] );
// 		// 	   }
// 		// 	   break;
// 		//     case 'D'  :
// 		//    		for (t = 0; t <= 3; t=t+0.1)
// 		//        {
// 		//        		// printf("%f\n",t );
// 		// 			tx[j] = 145+5.5*sin(t);
// 		// 			ty[j] = 50;
// 		// 			tz[j] = -139.5+4.5*cos(t);
// 		// 			(*np)++;
// 		//    			// printf("%f, %f, %f\n", tx[i], ty[i], tz[i] );
// 		// 	   }

// 		// 	   for (x=145; x<=156; x++)
// 		//        {
// 		//        	// printf("%f\n",z );
// 		// 			tx[j] = x;
// 		// 			ty[j] = 50;
// 		// 			tz[j] = -139.5;
// 		// 			(*np)++;
// 		//    			// printf("%f, %f, %f\n", tx[i], ty[i], tz[i] );
// 		// 	   }
// 		//        break; 
// 		//     case 'C'  :
// 		//      	for (t = 0; t <= 3; t=t+0.1)
// 		//        {
// 		//        		// printf("%f\n",t );
// 		// 			tx[j] = 145+5.5*sin(t);
// 		// 			ty[j] = 50;
// 		// 			tz[j] = -139.5+4.5*cos(t);
// 		// 			(*np)++;
// 		//    			// printf("%f, %f, %f\n", tx[i], ty[i], tz[i] );
// 		// 	   }
// 		//        break; 
		       
		       
// 		}
// 	}
}