// gcc -Wall mm8.c -o mm8
// ./mm8 4 8 -5 0 20
// prints: mm8: min=-5 max=20

#include <stdio.h>
#include <stdlib.h>

// mms[0] is mm, [1] is mm squares, [2] is mm cubes
static void mm8(int argc, char *argv[], int *mms) {
  TBD
}

int main(int argc, char *argv[]) {
  int mms[2];  // mms[0] is min, [1] is max
  TBD
  printf("mm8: min=%d max=%d\n", mms[0], mms[1]);
  return 0;
}
