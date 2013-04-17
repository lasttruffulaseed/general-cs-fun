/*
 * space.h
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 */

#ifndef _Space_Def
#define _Space_Def

#include "ClassRegistry.h"
#include <iostream>
#include <vector>
#include <string>

class Player;

#define SPACE_BASE_PARMS 1+2		

using namespace std;

/*
 * Space
 *
 * Base class representing the various types of playing spaces.
 *
 */
class Space
{
private:
	string name;
	int boardPosition;

public:
	Space();
	virtual ~Space();
	
	// Space* create()=0;								// reminder - need a factory

	string getName();

	// what should happen when a player lands on the space
	virtual void land(Player* p);

	int getPosition();

	virtual void info();

	// ----------------------------------------------------------------------------------
	// construction methods
	virtual void configure(vector<string>& params);		// parameters from loading

protected:
};

#endif // ndef _Space_Def
