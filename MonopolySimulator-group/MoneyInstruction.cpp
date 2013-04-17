/*
 * MoneyInstruction.cpp
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 * What happens when a player receives a money charge or recieve instruction - defined here!
 *
 */

#include "MoneyInstruction.h"

void MoneyInstruction::perform(Player* player)
{
	
}

void MoneyInstruction::setAmount(int amount)
{
	this->amount = amount;
}

int MoneyInstruction::getAmount()
{
	return amount;
}
