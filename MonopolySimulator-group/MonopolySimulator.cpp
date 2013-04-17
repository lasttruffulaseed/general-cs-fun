// MonopolySimulator.cpp : Defines the entry point for the console application.
//

#include "NoActionSpace.h"
#include "Game.h"
#include "GameRunner.h"
#include <fstream>

int main(int argc, const char* argv[])
{
	Game g;

	ifstream cfgfile("monopoly.cfg");

	g.load(cfgfile);

	cfgfile.close();

	cout << "Game is loaded and ready to start!!!" << endl;

	cin.ignore();

	GameRunner runner(g, 20);					// run for 10 rolls!

	runner.runGame();
	
	cout << "Game is finished!!!" << endl;

	cin.ignore();

	return 0;
}

void testClassRegistry()
{
	Space* space = ClassRegistry<Space>::get().createClass("NoActionSpace");
	
	// space->tester();

	delete space;
}
