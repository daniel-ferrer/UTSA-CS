#include <stdio.h>  //For input/output functions.
#include <stdlib.h> //For malloc, free, etc.
#include "Project0.h"  //Include our own header file for the Employee struct.

int main()
{
	//1.  Open the file Project0.txt and read in the first line of the file to determine how many Employees we need for our array, and use malloc() to dynamically allocate an array of this size.
	FILE *fptr;
	int lines, i, count = 0;

	fptr = fopen("Project0Input.txt", "r");

	if(fptr == NULL)
	{
		return -1;
	}

	fscanf(fptr, "%d", &lines);

	Employee *emps = (Employee*)malloc((lines) * sizeof(Employee));

	//2.  Use a loop to read the Employee information from Project0.txt and write the information to the entries of your array.  Suggestion:  read a single line of the file using fgets() then use sscanf() to parse out the variables from the line.

	while(!feof(fptr))
	{
		fscanf(fptr, "%s %d %lf", emps[count].name, &emps[count].id, &emps[count].hrlyRate);
		count++;
	}

	fclose(fptr);

	//3.  Loop through your array and print out the employee information.  Each employee (name, ID, hourly rate) should be on a single line.  The name should be left justified in a column of width 10.  The IDs are each 6 digits long so they can be printed with a single space after it.  The hourly rate should be printed to 2 decimal places.

	for(i = 0; i < lines; i++)
	{
		printf("%-10s %d %0.2f\n", emps[i].name, emps[i].id, emps[i].hrlyRate);
	}

	free(emps);
	return 0;
}
