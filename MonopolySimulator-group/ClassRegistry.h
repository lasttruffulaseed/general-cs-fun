/*
 * ClassRegistry.h
 *
 * General purpose class registry, for creating instances of derived classes by name
 * Each derived class definition (cpp) should define a factory method and add a registration 
 * step using static code
 *
 * The factory method would be:
 *		Base* DerivedClass_creator() { return new DerivedClass(); }
 *
 * The registration step would be:
 *		ClassRegistry<Base>.registerDerived( "DerivedClassName", &DerivedClass_creator );
 *
 * This header includes a macro to define this class registration in a single line:
 *		REGISTER_CLASS(Base, Derived)
 *
 */

#ifndef _ClassRegistry_Def
#define _ClassRegistry_Def

#include <map>
#include <string>

using namespace std;

/*
 * ClassRegistry<Base>
 *
 * used for holding a static registry of all concrete derived classes, that can have
 * objects constructed by name
 * we'll use this for contructing objects from input files, specifying the class names
 *
 */
template<class Base>
class ClassRegistry
{
	typedef Base* (Func) ();							// prototype of a factory function

private:
	map<string, Func*> regMap;							// factories by classname

public:
	static ClassRegistry& get()
	{
		static ClassRegistry cr;
		return cr;
	}

	ClassRegistry()
	{
	}

	ClassRegistry(const char* className, Func* classFactory)
	{
		get().regMap[className] = classFactory;
	}

	Base* createClass(const char* className)
	{
		return get().regMap[className]();
	}

	Base* createClass(const string& className)
	{
		return createClass(className.c_str());
	}
};

// This macro defines the factory function and registers it with the base class registry
#define REGISTER_CLASS(Base, Derived)										\
	Base* Derived ## _create() { return new Derived(); }					\
	ClassRegistry<Base> Derived ## _register( #Derived , & Derived ## _create )

#endif _ClassRegistry_Def
