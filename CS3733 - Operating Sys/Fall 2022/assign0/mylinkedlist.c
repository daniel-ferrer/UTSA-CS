/*
 * File: mylinkedlist.c
 * Daniel Ferrer Sosa (tfe646) ... 
 * YOU NEED TO IMPLEMENT THE FUNCTIONS  here
 * ....
 */

#include <stdio.h>
#include <stdlib.h>
#include "mylinkedlist.h"
 
/*
 * Function: NewStudentCell
 * Usage: student_cell_T *element;
 *        element = NewStudentCell(int id, double gpa, char *name);
 * --------------------------
 * This function allocates space for a student cell and intilize its fileds
 */
student_cell_T *NewStudentCell(int id, double gpa, char *name)
{
   student_cell_T *element;
  
   element = (student_cell_T *) malloc( sizeof(student_cell_T) );
   if( !element){
     fprintf(stderr,"NewStudentCell cannot allocate memory\n");
     return NULL;
   }

   element->id = id;
   element->gpa = gpa;
   element->name = name;

  return element;
}


/*
 * Function: NewLinkedList
 * Usage: linked_list_T *list;
 *        list = NewLinkedList();
 * --------------------------
 * This function allocates and returns an empty linked list.
 */
linked_list_T *NewLinkedList(void)
{
   linked_list_T *list;
  
   list = (linked_list_T *) malloc( sizeof(linked_list_T) );
   if( !list){
     fprintf(stderr,"NewLinkedList cannot allocate memory\n");
     return NULL;
   }

   list->head = NULL;
   list->tail = NULL;

  return list;
}


/*
 * Function: FreeLinkedList
 * Usage: FreeLinkedList(list);
 * ------------------------
 * This function frees the storage associated with list.
 */
void FreeLinkedList(linked_list_T *list)
{
  student_cell_T *curr = list->head;

  while (curr != NULL)
  {
    list->head = list->head->next;
    free(curr);
  }

  list->head = NULL;
}

/*
 * Function: Enlist
 * Usage: Enlist(list, element);
 * -------------------------------
 * This function adds a student cell pointed by element to the end of the list.
 */
void Enlist(linked_list_T *list, student_cell_T *element)
{
  // if the list is empty, simply add element
  if (LinkedListIsEmpty(list) == 1)
    list->head = element;
  else
  {
    if (LinkedListLength(list) == 1)
    {
      list->tail = element;
      list->tail->next = NULL;
      list->head->next = list->tail;
    }
    else
    {
      list->tail->next = element;
      list->tail = list->tail->next;
    }
  }
  return;
}

/*
 * Function: Delist
 * Usage: element = Delist(list);
 * --------------------------------
 * This function removes the student cell at the head of the list
 * and returns its address to the caller (client).  If the list is empty, Delist
 * prints an Error with an appropriate message and returns NULL.
 */
student_cell_T *Delist(linked_list_T *list)
{
  if(LinkedListIsEmpty(list) == 1)
  {
    fprintf(stderr, "Delist cannot remove element from empty list\n");
    return NULL;
  }

  student_cell_T *curr = list->head;
  list->head = list->head->next;

  free(curr);

  return curr;
}

student_cell_T *DelistMaxGpa(linked_list_T *list)
{
  if(LinkedListIsEmpty(list) == 1)
  {
    fprintf(stderr, "DelistMaxGpa cannot remove element from empty list\n");
    return NULL;
  }

  student_cell_T *maxGpaStudent = FindMaxGpa(list);
  student_cell_T *curr = list->head;
  student_cell_T *prev = NULL;

  if(maxGpaStudent != NULL)
  {
    while(curr != NULL)
    {
      if(curr->id == maxGpaStudent->id)
      {
        prev->next = curr->next;
        free(curr);
        return curr;
      }
      prev = curr;
      curr = curr->next;
    }
  }

  return NULL;
}

/*
 * Functions: LinkedListIsEmpty, LinkedListIsFull
 * Usage: if (LinkedListIsEmpty(list)) . . .
 *        if (LinkedListIsFull(list)) . . .
 * -------------------------------------
 * These functions test whether the list is empty or full.
 */
int LinkedListIsEmpty(linked_list_T *list)
{
  if(list->head == NULL)
    return 1;

  return 0;
}

int LinkedListIsFull(linked_list_T *list)
{
  return 0; // because we have linked list
}

/*
 * Function: LinkedListLength
 * Usage: n = LinkedListLength(list);
 * ------------------------------
 * This function returns the number of elements in the list.
 */
int LinkedListLength(linked_list_T  *list)
{
  int listLength = 0;
  student_cell_T *curr = list->head;

  while(curr != NULL)
  {
    listLength++;
    curr = curr->next;
  }
  return listLength;
}

/*
 * Function: GetLinkedListElement
 * Usage: element = GetLinkedListElement(list, index);
 * -----------------------------------------------
 * This function returns the element at the specified index in the
 * list, where the head of the list is defined as index 0. For
 * example, calling GetLinkedListElement(list, 0) returns the initial
 * element from the list without removing it.  If the caller tries
 * to select an element that is out of range, GetLinkedListElement prints
 * Error and returns NULL.  Note: This function is not a fundamental list operation
 * and is instead provided mainly to facilitate debugging.
 */
student_cell_T *GetLinkedListElement(linked_list_T *list, int index)
{
  int count = 0;
  student_cell_T *curr = list->head;

  while(curr != NULL)
  {
    if (count == index)
      return (curr);

    count++;
    curr = curr->next;
  }

  fprintf(stderr, "Element out of range\n");
  return NULL;
}



/* OTHER FUNCTIONS YOU WOULD NEED....
 * EXPORT THEM HERE, BUT IMPLMENT THEM in mylinkedlist.c 
 */

student_cell_T *FindMinGpa(linked_list_T *list)
{
  double minGpa = (double)999999;
  student_cell_T *curr = list->head;
  student_cell_T *retNode = NULL;

  while(curr != NULL)
  {
    if(curr->gpa < minGpa)
    {
      minGpa = curr->gpa;
      retNode = curr;
    }
    curr = curr->next;
  } 
  
  return retNode;
}

student_cell_T *FindMaxGpa(linked_list_T *list)
{
  double maxGpa = (double)0;
  student_cell_T *curr = list->head;
  student_cell_T *retNode = NULL;

  while(curr != NULL)
  {
    if(curr->gpa > maxGpa)
    {
      maxGpa = curr->gpa;
      retNode = curr;
    }  
    curr = curr->next;
  }

  return retNode;
}

double CalculateAvgGpa(linked_list_T *list)
{
  double sum = 0;
  student_cell_T *curr = list->head;

  while(curr != NULL)
  {
    sum += curr->gpa;
    curr = curr->next;
  }

  return (double) (sum / LinkedListLength(list));
}

void PrintAllStudents(linked_list_T *list)
{
  student_cell_T *curr = list->head;

  while(curr != NULL)
  {
    printf("Student Id: %d\n", curr->id);
    printf("Student GPA: %.2f\n", curr->gpa);
    printf("Student Name: %s\n\n", curr->name);

    curr = curr->next;
  }
}