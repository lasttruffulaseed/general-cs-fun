/*
 * game.cpp
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 * implementation of the Game state
 *
 */

#include "Game.h"
#include "Player.h"
#include "ClassRegistry.h"
#include "Helpers.h"
#include <vector>

Game::Game()
{
}

/*
 * destructor
 *
 * cleans up the dynamically created game components
 */
Game::~Game()
{
	// ----- remove all the dynamically created Players
	for_each(players.begin(), players.end(), deleter<Player>);

	// ----- remove all the dynamically created Deeds
	for_each(deeds.begin(), deeds.end(), valDeleter<Deed>);

	// ----- remove all the dynamically created Spaces
	for (int i=0; i<NUM_SPACES; i++)
		delete spaces[i];

	// ----- remove all the dynamically created cards
	while (!chance.empty())
	{
		delete chance.front();
		chance.pop();
	}
	while (!communityChest.empty())
	{
		delete communityChest.front();
		communityChest.pop();
	}
}

vector<Player *>& Game::getPlayers()
{
	return players;
}

bool Game::hasWinner()
{
	return players.size()==1;
}

Space* Game::spaceAt(int position)
{
	return this->spaces[position];
}

Dice& Game::getDice()
{
	return dice;
}

void extractParams(istream& stream, vector<string>& params)
{
	char line[400];					// space for a line

	params.clear();					// reset the params
	stream.getline(line, 400);		// read a full line
	string loadLine = line;			// line for tokenizing
	int commaPos, prevPos = 0;		// position of commas
	
	do
	{
		commaPos = loadLine.find(',', prevPos);			// find next comman position

		// extract from previous comma to current comma as one string
		string param = loadLine.substr(prevPos, commaPos==string::npos ? commaPos : commaPos-prevPos);
		
		// trim the string (no white space before or after)
		param = trim(param);

		// include the param in result
		params.push_back(param);

		prevPos = commaPos+1;
	}
	while (commaPos != string::npos);
}

/*
 * this is some boilerplate code, where only change is the base class hierarchy and the action 
 * to take after configuring the created objects. Thus, reusing via a template, to support
 * similar logic for Space, Deed, ... etc.
 */
template<class Base>
void sectionLoader(istream& stream, int numElems, Game& g, void (*whatToDo)(Game& g, Base*))
{
	vector<string> params;			// params holder
	
	ClassRegistry<Base> factory = ClassRegistry<Base>::get();
	for (int i=0; i< numElems; i++)
	{
		extractParams(stream, params);

		Base* base = factory.createClass(params[0]);
		base->configure(params);

		whatToDo(g, base);					// i.e. the step that can vary
	}

}

// what to do, after loading and configuring a Deed
// - basically want to store it in the Deed map
void loadADeed(Game& g, Deed* deed)
{
	deed->info();

	g.deeds[deed->getName()] = deed;
}

// what to do, after loading and configuring a Space
// - basically want to store it in the Space array
void loadASpace(Game& g, Space* space)
{
	space->info();

	g.spaces[space->getPosition()] = space;
}

// what to do, after loading and configuring a Card
// - basically want to store it in the appropriate card deck, based on type
void loadACard(Game& g, Card* card)
{
	card->info();

	if (card->getType()==Card::chanceDeck)
		g.chance.push(card);
	else
		g.communityChest.push(card);
}

// what to do, after loading and configuring a Player
// - basically want to add it to the game list of players
void loadAPlayer(Game& g, Player* player)
{
	player->info();

	player->setContext(&g);

	g.players.push_back(player);
}

/*
 * load the components of the game from a configuration file
 *
 * The text and instructions for the following components will vary
 * across versions of the game - such as the UK version vs, the US version:
 * - deeds, spaces (really just determined by deeds), chance and community
 *   chest
 * The loader reads a line from the file and passes it to the appropriate
 * class's factory, based on the type/classname in the first field of the
 * line. The rest of the line is specific to that class and should be
 * handled by the specific derived class's load method.
 */
void Game::load(istream& stream)
{
	while (stream.good())
	{
		string section;					// component section --> base class
		int numElems;					// number of these components in the file

		// ----- read the section name and number of elements
		stream >> section >> numElems;
		stream.ignore(400, '\n');		// ignore the header

		// ----- read the deeds
		if (section == "Deeds")
		{
			sectionLoader<Deed>(stream, numElems, *this, &loadADeed);
		}

		// ----- read the spaces
		if (section == "Spaces")
		{
			sectionLoader<Space>(stream, numElems, *this, &loadASpace);
		}

		// ----- read the cards
		if (section == "Cards")
		{
			sectionLoader<Card>(stream, numElems, *this, &loadACard);
		}

		// ----- read the players
		if (section == "Players")
		{
			sectionLoader<Player>(stream, numElems, *this, &loadAPlayer);
		}
	}
}

Deed* Game::getDeed(const string& name)
{
	return deeds[name];
}


Player* Game::getPlayer(const string& name)
{
	for (vector<Player*>::iterator it = players.begin(); it < players.end(); it++)
	{
		Player *p = (*it);
		if (p->getName().compare(name)==0)
			return p;
	}
	return (Player*)0;
}
