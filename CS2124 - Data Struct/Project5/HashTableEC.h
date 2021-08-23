/****************************
 HashTable.h

Purpose:
	This file is for Extra Credit only.  If you are not interested in doing
	the extra credit then you can ignore this file.
 *************************/


#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

//Defining the maximum team name length.
#define MAX_NAME_LENGTH 50

//TRUE and FALSE constants
#define TRUE 1
#define FALSE 0


//Defining an ElementEC to be the data for a team.
typedef struct
{
    char teamName[MAX_NAME_LENGTH];
    int wins;
    int losses;
} ElementEC;

//Typedef for a node a linked list.
typedef struct NodeLL
{
    ElementEC element;
    struct NodeLL *next;
} NodeLL;


//Defining the a struct for a Hash Table Implementation.
typedef struct
{
	int n;
	//The size of the array to store all the data.

	NodeLL **hashTable;
	//Pointer that we will use ty dynamically allocate an array of NodeLL*'s.
	//For each i between 0 and n-1, hashTable[i] should be a head pointer to a linked list containing 
	//every team that hashed to index i.
	
} HashTableECImp;


//Defining a HashTable to be a HashTableImp Pointer.
typedef HashTableECImp *HashTableEC;



/*****FUNCTION PROTOTYPES**********/

//Malloc a new HashTableImp, malloc the hashTable to be an array of NodeLL* of size n, 
//and set each of these n pointers to be NULL.
HashTableEC newHashTableEC(int n);


//Free all nodes in all linked lists, then free hashTable, then free h itself.
void freeHashTableEC(HashTableEC h);


//Given a string, convert it into an integer to be used in either
//the division method or the midsquare method.
int stringToInt(char *stringToConvert);


//Given a key value, use the division method to find a 
//valid index for hashTableM.
int divisionMethod(int key, int n);


//Given a key value, use the midsquare method to find a 
//valid index for hashTableM.
int midsquareMethod(int key, int n);

//Allocate a new node and store "value" as the ElementEC in the node.  Return the address of the node.
NodeLL *allocateNode(ElementEC value);


//Insert e into our HashTable h by using stringToInt to convert the team name
//into an integer and then passing that integer to one of the division or 
//midsquare method functions.  Add e as a new node at the beginning of the
//linked list corresponding to the chosen index.
void put(HashTableEC h, ElementEC e);


//Return the address of the struct stored in HashTable h from the
//team name stored in teamName.  If it does not exist, return NULL.
ElementEC* get(HashTableEC h, char *teamName);

