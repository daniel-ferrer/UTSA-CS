#ifndef DICEGAME_H
#define DICEGAME_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum ROUNDTYPE
{
	BONUS, 
	DOUBLE,
	REGULAR
} ROUNDTYPE;

typedef struct DiceRound
{
	int dice;
	int points;
	ROUNDTYPE type;
} DiceRound;

int getRandomNumber(int min, int max);

void fillRounds(DiceRound *rounds, int ARRAY_SIZE);

int getRoundPoints(DiceRound object);

void printRoundInfo(DiceRound object);

void printPlayerInfo(int p1Points, int p2Points);

#endif //DICEGAME_H