/*
 * dice.cpp
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 * implementation of the game dice class
 *
 */

#include "Dice.h"

Dice::Dice()
{
	// seed the random number generator
	time_t seconds;
	time(&seconds);
	srand((unsigned int) seconds);
}

Dice::~Dice()
{
	die1=0;
	die2=0;
}

bool Dice::isDouble()
{
	return die1==die2;
}

// the total would be as follow when needed.
// total = die1+ die2 ;
// for the random player choose.. you can use the same code of dice ..( just changing min and max to determine the range )
int Dice::roll()
{
	die1 = rand() % (MAXDICE - MINDICE + 1) + MINDICE;
	die2 = rand() % (MAXDICE - MINDICE + 1) + MINDICE;

	return lastRoll();
}

int Dice::lastRoll()
{
	return die1+die2;
}
