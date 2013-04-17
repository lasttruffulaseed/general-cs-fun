/*
 * propertyspace.cpp
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 * Implementation for the board spaces representing property deeds
 * This is a superclass of BuildablePropertySpace, which supports
 * similar properties, except that they can be developed
 *
 */

#include "PropertySpace.h"
#include "Space.h"
#include "Player.h"
#include "Game.h"

REGISTER_CLASS(Space, PropertySpace);

PropertySpace::PropertySpace()
{
}

void PropertySpace::land(Player* p)
{
	Game* game = p->getGame();

	string deedName = getName();

	Deed* deed = game->getDeed(deedName);		// deed for space landed on
	
	string ownerName = deed->getOwner();

	if (ownerName.length()>0)								// if there is an owner
	{
		Player* owner = game->getPlayer(ownerName);

		if (owner)
		{
			p->takeMoney(owner, deed->getCostToRent(*game));
		}
	}
	else
	{
		if (p->buyProperty(deed))
		{
			p->takeMoney(deed->getPurchasePrice());
			deed->setOwner(p->getName().c_str());
		}
	}
}

PropertySpace::~PropertySpace()
{
}

void PropertySpace::configure(vector<string>& params)
{
	Space::configure(params);

	deedName = params[SPACE_BASE_PARMS];
}

void PropertySpace::info()
{
	Space::info();
	cout << "This is a property space for the " << deedName << " deed." << endl;
}
