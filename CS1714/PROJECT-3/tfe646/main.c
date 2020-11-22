#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cards.h"

int main( int argc, char *argv[] ) {
	FILE *fptr;
	int deckSize, p1Size, p2Size, currRound = 1;
	Card* p1, p2;

	if(argc < 3) {
		printf("ERROR NOT ENOUGH ARGS\n");
		return 1;
	}
	else if (argc >= 3) {
		fptr = fopen(argv[1], "r");
	}
	else {
		fptr = fopen("project3-output.txt", "r");
	}

	deckSize = atoi(argv[2]);
	if(deckSize < 1) {
		printf("ERROR, ENTER DECK SIZE GREATER THAN 0\n");
		return 1;
	}

	if (fptr == NULL) {
		printf("ERROR FILE NOT OPEN\n");
		return 1;
	}

	fclose(fptr);

	printf("============= PLAYER 1 V PLAYER 2 SHOWDOWN ============\n");
	printf("Start size: %d cards\n", deckSize);

	p1 = buildCards(deckSize);
	p1Size = deckSize;
	printf("Player 1 starting cards: ");
	printCards(p1);

	printf("\n");

	p2 = buildCards(deckSize);
	p2Size = deckSize;
	printf("Player 2 starting cards: ");
	printCards(p2);

	printf("\n");

	while((p1 != NULL) && (p2 != NULL)) {
		printf("----- ROUND %d -----\n", currRound);

		Card* p1Card = p1;
		Card* p2Card = p2;

		p1 = removeCard(p1);
		p1Size--;
		p2 = removeCard(p2);
		p2Size--;

		printf("Player 1 (%d): ", p1Size);
		printCard(p1);
		printf("\n");

		printf("Player 2 (%d): ", p2Size);
		printCard(p2);
		printf("\n");


		if((p1Card->ct == ATTACK) && (p2Card->ct == ATTACK)) {
			if(p1Card->value < p2Card->value) {
				p1 = removeCard(p1);
				p1Size--;
				Card* temp = createCard();
				p2 = addCard(p2, temp);
				p2Size++;
				printf("Player 1 gets a new card. Player 2 loses their next card into the abyss.\n");
			}
			else {
				p2 = removeCard(p2);
				p2Size--;
				Card* temp = createCard();
				p1 = addCard(p1, temp);
				p1Size++;
				printf("Player 2 gets a new card. Player 1 loses their next card into the abyss.\n");
			}
		}

		if((p1Card->ct == ATTACK) && (p2Card->ct == DEFEND)) {
			if(p1Card->value <= p2Card->value) {
				p1 = removeCard(p1);
				p1Size--;
				Card* temp = createCard();
				p2 = addCard(p2, temp);
				p2Size++;
				printf("Player 1 loses and Player 2 survives.\n");
				printf("Player 1 loses their next card into the abyss.\n");
			}
			else if(p1Card->value > p2Card->value) {
				Card* temp = createCard();
				p1 = addCard(p1, temp);
				p1Size++;
				printf("Player 1 wins. Player 1 gets a new card.\n");
			}
		}

		if((p1Card->ct == ATTACK) && (p2Card->ct == RUN)) {
			p2 = removeCard(p2);
			p2Size--;
			printf("Player 2 loses their next card into the abyss.\n");
		}

		if((p1Card->ct == DEFEND) && (p2Card->ct == DEFEND)) {
			printf("Both players DEFEND.\n");
			printf("Nothing happens.\n");
		}

		if((p1Card->ct == DEFEND) && (p2Card->ct == ATTACK)) {
			if(p1Card->value < p2Card->value) {
				Card* temp = createCard();
				p2 = addCard(p2, temp);
				printf("Player 2 wins. Player 2 gets a new card.\n");
			}
			else if(p1Card->value >= p2Card->value) {
				p2 = removeCard(p2);
				Card* temp = createCard();
				p1 = addCard(p1, temp);
				p1Size++;
				printf("Player 2 loses and Player 1 survives.\n");
				printf("Player 2 loses their next card into the abyss.\n");
			}
		}

		if((p1Card->ct == DEFEND) && (p2Card->ct == RUN)) {
			p2 = removeCard(p2);
			p2Size--;
			Card* temp = createCard();
			p1 = addCard(p1, temp);
			p1Size++;
			printf("Player 2 loses their next card into the abyss.\n");
		}

		if((p1Card->ct == RUN) && (p2Card->ct == ATTACK)) {
			p1 = removeCard(p1);
			p1Size--;
			printf("Player 1 loses their next card into the abyss.\n");
		}

		if((p1Card->ct == RUN) && (p2Card->ct == DEFEND)) {
			p1 = removeCard(p1);
			p1Size--;
			Card* temp = createCard();
			p2 = addCard(p2, temp);
			p2Size++;
			printf("Player 2 gets a new card. Player 1 loses their next card into the abyss.\n");
		}

		if((p1Card->ct == RUN) && (p2Card->ct == RUN)) {
			p1 = removeCard(p1);
			p1Size--;
			p2 = removeCard(p2);
			p2Size--;
			printf("Player 1 loses their next card into the abyss.\n");
			printf("Player 2 loses their next card into the abyss.\n");
		}
		printf("\n");
		currRound++;
	}

	printf("============ GAME OVER  =============\n");

	printf("Player 1 ending cards: ");
	printCards(p1);
	printf("\n");

	printf("Player 2 ending cards: ");
	printCards(p2);
	printf("\n");

	if((p1 == NULL) && (p2 == NULL)) {
		printf("\nBoth players ran out of cards. Tie.\n");
		printf("The end.")
	}
	else if(p1 == NULL) {
		printf("\nPlayer 1 ran out of cards. Player 2 wins.\n");
		printf("The end.");
	}
	else if(p2 == NULL) {
		printf("\nPlayer 2 ran out of cards. Player 1 wins.\n");
		printf("The end.");
	}

	return 0;
}
