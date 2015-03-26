TARGET:=prog.exe
CFLAGS:=-c -O2 -std=c11
<<<<<<< HEAD
LFLAGS:=-lSDL2main  -L. -lSDL2 -lm
=======
LFLAGS:=-lSDL2 -lSDL2_ttf

ifeq ($(OS),Windows_NT)
	LFLAGS+=-lSDL2main -L.
endif
>>>>>>> origin/yolo

$(TARGET): main.o calcul.o conversion.o lettresXYZ.o ecriture_Traj.o lettres_theta.o lettres_moteur.o
	gcc  -o $(TARGET) main.o calcul.o conversion.o lettresXYZ.o ecriture_Traj.o lettres_theta.o lettres_moteur.o $(LFLAGS)

main.o: main.c calcul.h
	gcc $(CFLAGS) main.c

calcul.o: calcul.c calcul.h
	gcc $(CFLAGS) calcul.c
	
lettresXYZ.o: lettresXYZ.c lettresXYZ.h
	gcc $(CFLAGS) lettresXYZ.c

conversion.o: conversion.c conversion.h
	gcc $(CFLAGS) conversion.c

<<<<<<< HEAD
ecriture_Traj.o: ecriture_Traj.c ecriture_Traj.h
	gcc $(CFLAGS) ecriture_Traj.c

lettres_theta.o: lettres_theta.c lettres_theta.h
	gcc $(CFLAGS) lettres_theta.c

lettres_moteur.o: lettres_moteur.c lettres_moteur.h
	gcc $(CFLAGS) lettres_moteur.c

=======
>>>>>>> origin/yolo
clean:
	rm *.o *.exe