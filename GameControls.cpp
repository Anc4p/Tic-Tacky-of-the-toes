#include "GameControls.h"
using namespace std;
void standardGameControl()
{
	cout << "Game starting..." << endl;
	Board b1(0);
	b1.displayBoard();
	while (b1.Victory == false)
	{
		if (b1.Victory == false)
		{
			cout << "Player X turn" << endl;
			b1.makeStandardMove('X');
		}
		if (b1.Victory == false)
		{
			cout << "Player O turn" << endl;
			b1.makeStandardMove('O');
		}
		else
		{
			cout << "Press 2 to start a new game" << endl;
			cout << "Press 5 to display the menu" << endl;
			return;
		}
	}
}

void enhancedGameControl()
{
	BiggerBoard bb1;
	bb1.displayBiggerBoard();
	cout << "Welcome to Enhanced Tick Tack Toe" << endl;
	bb1.makeOpenMove('X');
	while (bb1.Victory == false)
	{
		if (bb1.Victory == false)
		{
			cout << "Player O turn " << endl;
			bb1.makeRegularMove('O');
		}
		if (bb1.Victory == false)
		{
			cout << "Player X turn " << endl;
			bb1.makeRegularMove('X');
		}
		else
		{
			cout << "Press 3 to start a new game" << endl;
			cout << "Press 5 to display the menu" << endl;
			return;
		}
	}
}

