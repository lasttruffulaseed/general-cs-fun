/*
 * deed.cpp
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 * implementation of methods that are common to all Deed classes
 *
 */

#include "Deed.h"
#include <iostream>
#include <map>
#include <vector>

multimap<string, string> Deed::deedGroups;

Deed::Deed()
{
}

Deed::~Deed()
{
	cout << "----- " << name << " being deleted!";
}

void Deed::configure(vector<string>& params)
{
	// classname = params[0]
	name = params[1];
	cost = atoi(params[2].c_str());
	mortgage = atoi(params[3].c_str());
}

void Deed::info()
{
	cout << "Deed with name " << name << " costing " << cost << " and a mortgage of " << mortgage << endl;
}

const char* Deed::getName() const
{
	return name.c_str();
}

multimap<string, string>::iterator Deed::getFirstDeedInGrp(const string& grp)
{
	return deedGroups.lower_bound(grp);
}

multimap<string, string>::iterator Deed::getEndDeedInGrp(const string& grp)
{
	return deedGroups.upper_bound(grp);
}

void Deed::addToGrp(const string& grp, const string& deedName)
{
	deedGroups.insert(pair<string, string>(grp, deedName));
}

// number of deeds in the same group owned by the same owner
int Deed::getNumberOwned()
{
	int num_found = 0;
	const char* groupName = getGroupName();

	// find number of deeds owned by same owner
	multimap<string, string>::iterator it;
	for (it = getFirstDeedInGrp(groupName); it != getEndDeedInGrp(groupName); it++)
	{
		if (it->second.compare(this->owner))
			num_found++;
	}

	return num_found;
}

void Deed::setOwner(const char* ownerName)
{
	this->owner = ownerName;
}

const string& Deed::getOwner()
{
	return this->owner;
}

int Deed::getPurchasePrice()
{
	return cost;
}