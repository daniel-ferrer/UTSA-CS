/*
 * File: driver1.c
 * Daniel Ferrer Sosa (tfe646) 
 * YOU NEED TO IMPLEMENT THE main() + additional functions if needed
 *
 * ....
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylinkedlist.h"

/* 
 * Function: ReadLine
 * Usage: s = ReadLine();
 * ---------------------
 * ReadLine reads a line of text from standard input and returns
 * the line as a string.  The newline '\n' character that terminates
 * the input is not stored as part of the string.
 */
char *ReadLine(void);

// custom functions
void ShowMenu(void);
int DoesNodeExist(linked_list_T*, int);


int main(int argc, char *arvg[])
{
  char charAction[2];
  int intAction = 0;
  linked_list_T *studentList;
  studentList = NewLinkedList();

  do
  {
    ShowMenu();
    printf("Enter your choice: ");
    scanf(" %s", charAction);
    intAction = atoi(charAction);

    int id, idx;
    double gpa;
    char* name;
    student_cell_T *student;

    switch (intAction)
    {
      case 1:
        // create new student 
        // and add them to the list

       // get student id
        printf("\nEnter the student's id: ");
        scanf("%d", &id);

        // don't continue if student id exists
        if(DoesNodeExist(studentList, id) == 1)
        {
          break;
        }

        // student id did't exists
        // ask for additional details

        // get student gpa
        printf("\nEnter the student's gpa (ex: 3.58): ");
        scanf("%lf", &gpa);

        // get student name
        printf("\nEnter the student's full name: ");
        name = ReadLine();

        // all details have been taken in
        // create and enlist student

        student = NewStudentCell(id, gpa, name);
        Enlist(studentList, student);

        break;
      
      case 2:
        // remove first student from the list
        // and print their details

        student = Delist(studentList);

        if (student != NULL)
        {
          printf("Top student removed...\n");
          printf("Student Id: %d\n", student->id);
          printf("Student GPA: %.2f\n", student->gpa);
          printf("Student Name: %s\n\n", student->name);          
        }
        break;
      
      case 3:
        printf("Number of students in list: %d\n\n", LinkedListLength(studentList));
        break;

      case 4:
        // print the details of the student and the given position of the list

        // get index
        printf("Enter the index: ");
        scanf("%d", &idx);

        // get student using entered index
        student = GetLinkedListElement(studentList, idx);

        if (student != NULL)
        {
          printf("Student Id: %d\n", student->id);
          printf("Student GPA: %.2f\n", student->gpa);
          printf("Student Name: %s\n\n", student->name); 
        }
        break;
      
      case 5:
        // print all students and their details from the list

        if (LinkedListIsEmpty(studentList) == 0)
          PrintAllStudents(studentList);
        else
          printf("Empty list, no students to print!\n");
        break;

      case 6:
        // print min, max, and avg GPAs of elements in the list

        if (LinkedListIsEmpty(studentList) == 0)
        {
          student = FindMinGpa(studentList);
          printf("Min GPA: %.2f\n", student->gpa);
          student = FindMaxGpa(studentList);
          printf("Max GPA: %.2f\n", student->gpa);
          gpa = CalculateAvgGpa(studentList);
          printf("Avg GPA: %.2f\n\n", gpa);
        }
        else
          printf("Empty list!\n");
        break;

      case 7:
        // find the student with the highest GPA
        // print out their details
        // and remove them from the list

        student = DelistMaxGpa(studentList);

        if(student != NULL)
        {
          printf("Student Id: %d\n", student->id);
          printf("Student GPA: %.2f\n", student->gpa);
          printf("Student Name: %s\n\n", student->name);
        }
        break;

      case 8:
        // free mem allocations and exit prog

        free(name);
        free(student);
        FreeLinkedList(studentList);
        break;

      default:
        printf("Invalid choice, please choose again...\n");
        break;
    }


  } while (intAction != 8);
  return 0;
}

/* 
 * IMPLEMENTATION of ReadLine();
 * Function: ReadLine
 * Usage: s = ReadLine();
 * ---------------------
 * ReadLine reads a line of text from standard input and returns
 * the line as a string.  The newline '\n' character that terminates
 * the input is not stored as part of the string.
 *
 * In contrast to standard I/O functions (e.g., scanf with "%s", fgets) 
 * that can read strings into a given static size buffer, ReadLine function 
 * should read the given input line of characters terminated by a newline 
 * character ('\n') into a dynamically allocated and resized buffer based on 
 * the length of the given input line. 
 *
 * When implementing this function you can use standard I/O functions. 
 * We just want you to make sure you allocate enough space for the entered data. 
 * So don't simply allocate 100 or 1000 bytes every time. 
 * If the given input has 5 characters, you need to allocate space for 6 characters.
 *
 * Hint: initially dynamically allocate an array of char with size 10. 
 * Then, read data into that array character by charecter (e.g, you can use getchar()). 
 * If you see '\n' char before reading 10th character, you are done. And you know the 
 * exact length of the input string. So, accordingly allocate enough space and copy the 
 * data into new char array, insert '\0' instead of '\n' and free the original array. 
 * Then return the new string. However, if you DO NOT see '\n' char after 10th character, 
 * then you need larger space. Accordingly, resize your original array and double its size 
 * and continue reading data character by character as in the first step... 
 * Hope you got the idea! 
 *
 * Also please check for possible errors (e.g., no memory etc.) and appropriately handle 
 * them. For example, if malloc returns NULL, free partially allocated space and return 
 * NULL from this function. The program calling this function may take other actions, 
 * e.g., stop the program!
 */
char *ReadLine()
{
  int c; // getchar() returns an int
  int i = 0;
  int inputSize = 10; // used to realloc array size if needed

  // create array to hold input of up to inputSize chars
  char *readInArray = malloc(inputSize);
  if (!readInArray)
  {
    fprintf(stderr, "ReadLine cannot allocate memory\n");
    return NULL;
  }

  getchar(); // make sure stdin is  clear before taking input 
  
  while (((c = getchar()) != '\n') && c != EOF)
  {
    // realloc array as needed
    if (i == inputSize-1)
    {
      inputSize *= 2;
      readInArray = realloc(readInArray, inputSize);
    }
    // copy char to array
    readInArray[i++] = c;
  }
  readInArray[i] = '\0';
  
  int optimalSize = (int)strlen(readInArray);

  char *optSizeArray = malloc(optimalSize);
  strcpy(optSizeArray, readInArray);

  free(readInArray);

  return(optSizeArray);
}

void ShowMenu()
{
  printf("******* ENTER THE NUMBER OF THE OPTION YOU'D LIKE TO SELECT *******\n\n");
  printf("1 - Create a new student cell with given id, gpa, name info, and add (Enlist) it to the end of the linked list. (if the student id has already been added, don't add that student)\n");
  printf("2 - Remove (Delist) the first student from linked list and print his/her id, gpa, name info\n");
  printf("3 - Print the number of students in the linked list (Length)\n");
  printf("4 - Print (id, gpa, name) of a student at a specific index (head of the list is defined as index 0)\n");
  printf("5 - Print the list of all studdents in the linked list. Print (id, gpa, name) of every student\n");
  printf("6 - Print the min, average, max GPAs in the linked list\n");
  printf("7 - Remove the student with highest GPA and print his/her info (if there are ties, just take the first one you found)\n");
  printf("8 - Exit\n\n");
}

int DoesNodeExist(linked_list_T *list, int id)
{
  if(LinkedListIsEmpty(list) == 0)
  {
    student_cell_T *curr = list->head;
    while(curr != NULL)
    {
      if(curr->id == id)
      {
        printf("ID already exists!\n");
        return 1;
      }
      curr = curr->next;
    }
  }
  return 0;
}


