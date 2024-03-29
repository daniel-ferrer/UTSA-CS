#include <stdio.h>
#include <string.h>
#include "pslibrary.h"

#define READY  0
#define RUNNING  1
#define WAITING  2
#define DONE  3

static char stateChars[] = {'r','R','w','\0'};

/* 1) handle state changes:
   running process completes CPU burst
   running process has quantum expire
   IO complete
   2) do context switch if necessary
   both ready
   one ready and CPU free
   3) append appropriate characters to character arrays
   avoid putting in multiple string terminators
 */
/* assume s1 and s2 point to buffers with enough space to hold the result */
/* assume that the int parameters are strictly greater than 0 */

void fcfs(char *s1, char *s2, int x1, int y1, int z1, int x2, int y2, int z2) {
    int i;                                   /* next string position (time) */
    int state1 = READY;                            /* start with both ready */
    int state2 = READY;
    int cpuLeft1 = x1;                       /* P1 next CPU burst remaining */
    int cpuLeft2 = x2;                       /* P2 next CPU burst remaining */
    int ioLeft1 = y1;        /* P1 next IO burst remaining, 0 if no more IO */
    int ioLeft2 = y2;        /* P2 next IO burst remaining, 0 if no more IO */

    int s1Count = 0;
    int s2Count = 0;
    int cpuCount = 0;
    double avgWaitTime = 0.0;
    double cpuUtilization = 0.0;

    for (i=0; (state1 != DONE) || (state2 != DONE); i++) {
        /* running process completes its CPU burst */
        if ((state1 == RUNNING) && (cpuLeft1 == 0)) {
            if (ioLeft1 == 0) {
                state1 = DONE;
                s1[i] = stateChars[state1];            /* terminate the string */
            }
            else
                state1 = WAITING;
        }
        else if ((state2 == RUNNING) && (cpuLeft2 == 0) ) {
            if (ioLeft2 == 0) {
                state2 = DONE;
                s2[i] = stateChars[state2];            /* terminate the string */
            }
            else
                state2 = WAITING;
        }
        if ((state1 == WAITING) && (ioLeft1 == 0)) {
            state1 = READY;
            cpuLeft1 = z1;
        }  
        if ((state2 == WAITING) && (ioLeft2 == 0)) {
            state2 = READY;
            cpuLeft2 = z2;
        }  
        /* if both ready, depends on algorithm */
        if ( (state1 == READY) && (state2 == READY)) {
            state1 = RUNNING;
        }  
        /* handle one ready and CPU available */
        else if ( (state1 == READY) && (state2 != RUNNING)) {
            state1 = RUNNING;
        }  
        else if ( (state2 == READY) && (state1 != RUNNING)) {
            state2 = RUNNING;
        }  
        /* insert chars in string, but avoid putting in extra string terminators */
        if (state1 != DONE)
            s1[i] = stateChars[state1];
        if (state2 != DONE)
            s2[i] = stateChars[state2];
        /* decrement counts */
        
        if (state1 == RUNNING)
            cpuLeft1--;
        if (state1 == WAITING)
            ioLeft1--;
        if (state2 == RUNNING)
            cpuLeft2--;
        if (state2 == WAITING)
            ioLeft2--;

        // chk for adds to counts
        if(s1[i] == 'r') {
            s1Count++;
        }
        else if(s1[i] == 'R') {
            cpuCount++;
        }

        if(s2[i] == 'r') {
            s2Count++;
        }
        else if(s2[i] == 'R') {
            cpuCount++;
        }

        // get cpu util
        if(strlen(s1) > strlen(s2)) {
            cpuUtilization = (double)cpuCount / strlen(s1);
        }
        else {
            cpuUtilization = (double)cpuCount / strlen(s2);
        }
    }                                               /* end of main for loop */

    avgWaitTime = (s1Count + s2Count) / 2;
    printf("\n");
    printf("Scheduler FCFS: \n");
    printf("%s \n", s1);
    printf("%s \n", s2);
    printf("%d %d %.1lf %.5lf\n", s1Count, s2Count, avgWaitTime, cpuUtilization);
}

void sjf(char *s1, char *s2, int x1, int y1, int z1, int x2, int y2, int z2) {
    int i;                                   /* next string position (time) */
    int state1 = READY;                            /* start with both ready */
    int state2 = READY;
    int cpuLeft1 = x1;                       /* P1 next CPU burst remaining */
    int cpuLeft2 = x2;                       /* P2 next CPU burst remaining */
    int ioLeft1 = y1;        /* P1 next IO burst remaining, 0 if no more IO */
    int ioLeft2 = y2;        /* P2 next IO burst remaining, 0 if no more IO */

    int s1Count = 0;
    int s2Count = 0;
    int cpuCount = 0;
    double avgWaitTime = 0.0;
    double cpuUtilization = 0.0;


    for (i=0; (state1 != DONE) || (state2 != DONE); i++) {
        /* running process completes its CPU burst */
        if ((state1 == RUNNING) && (cpuLeft1 == 0)) {
            if (ioLeft1 == 0) {
                state1 = DONE;
                s1[i] = stateChars[state1];            /* terminate the string */
            }
            else
                state1 = WAITING;
        }
        else if ((state2 == RUNNING) && (cpuLeft2 == 0) ) {
            if (ioLeft2 == 0) {
                state2 = DONE;
                s2[i] = stateChars[state2];            /* terminate the string */
            }
            else
                state2 = WAITING;
        }
        /* runnign proccess has quantum expire */
        if (state1 == RUNNING) {
            state1 = READY;
        }
        if (state2 == RUNNING) {
            state2 = READY;
        }
        /* handle IO complete */
        if ((state1 == WAITING) && (ioLeft1 == 0)) {
            state1 = READY;
            cpuLeft1 = z1;
        }  
        if ((state2 == WAITING) && (ioLeft2 == 0)) {
            state2 = READY;
            cpuLeft2 = z2;
        }  
        /* if both ready, depends on algorithm */
        if ( (state1 == READY) && (state2 == READY)) {
            if (cpuLeft1 < cpuLeft2) {
                state1 = RUNNING;
            } 
            else if (cpuLeft1 > cpuLeft2) {
                state2 = RUNNING;
            } 
            else {
                state1 = RUNNING;
            }
        }  
        /* handle one ready and CPU available */
        else if ( (state1 == READY) && (state2 != RUNNING)) {
            state1 = RUNNING;
        }  
        else if ( (state2 == READY) && (state1 != RUNNING)) {
            state2 = RUNNING;
        }  
        /* insert chars in string, but avoid putting in extra string terminators */
        if (state1 != DONE)
            s1[i] = stateChars[state1];
        if (state2 != DONE)
            s2[i] = stateChars[state2];
        /* decrement counts */
        if (state1 == RUNNING) 
            cpuLeft1--;
        if (state1 == WAITING) 
            ioLeft1--;
        if (state2 == RUNNING)
            cpuLeft2--;
        if (state2 == WAITING)
            ioLeft2--;
        
        // chk for adds to counts
        if(s1[i] == 'r') {
            s1Count++;
        }
        else if(s1[i] == 'R') {
            cpuCount++;
        }

        if(s2[i] == 'r') {
            s2Count++;
        }
        else if(s2[i] == 'R') {
            cpuCount++;
        }

        // get cpu util
        if(strlen(s1) > strlen(s2)) {
            cpuUtilization = (double)cpuCount / strlen(s1);
        }
        else {
            cpuUtilization = (double)cpuCount / strlen(s2);
        }

    }                                               /* end of main for loop */

    avgWaitTime = (s1Count + s2Count) / 2;
    printf("\n");
    printf("Scheduler SJF: \n");
    printf("%s \n", s1);
    printf("%s \n", s2);
    printf("%d %d %.1lf %.5lf\n", s1Count, s2Count, avgWaitTime, cpuUtilization);
}

void psjf(char *s1, char *s2, int x1, int y1, int z1, int x2, int y2, int z2) {

    int i;                                   /* next string position (time) */
    int state1 = READY;                            /* start with both ready */
    int state2 = READY;
    int cpuLeft1 = x1;                       /* P1 next CPU burst remaining */
    int cpuLeft2 = x2;                       /* P2 next CPU burst remaining */
    int ioLeft1 = y1;        /* P1 next IO burst remaining, 0 if no more IO */
    int ioLeft2 = y2;        /* P2 next IO burst remaining, 0 if no more IO */

    int s1Count = 0;
    int s2Count = 0;
    int cpuCount = 0;
    double avgWaitTime = 0.0;
    double cpuUtilization = 0.0;


    for (i=0; (state1 != DONE) || (state2 != DONE); i++) {
        /* running process completes its CPU burst */
        if ((state1 == RUNNING) && (cpuLeft1 == 0)) {
            if (ioLeft1 == 0) {
                state1 = DONE;
                s1[i] = stateChars[state1];            /* terminate the string */
            }
            else
                state1 = WAITING;
        }
        else if ((state2 == RUNNING) && (cpuLeft2 == 0) ) {
            if (ioLeft2 == 0) {
                state2 = DONE;
                s2[i] = stateChars[state2];            /* terminate the string */
            }
            else
                state2 = WAITING;
        }
        if (state1 == RUNNING) {
            state1  = READY;
        }  
        if (state2 == RUNNING) {
            state2 = READY;
        }  
        /* handle IO complete */
        if ((state1 == WAITING) && (ioLeft1 == 0)) {
            state1 = READY;
            cpuLeft1 = z1;
        }  
        if ((state2 == WAITING) && (ioLeft2 == 0)) {
            state2 = READY;
            cpuLeft2 = z2;
        }  
        if ((state1 == RUNNING) && (cpuLeft1 > cpuLeft2) && (cpuLeft2 != 0)) {
            state1 = READY;
            state2 = RUNNING;
        }
        if ((state2 == RUNNING) && (cpuLeft1 < cpuLeft2) && (cpuLeft1 != 0)) {
            state1 = RUNNING;
            state2 = READY;
        }
        /* if both ready, depends on algorithm */
        if ( (state1 == READY) && (state2 == READY)) {
            if (cpuLeft1 < cpuLeft2) {
                state1 = RUNNING;
            } 
            else if (cpuLeft1 > cpuLeft2) {
                state2 = RUNNING;
            }
            else {
                state1 = RUNNING;
            }
        }  
        /* handle one ready and CPU available */
        else if ( (state1 == READY) && (state2 != RUNNING)) {
            state1 = RUNNING;
        }  
        else if ( (state2 == READY) && (state1 != RUNNING)) {
            state2 = RUNNING;
        }  
        /* insert chars in string, but avoid putting in extra string terminators */
        if (state1 != DONE)
            s1[i] = stateChars[state1];
        if (state2 != DONE)
            s2[i] = stateChars[state2];
        /* decrement counts */
        if (state1 == RUNNING)
            cpuLeft1--;
        if (state1 == WAITING)
            ioLeft1--;
        if (state2 == RUNNING)
            cpuLeft2--;
        if (state2 == WAITING)
            ioLeft2--;

        // chk for adds to counts
        if(s1[i] == 'r') {
            s1Count++;
        }
        else if(s1[i] == 'R') {
            cpuCount++;
        }

        if(s2[i] == 'r') {
            s2Count++;
        }
        else if(s2[i] == 'R') {
            cpuCount++;
        }

        // get cpu util
        if(strlen(s1) > strlen(s2)) {
            cpuUtilization = (double)cpuCount / strlen(s1);
        }
        else {
            cpuUtilization = (double)cpuCount / strlen(s2);
        }

    }                                               /* end of main for loop */

    avgWaitTime = (s1Count + s2Count) / 2;
    printf("\n");
    printf("Scheduler PSJF: \n");
    printf("%s \n", s1);
    printf("%s \n", s2);
    printf("%d %d %.1lf %.5lf\n", s1Count, s2Count, avgWaitTime, cpuUtilization);
}

void rr(char *s1, char *s2, int q, int x1, int y1, int z1, int x2, int y2, int z2) {
    int i;                                   /* next string position (time) */
    int state1 = READY;                            /* start with both ready */
    int state2 = READY;
    int cpuLeft1 = x1;                       /* P1 next CPU burst remaining */
    int cpuLeft2 = x2;                       /* P2 next CPU burst remaining */
    int ioLeft1 = y1;        /* P1 next IO burst remaining, 0 if no more IO */
    int ioLeft2 = y2;        /* P2 next IO burst remaining, 0 if no more IO */

    int qleft = q;
    int s1Count = 0;
    int s2Count = 0;
    int cpuCount = 0;
    double cpuUtilization = 0.0;
    double avgWaitTime = 0.0;

    for (i=0; (state1 != DONE) || (state2 != DONE); i++) {
        /* running process completes its CPU burst */
        if ((state1 == RUNNING) && (cpuLeft1 == 0)) {
            if (ioLeft1 == 0) {
                state1 = DONE;
                s1[i] = stateChars[state1];            /* terminate the string */
            }
            else
                state1 = WAITING;
        }
        else if ((state2 == RUNNING) && (cpuLeft2 == 0) ) {
            if (ioLeft2 == 0) {
                state2 = DONE;
                s2[i] = stateChars[state2];            /* terminate the string */
            }
            else
                state2 = WAITING;
        }
        /* running process has quantum expire */
        if ((state1 == RUNNING) && (qleft == 0) ) {
            state1 = READY;
            if (state2 == READY) {
                state2 = RUNNING;
                qleft = q;
            }
            
        }  
        if ((state2 == RUNNING) && (qleft == 0) ) {
            state2 = READY;
            if (state1 == READY) {
                state1 = RUNNING;
                qleft = q;
            }
        }  
        /* handle IO complete */
        if ((state1 == WAITING) && (ioLeft1 == 0)) {
            state1 = READY;
            cpuLeft1 = z1;
        }  
        if ((state2 == WAITING) && (ioLeft2 == 0)) {
            state2 = READY;
            cpuLeft2 = z2;
        }  
        /* if both ready, depends on algorithm */
        if ( (state1 == READY) && (state2 == READY)) {
            state1 = RUNNING;
            qleft = q;
        }  
        /* handle one ready and CPU available */
        else if ( (state1 == READY) && (state2 != RUNNING)) {
            state1 = RUNNING;
            qleft = q;
        }  
        else if ( (state2 == READY) && (state1 != RUNNING)) {
            state2 = RUNNING;
            qleft = q;
        }  
        /* insert chars in string, but avoid putting in extra string terminators */
        if (state1 != DONE)
            s1[i] = stateChars[state1];
        if (state2 != DONE)
            s2[i] = stateChars[state2];
        /* decrement counts */
        qleft--;                   /* OK to decrement even if nothing running */
        if (state1 == RUNNING)
            cpuLeft1--;
        if (state1 == WAITING)
            ioLeft1--;
        if (state2 == RUNNING)
            cpuLeft2--;
        if (state2 == WAITING)
            ioLeft2--;

        // chk for adds to counts
        if(s1[i] == 'r') {
            s1Count++;
        }
        else if(s1[i] == 'R') {
            cpuCount++;
        }

        if(s2[i] == 'r') {
            s2Count++;
        }
        else if(s2[i] == 'R') {
            cpuCount++;
        }

        // get cpu util
        if(strlen(s1) > strlen(s2)) {
            cpuUtilization = (double)cpuCount / strlen(s1);
        }
        else {
            cpuUtilization = (double)cpuCount / strlen(s2);
        }
    }                                               /* end of main for loop */

    avgWaitTime = (s1Count + s2Count) / 2;
    printf("\n");
    printf("Scheduler RR: \n");
    printf("%s \n", s1);
    printf("%s \n", s2);
    printf("%d %d %.1lf %.5lf\n", s1Count, s2Count, avgWaitTime, cpuUtilization);
}
