#include <stdio.h>
#include <stdlib.h>
#include "pslibrary.h"

int main(int argc, char *argv[]) {
    
    if(argc != 8) {
        perror("Invalid amount of parameters, please try again");
        return EXIT_FAILURE;
    }
    else {
        printf("CS 3733 Assignment 2, written by Daniel Ferrer-Sosa");
        
        int i;
        for(i = 1; i < argc; i++) {
            printf("%d ", argv[i]);
        }
        printf("\n");
    }
    
    /*TODO: call the 4 scheduler functions
            each call should display 5 lines: - a blank line servers as separator
                                              - heading line to indicate the scheduler function
                                              - the two output strings
                                              - four numeric values in the same line
    */

    // FCFS Scheduler call

    // SJF Scheduler call

    // PSJF Scheduler call

    // RR Scheduler call




    return 0;
}