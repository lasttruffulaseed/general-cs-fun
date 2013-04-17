/*
 * buildablespace.cpp
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 * Implementation for the board spaces representing property deeds that
 * can be developed (i.e. have houses or a hotel)
 *
 */

#include "BuildableSpace.h"
#include "Space.h"

REGISTER_CLASS(Space, BuildableSpace);

BuildableSpace::BuildableSpace()
{
}

void BuildableSpace::land(Player* p)
{
}

BuildableSpace::~BuildableSpace()
{
}

void BuildableSpace::configure(vector<string>& params)
{
	PropertySpace::configure(params);
}

void BuildableSpace::info()
{
	PropertySpace::info();
	cout << "This property can be built on" << endl;
}
