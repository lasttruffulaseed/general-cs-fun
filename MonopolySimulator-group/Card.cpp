/*
 * Card.cpp
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 * Implementation for the Card base class
 *
 */

#include "Card.h"
#include <iostream>

Card::Card()
{
}

Card::~Card()
{
}

void Card::configure(vector<string>& params)
{
	cardType = params[1].compare("Chance")==0 ? chanceDeck : communityDeck;
	instructions = params[2];
}

void Card::info()
{
	cout << "This is a " << (cardType==chanceDeck? "chance" : "community chest") << " card, with instructions\"" << instructions << "\"" << endl;
}

Card::CardTypeEnum Card::getType()
{
	return cardType;
}