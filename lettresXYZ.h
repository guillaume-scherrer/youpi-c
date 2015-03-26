#pragma once

void lettresXYZ(char* str, float* tx, float* ty, float* tz, int* ttr, int* np);

void chooseMoves(char letter, int* moves, float data[][6]);

void line(float* tx, float* tz, int* ttr, int* np, float* data);

void ellipse(float* tx, float* tz, int* ttr, int* np, float* data);