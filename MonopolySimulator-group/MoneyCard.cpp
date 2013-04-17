/*
 * MoneyCard.cpp
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 * Implementation of game card that includes a Money instruction
 *
 */
#include "ClassRegistry.h"
#include "MoneyCard.h"
#include <iostream>

REGISTER_CLASS(Card, MoneyCard);

MoneyCard::MoneyCard()
{
}

MoneyCard::~MoneyCard()
{
}

void MoneyCard::configure(vector<string>& params)
{
	Card::configure(params);

	setAmount( atoi(params[CARD_BASE_PARMS].c_str()) );			    // amount of Money
}

void MoneyCard::info()
{
	Card::info();
	cout << "This is a Money card with val=" << getAmount() << endl;
}
