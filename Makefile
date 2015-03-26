TARGET:=prog.exe
CFLAGS:=-c -O2 -std=c11

ifeq ($(OS),Windows_NT)
	LFLAGS:=-lmingw32 -lSDL2main
endif

LFLAGS+=-lSDL2 -lSDL2_ttf -lm -L.

$(TARGET): main.o ihm.o calcul.o conversion.o lettresXYZ.o ecritureTraj.o
	gcc -o $(TARGET) main.o ihm.o calcul.o conversion.o lettresXYZ.o ecritureTraj.o $(LFLAGS)

main.o: main.c calcul.h ihm.h
	gcc $(CFLAGS) main.c

calcul.o: calcul.c calcul.h
	gcc $(CFLAGS) calcul.c

ihm.o: ihm.c ihm.h
	gcc $(CFLAGS) ihm.c

conversion.o: conversion.c conversion.h
	gcc $(CFLAGS) conversion.c

lettresXYZ.o: lettresXYZ.c lettresXYZ.h
	gcc $(CFLAGS) lettresXYZ.c

ecritureTraj.o: ecritureTraj.c ecritureTraj.h
	gcc $(CFLAGS) ecritureTraj.c

clean:
	rm *.o *.exe