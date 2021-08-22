#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <stdio.h>
#include <math.h>

typedef struct Employee
{
	int id;
	char name[10];
	double salary;

} Employee;

Employee* readData(char* fname, int* size);

Employee getBestEmployee(Employee* empNames, int size);

void writeData(char* fname, Employee emp);

#endif //EMPLOYEE_H