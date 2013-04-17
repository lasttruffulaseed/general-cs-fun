/*
 * simpleplayer.cpp
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 * implementation of the Base player class
 *
 */

#include "ClassRegistry.h"
#include "SimplePlayer.h"
#include "Deed.h"

REGISTER_CLASS(Player, SimplePlayer);

// callbacks / events for player to handle (to be defined by specific concrete player)

void SimplePlayer::discretion()
{
}

// decide yes/no on buying a property
bool SimplePlayer::buyProperty(Deed* d)
{
	// for simple player - buy if you have the money!
	return d->getPurchasePrice() < this->getCashHoldings();
}

// take action for being less than zero in cash
void SimplePlayer::yourSkint(Player *creditor)
{
	creditor->addMoney(getCashHoldings());
	//creditor->addProperties...

	justQuit();
}
