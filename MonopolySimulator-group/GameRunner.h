/*
 * gamerunner.h
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 */

#ifndef _GameRunner_Def
#define _GameRunner_Def

#include "Game.h"
#include "Player.h"

/*
 * GameRunner
 *
 * This class sequences through the game. The basic rules related to taking of turns are
 * described here (in turn() method). The sequncing continues - by calling turn() each time,
*  until there is a winner, or until the game gets boring (defined by the maximum number of turns).
 *
 */
class GameRunner
{
	int maxTurns;						// maximum number of turns of the game to take
	Game& game;							// local reference to game state

public:
	GameRunner(Game& g, int maxTurns=1000);
	~GameRunner();					

	void showProgress();

	// ----------------------------------------------------------------------------------
	// main game runner entry point
	void runGame();						// runs the overall game [start to finish]

	// ----------------------------------------------------------------------------------
	// game execution sub-phases
protected:
	void turn(int playerNum);			// sequence for a single turn of the game
	int selectStartingPlayer();			// who goes first

};

#endif // ndef _GameRunner_Def
