//fullDeckCount(int player, int card, struct gameState *state)
#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define playernum 2

void assert_fullDeckCount(struct gameState *gstate){
	int res;
	res = fullDeckCount(0, 0, gstate);
	if(res == 0)
		printf("The funtion passed the unit test. \n");
	else
		printf("The function failed. \n");
}

int main(){
	int kingdomCards[10] = {adventurer, minion, mine, cutpurse, sea_hag, tribute, smithy, gardens, embargo, village};
	struct gameState *gstate;
	gstate = newGame();
	initializeGame(playernum, kingdomCards, 1, gstate);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Unit Test 4 begins (for fullDeckCount()): \n");
	assert_fullDeckCount(gstate);
	printf("Unit Test 4 ends (for fullDeckCount()). \n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	return 0;
}