routerecs: main.o routeRecords.o
   gcc main.o routeRecords.o -o routerecs
main.o: main.c routeRecords.h
   gcc -c main.c
routeRecords.o: routeRecords.c routeRecords.h
   gcc -c routeRecords.c
clean:
   rm *.o routerecs