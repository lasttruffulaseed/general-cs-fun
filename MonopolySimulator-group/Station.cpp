/*
 * Station.cpp
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 * implementation of methods for a Station Deed.
 *
 */

#include "Station.h"
#include "ClassRegistry.h"
#include <iostream>

REGISTER_CLASS(Deed, Station);

Station::Station()
{
}

Station::~Station()
{
}

void Station::configure(vector<string>& params)
{
	Deed::configure(params);

	// ----- get the amount to charge, based on total stations owned
	// first 3 params are common to all deeds
	for (int i = 0; i < 4; i++)
		this->rentPerTotalOwned[i] = atoi(params[i+DEED_BASE_PARMS].c_str());

	// ----- build the stations group, for lookup during runtime
	addToGrp("stations",getName());
}

void Station::info()
{
	Deed::info();
	cout << "This is a station";
	for (int i=0; i<4; i++)
		cout << ". with " << i+1 << " the cost is " << rentPerTotalOwned[i];
	cout << endl;
}

// cost, based on current level of development and number of stations owned!
int Station::getCostToRent(Game& g)
{
	int num_found = getNumberOwned();

	return rentPerTotalOwned[num_found];
}

const char* Station::getGroupName()
{
	return "stations";
}