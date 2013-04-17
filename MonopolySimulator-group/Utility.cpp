/*
 * Utility.cpp
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 * implementation of methods for a Utility Deed.
 *
 */

#include "Utility.h"
#include "ClassRegistry.h"
#include <iostream>
#include <algorithm>
#include <map>

REGISTER_CLASS(Deed, Utility);

Utility::Utility()
{
}

Utility::~Utility()
{
}

void Utility::configure(vector<string>& params)
{
	Deed::configure(params);

	times_1_ute = atoi(params[DEED_BASE_PARMS].c_str());
	times_2_ute = atoi(params[DEED_BASE_PARMS+1].c_str());

	// ----- build the Utilitys group, for lookup during runtime
	addToGrp("Utilities",getName());
}

void Utility::info()
{
	Deed::info();
	cout << "This is a Utility";

	// TODO...

	cout << "cost for one ute is " << times_1_ute << " x dice. ";
	cout << "cost for two utea is " << times_2_ute << " x dice. " << endl;
}

// cost, based on current level of development and number of properties owned
int Utility::getCostToRent(Game& g)
{
	int num_found = getNumberOwned();

	int rent;
	Dice dice = g.getDice();

	if (num_found>1)
		rent = dice.lastRoll()*times_2_ute;
	else
		rent = dice.lastRoll()*times_1_ute;

	return rent;
}

const char* Utility::getGroupName()
{
	return "Utilities";
}