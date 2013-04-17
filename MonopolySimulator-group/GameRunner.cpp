/*
 * gamerunner.cpp
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 * implementation of the GameRunner class
 * see header for description
 *
 */

#include "Helpers.h"
#include "GameRunner.h"
#include <algorithm>

GameRunner::GameRunner(Game& g, int maxRolls) : game(g), maxTurns(maxRolls)
{
}

GameRunner::~GameRunner()
{
}

/*
 * runGame
 * 
 * sequence through each player taking turns, until there is a winner or 
 * players get "bored" (reach max turns)
 *
 */
void GameRunner::runGame()
{
	int currentPlayerNum = selectStartingPlayer();				// starting player

	int turnCount = 0;
	while (!game.hasWinner() && (++turnCount < maxTurns))
	{
		turn(currentPlayerNum);									// sequence through next player's turn

		showProgress();
	
		int numPlayers = game.getPlayers().size();				// current num players in game
		currentPlayerNum = bounded(++currentPlayerNum, numPlayers); // advance to next player
	}	
}

/*
 * turn
 *
 * sequence through the stages of a single turn, for the given player number
 */
void GameRunner::turn(int playerNum)
{
	Dice& dice = game.getDice();						// game dice
	Player* player = game.getPlayers()[playerNum];		// current player
	int numDoubles = 0;									// number of doubles rolled

	// ----- give player chance to trade and buy property
	player->discretion();

	do
	{
		// ----- roll dice
		int roll = dice.roll();							
		numDoubles += (dice.isDouble() ? 1: 0);			// increment # doubles (if applicable)

		// ----- if third double - send player to jail
		if (numDoubles == 3)
		{
			game.spaceAt(GO_TO_JAIL)->land(player);		// same logic as if we landed on this space
			break;
		}

		// ----- otherwise move forward by the number of spaces
		//       (if player passes go, they get 200 - defined in base Player)
		player->advanceBy(roll);						// move forward by the number of spaces on dice

		// ----- give player another chance to trade and buy property
		player->discretion();
	}
	while (dice.isDouble());						// player can keep rolling, while throwing doubles
}

/*
 * selectStartingPlayer
 *
 * who rolls first (random)
 *
 */
int GameRunner::selectStartingPlayer()
{
	// best roll wins - but this is simply by chance => just use the chance from a single roll!
	return bounded(game.getDice().roll(), game.getPlayers().size());
}

void showPlayerStatus(Player* p)
{
	string name = p->getName();
	int cash = p->getCashHoldings();
	string space = p->getSpaceName();

	cout << "Player: " << name << " has $" << cash << " and is on " << space << endl;
}

void GameRunner::showProgress()
{
	cout << "---------------------------------------------------------------------" << endl;
	for_each(game.getPlayers().begin(), game.getPlayers().end(), showPlayerStatus);
}