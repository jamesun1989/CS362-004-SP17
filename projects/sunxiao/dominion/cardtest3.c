//village
#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define playernum 2

void assert_village(struct gameState *gstate){
	int currentplayer;
	int drawntreasure;
	currentplayer = gstate -> whoseTurn;
	gstate -> hand[currentplayer][0] = copper;
	gstate -> hand[currentplayer][1] = copper;
	gstate -> hand[currentplayer][2] = village;
	gstate -> hand[currentplayer][3] = gold;
	gstate -> hand[currentplayer][4] = copper;
	cardEffect_village(currentplayer, gstate, 2);

	if (gstate -> playedCardCount == 1 && gstate -> playedCards[0] == village && gstate -> handCount[currentplayer] == 5 && gstate -> numActions == 3)
	{
		printf("The function passed this test. \n");
	}else{
		printf("The function failed. \n");
	}


}

int main(){
	int kingdomCards[10] = {adventurer, minion, mine, cutpurse, sea_hag, tribute, smithy, gardens, embargo, village};
	struct gameState *gstate;
	gstate = newGame();
	initializeGame(playernum, kingdomCards, 1, gstate);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Card Test 3(village) begins: \n");
	assert_village(gstate);
	printf("Card Test 3(village) ends. \n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	return 0;
}