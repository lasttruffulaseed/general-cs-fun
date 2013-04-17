/*
 * noactionspace.cpp
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 * implementation for the free parking and just-visiting board spaces
 *
 */

#include "Space.h"
#include "NoActionSpace.h"

REGISTER_CLASS(Space, NoActionSpace);

NoActionSpace::NoActionSpace()
{
}

void NoActionSpace::land(Player* p)
{
}

NoActionSpace::~NoActionSpace()
{
}

