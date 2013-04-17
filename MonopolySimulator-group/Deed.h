/*
 * deed.h
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 */

#ifndef _Deed_Def
#define _Deed_Def

#include <string>
#include <map>
#include <vector>

class Game;

#define DEED_BASE_PARMS 1+3

using namespace std;

/*
 * Deed
 *
 * Monopoly deed for a property.
 *
 */
class Deed
{
private:
	static multimap<string, string> deedGroups;			// deed names organized by groups
														// (stations, colours, etc.) 
protected:
	string name;
	string owner;
	int cost;
	int mortgage;

public:
	Deed();
	virtual ~Deed();

	virtual void info();

	const char* getName() const;

	// ----------------------------------------------------------------------------------
	// construction methods
	virtual void configure(vector<string>& params);		// parameters from loading

	// ----------------------------------------------------------------------------------
	// deed info
	int getPurchasePrice();
	virtual int getCostToRent(Game& g)=0;				// cost, based on current level of development
	virtual const char* getGroupName()=0;				// group that this deed belongs to

	// ----------------------------------------------------------------------------------
	// deed runtime management
	void setOwner(const char* name);					// owner, once bought
	const string& getOwner();							// if any!
	int getNumberOwned();								// number owned by this owner

protected:
	// ----------------------------------------------------------------------------------
	// grouping information (e.g. stations, blue properties, utilities, etc.)
	multimap<string, string>::iterator getFirstDeedInGrp(const string& grp);
	multimap<string, string>::iterator getEndDeedInGrp(const string& grp);
	void addToGrp(const string& grp, const string& deedName);
};

#endif // ndef _Deed_Def
