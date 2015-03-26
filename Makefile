TARGET:=prog.exe
CFLAGS:=-c -O2 -std=c11
COMMAND=gcc $(CFLAGS) $<

ifeq ($(OS),Windows_NT)
	LFLAGS:=-lmingw32 -lSDL2main
endif

LFLAGS+=-lSDL2 -lSDL2_ttf -lm -L.

$(TARGET): main.o calcul.o ihm.o conversion.o lettresXYZ.o lettresTheta.o lettresMoteur.o ecritureTraj.o
	gcc -o $(TARGET) $^ $(LFLAGS)

main.o: main.c
	$(COMMAND)

calcul.o: calcul.c calcul.h
	$(COMMAND)

ihm.o: ihm.c ihm.h
	$(COMMAND)

conversion.o: conversion.c conversion.h
	$(COMMAND)

lettresXYZ.o: lettresXYZ.c lettresXYZ.h
	$(COMMAND)

lettresTheta.o: lettresTheta.c lettresTheta.h
	$(COMMAND)

lettresMoteur.o: lettresMoteur.c lettresMoteur.h
	$(COMMAND)

ecritureTraj.o: ecritureTraj.c ecritureTraj.h
	$(COMMAND)

clean:
	-@rm *.o *.exe
	@echo Directory purged.