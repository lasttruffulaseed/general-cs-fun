/*
 * player.h
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 */

#ifndef _Player_Def
#define _Player_Def

#include <list>
#include <string>
#include "Deed.h"

class Game;

using namespace std;

/*
 * Player
 *
 * Base class for the various types of Monopoly players.
 * The base player is an actual functional player. The "strategy" is to buy for full price
 * whenever there is cash available
 *
 */
class Player
{
	string name;							// dog, car, ship, boot, top-hat, etc....
	int cash;								// current holdings of cash
	int jailCount;							// countdown number of throws while in jail
	bool quit;								// true when player has quit
	int position;							// position on the board
	Game* game;								// game being participated in

public:
	Player();
	virtual ~Player();

	virtual void info();

	// ----------------------------------------------------------------------------------
	// player management
	void advanceBy(int amount);				// move a relative number of spaces
	void moveTo(int position);				// move forward to (and collect 200 if passing "go")
	void goDirect(int position);			// go directly to (and do not pass "go")
	void addMoney(int amount);				// give player some money
	void takeMoney(Player* receiver, int m);// charge player some money
	void takeMoney(int m);					// charge player some money (to bank)
	void setInJail();						// "in jail" state
	void justQuit();						// give up
	Game* getGame();							// game context

	// ----------------------------------------------------------------------------------
	// player info
	string& getName();						// player name
	int getCashHoldings();					// current money
	bool hasQuit();							// true when player gives up
	const string getSpaceName();			// name of current space

	// ----------------------------------------------------------------------------------
	// callbacks / events for player to handle (to be defined by specific concrete player)
	virtual void discretion()=0;			// chance to trade or develop property
	virtual bool buyProperty(Deed* d)=0;	// decide yes/no on buying a property
	virtual void yourSkint(Player* cred)=0;	// take action for being less than zero in cash

	// ----------------------------------------------------------------------------------
	// construction methods
	virtual void configure(vector<string>& params);		// parameters from loading
	void setContext(Game* game);						// for decisions/interactions

protected:
};

#endif // ndef _Player_Def
