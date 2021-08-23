#include "HashTable.h"

/******
 * In this file, provide all of the definitions of the hash table functions as described in HashTable.h.
 *
 * ****/

//Malloc a new HashTableImp, malloc the hashTable to be an array of HashTableEntrys of size n, 
//initialize each iChainIndex to be -2 (indicating that the spot is empty), 
//and return a pointer to the HashTableImp.
HashTable newHashTable(int n) {
    HashTableImp* ht = (HashTableImp*)malloc(sizeof(HashTableImp));
    ht->n = n;
    ht->hashTable = (HashTableEntry*)malloc(n * sizeof(HashTableEntry));

    int i;
    for(i = 0; i < n; i++) {
        ht->hashTable[i].chainIndex = -2;
    }

    return ht;
}


//Free the HashTable h.
void freeHashTable(HashTable h) {
    free(h->hashTable);
    free(h);
}


//Given a string, convert it into an integer to be used in either
//the division method or the midsquare method.
int stringToInt(char *stringToConvert) {
    cleanString(stringToConvert);

    int i, sum = 0, cnt = 0;
    char ch = stringToConvert[0];

    for(i = 0; ch != '\0'; i++) {
        ch = stringToConvert[i];
        sum += stringToConvert[i];

        if(ch == ' ') {
            cnt++;
        }
    }

    sum = abs(sum) - 48 - (32*cnt);
    return sum;
}


//Given a key value, use the division method to find a 
//valid index for hashTable.
int divisionMethod(int key, int n) {
    return (key % n);
}

//Helper function to count number of digits of int
int countDigits(int num) {
    int count = 0;
    while(num != 0) {
        count++;
        num /= 10;
    }
    return count;
}

//Helper function to remove carriage return from stringToClean
void cleanString(char* stringToClean) {
    char *src, *dst;
    for(src = dst = stringToClean; *src != '\0'; src++) {
        *dst = *src;
        if(*dst != '\r') {
            dst++;
        }
    }
    *dst = '\0';
}


//Given a key value, use the midsquare method to find a 
//valid index for hashTable.
int midsquareMethod(int key, int n) {
    key = abs(key*key);
    int digits = countDigits(key);
    key = (int)(key / pow(10, digits / 2)) % 100;

    return divisionMethod(key, 100);
}


//Insert e into our HashTable h by using stringToInt to convert the team name
//into an integer and then passing that integer to one of the division or 
//midsquare method functions.  If this entry is not occupied, insert it there
//and change the corresponding iChainIndex to be -1.  If there is a collision,
//use open chaining to find an open location for e, and update the iChainIndex
//values accordingly.
void put(HashTable h, Element e) {
    int key, idx, i = 0;

    key = stringToInt(e.teamName);
    idx = midsquareMethod(key, h->n);
    
    while(h->hashTable[idx].chainIndex != -2) {
        idx += 1;
        idx %= h->n;
        i++;

        if(i == 100) {
            return;
        }
    }
    h->hashTable[idx].key = e;
    h->hashTable[idx].chainIndex = -1;
}


//Return a pointer to the key stuct containing the data that matches teamName
//if it exists.  If it does not exist, return NULL.
Element* get(HashTable h, char *teamName) {
    int key, idx;

    key = stringToInt(teamName);
    idx = midsquareMethod(key, h->n);

    while(strcmp(h->hashTable[idx].key.teamName, teamName) != 0) {
        idx++;
        idx %= h->n;
    }
    return &(h->hashTable[idx].key);
}