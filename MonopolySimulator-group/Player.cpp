/*
 * player.cpp
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 * implementation of the Base player class
 *
 */

#include "Player.h"
#include "Game.h"

Player::Player()
{
	cash = INITIAL_CASH;
	jailCount = 0;
	quit = false;
	position = 0;
}

Player::~Player()
{
}

void Player::advanceBy(int amount)
{
	// advance the position
	moveTo(position + amount);
}

void Player::moveTo(int pos)
{
	int newPos = pos;

	// check for passing go
	if (newPos >= NUM_SPACES)				// pass "go"!
	{
		this->addMoney(SALARY);
		newPos -= NUM_SPACES;				// back into actual board positions
	}

	goDirect(newPos);
}

void Player::goDirect(int pos)
{
	position = pos;

	// handle landing on the new space
	game->spaceAt(position)->land(this);
}

void Player::addMoney(int amount)
{
	cash += amount;
}

void Player::takeMoney(Player* receiver, int amount)
{
	cash -= amount;
	if (cash < 0)
	{
		yourSkint(receiver);				// callback for the player to sort out being skint
	}
}

void Player::setInJail()
{
	jailCount = 3;							// counter for number of dice tries
}

string& Player::getName()
{
	return name;
}

void Player::discretion()
{
	// default = do nothing
}

void Player::setContext(Game* g)
{
	game = g;
}

void Player::configure(vector<string>& params)
{
	name = params[1];							// param 0 is class name
}

void Player::justQuit()
{
	quit = true;
}

Game* Player::getGame()
{
	return this->game;
}

void Player::takeMoney(int money)
{
	if (money > getCashHoldings())
	{
		justQuit();						// !!!!
	}
	else
		cash -= money;
}

int Player::getCashHoldings()
{
	return cash;
}

void Player::info()
{
	cout << "player " << this->getName() << endl;
}

const string Player::getSpaceName()
{
	return game->spaceAt(position)->getName();
}