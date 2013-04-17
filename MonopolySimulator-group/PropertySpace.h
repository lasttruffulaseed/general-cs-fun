/*
 * propertyspace.h
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 */

#ifndef _PropertySpace_Def
#define _PropertySpace_Def

#include "Space.h"
#include <iostream>

using namespace std;

/*
 * PropertySpace
 *
 * A board space that represents a property and matches a deed
 *
 */
class PropertySpace : public Space
{
private:

protected:
	string deedName;									// deed associated to this space

public:
	PropertySpace();
	virtual ~PropertySpace();

	// what should happen when a player lands on the space
	virtual void land(Player* p);

	virtual void info();

	// ----------------------------------------------------------------------------------
	// construction methods
	virtual void configure(vector<string>& params);		// parameters from loading
};

#endif // ndef _PropertySpace_Def
