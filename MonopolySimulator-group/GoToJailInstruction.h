/*
 * gotojailinstruction.h
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 */

#ifndef _GoToJailInstruction_Def
#define _GoToJailInstruction_Def

#include "Instruction.h"

//#define SPACE_BASE_PARMS 1+2		

/*
 * GotoJailInstruction
 *
 * A player instruction that forces the player to move to jail and to have the "in jail" state.
 * perform() will call immediateMove() and setInJail() on the player
 *
 */
class GoToJailInstruction : public Instruction
{
private:

public:
	// what should happen when a player gets the instruction
	virtual void perform(Player* p);

	// ----------------------------------------------------------------------------------
	// construction methods

	// none

protected:
};

#endif // ndef _GoToJailInstruction_Def
