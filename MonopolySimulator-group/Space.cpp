/*
 * space.cpp
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 * implementation of the property space base class
 * see header for description
 *
 */

#include "Space.h"
#include "ClassRegistry.h"

Space::Space()
{
}

Space::~Space()
{
}

void Space::land(Player* p)
{
}

void Space::configure(vector<string>& params)
{
	name = params[1];							// param 0 is class name
	boardPosition = atoi(params[2].c_str());
}

int Space::getPosition()
{
	return boardPosition;
}

void Space::info()
{
	cout << "Board space " << name << " at position " << getPosition() << endl;
}

string Space::getName()
{
	return name;
}
