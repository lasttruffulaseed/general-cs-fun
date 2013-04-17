/*
 * station.h
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 */

#ifndef _Station_Def
#define _Station_Def

#include "Deed.h"
#include "Game.h"

/*
 * Station
 *
 * A type of Monopoly deed. A station collects more rent depending on the 
 * number of total stations owned by the same player.
 * However, it cannot be developed on.
 *
 */
class Station : public Deed
{
private:
	// how much to charge for landing on a property with this deed (depends on number owned by the player)
	int rentPerTotalOwned[4];			
public:
	Station();
	virtual ~Station();

	virtual void info();

	virtual int getCostToRent(Game& g);				// cost, based on current level of development
	virtual const char* getGroupName();				// group for this = "Stations"

	// ----------------------------------------------------------------------------------
	// construction methods
	virtual void configure(vector<string>& params);		// parameters from loading

protected:
};

#endif // ndef _Station_Def
