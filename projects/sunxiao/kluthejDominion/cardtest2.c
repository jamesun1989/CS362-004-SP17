//adventurer
#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define playernum 2

void assert_adventurer(struct gameState *gstate){
	int currentplayer;
	int kingdomCards[10] = {adventurer, minion, mine, cutpurse, sea_hag, tribute, smithy, gardens, embargo, village};
	int drawntreasure = 0;
	int afterdrawn = 0;
	currentplayer = gstate -> whoseTurn;
	gstate -> hand[currentplayer][0] = copper;
	gstate -> hand[currentplayer][1] = copper;
	gstate -> hand[currentplayer][2] = adventurer;
	gstate -> hand[currentplayer][3] = gold;
	gstate -> hand[currentplayer][4] = copper;

	drawntreasure = treasurecount(currentplayer, gstate);
	playAdventurer(gstate);
	afterdrawn = treasurecount(currentplayer, gstate);

	if(afterdrawn - drawntreasure == 2 && gstate -> handCount[currentplayer] == 6){
		printf("This function passed the test. \n");
	}else{
		printf("This function failed. \n");
	}
}

int treasurecount(int currentplayer, struct gameState *gstate){
	int count = 0;
	int i;

	for(i=0;i<gstate -> handCount[currentplayer];i++){
		if(gstate -> hand[currentplayer][i] == copper ||gstate -> hand[currentplayer][i] == silver || gstate -> hand[currentplayer][i] == gold)
			count ++;
	}
	return count;
}

int main(){
	int kingdomCards[10] = {adventurer, minion, mine, cutpurse, sea_hag, tribute, smithy, gardens, embargo, village};
	struct gameState *gstate;
	gstate = newGame();
	initializeGame(playernum, kingdomCards, 1, gstate);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Card Test 2(adventurer) begins: \n");
	assert_adventurer(gstate);
	printf("Card Test 2(adventurer) ends. \n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	return 0;
}