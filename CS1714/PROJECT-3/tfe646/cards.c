#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "cards.h"

//helper function to get random %
int getRandom() {
	int random = rand();
	if(random >= RAND_MAX / 2) {
		return 1;
	}
	else if((random < RAND_MAX / 2) && (random > RAND_MAX / 10)) {
		return 0;
	}
	else {
		return 2;
	}
}

Card* createCard() {
	srand(time(NULL));
	Card* newCard = (Card*)malloc(1 * sizeof(Card));

	int tempVal = (rand() % 8) + 1;
	newCard->value = tempVal;

	int random = getRandom();

	//int lower = 1, upper = 100, percentage

	if(random == 0) {
		newCard->ct = ATTACK;
	}
	else if(random == 1) {
		newCard->ct = DEFEND;
	}
	else {
		newCard->ct = RUN;
	}

	return newCard;
}

Card* removeCard(Card *head) {
	head = head->next;
	return head;
}

Card* addCard(Card *head, Card *c) {
	Card* curr = head;
	Card* prev = NULL;

	if(head != NULL) {
		while(curr->value > c->value) {
			prev = curr;
			curr = curr->next;
		}
		c->next = curr;
		if(prev != NULL) {
			prev->next = c;
		}
		else {
			head = c;
		}
	}
	else {
		c->next = head;
		head = c;
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
	printf("%c", head->ct);
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
	head = NULL;
	return head;
}
