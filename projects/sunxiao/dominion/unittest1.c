//function: int drawCard(int player, struct gameState *state)
#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define playernum 2

//Player should have five cards in hands when drawcards() is called in initializeGame function.
void assert_drawcard(struct gameState *gstate){
	if(numHandCards(gstate) == 5){
		printf("This function pass the test. \n");
	}else{
		printf("This function fails. \n");
	}
}

int main(){
	int kingdomCards[10] = {adventurer, minion, mine, cutpurse, sea_hag, tribute, smithy, gardens, embargo, village};
	struct gameState *gstate;
	gstate = newGame();
	initializeGame(playernum, kingdomCards, 1, gstate);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Unit Test 1 begins(for drawCard()): \n");
	assert_drawcard(gstate);
	printf("Unit Test 1 ends (for drawCard()). \n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	return 0;
}