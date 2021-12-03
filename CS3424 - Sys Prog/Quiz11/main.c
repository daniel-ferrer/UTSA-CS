#include <stdio.h>

// Daniel Ferrer-Sosa (tfe646)

typedef struct {
    char course_Name[80];
    unsigned course_Hours;
    unsigned course_Size;
    unsigned paddings;
} StudentRecord;

int main( int argc, char *argv[] ) 
{
    FILE *fptr;
    StudentRecord student1;

    fptr = fopen("gpa.dat", "rb+");
    if(fptr == NULL) {
        perror("Unable to open file.\n");
        return -1;
    }

    long offset = 3 * sizeof(StudentRecord);
    fseek(fptr, offset, SEEK_SET);

    fread(&student1, sizeof(StudentRecord), 1, fptr);

    return 0;
}