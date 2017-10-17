#include "StandardAI.h"
#include <iostream>
using namespace std;

StandardAI::StandardAI()
{
	me = 'O';
	opp = 'X';
	for (int i = 0; i < 9; i++)
	{
		risk[i] = 0;
	}
}

StandardAI::StandardAI(char i, char u)
{
	me = i;
	opp = u;
	for (int i = 0; i < 9; i++)
	{
		risk[i] = 0;
	}
}

void StandardAI::updateTrackerAndSpaces(char base[])
{
	int index = 0;
	for (int i = 0; i < 9; i++)
	{
		if (base[i] == ' ')
		{
			openSpaces[index] = i;
			index++;
		}
	}
}

void StandardAI::assessRisk(char base[])
{
	updateTrackerAndSpaces(base);
	int i = 0;
	while (openSpaces[i] != NULL)
	{
		calcRisk(openSpaces[i], base);
		i++;
	}
}

void StandardAI::calcRisk(int space, char base[])
{
	bool tracker[9];
	bool comboTracker[9];
	int singleRisk = 5;
	int doubleRisk = 10;
	for (int i = 0; i < 9; i++)
	{
		tracker[i] = false;
	}
	//potentially use a second tracker array to track specific win condition
	//8 conditions, if 0-1-2 is checked in case 0, should not be rechecked in
	//case 1 or 2
	switch (space) //break me and opp versions into different functions?
		//calc offMove, calcDefmove?
	{
	case 0:
	{
		if (base[1] == me)
		{
			risk[0] += singleRisk;
			tracker[1] = true;
			if (base[2] == me)
			{
				risk[0] += doubleRisk;
				tracker[2] = true;
			}
		}
		if (base[2] == me && tracker[2] == false)
		{
			risk[0] += singleRisk;
			tracker[2] = true;
		}
		if (base[3] == me)
		{
			risk[0] += singleRisk;
			tracker[3] = true;
			if (base[6] == me)
			{
				risk[0] += doubleRisk;
				tracker[6] = true;
			}
		}
		if (base[6] == me && tracker[6] == false)
		{
			risk[0] += singleRisk;
			tracker[6] = true;
		}
	}
	}
}


