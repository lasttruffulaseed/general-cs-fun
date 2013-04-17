/*
 * instruction.h
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 */

#ifndef _Instruction_Def
#define _Instruction_Def

#include "ClassRegistry.h"
#include "Player.h"
#include <string>

using namespace std;

class Game;

//#define SPACE_BASE_PARMS 1+2		

/*
 * Instruction
 *
 * A base class for any component that is an instruction for a player. The main method here is
 * perform - i.e. perform the instructions.
 * Reuse this class hierarchy across components that can include an instruction - namely
 * TaxSpace, GoToJailCard, GoToJailSpace, MovementCard and TaxOrReceiptCard
 *
 */
class Instruction
{
private:
	string text;

public:
	// what should happen when a player gets the instruction
	virtual void perform(Player* p)=0;

	// ----------------------------------------------------------------------------------
	// construction methods
	void setText(const string&);			// set the instruction text

protected:
};

#endif // ndef _Instruction_Def
