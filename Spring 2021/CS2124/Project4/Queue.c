#include "Queue.h"

/******
 * In this file, provide all of the definitions of the queue functions as described in Queue.h.
 *
 * ****/

//Malloc a new QueueImp, set the head and foot pointers to NULL, and return it's address.
Queue newQueue() {
    Queue myQ = (Queue)malloc(sizeof(QueueImp));
    myQ->head = NULL;
    myQ->foot = NULL;

    return myQ;
}

//Free each node that remains in the Queue and then free q itself.
void freeQueue(Queue q) {
    NodeLL *temp;

    while(!(isEmptyQueue(q))) {
        temp = q->head;
        q->head = q->head->next;
        free(temp);
    }

    free(q);
}

//Allocate a new node and store "value" as the Element in the node.  Return the address of the node.
NodeLL *allocateNode(Element value) {
    NodeLL *node = (NodeLL*)malloc(sizeof(NodeLL));
    node->element = value;
    node->next = NULL;
    return node;
}

//Call allocateNode() to get a new node that contains "value" and append it to the "foot end" of the queue.  Make sure to consider "edge cases" (e.g., when the queue is currently empty).
void enqueue(Queue q, Element value) {
    NodeLL *temp = allocateNode(value);

    if(q->foot == NULL) {
        q->head = temp;
        q->foot = temp;
    }
    else {
        q->foot->next = temp;
        q->foot = q->foot->next;
    }
}

//Remove the node at the "head" end of the queue, and return the value of the element stored in this node through an element e that is passed by reference.
//Functionally return TRUE (1) if the dequeue was successful and return FALSE (0) if it was not successful (i.e., the queue was empty).
//Remember to consider any "edge cases" (e.g., when the queue becomes empty after this dequeue).
int dequeue(Queue q, Element *e) {

    if(q->foot == NULL) {
        return FALSE;
    }
    else if(q->head == q->foot) {
        *e = q->head->element;
        NodeLL *p = q->head;
        q->head = NULL;
        q->foot = NULL;
        free(p);
        return TRUE;
    }
    else {
        NodeLL *p = q->head;
        q->head = q->head->next;
        *e = p->element;
        free(p);
        return TRUE;
    }
}

//Return the value of the element stored in the first node of the queue without removing the node itself (similar to topElement() for Stacks).
//Return the value through e that is passed by reference, and return TRUE (1) if the call was successful and return FALSE (0) if it was not successful (i.e., the queue was empty).
int frontElement(Queue q, Element *e) {
    if(isEmptyQueue(q)) {
        return FALSE;
    }
    else {
        e = q->head->element;
        return TRUE;
    }
}

//Return TRUE (1) if the queue is empty, otherwise return FALSE (0).
int isEmptyQueue(Queue q) {
    if(q->head == NULL) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

void printQueue(Queue q, int start, int destination) {
    if(q->head == NULL) {
        printf("There is no path from %d to %d.\n", start, destination);
    }
    else {
        printf("Shortest path from %d to %d: ", start, destination);
        NodeLL *node = q->head;
        while(node != q->foot->next){
            printf("%d -> ", node->element);
            node = node->next;
        }
        printf("\n");
    }
}