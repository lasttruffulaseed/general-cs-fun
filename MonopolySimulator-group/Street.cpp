/*
 * street.cpp
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 * implementation of methods for a Street Deed.
 *
 */

#include "Street.h"
#include "ClassRegistry.h"
#include <iostream>

REGISTER_CLASS(Deed, Street);

Street::Street()
{
}

Street::~Street()
{
}

void Street::configure(vector<string>& params)
{
	Deed::configure(params);

	// first 3 params are common to all deeds
	colourGroup = params[DEED_BASE_PARMS];

	// ----- get the amount to charge, based on total houses on the property
	for (int i = 0; i < 5; i++)
		rentByTotalHouses[i] = atoi(params[i+DEED_BASE_PARMS+1].c_str());		
	
	rentForHotel = atoi(params[DEED_BASE_PARMS+1+5].c_str());	

	// ----- build the colour group, for lookup during runtime
	addToGrp(colourGroup, getName());
}

void Street::info()
{
	Deed::info();

	cout << "This is a street";
	for (int i=0; i<5; i++)
		cout << ". rent for " << i << " houses is " << rentByTotalHouses[i];
	cout << ". rent for a hotel is " << rentForHotel << endl;
}

// cost, based on current level of development and number of properties owned
int Street::getCostToRent(Game& g)
{
	return rentByTotalHouses[0];				// simple rule, for now!
}

const char* Street::getGroupName()
{
	return colourGroup.c_str();
}