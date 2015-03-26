#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lettresXYZ.h"
#include "define.h"

#include <stdio.h> // Test

void lettresXYZ(char* str, float* tx, float* ty, float* tz, int* ttr, int* np)
{
    int i;
    int j;
    int start;
    int moves[5];
    float data[4][6];
    
    *np = 0;
    
    for(i = 0; i < strlen(str); ++i)
    {
        start = *np;
        
        chooseMoves(str[i], moves, data);
        
        for(j = 0; moves[j] != 2; ++j)
        {
            if(moves[j])
            {
                ellipse(tx, tz, ttr, np, data[j]);
            } else
            {
                line(tx, tz, ttr, np, data[j]);
            }
        }
        
        for(j = start; j < *np; ++j)
        {
            tz[j] += 2 * CELL_Z * i;
        }
    }
    
    for(i = 0; i < *np; ++i)
    {
        tx[i] += OFFSET_X;
        ty[i] = 50;
        tz[i] += OFFSET_Z;
    }
}

void chooseMoves(char letter, int* moves, float data[][6])
{
    static char letters[] = "MDCLXVI";
    static int lettersMoves[][5] = {
        { 0, 0, 0, 0, 2 },
        { 0, 1, 2 },
        { 1, 2 },
        { 0, 0, 2 },
        { 0, 0, 2 },
        { 0, 0, 2 },
        { 0, 0, 0, 2 }
    };
    static float lettersData[][4][6] = {
        {
            { 0, 0, 11, 0 },
            { 11, 0, 0, 4.5 },
            { 0, 4.5, 11, 9 },
            { 11, 9, 0, 9 }
        },
        {
            { 0, 0, 11, 0 },
            { 5.5, 0, 5.5, 9, -90, 90 }
        },
        {
            { 5.5, 4.5, 5.5, 4.5, 45, 315 }
        },
        {
            { 11, 0, 0, 0 },
            { 0, 0, 0, 9 }
        },
        {
            { 0, 0, 11, 9 },
            { 11, 0, 0, 9 }
        },
        {
            { 11, 0, 0, 4.5 },
            { 0, 4.5, 11, 9 }
        },
        {
            { 11, 0, 11, 9 },
            { 11, 4.5, 0, 4.5 },
            { 0, 0, 0, 9 }
        }
    };
    int i = 0;
    int j;
    int k;
    
    while(letters[i] != letter)
    {
        ++i;
    }
    
    for(j = 0; j < 5; ++j)
    {
        moves[j] = lettersMoves[i][j];
    }
    
    for(j = 0; j < 4; ++j)
    {
        for(k = 0; k < 6; ++k)
        {
            data[j][k] = lettersData[i][j][k];
        }
    }
}

void line(float* tx, float* tz, int* ttr, int* np, float* data)
{
    int i;
    int x;
    int y;
    int length = sqrt(pow(data[2] - data[0], 2) + pow(data[3] - data[1], 2));
    float xStep = (data[2] - data[0]) / length / 5;
    float zStep = (data[3] - data[1]) / length / 5;
    
    for(i = 0; i <= length * 5; ++i)
    {
        tx[*np + i] = data[0] + i * xStep;
        tz[*np + i] = data[1] + i * zStep;
        ttr[*np + i] = i != 0;
    }
    
    *np += i;
}

void ellipse(float* tx, float* tz, int* ttr, int* np, float* data)
{
    int i;
    int ang;
    
    for(i = 0, ang = data[4]; ang <= data[5]; ++i, ang += 3)
    {
        tx[*np + i] = data[0] + sin(ang * M_PI / 180) * data[2];
        tz[*np + i] = data[1] + cos(ang * M_PI / 180) * data[3];
        ttr[*np + i] = i != 0;
    }
    
    *np += i;
}