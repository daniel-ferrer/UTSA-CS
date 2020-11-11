#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "route-records.h"

Card* createCard();

Card* removeCard(Card *head);

Card* addCard(Card *hhead, Card *c);

int getLength(Card *head);

void printCard(Card *head);

void printCards(Card *head);

Card* buildCards(int n);

Card* destroyCards(Card *head);