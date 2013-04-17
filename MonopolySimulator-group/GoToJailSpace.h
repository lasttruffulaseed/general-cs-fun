/*
 * GoToJailSpace.h
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 */

#ifndef _GoToJailSpace_Def
#define _GoToJailSpace_Def

#include "Space.h"
#include "GoToJailInstruction.h"

using namespace std;

/*
 * GoToJailSpace
 *
 * A special instruction board space. Sends player directly to jail.
 *
 */
class GoToJailSpace : public Space , public GoToJailInstruction
{
public:
	GoToJailSpace();
	virtual ~GoToJailSpace();

	// what should happen when a player lands on the space
	virtual void land(Player* p);

	virtual void info();

	// ----------------------------------------------------------------------------------
	// construction methods
	virtual void configure(vector<string>& params);		// parameters from loading
};

#endif // ndef _GoToJailSpace_Def
