#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "employee.h"

Employee* readData(char* fname, int* size)
{
	Employee temp;
	int cnt = 0;
	*size = 0;
	FILE *fptr = fopen(fname, "r");
	if (fptr == NULL) { 
        return; 
    } 

	while(!feof(fptr))
	{
		fscanf(fptr, "%s %d %lf", temp.name, &temp.id, &temp.salary);
		(*size)++;
	}

	fseek(fptr, 0, SEEK_SET);

	Employee *emps = (Employee*)malloc((*size) * sizeof(Employee));

	while(!feof(fptr))
	{
		fscanf(fptr, "%s %d %lf", temp.name, &temp.id, &temp.salary);
		emps[cnt] = temp;
		cnt++;
	}

	fclose(fptr);
	return emps;
}

Employee getBestEmployee(Employee* empNames, int size)
{
	Employee temp = empNames[0];

	for(int i = 1; i < size; i++)
	{
		if(empNames[i].salary > temp.salary)
		{
			temp = empNames[i];
		}
	}

	return temp;
}

void writeData(char* fname, Employee emp)
{
	FILE *fptr = fopen(fname, "w");
	fprintf(fptr, "%s %d %.0f", emp.name, emp.id, emp.salary);
	fclose(fptr);
}