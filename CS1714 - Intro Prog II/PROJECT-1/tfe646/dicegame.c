#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dicegame.h"

int getRandomNumber(int min, int max)
{
	// computes a random number between min and max, inclusive, and returns it. 
	int randNum = (rand() % (max - min + 1)) + min;

	return randNum;
}

void fillRounds(DiceRound *rounds, int ARRAY_SIZE)
{

	for(int i = 0; i < ARRAY_SIZE; i++)
	{
		// assign dice value between 1 and 6 (inclusive)
		rounds[i].dice = getRandomNumber(1,6);

		// assign points between 10-100 (inclusive) in multiples of 10
		rounds[i].points = getRandomNumber(1,10) * 10;

		// get a random number between (1,10)
		int n = getRandomNumber(1,10); 

		//decide round type based on random number
		if(n <= 2)
		{
			rounds[i].type = BONUS;
		}
		else if(n <= 4)
		{
			rounds[i].type = DOUBLE;
		}
		else
		{
			rounds[i].type = REGULAR;
		}
		
	}
}

int getRoundPoints(DiceRound object)
{
	// BONUS round will either add or subtract 100 points from player's score
	if(object.type == BONUS)
	{	
		return 100;
	}
	// DOUBLE round will either add or subtract current round's points * 2
	else if(object.type == DOUBLE)
	{
		return 2 * object.points;
	}
	// REGULAR round will either add or subtract current round's points
	else
	{
		return object.points;
	}
}

// Printing current round's info
void printRoundInfo(DiceRound object)
{
	printf("Type\t: ");
	if(object.type == BONUS)
	{
		printf("BONUS");
	}
	else if(object.type == DOUBLE)
	{
		printf("DOUBLE");
	}
	else
	{
		printf("REGULAR");
	}

	printf("\n");
	printf("Dice\t: %d\n", object.dice);
	printf("Points\t: %d\n", object.points);

}

// Printing current round's player points
void printPlayerInfo(int p1Points, int p2Points)
{
	printf("P-1\t: %d\n", p1Points);
	printf("P-2\t: %d\n", p2Points);
}