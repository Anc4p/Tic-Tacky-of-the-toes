#include "Instructions.h"
using namespace std;
void getInstructions()
{
	ifstream instruct;
	string instructString;
	instruct.open("Instructions.txt");

	while (!instruct.eof())
	{
		getline(instruct, instructString);
		cout << instructString << "\n";
	}
}
