/*
 * dice.h
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 */

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>


#ifndef _Dice_Def
#define _Dice_Def

using namespace std;

#define MINDICE 1
#define MAXDICE 6

/*
 * Dice
 *
 * Class representing the playing dice.
 *
 */
class Dice
{
private:
	int die1, die2;					// the roll
public:
	Dice();
	~Dice();

	// 
	int roll();						// rolls dice and returns the count
	bool isDouble();	            // indicates if this is a double
	int lastRoll();					// to see what last roll was
};

#endif // ndef _Dice_Def
