/*
 * noactionspace.h
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 */

#ifndef _NoActionSpace_Def
#define _NoActionSpace_Def

#include "Space.h"
#include <iostream>

using namespace std;

/*
 * NoActionSpace
 *
 * A board space that is uneventful, when a player lands on it!
 *
 */
class NoActionSpace : public Space
{
public:
	NoActionSpace();
	virtual ~NoActionSpace();

	// what should happen when a player lands on the space
	virtual void land(Player* p);
};

#endif // ndef _NoActionSpace_Def
