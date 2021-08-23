#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "employee.h"

int main()
{
    int size;

    Employee* employees  = readData("a6-input.txt", &size);

    Employee bestEmployee = getBestEmployee(employees, size);

    writeData("a6-output.txt", bestEmployee);

    free(employees);

    return 0;
}
