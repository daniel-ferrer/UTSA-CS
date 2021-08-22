#ifndef LINKEDLIST_H
#define LINKEDLIST_H

 struct Node{
    int id;
    char name[10];
    double gpa;
    struct Node *next;
};

typedef struct Node LLNode;

LLNode* createNode(int,char[],double);

LLNode* insertNode(LLNode**,LLNode*);

double averageGPA(LLNode**);

void printLL(LLNode**);

LLNode* destroyLL(LLNode**);

#endif //LINKEDLIST_H
