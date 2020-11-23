#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "linkedlist.h"

int main(int argc,char *argv[]) {
  if (argc < 2) {
    printf("ERROR NO ARGS\n");
    exit(0);
  } else {
    LLNode *head = NULL, *node;

    FILE *fptr;
    if (argc >= 2) {
      fptr = fopen(argv[1], "r");
    }
    else {
      fptr = fopen("a10-input.csv", "r");
    }
    if(fptr == NULL) {
      printf("ERROR FILE NOT OPEN");
      return 0;
    }
    char line[256];
    while (fgets(line, sizeof(line), fptr)) {
      char *token = strtok(line, ",");
      int id = atoi(token);
      char *name = strtok(NULL, ",");
      double gpa = atof(strtok(NULL, ","));
      node = createNode(id, name, gpa);
      insertNode(&head, node);

    }
    printf("Average = %.2lf\n", averageGPA(&head));
    printLL(&head);
    destroyLL(&head);
  }
}
