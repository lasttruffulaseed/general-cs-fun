/*
 * moneycard.h
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 */

#ifndef _MoneyCard_Def
#define _MoneyCard_Def

#include "MoneyInstruction.h"
#include "Card.h"
#include <string>

using namespace std;

/*
 * MoneyCard
 *
 * Monopoly playing card with a Money instruction.
 *
 */
class MoneyCard : public Card, public MoneyInstruction
{
public:
	MoneyCard();
	virtual ~MoneyCard();

	virtual void info();

	// what should happen when a player gets the card
	// virtual void perform(Player* p); // virtual from Instruction and defined in MoneyInstruction

	// ----------------------------------------------------------------------------------
	// construction methods
	virtual void configure(vector<string>& params);		// parameters from loading

protected:
};

#endif // ndef _MoneyCard_Def
