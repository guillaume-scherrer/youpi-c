TARGET:=prog
CFLAGS:=-c -O2 -std=c11
LFLAGS:=-lm -lSDL2

$(TARGET): main.o ihm.o calcul.o conversion.o
	gcc $(LFLAGS) -o $(TARGET) main.o ihm.o calcul.o conversion.o

main.o: main.c calcul.h ihm.h
	gcc $(CFLAGS) main.c

calcul.o: calcul.c calcul.h
	gcc $(CFLAGS) calcul.c

ihm.o: ihm.c ihm.h
	gcc $(CFLAGS) ihm.c

conversion.o: conversion.c conversion.h
	gcc $(CFLAGS) conversion.c