/*
 * moneyinstruction.h
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 */

#ifndef _MoneyInstruction_Def
#define _MoneyInstruction_Def

#include "Instruction.h"

//#define SPACE_BASE_PARMS 1+2		

/*
 * MoneyInstruction
 *
 * A player instruction involving the transfer of money.
 * perform() will call give() or take() on the player
 *
 */
class MoneyInstruction : virtual public Instruction
{
private:
	int amount;

public:
	// what should happen when a player gets the instruction
	virtual void perform(Player* p);

	int getAmount();

	// ----------------------------------------------------------------------------------
	// construction methods
	void setAmount(int);

protected:
};

#endif // ndef _MoneyInstruction_Def
