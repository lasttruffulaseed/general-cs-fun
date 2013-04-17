/*
 * game.h
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 */

#ifndef _Game_Def
#define _Game_Def

class Player;

#include "Card.h"
#include "Space.h"
#include "Deed.h"
#include "Bank.h"
#include "Dice.h"
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <iostream>

using namespace std;

#define NUM_SPACES 40								// number of board spaces
#define SALARY 200									// amount for passing "go"
#define JAIL 10										// position of jail on the board
#define INITIAL_CASH 1500							// initial cash
#define GO_TO_JAIL 30								// position of go to jail on the board

/*
 * Game
 *
 * This class represents the state of a game of Monopoly.
 * official rules defined by: http://www.hasbro.com/common/instruct/monins.pdf
 * additional info: http://en.wikipedia.org/wiki/Monopoly_(game)
 * components used: http://coromandal.files.wordpress.com/2011/01/monopoly-board.jpg
 *
 */
class Game
{
	// ----------------------------------------------------------------------------------
	// game components
private:
	vector<Player*> players;						// game participants
	Space* spaces[NUM_SPACES];						// game spaces
	map<string, Deed*> deeds;						// title deeds
	queue<Card*> chance;							// chance card deck (16 in deck at start)
	queue<Card*> communityChest;					// community chest card deck (16 at start)
	Bank bank;										// the bank
	Dice dice;										// 2 dice

public:
	Game();
	~Game();

	// ----------------------------------------------------------------------------------
	// Game setup methods
public:
	void load(istream& stream);						// loads the specific version of the game from input
protected:
	friend void loadADeed(Game& g, Deed* deed);
	friend void loadASpace(Game& g, Space* space);
	friend void loadACard(Game& g, Card* card);
	friend void loadAPlayer(Game& g, Player* player);

	// ----------------------------------------------------------------------------------
	// Runtime game state methods
public:
	bool hasWinner();								// when we have a clear winner! (#players==1)
	Dice& getDice();								// get the dice component
	vector<Player*>& getPlayers();					// get the game players list
	Space* spaceAt(int position);					// get a board space
	Deed* getDeed(const string& name);				// get a deed by name
	Player* getPlayer(const string& name);			// get a player by name

	void report(string& whatHappened);				// provide a status of happenings!
};

#endif // ndef _Game_Def
