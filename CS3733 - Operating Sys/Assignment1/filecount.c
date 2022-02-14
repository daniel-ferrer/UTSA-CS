#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

// by Daniel Ferrer-Sosa (tfe646)

int CountWords(char* filename, int ppid); // prototype


int main(int argc, char* argv[]) {

    if(argc == 1) {
        printf("No filenames provided\nSample: ./a.out file1 file2 file3 ...\n");
        return -1;
    }


    int filesToProcess = argc;
    
    int parent_pid = getpid();


    int i, status;
    for(i = 1; i < filesToProcess; i++)
    {
        int pid = fork();
        if(pid == 0) // child process
        {
            int wordCount = CountWords(argv[i], parent_pid);
            if(wordCount > 0) {
                printf("Child process for %s: number of words is %d\n", argv[i], wordCount);
            }
        }
        else { // parent process
            if(parent_pid == getpid()){ 
                wait(&status);
            }
        }
    }
    printf("All %d files have been counted.", filesToProcess-1);
    return 0;
}


int CountWords(char* filename, int ppid) {
    char ch;
    int count = 0;

    if(ppid == getppid())  // only child processes, this will avoid exponential fork() execution
    {
        FILE* fptr = fopen(filename, "r");

        if(fptr == NULL) {
            printf("Error opening file.\n");
            return -1;
        }

        // space and tab char will act as delims
        // increase count when found
        while((ch = fgetc(fptr)) != EOF) {
            if(ch == ' ' || ch == '\t') {
                count++;
            }
        }
        return count;
    }

    else {
        return -1;
    }
}
