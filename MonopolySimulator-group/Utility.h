/*
 * utility.h
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 */

#ifndef _Utility_Def
#define _Utility_Def

#include "Deed.h"
#include "Game.h"

/*
 * Utility
 *
 * A type of Monopoly deed. A utility collects more rent depending on the 
 * number of utilities owned (one or both) and the dice roll. The dice roll
 * multiplier is a different number depending on the number of properties owned
 *
 */
class Utility : public Deed
{
private:
	// TODO: what attributes?
	//int rentPerTotalOwned[4];			

	int times_1_ute, times_2_ute;					// cost multiplier for dice roll
public:
	Utility();
	virtual ~Utility();

	virtual void info();

	virtual int getCostToRent(Game& g);				// cost, based on current level of development
	virtual const char* getGroupName();

	// ----------------------------------------------------------------------------------
	// construction methods
	// TODO: define the config, based on attributes needed
	virtual void configure(vector<string>& params);		// parameters from loading

protected:
};

#endif // ndef _Utility_Def
