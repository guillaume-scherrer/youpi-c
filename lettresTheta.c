#include <stdlib.h>
#include <stdio.h> 
#include "lettres_theta.h"
#include "math.h"
void lettresTheta(float* tx, float* ty, float* tz, int np, float* tt1, float* tt2, float* tt3)
{
	int i,L1,L2,L3;
	float x,y,z;
	L1=175;
	L2=160;
	L3=160;
	for (i = 0; i < np ; ++i)
	{
		x=tx[i];
		y=ty[i];
		z=tz[i];

		tt1[i] = atan(-z/x);
		tt3[i] = -acos((pow(x,2)+pow(z,2)+pow(y-L1, 2)-pow(L1,2)-pow(L2,2))/(2*L2*L3));
		tt3[i] = -acos((pow(x,2)+pow(z,2)+pow(y-L1, 2)-pow(L1,2)-pow(L2,2))/(2*L2*L3));
		printf("%f, %f, %f\n", tt1[i], tt2[i], tt3[i] );
	}	

}	