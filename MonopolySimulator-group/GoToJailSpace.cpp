/*
 * GoToJailSpace.cpp
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 * Implementation for the Tax spaces representing Tax
 *
 */

#include "GoToJailSpace.h"
#include "Space.h"

REGISTER_CLASS(Space, GoToJailSpace);

GoToJailSpace::GoToJailSpace()
{
}

void GoToJailSpace::land(Player* p)
{
	perform(p);					// perform the corresponding gotojail instruction
}

GoToJailSpace::~GoToJailSpace()
{
}

void GoToJailSpace::configure(vector<string>& params)
{
	Space::configure(params);

	setText(getName());
}

void GoToJailSpace::info()
{
	Space::info();
	cout << "This is a go to jail space." << endl;
}
