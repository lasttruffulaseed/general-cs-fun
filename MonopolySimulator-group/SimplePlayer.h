/*
 * simpleplayer.h
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 */

#ifndef _SimplePlayer_Def
#define _SimplePlayer_Def

#include <list>
#include <string>
#include "Player.h"

class Game;

using namespace std;

/*
 * SimplePlayer
 *
 * A simple experimental player, but functional
 * The "strategy" is to buy for full price
 * whenever there is cash available
 *
 */
class SimplePlayer : public Player
{
	// ----------------------------------------------------------------------------------
	// callbacks / events for player to handle (to be defined by specific concrete player)
	virtual void discretion();				// chance to trade or develop property
	virtual bool buyProperty(Deed* d);		// decide yes/no on buying a property
	virtual void yourSkint(Player* cred);	// take action for being less than zero in cash

protected:
};

#endif // ndef _SimplePlayer_Def
