// gcc -Wall scope.c -o scope
// ./scope

#include <stdio.h>

int aa = 25;
int bb = 15;
int cc = 5;

void cobra(int cc) {
  aa += 20;
  bb += 30;
  cc += 40;
  printf("cobra: aa=%4d bb=%4d cc=%4d aa+bb+cc=%4d\n", aa, bb, cc, aa+bb+cc);
}

void rhino(void) {
  int cc = 100;
  bb += 30;
  cc += 10;
  cobra(20);
  printf("rhino: aa=%4d bb=%4d cc=%4d aa+bb+cc=%4d\n", aa, bb, cc, aa+bb+cc);
}
void hippo(int aa) {
  aa += 40;
  rhino();
  printf("hippo: aa=%4d bb=%4d cc=%4d aa+bb+cc=%4d\n", aa, bb, cc, aa+bb+cc);
}

int hyena() {
  int bb = 90;
  hippo(80);
  printf("hyena: aa=%4d bb=%4d cc=%4d aa+bb+cc=%4d\n", aa, bb, cc, aa+bb+cc);
  return 1000;
}

int main(int arc, char *argv[]) {
  int bb = hyena();
  cc += 2000;
  printf("main:  aa=%4d bb=%4d cc=%4d aa+bb+cc=%4d\n", aa, bb, cc, aa+bb+cc);
}
