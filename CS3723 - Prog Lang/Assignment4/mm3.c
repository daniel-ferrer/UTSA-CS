// gcc -Wall mm3.c -o mm3
// ./mm3 4 8 -5 0 20
// prints: mm3: min=-5 max=20

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int x;   // min
  int y;   // max
} mm_t;

static mm_t *mm3(int argc, char *argv[]) {
  static mm_t mm;
  TBD
  return &mm;
}

int main(int argc, char *argv[]) {
  mm_t *mm;
  TBD
  printf("mm3: min=%d max=%d\n", mm->x, mm->y);
  return 0;
}
