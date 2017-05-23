//function: getCost(int cardNumber)
#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

void assert_getCost(){
	int res;

	res = getCost(adventurer);
	if(res == 6)
		printf("Test 1: Funtion passed. \n");
	else
		printf("Test 1: Funtion failed. \n");

	res = getCost(smithy);
	if(res == 4)
		printf("Test 2: Funtion passed. \n");
	else
		printf("Test 2: Funtion failed. \n");

	res = getCost(curse);
	if(res == 0)
		printf("Test 3: Funtion passed. \n");
	else
		printf("Test 3: Funtion failed. \n");

	res = getCost(silver);
	if(res == 3)
		printf("Test 4: Funtion passed. \n");
	else
		printf("Test 4: Funtion failed. \n");

	res = getCost(feast);
	if(res == 4)
		printf("Test 5: Funtion passed. \n");
	else
		printf("Test 5: Funtion failed. \n");
}

int main(int argc, char const *argv[])
{
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Unit Test 2 begins (for getCost()): \n");
	assert_getCost();
	printf("Unit Test 2 ends (for getCost()).  \n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	return 0;
}