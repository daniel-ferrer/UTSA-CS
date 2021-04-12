#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "routeRecords.h"

RouteRecord* createRecords(FILE* fileIn)
{
	fseek(fileIn, 0, SEEK_SET); //Set cursor at beginning of file

	int i, count = 0;
	char c;

	//Count number of total records in file
	for(c = getc(fileIn); c != EOF; c = getc(fileIn))
	{
		if(c == '\n')
		{
			count++;
		}
	}

	//printf("%d", count); //This prints 13357

  	RouteRecord *r = (RouteRecord*)malloc((count + 1) * sizeof(RouteRecord)); //Alloc memory for array

  	for(i = 0; i < count+1; i++)
  	{
  		//Initialize each passenger val to 0
  		r[i].passengers[0] = 0;
  		r[i].passengers[1] = 0;
  		r[i].passengers[2] = 0;
  		r[i].passengers[3] = 0;
  		r[i].passengers[4] = 0;
  		r[i].passengers[5] = 0;
  	}

  	rewind(fileIn); //Rewind file pointer

  	return r; //Return populated array
}

int fillRecords(RouteRecord* r, FILE* fileIn)
{
	char type[10], origin[4], destination[4], airline[3], buffer[1024];
	int i = 0, totalPassengers = 0, curMonth = 0, numOfRouteRecords = 0, foundIdx = 0;
	fseek(fileIn, 43, SEEK_SET); //Set cursor at beginning of file, skipping first row

	while(fgets(buffer, 1024, fileIn))
	{
		fscanf(fileIn, "%d%*c %[^,]%*c %[^,]%*c %[^,]%*c %[^,]%*c %d[^,]", &curMonth, origin, destination, airline, type, &totalPassengers);
		
		if(findAirlineRoute(r, numOfRouteRecords, origin, destination, airline, i) == -1)
		{
			strcpy(r[i].origin, origin);
			strcpy(r[i].destination, destination);
			strcpy(r[i].airline, airline);
			r[i].passengers[curMonth] += totalPassengers;
			numOfRouteRecords++;
		}
		else if(findAirlineRoute(r, numOfRouteRecords, origin, destination, airline, i) != -1)
		{
			foundIdx = findAirlineRoute(r, numOfRouteRecords, origin, destination, airline, i);
			r[foundIdx].passengers[curMonth] += totalPassengers;
		}

		i++;
	}
	printf("Unique routes operated by airlines: %d", numOfRouteRecords);
	return numOfRouteRecords;
}

int findAirlineRoute(RouteRecord* r, int length, const char* origin, 
	const char* destination, const char* airline, int curIdx)
{

	int i = 0, temp = -1; //Function will return temp(-1) if no match is found
	while(i < length)
	{
		if(strcmp(r[i].origin, origin) == 0) //If origins match
		{
			if(strcmp(r[i].destination, destination) == 0) //If destinations match
			{
				if(strcmp(r[i].airline, airline) == 0) //If airlines match
				{
					temp = i; //If match is found, set temp equal to current index
					printf("Found 3 matches at index %d\n", temp);
					break;
				}
			}
		}
		i++; //Increase index to check next object
	}
	return temp; //Return index where match was found
}

void SearchRecords(RouteRecord* r, int length, const char* key1,
	const char* key2, SearchType st)
{
	int i = 0, count = 0, tempIdx = 0;;
	char origin[4], destination[4], airline[3];
	while(i < length)
	{
		if(st == 1)
		{
			/*strcpy(r[i].origin, key1);
			strcpy(r[i].destination, key2);
			strcpy(r[i].airline, airline);*/
			i = findAirlineRoute(r, length, key1, key2, airline, 0);

			//strcpy(key1, r[i].origin);
			//strcpy(key2, r[i].destination);
			strcpy(airline, r[i].airline);
			
			printf("%s (%s-%s) ", airline, key1, key2);
			count++;
		}
		else if(st == 2)
		{
			/*strcpy(r[i].destination, key1);
			strcpy(r[i].origin, origin);
			strcpy(r[i].airline, airline);*/

			strcpy(key1, r[i].destination);
			strcpy(origin, r[i].origin);
			strcpy(airline, r[i].airline);

			printf("%s (%s-%s) ", airline, origin, key1);
			count++;	
		}
		else if(st == 3)
		{
			/*strcpy(r[i].origin, key1);
			strcpy(r[i].airline, airline);
			strcpy(r[i].destination, destination);*/

			strcpy(key1, r[i].origin);
			strcpy(airline, r[i].airline);
			strcpy(destination, r[i].destination);
			
			printf("%s (%s-%s) ", airline, key1, destination);
			count++;
		}
		else if(st == 4)
		{
			/*strcpy(r[i].airline, key1);
			strcpy(r[i].origin, origin);
			strcpy(r[i].destination, destination);*/

			strcpy(key1, r[i].airline);
			strcpy(origin, r[i].origin);
			strcpy(destination, r[i].destination);

			printf("%s (%s-%s) ", key1, origin, destination);
			count++;
		}
	i++;
	}
	printf("%d matches were found.", count);
}

void printRecords(RouteRecord* r, int length);

void printRecord(RouteRecord* r);

void printMenu()
{
	printf( "\n\n######### Airline Route Records Database MENU #########\n" );
	printf( "1. Search by Route\n" );
	printf( "2. Search by Origin Airport\n" );
	printf( "3. Search by Destination Airport\n" );
	printf( "4. Search by Airline\n" );
	printf( "5. Quit\n" );
	printf( "Enter your selection: " );
}