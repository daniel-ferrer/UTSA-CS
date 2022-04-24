#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
    int pageTable[] = {2, 4, 1, 7, 3, 5, 6};
    int pageNum, frameNum, offset;

    FILE *infile, *outfile;
    unsigned long vAddress, pAddress;

    char c;

    if(argc != 3) { 
        printf("Not enough/Too many arguments passed.");
        return -1;
    }

    infile = fopen(argv[1],"rb+");
    outfile = fopen(argv[2], "wb+");
    if(infile == NULL) {
        printf("Error opening file");
        exit(1);
    }

    while ((c = feof(infile)) != EOF) {
        if(fread(&vAddress, sizeof(unsigned long), 1, infile) != 1) {
            break;
        }

        pageNum = vAddress >> 7;
        offset = vAddress & 0x07f;
        frameNum = pageTable[pageNum];
        pAddress = (frameNum << 7) + offset;

        fprintf(outfile, "Virtual address: 0x%lx\nPhysical address: 0x%lx\n\n", vAddress, pAddress);
    }

    fclose(infile);
    fclose(outfile);

    return 0;
}
