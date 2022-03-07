// gcc -Wall mm5.c -o mm5
// ./mm5 4 8 -5 0 20
// prints: mm5: min=-5 max=20

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int x;   // min
  int y;   // max
} mm_t;

static mm_t *mm5(int argc, char *argv[]) {
  mm_t *mm = (mm_t *) malloc(sizeof(mm_t));
  TBD
  return mm;
}

int main(int argc, char *argv[]) {
  TBD
  printf("mm5: min=%d max=%d\n", mm->x, mm->y);
  return 0;
}
