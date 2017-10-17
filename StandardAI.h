#ifndef STANDARDAI_H
#define STANDARDAI_H

class StandardAI
{
	char me;
	char opp;
	int openSpaces[9];
	int risk[9];
	StandardAI();
	StandardAI(char, char);
	void updateTrackerAndSpaces(char[]); //potentially pass the board object as a var?
	void assessRisk(char[]);
	void calcRisk(int, char[]);
	int getMoveStandardAI();
};

#endif // !STANDARDAI_H
