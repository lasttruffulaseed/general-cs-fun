/*
 * MoveInstruction.cpp
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 * What happens when a player receives a money charge or recieve instruction - defined here!
 *
 */

#include "MoveInstruction.h"

void MoveInstruction::perform(Player* player)
{
	
}

void MoveInstruction::setAbsolute(bool isAbs)
{
	absolute = isAbs;
}

void MoveInstruction::setDirect(bool isDirect)
{
	direct = isDirect;
}

void MoveInstruction::setMovement(int amount)
{
	movement = amount;
}

bool MoveInstruction::getAbsolute()
{
	return absolute;
}

bool MoveInstruction::getDirect()
{
	return direct;
}

int MoveInstruction::getMovement()
{
	return movement;
}