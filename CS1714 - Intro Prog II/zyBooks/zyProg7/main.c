#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flights.h"

int main(int argc, char* argv[])
{ 
  Flight temp;
  FILE *fptr;
  char userIn[2];
  int totalPass = 0, numAirlineFlights = 0, count = 0;

  if (argc < 2) 
  {
    printf("ERROR NO ARGS");
    return 1;
  }
  else if (argc >= 2)
  {
    fptr = fopen(argv[1], "r");
  }
  else
  {
    fptr = fopen("passenger-data-short.csv", "r");
  }

  if (fptr == NULL)
  { 
    printf("ERROR FILE NOT OPEN");
    return 1; 
  } 

  fseek(fptr, 0, SEEK_SET);

  Flight *FArray = (Flight*)malloc((NUM_FLIGHTS + 1) * sizeof(Flight));

  while(count < NUM_FLIGHTS)
  {
    fscanf(fptr, "%s,%s,%s,%d", FArray[count].origin, FArray[count].destination, FArray[count].airline, &FArray[count].passengers);
    printf("%d\n", FArray[count].passengers);
    count++;
  }

  scanf("%s", userIn);

  for(int i = 0; i < NUM_FLIGHTS; i++)
  {
    if(FArray[i].airline == userIn)
    {
      totalPass += FArray[i].passengers;
      numAirlineFlights++;
    }
  }

  printf("airline: %s\nflights: %d\npassengers: %d", userIn, numAirlineFlights, totalPass);

  fclose(fptr);
  free(FArray);

  return 0;
}