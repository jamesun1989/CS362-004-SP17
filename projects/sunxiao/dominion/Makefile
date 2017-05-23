CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)


testgdb: cardtest2.c dominion.c rngs.c
	gcc cardtest2.c dominion.c rngs.c -g $(CFLAGS)


unittestresults.out: unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.c rngs.c
	echo "Result for running Unit tests:" > unittestresults.out
	
	echo "unittest1.c:" >> unittestresults.out
	gcc -fprofile-arcs -ftest-coverage -o unittest1 dominion.c rngs.c unittest1.c -g $(CFLAGS)
	unittest1 >> unittestresults.out
	echo "Branch coverage for unittest1.c" >> unittestresults.out
	gcov -b -c unittest1.c >> unittestresults.out
	
	echo "unittest2.c:" >> unittestresults.out
	gcc -fprofile-arcs -ftest-coverage -o unittest2 dominion.c rngs.c unittest2.c -g $(CFLAGS)
	unittest2 >> unittestresults.out
	echo "Branch coverage for unittest2.c" >> unittestresults.out
	gcov -b -c unittest2.c >> unittestresults.out
	
	echo "unittest3.c:" >> unittestresults.out
	gcc -fprofile-arcs -ftest-coverage -o unittest3 dominion.c rngs.c unittest3.c -g $(CFLAGS)
	unittest3 >> unittestresults.out
	echo "Branch coverage for unittest3.c" >> unittestresults.out
	gcov -b -c unittest3.c >> unittestresults.out
	
	echo "unittest4.c:" >> unittestresults.out
	gcc -fprofile-arcs -ftest-coverage -o unittest4 dominion.c rngs.c unittest4.c -g $(CFLAGS)
	unittest4 >> unittestresults.out
	echo "Branch coverage for unittest4.c" >> unittestresults.out
	gcov -b -c unittest4.c >> unittestresults.out

	echo "cardtest1.c:" >> unittestresults.out
	gcc -fprofile-arcs -ftest-coverage -o cardtest1 dominion.c rngs.c cardtest1.c -g $(CFLAGS)
	cardtest1 >> unittestresults.out
	echo "Branch coverage for cardtest1.c" >> unittestresults.out
	gcov -b -c cardtest1.c >> unittestresults.out

	echo "cardtest2.c:" >> unittestresults.out
	gcc -fprofile-arcs -ftest-coverage -o cardtest2 dominion.c rngs.c cardtest2.c -g $(CFLAGS)
	cardtest2 >> unittestresults.out
	echo "Branch coverage for cardtest2.c" >> unittestresults.out
	gcov -b -c cardtest2.c >> unittestresults.out

	echo "cardtest3.c:" >> unittestresults.out
	gcc -fprofile-arcs -ftest-coverage -o cardtest3 dominion.c rngs.c cardtest3.c -g $(CFLAGS)
	cardtest3 >> unittestresults.out
	echo "Branch coverage for cardtest3.c" >> unittestresults.out
	gcov -b -c cardtest3.c >> unittestresults.out

	echo "cardtest4.c:" >> unittestresults.out
	gcc -fprofile-arcs -ftest-coverage -o cardtest4 dominion.c rngs.c cardtest4.c -g $(CFLAGS)
	cardtest4 >> unittestresults.out
	echo "Branch coverage for cardtest1.4" >> unittestresults.out
	gcov -b -c cardtest4.c >> unittestresults.out

	
	echo "dominion.c:" >> unittestresults.out
	gcov -b -c dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out


randomtestcard1.out: randomtestcard1.c rngs.c dominion.c
	echo "randomtestcard1.c:" >> randomtestcard1.out
	gcc -fprofile-arcs -ftest-coverage -o randomtestcard1 dominion.c rngs.c randomtestcard1.c -g $(CFLAGS)
	randomtestcard1 >> randomtestcard1.out
	echo "Branch coverage for randomtestcard1.c" >> randomtestcard1.out
	gcov -f -b dominion.c >> randomtestcard1.out

randomtestcard2.out: randomtestcard2.c rngs.c dominion.c
	echo "randomtestcard2.c:" >> randomtestcard2.out
	gcc -fprofile-arcs -ftest-coverage -o randomtestcard2 dominion.c rngs.c randomtestcard2.c -g $(CFLAGS)
	randomtestcard2 >> randomtestcard2.out
	echo "Branch coverage for randomtestcard2.c" >> randomtestcard2.out
	gcov -f -b dominion.c >> randomtestcard2.out

randomtestadventurer.out: randomtestadventurer.c rngs.c dominion.c
	echo "randomtestadventurer.c:" >> randomtestadventurer.out
	gcc -fprofile-arcs -ftest-coverage -o randomtestadventurer dominion.c rngs.c randomtestadventurer.c -g $(CFLAGS)
	randomtestadventurer >> randomtestadventurer.out
	echo "Branch coverage for randomtestadventurer.c" >> randomtestadventurer.out
	gcov -f -b dominion.c >> randomtestadventurer.out



all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so
