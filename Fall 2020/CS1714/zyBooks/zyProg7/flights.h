#include<stdio.h>

#define NUM_FLIGHTS 200

typedef struct Flight
{
    char origin[4],destination[4],airline[3];
    int passengers;
}Flight;