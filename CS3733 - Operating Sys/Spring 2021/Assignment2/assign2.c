#include <stdio.h>
#include <stdlib.h>
#include "pslibrary.h"

int main(int argc, char *argv[]) {
    
    if(argc != 8) {
        perror("Invalid amount of arguments");
        return EXIT_FAILURE;
    }
    else {
        printf("CS 3733 Assignment 2, written by Daniel Ferrer-Sosa ");
        
        int i;
        for(i = 1; i < argc; i++) {
            printf("%d ", atoi(argv[i]));
        }
        printf("\n");

        char s1[66];
        char s2[66];
        int q = atoi(argv[1]);
        int x1 = atoi(argv[2]);
        int x2 = atoi(argv[3]);
        int y1 = atoi(argv[4]);
        int y2 = atoi(argv[5]);
        int z1 = atoi(argv[6]);
        int z2 = atoi(argv[7]);

        fcfs(s1, s2, x1, y1, z1, x2, y2, z2);
        sjf(s1, s2, x1, y1, z1, x2, y2, z2);
        psjf(s1, s2, x1, y1, z1, x2, y2, z2);
        rr(s1, s2, q, x1, y1, z1, x2, y2, z2);
    }

    return 0;
}
