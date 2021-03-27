#include "Queue.h"

/******
 * In this file, provide all of the definitions of the queue functions as described in Queue.h.
 *
 * ****/

 //Malloc a new QueueImp, set the head and foot pointers to NULL, and return it's address.
 Queue newQueue() {
   QueueImp *myQ = (*Queue) malloc (sizeof(QueueImp));
   myQ->head = NULL;
   myQ->foot = NULL;

   return myQ;
 }


 //Free each node that remains in the Queue and then free q itself.
 void freeQueue(Queue q) {
   NodeLL *temp;
   while(q->head != NULL) {
     temp = q->head;
     q->head = q->head->next;
     free(temp);
   }
   free(q);
 }


 //Allocate a new node and store "value" as the Element in the node.  Return the address of the node.
 NodeLL *allocateNode(Element value) {
   NodeLL *node = (*NodeLL) malloc (sizeof(NodeLL));
   node->element = value;
   node->next = NULL;
   return node;
 }


 //Call allocateNode() to get a new node that contains "value" and append it to the "foot end" of the queue.  Make sure to consider "edge cases" (e.g., when the queue is currently empty).
 void enqueue(Queue q, Element value) {
   NodeLL *temp = allocateNode(value);
   if(q->head == NULL) {
     q->head = temp;
     q->foot = temp;
   }
   q->foot->next = temp;
   q->foot = temp;
 }


 //Remove the node at the "head" end of the queue, and return the value of the element stored in this node through an element e that is passed by reference.
 //Functionally return TRUE (1) if the dequeue was successful and return FALSE (0) if it was not successful (i.e., the queue was empty).
 //Remember to consider any "edge cases" (e.g., when the queue becomes empty after this dequeue).
 int dequeue(Queue q, Element *e) {
   if(isEmpty(q)) {
     return FALSE;
   }
   NodeLL *temp = q->head;
   q->head = q->head->next;
   if(q->head == NULL) {
     q->foot = NULL;
   }
   e = &temp->element;
   return TRUE;
 }


 //Return the value of the element stored in the first node of the queue without removing the node itself (similar to topElement() for Stacks).
 //Return the value through e that is passed by reference, and return TRUE (1) if the call was successful and return FALSE (0) if it was not successful (i.e., the queue was empty).
 int frontElement(Queue q, Element *e) {
   if(isEmpty(q)) {
     return FALSE;
   }
   e = &(q->head->element);
   return TRUE;
 }


 //Return TRUE (1) if the queue is empty, otherwise return FALSE (0).
 int isEmpty(Queue q) {
   if(q->head == NULL) {
     return TRUE;
   }
   return FALSE;
 }
