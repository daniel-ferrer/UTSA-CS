cardgame: main.o cards.o
   gcc main.o cards.o -o cardgame
main.o: main.c cards.h
   gcc -c main.c
cards.o: cards.c cards.h
   gcc -c cards.c
clean:
   rm *.o cardgame
