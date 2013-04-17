/*
 * bank.h
 *
 * benjamin.dasari
 * patrick.haren
 * rebaz.maroof
 *
 */

#ifndef _Utility_Def
#define _Utility_Def

#include <string>
#include <map>

using namespace std;

/*
 * General utility functions
 *
 */

// number within bounds
inline int bounded(int counter, int bound) { return counter % bound; }		

// string& toLower(string& str);

// functor for deleting elements held in a regular collection
template<class B>
void deleter(B* ptr)
{
	delete ptr;
}

// functor for deleting elements held in a map
template<class B>
void valDeleter(pair<const string, B*> val)
{
	delete val.second;
}

// trim the string (no white space before or after)
inline string trim(const string& param) 
{ 
	int startPos = param.find_first_not_of(" \t");
	return param.substr(startPos, param.find_last_not_of(" \t")+1-startPos); 
}

#endif // ndef _Utility_Def
