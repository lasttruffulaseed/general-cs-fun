/*
 * cardspace.h
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 */

#ifndef _CardSpace_Def
#define _CardSpace_Def

#include "Space.h"
#include "Card.h"
#include <iostream>

using namespace std;

/*
 * CardSpace
 *
 * A board space that represents when a player must take a card from a card deck and follow the instructions
 *
 */
class CardSpace : public Space
{
public:
	CardSpace();
	virtual ~CardSpace();

	void setType(Card::CardTypeEnum type);

	bool isChanceDeck();

	bool isCommunityDeck();

	virtual void info();

	// ----------------------------------------------------------------------------------
	// construction methods
	virtual void configure(vector<string>& params);		// parameters from loading

protected:
	Card::CardTypeEnum cardType;						// deck associated to this space
};

#endif // ndef _CardSpace_Def
