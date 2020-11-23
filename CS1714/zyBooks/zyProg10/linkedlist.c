#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "linkedlist.h"

LLNode * createNode(int id,char name[],double gpa) {
    LLNode *node = (LLNode *) malloc(sizeof(LLNode));
    node->id=id;
    strcpy(node->name,name);
    node->gpa=gpa;
    node->next=NULL;
    return node;
}

LLNode * insertNode(LLNode  **head,LLNode *node){
    if(*head==NULL){
        *head=node;
    }

   else {
        LLNode *temp=*head;
        while(temp->next!=NULL && strcmp(temp->next->name,node->name)<0 ){
            temp=temp->next;
        }
        node->next=temp->next;
        temp->next=node;

    }
}
double averageGPA(LLNode **head){
    LLNode *temp=*head;
    if(temp==NULL)
    {
        printf("List is empty");
        return 0;
    }
    else{
        double sum=0;
        int count=0;
        while(temp!=NULL){
            sum+=(temp->gpa);
            count++;
            temp=temp->next;
        }
        double average=sum/count;
        return average;
    }
}

void printLL(LLNode **head){
    LLNode *temp=*head;
    if(temp==NULL){
        printf("List is empty\n");
        return;
    }
    else{
        printf("(%d,%s,%.2lf) -> ",temp->id,temp->name,temp->gpa);
        temp=temp->next;
        while(temp!=NULL){
            printf("(%d,%s,%.2lf) -> ",temp->id,temp->name,temp->gpa);
            temp=temp->next;
        }
        printf("\n");
    }
}
LLNode * destroyLL(LLNode **head){
    LLNode *temp=*head,*temp1;
    if(temp==NULL){
        return temp ;
    }
    else{
        while(temp!=NULL){
            temp1=temp;
            temp=temp->next;
            free(temp1);
        }
        return temp;
    }
}
