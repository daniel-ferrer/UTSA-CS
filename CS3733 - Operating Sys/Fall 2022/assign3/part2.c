#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>


struct PageTable {
    int fNum, Vi;
};

int FindEmptyFrame(int arr[]);
int FindLRU(int arr[]);

int main(int argc, char *argv[]) {
    
    int i, j;
    int count = 0, clk = 0;
    unsigned long LA, PA;
    unsigned int pNum, fNum, dNum;
    unsigned int p = 5, f = 3, d = 7;
    struct PageTable PT[32];
    int countLRU[8] = {0}, revMap[8] = {-1};
    int freeFrames[8] = {0, 1, 1, 1, 1, 1, 1, 1};
    FILE *inFile = NULL, *outFile = NULL;

    for(i = 0; i < 33; i++) {
        PT[i].Vi = 0;
    }

    if(argv[1] != NULL)
        inFile = fopen(argv[1], "r");
    else {
        fprintf(stderr, "Input file not found\n");
        exit(-1);
    }

    if(argv[2] != NULL) {
        outFile = fopen(argv[2], "w");
    }
    else {
        fprintf(stderr, "Output file not found\n");
        exit(-1);
    }

    if(inFile == NULL) {
        fprintf(stderr, "Could not open input file\n");
        exit(-1);
    }

    while(fread(&LA, sizeof(unsigned long), 1, inFile) == 1) {
        clk++;
        dNum = (LA & 0x07F);
        pNum = (LA >> d);

        if(PT[pNum].Vi == 1) {
            fNum = PT[pNum].fNum;
            PA = (fNum << d) + dNum;
            fwrite(&PA, sizeof(unsigned long), 1, outFile);
            countLRU[fNum] = clk;
        }
        else {
            int emptyFrame = FindEmptyFrame(freeFrames);
            count++;

            if(emptyFrame > 0) {
                PT[pNum].fNum = emptyFrame;
                PT[pNum].Vi = 1;

                fNum = PT[pNum].fNum;
                PA = (fNum << d) + dNum;
                fwrite(&PA, sizeof(unsigned long), 1, outFile);
                revMap[emptyFrame] = pNum;
                countLRU[fNum] = clk;
                freeFrames[emptyFrame] = 0;
            }
            else {
                int index = FindLRU(countLRU);
                PT[revMap[index]].Vi = 0;
                PT[pNum].fNum = index;
                PT[pNum].Vi = 1;
                fNum = PT[pNum].fNum;
                PA = (fNum << d) + dNum;
                fwrite(&PA, sizeof(unsigned long), 1, outFile);
                countLRU[fNum] = clk;
                revMap[fNum] = pNum;
            }
        }
    }
    printf("Part 2 page faults: %d\n", count);
    fclose(inFile);
    fclose(outFile);
    return 0;
}

int FindEmptyFrame(int arr[]) {
    int i;

    for(i = 1; i < 8; i++) {
        if(arr[i] > 0) {
            return i;
        }
    }
    return -1;
}

int FindLRU(int arr[]) {
    int i;
    int index = 0, min = 4500;
    
    for(i = 1; i < 8; i++) {
        if(min > arr[i]) {
            index = i;
            min = arr[i];
        }
    }
    return index;
}