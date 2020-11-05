#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dicegame.h"

int main(int argc, char* argv[])
{
	// Initialize the srand() to start the random generator
	srand((int)time(0));

	// Initialize the player-1 and player-2 scores to 0
	int p1Points = 0;
	int p2Points = 0;

	// Initialize all other required variables
	int numRounds, currentPlayer;
	DiceRound* rounds = NULL;

	// Ask the user for the number of rounds to run the game
	printf("Enter the number of rounds you want to play: ");
	scanf("%d", &numRounds);

	// Dynamically create an array of DiceRound struct objects, based on the user input
	rounds = (DiceRound*)malloc(sizeof(DiceRound) * numRounds);

	// Check if array created. If not end program, by calling return 1;
	if(rounds == NULL)
	{
		return 1;
	}
	
	currentPlayer = getRandomNumber(1, 2);

	// Fill the DiceRound array by calling the fillRounds() function
	fillRounds(rounds, numRounds);

	// Call printPlayerInfo() function to print the initial player scores which will be 0
	printPlayerInfo(p1Points, p2Points);
	for(int i = 0; i < numRounds; i++)
	{
		// Call getRoundPoints() to get the actual points to be used for this round
		printf("\nROUND %d\n--------\n", i+1);
		printf("Player\t: %d\n", currentPlayer); // Print current player
	    // Call printRoundInfo() to print the round information
	    printRoundInfo(rounds[i]);
		
		// MAIN GAME LOGIC
		// Write code here to get the main game logic using branches
		// IF Player-1 (even player) is the current player and the dice rolled is even
	    if(currentPlayer == 1)
	    {
	    	if(rounds[i].dice % 2 == 0)
	    	{
	    		p1Points += getRoundPoints(rounds[i]);
	    	}
	    	else
	    	{
	    		p1Points -= getRoundPoints(rounds[i]);
	    		currentPlayer = 2;
	    	}
	    }
		// OR
		// IF Player-2 (odd player) is the current player and the dice rolled is odd
			// THEN Current player gains the points, based on the type of the round. The playerâ€™s turn continues in the next round.
		else
		{
			if(rounds[i].dice % 2 != 0)
	    	{
	    		p2Points += getRoundPoints(rounds[i]);
	    	}
	    	else
	    	{
	    		p2Points -= getRoundPoints(rounds[i]);
	    		currentPlayer = 1;
	    	}			
		}
		// IF Player-1 (even player) is the current player and the dice rolled is odd 
		// OR 
		// IF Player-2 (odd player) is the current player and the dice rolled is even
			// THEN Current player incurs penalty of the same amount of points, based on the type of the round (see above). In the next round, the current player is changed to the other player.

		// Call printPlayerInfo() to print the player information at the end of the round
		printPlayerInfo(p1Points, p2Points);
	}

	printf("\nGAME OVER!!\n");

	// Compare the final points for player-1 and player-2
	// Print the winner as the one with higher points
	if(p1Points > p2Points)
	{
		printf("P1 Won\n");
	}
	else if(p2Points > p1Points)
	{
		printf("P2 Won\n");
	}
	else
	{
		printf("Tie\n");
	}
	
	// Free the dynamically allocated array memory
	free(rounds);
	rounds = NULL;

	return 0;
}