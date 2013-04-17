/*
 * TaxSpace.h
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 */

#ifndef _TaxSpace_Def
#define _TaxSpace_Def

#include "Space.h"
#include "MoneyInstruction.h"
#include <iostream>

using namespace std;

/*
 * TaxSpace
 *
 * A board space that represents a TaxSpace
 *
 */
class TaxSpace : public Space, public MoneyInstruction
{
public:
	TaxSpace();
	virtual ~TaxSpace();

	// what should happen when a player lands on the space
	virtual void land(Player* p);

	virtual void info();

	// ----------------------------------------------------------------------------------
	// construction methods
	virtual void configure(vector<string>& params);		// parameters from loading
};

#endif // ndef _TaxSpace_Def
