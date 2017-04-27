//salvager
#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define playernum 2

void assert_salvager(struct gameState *gstate){
	int currentplayer;
	int drawntreasure;
	currentplayer = gstate -> whoseTurn;
	gstate -> hand[currentplayer][0] = mine;
	gstate -> hand[currentplayer][1] = copper;
	gstate -> hand[currentplayer][2] = copper;
	gstate -> hand[currentplayer][3] = gold;
	gstate -> hand[currentplayer][4] = salvager;
	gstate -> coins = 0;
	cardEffect(salvager, 1, 0, 0, gstate, 4, 0);

	if (gstate -> playedCardCount == 1 && gstate -> playedCards[0] == salvager && gstate -> handCount[currentplayer] == 3 && gstate -> coins == 5)
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
	printf("Card Test 4(salvager) begins: \n");
	assert_salvager(gstate);
	printf("Card Test 4(salvager) ends. \n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	return 0;
}