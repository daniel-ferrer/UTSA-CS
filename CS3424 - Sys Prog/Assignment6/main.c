#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int startIdx = 1;
    int endIdx, i;

    for(i = 1; i < argc; ++i) {
        if(strcmp(argv[i], ":") == 0) {
            endIdx = i;
            execute(argv, startIdx, endIdx);
            startIdx = i + 1;
        }
    }

    endIdx = argc;
    execute(argv, startIdx, endIdx);

    while(wait(NULL) > 0);

    return 0;
}

void execute(char *argv[], int startIdx, int endIdx) {
    int i;
    int argCount = endIdx - startIdx + 1;

    char *args[argCount];
    for(i = 0; i < argCount - 1; ++i) {
        args[i] = argv[i + startIdx];
    } 
    args[argCount - 1] = NULL;

    if(fork() != 0) {
        return;
    }

    printf("PID: %d, PPID: %d, CMD: %s\n", getpid(), getppid(), argv[startIdx]);

    execvp(argv[startIdx], args);

}
