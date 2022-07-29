CC=gcc
CFLAGS=-ansi -Wall
OBJ=Main.o Affichage.o Jeu.o Test.o

dames: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) -lncurses

Main.o: Main.c Affichage.h Test.h

Affichage.o: Affichage.c Jeu.h

Jeu.o: Jeu.c

Test.o: Test.c Jeu.h

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o

mrproper: clean
	rm -f dames