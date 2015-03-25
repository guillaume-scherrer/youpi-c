TARGET:=prog
CFLAGS:=-c -O2 -std=c11
LFLAGS:=-lSDL2main  -L. -lSDL2 -lm

$(TARGET): main.o calcul.o conversion.o lettresXYZ.o
	gcc  -o $(TARGET) main.o calcul.o conversion.o lettresXYZ.o $(LFLAGS)

main.o: main.c calcul.h
	gcc $(CFLAGS) main.c

calcul.o: calcul.c calcul.h
	gcc $(CFLAGS) calcul.c
	
lettresXYZ.o: lettresXYZ.c lettresXYZ.h
	gcc $(CFLAGS) lettresXYZ.c

conversion.o: conversion.c conversion.h
	gcc $(CFLAGS) conversion.c
clean:
	rm *.o *.exe