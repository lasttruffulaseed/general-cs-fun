/*
 * card.h
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 */

#ifndef _Card_Def
#define _Card_Def

#include "Instruction.h"
#include <string>
#include <vector>

class Player;

using namespace std;

#define CARD_BASE_PARMS 1+1+1		// classname + type + instructions

/*
 * Card
 *
 * Monopoly playing card.
 *
 */
class Card : virtual public Instruction
{
private:
	string instructions;

public:
	enum CardTypeEnum {chanceDeck = 0, communityDeck = 1};

	void setType(CardTypeEnum type);
	CardTypeEnum getType();

	Card();
	virtual ~Card();

	virtual void info();

	// what should happen when a player gets the card [note: same signature as Instruction::perform, on purpose]
	//virtual void perform(Player* p)=0;

	// ----------------------------------------------------------------------------------
	// construction methods
	virtual void configure(vector<string>& params);		// parameters from loading

private:
		CardTypeEnum cardType;
};

#endif // ndef _Card_Def
