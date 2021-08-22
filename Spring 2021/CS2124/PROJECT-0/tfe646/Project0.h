//In this file, write the definition of a struct for an Employee.
//An Employee should contain 3 variables:
//1.  A C-string for the name.  You can assume that no name is more than 9 characters long, so this can be a character array of size 10 (to account for the null character).
//2.  An integer for the ID.  Each ID is a 6-digit number.
//3.  A double for the hourly rate.

#ifndef PROJECT0_H
#define PROJECT0_H

typedef struct Employee
{
  int id;
  char name[10];
  double hrlyRate;
} Employee;


#endif //PROJECT0_H
