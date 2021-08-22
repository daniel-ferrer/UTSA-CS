#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "cards.h"

char GetCardType(CardType ct) {
	if(ct == ATTACK)
		return 'A';
	else if(ct == DEFEND)
		return 'D';
	else if(ct == RUN)
		return 'R';
	return ' ';
}

Card* createCard() {
	Card* newCard = (Card*)malloc(1 * sizeof(Card));

	int lBound = 1, uBound = 100, pct, val;
	pct = (rand() % (uBound - lBound + 1)) + lBound;

	if(pct <= 40) {
		lBound = 1;
		uBound = 5;
		newCard->ct = ATTACK;
	}
	else if(pct <= 90) {
		lBound = 3;
		uBound = 8;
		newCard->ct = DEFEND;
	}
	else {
		uBound = 8;
		newCard->ct = RUN;
	}
	val = (rand() % (uBound - lBound + 1)) + lBound;
	newCard->value = val;

	return newCard;
}

Card* removeCard(Card *head) {
	if(head == NULL) {
		return NULL;
	}
	Card* temp = head;
	head = head->next;
	free(temp);
	return head;
}

Card* addCard(Card *head, Card *c) {
	if((head == NULL) || head->value <= c->value) {
		c->next = head;
		head = c;
	}
	else {
		Card* temp = head;
		while((temp->next != NULL) && (temp->next->value > c->value)) {
			temp = temp->next;
		}
		c->next = temp->next;
		temp->next = c;
	}
	return head;
}

int getLength(Card *head) {
	int len = 0;
	Card* curr = head;

	if(curr == NULL) {
		return 0;
	}

	while(curr != NULL) {
		len++;
		curr = curr->next;
	}
	return len;
}

void printCard(Card *head) {
	printf("%c", GetCardType(head->ct));
	printf("%d ", head->value);
}

void printCards(Card *head) {
	Card* curr = head;

	while(curr != NULL) {
		printCard(curr);
		curr = curr->next;
	}
	printf("\n");
}

Card* buildCards(int n) {
	Card* curr = NULL;
	for(int i = 0; i < n; i++) {
		Card* card = createCard();
		curr = addCard(curr, card);
	}
	return curr;
}

Card* destroyCards(Card *head) {
	Card* temp = head;
	Card* next;
	while(temp != NULL) {
		next = temp->next;
		free(temp);
		temp = next;
	}
	head = NULL;
}
