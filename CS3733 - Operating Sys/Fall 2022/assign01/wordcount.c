/*
 * File: wordcount.c
 * Daniel Ferrer Sosa (tfe646) ... YOU NEED TO IMPLEMENT THE FUNCTIONS HERE....
 *
 * ....
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
// include other standard header files or your own user defined libraries needed 

const int MAX_ARGUMENTS = 2;

char *ReadLine(void);
/*
 * YOUR COMMENTS
 */

int main(int argc, char *arvg[])
{
  // YOU NEED TO IMPLEMENT THIS + some other functions! 
  if(argc == 1){
    printf("ERROR: no arguments entered\n");\
    return -1;
  }
  else if(argc > MAX_ARGUMENTS){
    printf("ERROR: too many arguments\n");
    return -1;
  }


  FILE* file;

  file = fopen(arvg[1], "r");
  if(file == NULL){
    printf("ERROR: could not open %s\n", arvg[1]);
    return 1;
  }

  int count = 0;
  char ch;
  char prevCh = 0;

  // word count logic
  while((ch = fgetc(file)) != EOF){
    if(ch == ' ' || ch == '\n' || ch == '\t'){
      if(prevCh == 0 || (prevCh != ' ' && prevCh != '.' && prevCh != ':')){
        count++;
      }
    }

    prevCh = ch;
  }

  count++;

  pid_t pid = getpid();
  printf("wordcount with process id of %d counted words in %s: number of words is %d\n", pid, arvg[1], count);
 
  return 0;
}
