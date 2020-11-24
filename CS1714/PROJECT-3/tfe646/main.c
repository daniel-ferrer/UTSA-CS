#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "cards.h"

int main( int argc, char *argv[] ) {
	int deckSize, currRound = 1;

	if(argc < 2) {
		printf("ERROR NOT ENOUGH ARGS\n");
		return 1;
	}
	else {
		deckSize = atoi(argv[1]);
	}

	if(deckSize < 1) {
		printf("ERROR, ENTER DECK SIZE GREATER THAN 0\n");
		return 1;
	}

	printf("============= PLAYER 1 V PLAYER 2 SHOWDOWN ============\n");
	printf("Start size: %d cards\n", deckSize);

	srand(time(0));

	Card* p1 = buildCards(deckSize);
	printf("Player 1 starting cards: ");
	printCards(p1);

	Card* p2 = buildCards(deckSize);
	printf("Player 2 starting cards: ");
	printCards(p2);

	printf("\n");


	while((p1 != NULL) && (p2 != NULL)) {
		printf("----- ROUND %d -----\n", currRound);

		Card* p1Card = p1;
		Card* p2Card = p2;

		printf("Player 1 (%d): ", getLength(p1Card));
		printCard(p1Card);
		printf("\n");

		printf("Player 2 (%d): ", getLength(p2Card));
		printCard(p2Card);
		printf("\n");

		if((p1Card->ct == ATTACK) && (p2Card->ct == ATTACK)) {
			printf("Both players ATTACK.\n");
			if(p1Card->value < p2Card->value) {
				p1 = removeCard(p1);
				Card* temp = createCard();
				p2 = addCard(p2, temp);
				printf("Player 2 wins and gets a new card. Player 1 loses their next card into the abyss.\n");
			}
			else {
				p2 = removeCard(p2);
				Card* temp = createCard();
				p1 = addCard(p1, temp);
				printf("Player 1 wins and gets a new card. Player 2 loses their next card into the abyss.\n");
			}
		}

		else if((p1Card->ct == ATTACK) && (p2Card->ct == DEFEND)) {
			printf("Player 1 ATTACKs and Player 2 DEFENDs.\n");
			if(p1Card->value <= p2Card->value) {
				p1 = removeCard(p1);
				printf("Player 1 loses and Player 2 survives.\n");
				printf("Player 1 loses their next card into the abyss.\n");
			}
			else if(p1Card->value > p2Card->value) {
				Card* temp = createCard();
				p1 = addCard(p1, temp);
				printf("Player 1 wins. Player 1 gets a new card.\n");
			}
		}

		else if((p1Card->ct == ATTACK) && (p2Card->ct == RUN)) {
			printf("Player 1 ATTACKs and Player 2 RUNs.\n");
			p2 = removeCard(p2);
			printf("Player 2 loses their next card into the abyss.\n");
		}

		else if((p1Card->ct == DEFEND) && (p2Card->ct == DEFEND)) {
			printf("Both players DEFEND.\n");
			printf("Nothing happens.\n");
		}

		else if((p1Card->ct == DEFEND) && (p2Card->ct == ATTACK)) {
			printf("Player 2 ATTACKs and Player 1 DEFENDs.\n");
			if(p1Card->value < p2Card->value) {
				Card* temp = createCard();
				p2 = addCard(p2, temp);
				printf("Player 2 wins. Player 2 gets a new card.\n");
			}
			else if(p1Card->value >= p2Card->value) {
				p2 = removeCard(p2);
				printf("Player 2 loses and Player 1 survives.\n");
				printf("Player 2 loses their next card into the abyss.\n");
			}
		}

		else if((p1Card->ct == DEFEND) && (p2Card->ct == RUN)) {
			printf("Player 1 DEFENDs and Player 2 RUNs.\n");
			p2 = removeCard(p2);
			Card* temp = createCard();
			p1 = addCard(p1, temp);
			printf("Player 2 loses their next card into the abyss.\n");
		}

		else if((p1Card->ct == RUN) && (p2Card->ct == ATTACK)) {
			printf("Player 2 ATTACKs and Player 1 RUNs.\n");
			p1 = removeCard(p1);
			printf("Player 1 loses their next card into the abyss.\n");
		}

		else if((p1Card->ct == RUN) && (p2Card->ct == DEFEND)) {
			printf("Player 2 DEFENDs and Player 1 RUNs.\n");
			p1 = removeCard(p1);
			Card* temp = createCard();
			p2 = addCard(p2, temp);
			printf("Player 2 gets a new card. Player 1 loses their next card into the abyss.\n");
		}

		else if((p1Card->ct == RUN) && (p2Card->ct == RUN)) {
			printf("Both players RUN.\n");
			p1 = removeCard(p1);
			p2 = removeCard(p2);
			printf("Player 1 loses their next card into the abyss.\n");
			printf("Player 2 loses their next card into the abyss.\n");
		}
		printf("\n");

		p1 = removeCard(p1);
		p2 = removeCard(p2);

		currRound++;
	}

	printf("============ GAME OVER  =============\n");

	printf("Player 1 ending cards: ");
	printCards(p1);

	printf("Player 2 ending cards: ");
	printCards(p2);

	destroyCards(p1);
	destroyCards(p2);


	if((p1 == NULL) && (p2 == NULL)) {
		printf("\nBoth players ran out of cards. Tie.\n");
		printf("The end.");
	}
	else if(p1 == NULL) {
		printf("\nPlayer 1 ran out of cards. Player 2 wins.\n");
		printf("The end.");
	}
	else if(p2 == NULL) {
		printf("\nPlayer 2 ran out of cards. Player 1 wins.\n");
		printf("The end.");
	}
	printf("\n");
	return 0;
}
