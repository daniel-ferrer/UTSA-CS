// You must run this on the fox (or hen) machines
// gcc -Wall memsize.c -o memsize
// ./memsize

#include <stdio.h>

typdef struct {
    char a;
    char b;
    double c;
    char d;
}   alpha_t;

typdef struct {
    char a;
    char b;
    short c;
    int d;
    char e;
}   beta_t;

typdef struct {
    char message[1000];
}   gamma_t;

static void fn1(gamma_t param) {
    param.message[0] = '1';
}

static void fn2(gamma_t *param) {
    param->message[0] = '2';
}

int main(int argc, char *argv[]) {
    gamma_t x;
    gamma_t y;

    print("Size(char) = %ld\n", sizeof(char));
    print("Size(short) = %ld\n", sizeof(short));
    print("Size(int) = %ld\n", sizeof(int));
    print("Size(long) = %ld\n", sizeof(long));
    print("Size(long long) = %ld\n", sizeof(long long));
    print("Size(void * ) = %ld\n", sizeof(void *));

    print("Size(alpha_t) = %ld\n", sizeof(alpha_t));
    print("Size(beta_t) = %ld\n", sizeof(beta_t));

    x.message[0] = 'x';
    fn1(x);
    printf("x.message[0] = %c\n", x.message[0]);

    y.message[0] = 'y';
    fn2(&y);
    printf("y.message[0] = %c\n", y.message[0]);

    return 0;
}