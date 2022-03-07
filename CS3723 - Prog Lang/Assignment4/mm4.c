// gcc -Wall mm4.c -o mm4
// ./mm4 4 8 -5 0 20
// prints: mm4: min=-5 max=20

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int x;   // min
  int y;   // max
} mm_t;

static void mm4(int argc, char *argv[], mm_t *mm) {
  TBD
}

int main(int argc, char *argv[]) {
  mm_t mm;
  TBD
  printf("mm4: min=%d max=%d\n", mm.x, mm.y);
  return 0;
}
