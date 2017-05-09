//Random Test for Smithy
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "assert.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define total_loop 50
#define playernum 2

void randomTestingvillage(struct gameState *state, int *kingdomcard, int seed){
	int currentplayer;
	int i,j;
	int card, hand_count, deck_count, discard_count, handPos;
	int actionpoint;
	currentplayer = state -> whoseTurn;
	handPos = 0;

	for (i = 0; i < total_loop; i++)
	{
		state = newGame();
		initializeGame(currentplayer, kingdomcard, seed, state);
		currentplayer = state -> whoseTurn;
		actionpoint = 0;
		state -> numActions = actionpoint;
		hand_count = rand() % 10 + 1;
		state -> handCount[currentplayer] = hand_count;
		state -> hand[currentplayer][handPos] = village;
		for (j = 1; j < hand_count; j++) {
			card = rand() % 27;
			state->hand[currentplayer][j] = card;
		}
		deck_count = rand() % 30 + 1;
		state->deckCount[currentplayer] = deck_count;
		for (j = 0; j < deck_count; j++) {
			card = rand() % 27;
			state->deck[currentplayer][j] = card;
		}
		discard_count = rand() % 5+1;
		state->discardCount[currentplayer] = discard_count;
		for (j = 0; j < discard_count; j++) {
			card = rand() % 27;
			state->discard[currentplayer][j] = card;
		}
		cardEffect_village(currentplayer, state, handPos);


		if (state -> numActions == 2)
		{
			printf("Random Testing for village: Success. Return correct number of actionpoint.\n");
		}else{
			printf("Random Testing for village: Failed. Return wrong number of actionpoint.\n");
		}

		if (state->handCount[currentplayer] == hand_count){
			printf("Random Testing for village: Success. Return correct number of cards in hand.\n");
		}else{
			printf("Random Testing for village: Failed. Return wrong number of cards in hand.\n");
		}

		if(state -> deckCount[currentplayer] == deck_count - 1){
			printf("Random Testing for village: Success. Return correct number of deck count.\n");
		}else{
			printf("Random Testing for village: Failed. Return wrong number of deck count.\n");
		}

		if(state -> discardCount[currentplayer] == discard_count){
			printf("Random Testing for village: Success. Return correct number of discarded cards count.\n");
		}else{
			printf("Random Testing for village: Failed. Return wrong number of discarded cards count.\n");
		}
		free(state);
	}
}

int main(int argc, char const *argv[])
{
	struct gameState *randomTest;
	int kingdomCards[10] = {adventurer, minion, mine, cutpurse, sea_hag, tribute, smithy, gardens, embargo, village};
	int seed;
	time_t t;
	srand((unsigned) time(&t));
	if (argc == 2)
	{
		seed = atoi(argv[1]);
	}else{
		seed = rand()%10 + 1;
	}

	printf("Random Test for village begins: \n");
	randomTestingvillage(randomTest, kingdomCards, seed);
	printf("Random Test for village ends. \n");

	return 0;
}