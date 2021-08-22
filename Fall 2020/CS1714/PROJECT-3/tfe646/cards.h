#ifndef CARDS_H
#define CARDS_H

typedef enum CardType {

	ATTACK,
	DEFEND,
	RUN

} CardType;

typedef struct Card_struct {

	int value;
	CardType ct;
	struct Card_struct* next;
} Card;

Card* createCard();

Card* removeCard(Card *head);

Card* addCard(Card *head, Card *c);

int getLength(Card *head);

void printCard(Card *head);

void printCards(Card *head);

Card* buildCards(int n);

Card* destroyCards(Card *head);

#endif //CARDS_H
