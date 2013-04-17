/*
 * MovementCard.cpp
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 * Implementation of game card that includes a movement instruction
 *
 */

#include "ClassRegistry.h"
#include "MovementCard.h"
#include <iostream>

REGISTER_CLASS(Card, MovementCard);

MovementCard::MovementCard()
{
}

MovementCard::~MovementCard()
{
}

void MovementCard::configure(vector<string>& params)
{
	Card::configure(params);

	setMovement( atoi(params[CARD_BASE_PARMS].c_str()) );			// amount of movement
	if (params[CARD_BASE_PARMS+1].compare("dir")==0)				// direct
	{
		setAbsolute(true);
		setDirect(true);
	}
	else if (params[CARD_BASE_PARMS+1].compare("abs")==0)
	{
		setAbsolute(true);
		setDirect(false);
	}
	else
	{
		setAbsolute(false);
		setDirect(false);
	}
}

void MovementCard::info()
{
	Card::info();
	cout << "This is a movement card with val=" << getMovement() << " and abs=" << getAbsolute() << " and dir=" << getDirect() << endl;
}
