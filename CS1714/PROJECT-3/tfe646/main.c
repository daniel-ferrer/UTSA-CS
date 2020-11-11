#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cards.h"

int main( int argc, char *argv[] )
{
	FILE *fptr;

	if(argc < 3)
  	{
  		printf("ERROR NOT ENOUGH ARGS\n");
  		return 1;
  	}
  	else if (argc >= 3)
  	{
    	fptr = fopen(argv[1], "r");
  	}
  	else
  	{
    	fptr = fopen("project3-output.txt", "r");
  	}

  	if (fptr == NULL)
  	{ 
    	printf("ERROR FILE NOT OPEN\n");
    	return 1; 
  	} 

	fclose(fptr);

	return 0;
}