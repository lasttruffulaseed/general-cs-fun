/*
 * TaxSpace.cpp
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 * Implementation for the Tax spaces representing Tax
 *
 */

#include "TaxSpace.h"
#include "Space.h"

REGISTER_CLASS(Space, TaxSpace);

TaxSpace::TaxSpace()
{
}

void TaxSpace::land(Player* p)
{
	perform(p);					// perform the corresponding money instruction
}

TaxSpace::~TaxSpace()
{
}

void TaxSpace::configure(vector<string>& params)
{
	Space::configure(params);

	int taxAmount = atoi(params[SPACE_BASE_PARMS].c_str());
	setAmount(taxAmount);
}

void TaxSpace::info()
{
	Space::info();
	cout << "This is a tax space of " << getAmount() << " units." << endl;
}
