/*
 * bank.h
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 */

#ifndef _Bank_Def
#define _Bank_Def

#include <map>
#include "Deed.h"

using namespace std;

/*
 * Bank
 *
 * Class representing the Bank in a game of Monopoly.
 *
 */
class Bank
{
	map<string, Deed*> deeds;						// property deeds, referenced by name
	int hotels;										// number of hotels available for development (12 at start)
	int houses;										// number of houses available for development (32 at start)
	// int money;									// not needed (since bank never goes broke!)

public:
	Bank();
	~Bank();

	// 

protected:
};

#endif // ndef _Bank_Def
