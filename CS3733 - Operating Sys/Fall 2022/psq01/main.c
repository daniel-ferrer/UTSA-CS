#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int newc;
    char **newv;
    int i, j;

    if (argc < 3)
    {
        printf("Not enough args passed!\n");
        exit(1);
    }

    newc = argc;

    newv = (char**) malloc (argc);

    int i, j;
    for(i = 0; i < newc; i++)
    {
       j = strlen(argv[i]);

       newv[i] = (char*) malloc (j);

       strcpy(newv[i], argv[i]); 
    }

    for(i = 0; i < newc; i ++)
        printf("%s\n", newv[i]);

    for(i = 0; i < newc; i ++)
        free(newv[i]);

    return 0;
}
