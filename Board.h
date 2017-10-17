#include "Menu.h"

#ifndef BOARD_H
#define BOARD_H
class Board
{
public:
	char sb[9];
	bool Victory;
	char Victor;
	int boardNumber;
	int moveCount;
	int lastMove; //Used in Enhanced game, sends player to the correct next board

	Board();
	Board(int);
	void makeMove(char);
	void makeStandardMove(char);
	void checkVictor(); 
	void displayBoard();
	char displayElement(int);
	int getLastMove();

};
//#endif 

/* BIGGER BOARD DEFINED BELOW */

//#ifndef BiggerBoard

class BiggerBoard
{
public:
	Board bb[9];
	bool Victory;
	char Victor;
	int moveCounter;
	int nextBoard;

	BiggerBoard();
	void makeOpenMove(char);
	void makeRegularMove(char);
	void checkVictorBB();
	void displayBiggerBoard();
};
#endif
