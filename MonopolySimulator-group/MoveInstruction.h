/*
 * moveinstruction.h
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 */

#ifndef _MoveInstruction_Def
#define _MoveInstruction_Def

#include "Instruction.h"

//#define SPACE_BASE_PARMS 1+2		

/*
 * MoveInstruction
 *
 * A player instruction that moves the player to a position or by a relative amount.
 * perform() will call advanceBy() or advanceTo() on the player
 *
 */
class MoveInstruction : virtual public Instruction
{
private:
	int movement;						// amount of movement
	bool absolute;						// move to the position (abs) or by amount (rel)
	bool direct;						// move directly, without passing "go"

public:
	// what should happen when a player gets the instruction
	virtual void perform(Player* p);

	int getMovement();					// for info purposes
	bool getAbsolute();					// for info
	bool getDirect();					// for info

	// ----------------------------------------------------------------------------------
	// construction methods
	void setMovement(int);
	void setAbsolute(bool);
	void setDirect(bool);

protected:
};

#endif // ndef _MoveInstruction_Def
