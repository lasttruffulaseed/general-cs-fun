/*
 * property.h
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 */

#ifndef _Property_Def
#define _Property_Def

#include "Space.h"
#include <iostream>

using namespace std;

/*
 * Property
 *
 * A board space that is tied to a deed and all the good/bad things that can
 * happen when landing on it!
 *
 */
class Property : public Space
{
private:
	Street* deed;

public:
	Property();
	virtual ~Property();

	// loader
	virtual void load(istream& stream);

	// what should happen when a player lands on the space
	virtual void land(Player* p);
};

#endif // ndef _Property_Def
