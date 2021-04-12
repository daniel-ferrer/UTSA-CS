#ifndef ROUTE_RECORDS_H
#define ROUTE_RECORDS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum SearchType
{
	ROUTE,
	ORIGIN,
	DESTINATION,
	AIRLINE
} SearchType;

typedef struct RouteRecord
{
	char origin[4], destination[4], airline[3];
	int passengers[6];
} RouteRecord;

RouteRecord* createRecords(FILE* fileIn);

int fillRecords(RouteRecord* r, FILE* fileIn);

int findAirlineRoute(RouteRecord* r, int length, const char* origin, 
	const char* destination, const char* airline, int curIdx);

void SearchRecords(RouteRecord* r, int length, const char* key1,
	const char* key2, SearchType st);

void printRecords(RouteRecord* r, int length);

void printRecord(RouteRecord* r);

void printMenu();

#endif //ROUTE_RECORDS_H