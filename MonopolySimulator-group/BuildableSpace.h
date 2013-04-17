/*
 * buildablespace.h
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 */

#ifndef _BuildableSpace_Def
#define _BuildableSpace_Def

#include "PropertySpace.h"
#include <iostream>

using namespace std;

/*
 * BuildableSpace
 *
 * A property space that can also be developed
 *
 */
class BuildableSpace : public PropertySpace
{
private:

protected:

public:
	BuildableSpace();
	virtual ~BuildableSpace();

	// what should happen when a player lands on the space
	// will be different to a regular property - rent/cost based on how much it is developed
	virtual void land(Player* p);

	virtual void info();

	// ----------------------------------------------------------------------------------
	// construction methods
	virtual void configure(vector<string>& params);		// parameters from loading
};

#endif // ndef _Buildable_Space_Def
