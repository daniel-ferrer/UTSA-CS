/*
 * File: multiple_wordcount.c
 * Daniel Ferrer Sosa (tfe646) ... YOU NEED TO IMPLEMENT THE FUNCTIONS HERE....
 *
 * ....
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
// include other standard header files or your own user defined libraries needed 

 

/*
 * YOUR COMMENTS
 */


int main(int argc, char *arvg[])
{
  if (argc == 1){
    printf("ERROR: no arguments provided");
    return -1;
  }
  const int n = argc - 1;
  // YOU NEED TO IMPLEMENT THIS + some other functions if needed! 
  pid_t cpid;
  int i;
  for(i = 1; i < argc; i++) {
   cpid = fork();
   if (cpid == -1) { printf("ERROR: could not fork child %d\n", i); }
   if (cpid == 0) {
      execl("./wordcount", "./wordcount", arvg[i], NULL);

      printf("ERROR: exec() failed for child %d\n", i);
      return 2;
    }  
  }


  // after the parent creates all children, it comes to this part
  int successes = 0, fails = 0;
  int returned = 0;
  int status;

  // keep count of successes and failures
  for(; returned < n;) {
    wait(&status);
    int code = WEXITSTATUS(status);

    if(code == 0){
      successes++;
    }
    else if(code == 1){
      fails++;
    }
    returned++;
  }

  pid_t ppid = getpid();
  printf("Parent process %d created %d child processes to count words in %d files\n", ppid, n, n);
  printf("%d files have been counted succesfully\n", successes);
  printf("%d files did not exist\n", fails);

  return 0;
}



   