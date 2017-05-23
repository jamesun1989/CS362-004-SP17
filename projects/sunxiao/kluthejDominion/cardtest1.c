//smithy
#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define playernum 2

void assert_smithy(struct gameState *gstate){
	int currentplayer;
	currentplayer = gstate -> whoseTurn;
	gstate -> hand[currentplayer][0] = copper;
	gstate -> hand[currentplayer][1] = copper;
	gstate -> hand[currentplayer][2] = smithy;
	gstate -> hand[currentplayer][3] = gold;
	gstate -> hand[currentplayer][4] = copper;
	playSmithy(gstate, 2);

	if (gstate -> playedCardCount == 1 && gstate -> playedCards[0] == smithy && gstate -> handCount[currentplayer] == 7)
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
	printf("Card Test 1(smithy) begins: \n");
	assert_smithy(gstate);
	printf("Card Test 1(smithy) ends. \n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	return 0;
}