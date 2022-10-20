#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    int i, p1Tmp = 0;
    unsigned long LA, PA;
    char *inFile, *outFile;
    unsigned int pNum, fNum, dNum;
    unsigned int p = 5, f = 3, d = 7;
    unsigned int PT[32] = {2, 4, 1, 7, 3, 5, 6, 0};

    if(argv[1] != NULL)
        inFile = argv[1];
    else {
        fprintf(stderr, "No input file specified\n");
        exit(-1);
    }
        
    if(argv[2] != NULL)
        outFile = argv[2];
    else {
        fprintf(stderr, "No output file specified\n");
        exit(-1);
    }

    for(i = 0; i < argc; i++) {
        if(strncmp("part1-out-test", argv[i], 14) == 0)
            p1Tmp = 1;
    }

    int pageCount = 0;
    FILE *fp, *writeFile;

    if(fp == NULL && writeFile == NULL) {
        fp = fopen(inFile, "r");
        writeFile = fopen(outFile, "w");

        while(fread(&LA, sizeof(unsigned long), 1, fp) == 1) {
            dNum = (LA & 0x7F);
            pNum = (LA >> d);
            fNum = PT[pNum];
            PA = (fNum << d) + dNum;

            if(p1Tmp != 0)
                printf("The LA is %lx and Translated PA is %lx\n", LA, PA);
            
            fwrite(&PA, sizeof(unsigned long), 1, writeFile);
            pageCount++;
        }

        if(p1Tmp != 0)
            printf("total number of pages = %d\n", pageCount);

        fclose(fp);
        fclose(writeFile);
    }
    else
    {
        fprintf(stderr, "Could not open input file\n");
        exit(-1);
    }
    return 0;
}