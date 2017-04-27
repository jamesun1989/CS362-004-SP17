//int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag);
#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define playernum 2

int assert_discardCard(struct gameState *gstate){
	int res = numHandCards(gstate);
	discardCard(0, 0, gstate, 0);
	int res2 = numHandCards(gstate);

	if(res2 == res-1)
		printf("The faction passed the unit test. \n");
	else
		printf("The function failed. \n");
}

int main(){
	int kingdomCards[10] = {adventurer, minion, mine, cutpurse, sea_hag, tribute, smithy, gardens, embargo, village};
	struct gameState *gstate;
	gstate = newGame();
	initializeGame(playernum, kingdomCards, 1, gstate);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Unit Test 3 begins (for discardCard()): \n");
	assert_discardCard(gstate);
	printf("Unit Test 3 ends (for discardCard()). \n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	return 0;
}

