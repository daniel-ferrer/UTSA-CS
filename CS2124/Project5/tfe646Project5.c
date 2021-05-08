#include "HashTable.h"

int main()
{
	HashTable ht = newHashTable(100);
	FILE *fptr;
	Element e;
	fptr = fopen("nbaTeamNames.csv", "r");
	if(fptr == NULL) {
		perror("Failed to open names file.\n");
		return -1;
	}

	int wins, losses, i, t1Score, t2Score;
	char team1[MAX_NAME_LENGTH], team2[MAX_NAME_LENGTH], teams[30][MAX_NAME_LENGTH];
	
	for(i = 0; i < 30; i++) {
		if(fscanf(fptr, "%[^\n]%*c", teams[i])); //inside of if statement to ignore error msg
		cleanString(teams[i]);
		strcpy(e.teamName, teams[i]);
		e.losses = e.wins = 0;
		put(ht, e);

	}

	fptr = fopen("nbaData2019.csv", "r");
	if(fptr == NULL) {
		perror("Failed to open data file.\n");
		return -1;
	}
	
	while(fscanf(fptr, "%[^,]%*c%d%*c%[^,]%*c%d\n", team1, &t1Score, team2, &t2Score) == 4) {

		cleanString(team1);
		cleanString(team2);

		if(t1Score > t2Score) {
			Element *e;
			e = get(ht, team1);
			e->wins++;

			e = get(ht, team2);
			e->losses++;
		
		}
		else {
			Element *e;
			e = get(ht, team2);
			e->wins++;

			e = get(ht, team1);
			e->losses++;
		}
	}

	for(i = 0; i < 30; i++) {
		Element e;
		strcpy(e.teamName, teams[i]);
		e = *get(ht, e.teamName);

		printf("%s : %d Wins - %d Losses\n", teams[i], e.wins, e.losses);
	}

	freeHashTable(ht);

	return 0;
}
