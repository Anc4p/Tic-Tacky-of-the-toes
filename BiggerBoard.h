#include <iostream>
#include "Board.h"

using namespace std;

#ifndef biggerBoard

class biggerBoard
{
public:
	Board bb[9];
	bool Victory;
	char Victor;
	int moveCounter;
	int nextBoard;

	biggerBoard()
	{
		Board b0(0);
		bb[0] = b0;
		Board b1(1);
		bb[1] = b1;
		Board b2(2);
		bb[2] = b2;
		Board b3(3);
		bb[3] = b3;
		Board b4(4);
		bb[4] = b4;
		Board b5(5);
		bb[5] = b5;
		Board b6(6);
		bb[6] = b6;
		Board b7(7);
		bb[7] = b7;
		Board b8(8);
		bb[8] = b8;

		Victory = false;
		Victor = ' ';
		moveCounter = 0;
		nextBoard = ' ';
	}

	void makeOpenMove(char p)
	{
		int boardNum;
		bool goodMove = false;
		cout << "Please choose a board, player " << p << endl;

		while (!goodMove)
		{
			cin >> boardNum;
			if (cin.fail())
			{
				cin.clear(); 
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Invalid input\nPlease try again" << endl;
				cin >> boardNum;
			}
			switch (boardNum)
			{
			case 0:
				if (bb[0].Victory == true)
				{
					cout << "This board has concluded\nPlease choose another board" << endl;
				}
				else
				{
					bb[0].makeMove(p);
					goodMove = true;
				}
				break;
			case 1:
				if (bb[1].Victory == true)
				{
					cout << "This board has concluded\nPlease choose another board" << endl;
				}
				else
				{
					bb[1].makeMove(p);
					goodMove = true;
				}
				break;
			case 2:
				if (bb[2].Victory == true)
				{
					cout << "This board has concluded\nPlease choose another board" << endl;
				}
				else
				{
					bb[2].makeMove(p);
					goodMove = true;
				}
				break;
			case 3:
				if (bb[3].Victory == true)
				{
					cout << "This board has concluded\nPlease choose another board" << endl;
				}
				else
				{
					bb[3].makeMove(p);
					goodMove = true;
				}
				break;
			case 4:
				if (bb[4].Victory == true)
				{
					cout << "This board has concluded\nPlease choose another board" << endl;
				}
				else
				{
					bb[4].makeMove(p);
					goodMove = true;
				}
				break;
			case 5:
				if (bb[5].Victory == true)
				{
					cout << "This board has concluded\nPlease choose another board" << endl;
				}
				else
				{
					bb[5].makeMove(p);
					goodMove = true;
				}
				break;
			case 6:
				if (bb[6].Victory == true)
				{
					cout << "This board has concluded\nPlease choose another board" << endl;
				}
				else
				{
					bb[6].makeMove(p);
					goodMove = true;
				}
				break;
			case 7:
				if (bb[7].Victory == true)
				{
					cout << "This board has concluded\nPlease choose another board" << endl;
				}
				else
				{
					bb[7].makeMove(p);
					goodMove = true;
				}
				break;
			case 8:
				if (bb[8].Victory == true)
				{
					cout << "This board has concluded\nPlease choose another board" << endl;
				}
				else
				{
					bb[8].makeMove(p);
					goodMove = true;
				}
				break;
			default:
				cout << "Invalid input, should be within the range of 0 - 8" << endl;
			}
		}
	}

	void makeRegularMove(char p)
	{
		switch (nextBoard)
		{
		case 0:
			if (bb[0].Victory == true)
			{
				makeOpenMove(p);
			}
			else
			{
				bb[0].makeMove(p);
				nextBoard = 0;
			}
			break;
		case 1:
			if (bb[1].Victory == true)
			{
				makeOpenMove(p);
			}
			else
			{
				bb[1].makeMove(p);
				nextBoard = 1;
			}
			break;
		case 2:
			if (bb[2].Victory == true)
			{
				makeOpenMove(p);
			}
			else
			{
				bb[2].makeMove(p);
				nextBoard = 2;
			}
			break;
		case 3:
			if (bb[3].Victory == true)
			{
				makeOpenMove(p);
			}
			else
			{
				bb[3].makeMove(p);
				nextBoard = 3;
			}
			break;
		case 4:
			if (bb[4].Victory == true)
			{
				makeOpenMove(p);
			}
			else
			{
				bb[4].makeMove(p);
				nextBoard = 4;
			}
			break;
		case 5:
			if (bb[5].Victory == true)
			{
				makeOpenMove(p);
			}
			else
			{
				bb[5].makeMove(p);
				nextBoard = 5;
			}
			break;
		case 6:
			if (bb[6].Victory == true)
			{
				makeOpenMove(p);
			}
			else
			{
				bb[6].makeMove(p);
				nextBoard = 6;
			}
			break;
		case 7:
			if (bb[7].Victory == true)
			{
				makeOpenMove(p);
			}
			else
			{
				bb[7].makeMove(p);
				nextBoard = 7;
			}
			break;
		case 8:
			if (bb[8].Victory == true)
			{
				makeOpenMove(p);
			}
			else
			{
				bb[8].makeMove(p);
				nextBoard = 8;
			}
			break;
		}
	}

	void checkVictor()
	{

	}

	void displayBiggerBoard()
	{
		system("cls");
		cout << "                         |                         |                         " << endl;
		cout << " "; bb[0].displayBoard(); cout << " | "; bb[1].displayBoard(); cout << " | ";
	}
};
#endif
