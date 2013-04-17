/*
 * street.h
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 */

#ifndef _Street_Def
#define _Street_Def

#include "Deed.h"

/*
 * Street
 *
 * A type of Monopoly deed. A street can be developed with houses.
 * The cost of landing on the street depends on how many houses and
 * if all properties in the colour group are owned by the same player
 *
 */
class Street : public Deed
{
private:
	string colourGroup;
	int rentByTotalHouses[5];					// house = 0 (just rent) to 4
	int rentForHotel;

public:
	Street();
	virtual ~Street();

	virtual void info();

	virtual int getCostToRent(Game& g);				// cost, based on current level of development
	virtual const char* getGroupName();				// colour group for this street!

	// ----------------------------------------------------------------------------------
	// construction methods
	virtual void configure(vector<string>& params);

protected:
};

#endif // ndef _Street_Def
