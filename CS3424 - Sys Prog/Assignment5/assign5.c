#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "assign5.h"

int main( int argc, char *argv[] )
{
    FILE *fptr, *in;
    int _pick, cnt = 0;

    printf("Assignment5 created by Daniel Ferrer-Sosa (tfe646)\n\n");

    // create file if doesn't exist in working dir
    fptr = fopen("courses.dat", "rb+");
    if(fptr == NULL) {
        fptr = fopen("courses.dat", "wb+");
    }

    do
    {
        printf("Enter one of the following actions or press CTRL-D to exit.\n");
        printf("C - create a new course record\n");
        printf("U - update an existing course record\n");
        printf("R - read an existing course record\n");
        printf("D - delete an existing course record\n");
        scanf(" %lc", &_pick);

        switch ((char)toupper(_pick))
        {
            case 'C':
                CreateRecord(fptr);
                cnt = 0;
                continue;
                
            case 'U':
                UpdateRecord(fptr);
                cnt = 0;
                continue;
                
            case 'R':
                ReadRecord(fptr);
                cnt = 0;
                continue;
                
            case 'D':
                DeleteRecord(fptr);
                cnt = 0;
                continue;

            default:
                printf("ERROR: invalid option\n");
                cnt +=1;
                break;
        }   


    } while (cnt <= 5); // if 5 invalid's something is wrong...
    
    fclose(fptr);
    return 0;
}

void CreateRecord(FILE *fptr) {
    COURSE course;
    int _num = 0;
    
    printf("Enter a course number: Course number: ");
    scanf(" %d", &_num);
    getchar();

    // check if record with course number exists
    bool isExist = DoesRecordExist(fptr, _num);
    if (isExist) {
        printf("ERROR: course already exists\n");
        return;
    }

    printf("Course name: ");
    fgets(course.course_Name, 1024, stdin);
    course.course_Name[strcspn(course.course_Name, "\n")] = 0; // strip newline

    printf("Scheduled days: ");
    scanf(" %s", course.course_Sched);

    printf("Credit hours: ");
    scanf(" %u", &course.course_Hours);

    printf("Enrolled students: ");
    scanf(" %u", &course.course_Size);
    
    // set cursor pos at record's byte
    long offset = _num * sizeof(course); 
    fseek(fptr, offset, SEEK_SET);

    // write record
    fwrite(&course, sizeof(COURSE), 1, fptr);
}

void ReadRecord(FILE *fptr) {
    COURSE course;
    int _num = 0;
    
    printf("Enter a CS course number: ");
    scanf(" %d", &_num);
    getchar(); // mouse trap for tailing newlines

    // check if record with course number exists
    bool isExist = DoesRecordExist(fptr, _num);
    if(!isExist) {
        printf("ERROR: course not found\n");
        return;
    }
    
    // set cursor pos at record's byte
    long offset = _num * sizeof(COURSE);
    fseek(fptr, offset, SEEK_SET);

    fread(&course, sizeof(COURSE), 1, fptr);

    printf("Course number: %d\n", _num);
    printf("Course name: %s\n", course.course_Name);
    printf("Scheduled days: %s\n", course.course_Sched);
    printf("Credit hours: %u\n", course.course_Hours);
    printf("Enrolled Students: %u\n", course.course_Size);
}

void UpdateRecord(FILE *fptr) {
    COURSE course, temp;
    int _num = 0;
    char c[99];

    printf("Enter a course number: Course number: ");
    scanf(" %d", &_num);
    getchar();

    // check if record with course number exists
    bool isExist = DoesRecordExist(fptr, _num);
    if (!isExist) {
        printf("ERROR: course not found\n");
        return;
    }

    // set cursor pos at record's byte
    long offset = _num * sizeof(COURSE);
    fseek(fptr, offset, SEEK_SET);

    fread(&temp, sizeof(COURSE), 1, fptr);

    printf("Course name: ");
    fgets(course.course_Name, 1024, stdin); 
    course.course_Name[strcspn(course.course_Name, "\n")] = 0; // strip newline

    if(strlen(course.course_Name) == 0) {
        printf("Empty course name. Reusing prev value.\n");
        strcpy(course.course_Name, temp.course_Name);
    }

    printf("Scheduled days: ");
    fgets(course.course_Sched, 1024, stdin);
    course.course_Sched[strcspn(course.course_Sched, "\n")] = 0; // strip newline

    if(strlen(course.course_Sched) == 0) {
        printf("Empty course schedule. Reusing last value.\n");
        strcpy(course.course_Sched, temp.course_Sched);
    }

    printf("Credit hours: ");
    fgets(c, sizeof(c), stdin);

    if(c[0] == '\n' || c[0] == '0')
        course.course_Hours = temp.course_Hours; 
    else
        course.course_Hours = atoi(c);
    
    printf("Enrolled students: ");
    fgets(c, sizeof(c), stdin);

    if(c[0] == '\n' || c[0] == '0')
        course.course_Size = temp.course_Size; 
    else 
        course.course_Size = atoi(c);

    //move cursor and write modified record
    fseek(fptr, offset, SEEK_SET);
    fwrite(&course, sizeof(COURSE), 1, fptr);
}

void DeleteRecord(FILE *fptr) {
    COURSE course, temp;
    int _num = 0;

    printf("Enter a course number: Course number: ");
    scanf(" %d", &_num);
    getchar();

    // check if record with course number exists
    bool isExist = DoesRecordExist(fptr, _num);
    if (!isExist) {
        printf("ERROR: course not found\n");
        return;
    }

    // set cursor pos at record's byte
    long offset = _num * sizeof(COURSE);
    fseek(fptr, offset, SEEK_SET);

    // POOF... gone !
    strcpy(temp.course_Name, "");
    strcpy(temp.course_Sched, "");
    temp.course_Hours = 0;
    temp.course_Size = 0;

    int rc = fwrite(&temp, sizeof(COURSE), 1, fptr);

    if (rc == 1)
        printf("course number was successfully deleted.\n");
}


bool DoesRecordExist(FILE *fptr, int _num) {
    COURSE temp;
    bool retval;

    // set cursor offset to _num byte
    long offset = _num * sizeof(COURSE);
    fseek(fptr, offset, SEEK_SET);
    
    // read chunk from file
    int _recordsRead = fread(&temp, sizeof(COURSE), 1, fptr);

    if(_recordsRead != 1)
        retval = false;

    // records initialized due to a higher record getting created, need logic to ret false
    else if((strlen(temp.course_Name) == 0) && (strlen(temp.course_Sched) == 0))
        retval = false;

    else retval = true;

    return retval;
}