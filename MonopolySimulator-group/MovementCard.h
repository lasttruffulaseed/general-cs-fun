/*
 * movementcard.h
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 */

#ifndef _MovementCard_Def
#define _MovementCard_Def

#include "MoveInstruction.h"
#include "Card.h"
#include <string>

using namespace std;

/*
 * MovementCard
 *
 * Monopoly playing card with a movement instruction.
 *
 */
class MovementCard : public Card, public MoveInstruction
{
public:
	MovementCard();
	virtual ~MovementCard();

	virtual void info();

	// what should happen when a player gets the card
	//virtual void perform(Player* p);

	// ----------------------------------------------------------------------------------
	// construction methods
	virtual void configure(vector<string>& params);		// parameters from loading

protected:
};

#endif // ndef _MovementCard_Def
