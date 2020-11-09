#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "student.h"

int main(int argc, char* argv[])
{
  FILE *fptr;
  int id, userIN, fileSize = 0;
  char name[10];

  if (argc < 2) 
  {
    printf("ERROR NO ARGS");
    return 1;
  }
  else if (argc >= 2)
  {
    fptr = fopen(argv[1], "r");
  }
  else
  {
    fptr = fopen("a09-input.csv", "r");
  }

  if (fptr == NULL)
  { 
    printf("ERROR FILE NOT OPEN");
    return 1; 
  } 

  while(fscanf(fptr, "%d%*c%s", &id, name) != EOF)
  {
    fileSize++;
  }

  rewind(fptr);

  Student *s = (Student*)malloc((fileSize) * sizeof(Student)); //Alloc memory for array

  for(int i = 0; i < fileSize; i++)
  {
    fscanf(fptr, "%d%*c%s", &id, name);
    s[i].id = id;
    strcpy(s[i].name, name);
  }

  fclose(fptr);

  print(s, fileSize);
  sortStudents(s, fileSize);
  print(s, fileSize);

  scanf("%d", &userIN);

  Student search = searchStudent(s, fileSize, userIN);

  printf("(%d,%s)\n", search.id, search.name);

  free(s);

  return 0;
}