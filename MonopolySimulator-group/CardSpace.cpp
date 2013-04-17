/*
 * CardSpace.cpp
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 * Implementation for the board spaces representing Cardspace
 *
 */

#include "CardSpace.h"
#include "Space.h"

REGISTER_CLASS(Space, CardSpace);

CardSpace::CardSpace()
{
	cardType = Card::chanceDeck;
}

CardSpace::~CardSpace()
{
}

void CardSpace::setType(Card::CardTypeEnum type) {
	cardType = type;
}

bool CardSpace::isChanceDeck() {
	return (cardType == Card::chanceDeck);
}

bool CardSpace::isCommunityDeck() {
	return (cardType == Card::communityDeck);
}

void CardSpace::configure(vector<string>& params)
{
	Space::configure(params);

	cardType = getName().compare("Chance")==0 ? Card::chanceDeck : Card::communityDeck;
}

void CardSpace::info()
{
	Space::info();
	cout << "This is a " << ((cardType == Card::chanceDeck) ? "Chance" : "Community Chest") << " card space " << endl;
}
