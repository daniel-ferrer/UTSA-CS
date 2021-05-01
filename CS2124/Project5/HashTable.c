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
    //return atoi(stringToConvert);
    int i = 0, sum = 0;
    char ch = stringToConvert[i];
    printf("len of str is %ld\n", strlen(stringToConvert));

    for(i = 0; ch != '\0' && ch != '\n' && ch != '\r'; i++) {
        ch = stringToConvert[i];
        sum += stringToConvert[i];
    }
    sum = abs(sum);
    printf("the sum is %d\n", sum);
    return sum;
    

//    int i, total = 0;
//    char ch = stringToConvert[0];
   
//     for(i = 0; ch != '\0'; i++) {
//         ch = stringToConvert[i];
//         if(ch == ' ' || ch == '\0') {
//             continue;
//         }
//         //printf("this is to lower %d\n", tolower(ch)-96);
//         total += tolower(ch) - 96;
//     }

//     //printf("total is %d\n", total);
//     //printf("String to convert is %s\n", stringToConvert);

//     return total;
}


//Given a key value, use the division method to find a 
//valid index for hashTable.
int divisionMethod(int key, int n) {
    return (key % n);
}

int countDigits(int num) {
    int count = 0;
    while(num != 0) {
        count++;
        num /= 10;
    }
    return count;
}

int powerOfNum(int num, int cnt) {
    while(cnt != 0) {
        num *= 10;
        cnt--;
    }
    return num;
}


//Given a key value, use the midsquare method to find a 
//valid index for hashTable.
int midsquareMethod(int key, int n) {
    key = abs(key*key);
    int temp = countDigits(key);
    printf("this is temp %d\n", temp);
    int min = countDigits(n);
    printf("this is min %d\n", min);
    int num1, num2;

    if(temp < min) {
        return temp;
    }

    num1 = powerOfNum(10, (temp-ceil((temp-min)/2)));
    num2 = powerOfNum(10, (temp-min)/2);
    key %= num1;
    key /= num2;
    return key;
}


//Insert e into our HashTable h by using stringToInt to convert the team name
//into an integer and then passing that integer to one of the division or 
//midsquare method functions.  If this entry is not occupied, insert it there
//and change the corresponding iChainIndex to be -1.  If there is a collision,
//use open chaining to find an open location for e, and update the iChainIndex
//values accordingly.
void put(HashTable h, Element e) {
    int key, idx, i = 0;
    printf("team name to get is %s\n", e.teamName);
    key = stringToInt(e.teamName);
    printf("key is %d\n", key);
    idx = midsquareMethod(divisionMethod(key, h->n), h->n);
    printf("this is idx %d\n", idx);
    

    while(h->hashTable[idx].chainIndex != -2) {
        idx += 1;
        idx %= h->n;
        i++;

        if(i == h->n) {
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
    //printf("team name to get is %s\n", teamName);
    key = stringToInt(teamName);
    //printf("key is %d\n", key);
    idx = midsquareMethod(key, h->n);
    //printf("this is idx %d\n", idx);

    while(strcmp(h->hashTable[idx].key.teamName, teamName) != 0) {
        idx++;
        idx %= h->n;
    }
    return &(h->hashTable[idx].key);
}