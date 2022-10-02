#include <fcntl.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h> 
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) 
{ 
    char buf;
    int Pipe1[2];
    int Pipe2[2];
    int ch1pid, ch2pid; 
    int numread, numwrite, status; 

    if(pipe(Pipe1) == -1)
    { 
        perror("Failed to create pipe 1\n"); 
        return 1;
    }

    if((ch1pid = fork()) == -1) 
    { 
        perror("Failed to create child 1\n");
        return 1;
    }
    if(ch1pid == 0) 
    { 
        if(dup2(Pipe1[1], STDOUT_FILENO)== -1) 
        { 
            perror("ch1 cannot redirect pipe1[1] to stdout\n");
            return 1;
        }
        else if (close(Pipe1[1]) == -1 || close(Pipe1[0]) ==-1)
        { 
            perror("ch1 cannot close extra pipe 1 fd\n");
            return 1;
        }
        else
        {
            //fprintf(stderr, "Child1: ready\n");
            execl(argv[1], "prog1", NULL); 
            perror("Failed to exec prog1");
        }
        return 1;
    }

    if(pipe(Pipe2) == -1) 
    { 
        perror("Failed to create pipe 2\n"); 
        return 1;
    }
	
    if((ch2pid = fork()) == -1) 
    { 
        perror("Failed to create child 2\n");
        return 1;
    }

    if(ch2pid == 0) 
    { 
        if(dup2(Pipe2[0], STDIN_FILENO) == -1) 
        { 
            perror("ch2 cannot redirect pipe2[0] to stdin\n");
            return 1;
        }
        else if(close(Pipe2[1]) == -1 || close(Pipe2[0]) == -1 ||
                close(Pipe1[1]) == -1 || close(Pipe1[0]) == -1) 
                { 
                    perror("ch2 cannot close extra pipe2 fd or pipe1 fd\n");
                    return 1;
                }
        else
        {
            //fprintf(stderr, "Child2: ready\n"); 
            execl(argv[2], "prog2", NULL);
            perror("Failed to exec prog2\n");
        }
        return 1;
    }

    if(dup2(Pipe1[0], STDIN_FILENO) == -1) 
    { 
        perror("Parent cannot dup pipe1[0] to stdin\n"); 
        return 1;
    }
    else if(close(Pipe1[1]) == -1 || close(Pipe1[0]) == -1)
    { 
        perror("Parent cannot close extra pipe 1 fd\n");        
    }
    else if(dup2(Pipe2[1], STDOUT_FILENO) == -1) 
    { 
        perror("Parent cannot dup pipe2[1] to stdout\n");
    }
    else if(close(Pipe2[1]) == -1 || close(Pipe2[0]) == -1) 
    { 
        perror("Parent cannot close extra pipe 2 fd\n");
    }
    else
    {
        //fprintf(stderr, "Parent: ready\n");
        while(1) 
        { 
            numread = read(STDIN_FILENO , &buf, 1); 
            if(numread <= 0) 
            { 
                break; 
            }
            if((buf >= '0' && buf <= '9')) 
            { 
                fprintf(stderr, "Parent detected a digit: %c\n", buf);
                continue;
            }
            numwrite = write(STDOUT_FILENO, &buf, 1); 
            if(numwrite <= 0) 
            { 
                break;
            } 
        } 
        close(STDOUT_FILENO); 
        //fprintf(stderr, "Parent: done\n");
        waitpid(ch1pid, &status, 0);
        waitpid(ch2pid, &status, 0);
    }
    return 1; 
}
