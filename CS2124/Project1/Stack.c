#include "Stack.h"

/******
 * In this file, provide all of the definitions of the stack functions as described in stack.h.
 *
 * ****/

 //Malloc a new StackImp, malloc an array of Elements of size maximumStackSize (store the address in stackElements pointer), set maxSize to be maximumStackSize, initialize count to be 0, and return a pointer to the StackImp.
 Stack newStack(int maximumStackSize)
 {
   StackImp *myStack = (Stack*) malloc (sizeof(StackImp));
   myStack->maxSize = maximumStackSize;
   myStack->count = 0;
   myStack->stackElements = (Element*)malloc(sizeof(Element) * maximumStackSize);

   return myStack;
 }

 //Free stackElements and then free the Stack s.
 void freeStack(Stack s)
 {
   free(s->stackElements);
   free(s);
 }

 //Push a new Element e onto the Stack s, and increment the count variable.  Print an error message if the stack was already full.
 void push(Stack s, Element e)
 {

   if(s->count >= s->maxSize)
   {
     perror("Stack is full");
     return -1;
   }
   else
   {
     s->stackElements[s->count] = e;
     s->count++;

     //Element temp = topElement(s);
     //topElement(s) = e;
     //s[s->count] = temp;
     //s->count++;
   }
 }


 //Pop an element off the stack, decrement the count variable, and return the element's value.
 Element pop(Stack s)
 {
   s->count--;
   return s->stackElements[s->count]
 }


 //Return true (1) if stack is empty and false (0) otherwise.
 int isEmpty(Stack s)
 {
   if(s->count == 0)
   {
     return 1;
   }
   else
   {
     return 0;
   }
 }


 //Return the value of the top element of the stack (without removing it).
 Element topElement(Stack s)
 {
   return s->stackElements[s->count - 1];
 }
