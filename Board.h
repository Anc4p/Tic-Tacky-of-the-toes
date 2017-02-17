//#define Board
#include <iostream>

using namespace std;


#ifndef Board
class Board
{
public:
	char sb[9];
	bool Victory;
	char Victor;
	char boardName;
	int moveCount;

	Board(char bn)
	{
		for (int i = 0; i < 9; i++)
		{
			sb[i] = ' ';
		}
		Victory = false;
		Victor = ' ';
		boardName = bn;
		int moveCount = 0;
	}
	
	void makeMove(char p)
	{
		if (moveCount == 9)
		{
			cout << "The board is full: Tie Board" << endl;
			return;
		}
		bool goodMove = false;
		int move;
		cout << "Please input your move" << endl;
		
		while (!goodMove)
		{
			cin >> move;
			if (cin.fail()) //if input is invalid
			{
				cin.clear(); //clears input value
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignores character, allows new input via clearing out mem location
							//causes stream size to be only numeric values, and ignores everything else, and only lets you put in numeric limits
				cout << "Invalid Input: Please input a valid move: " << endl;
			}
			else if (move < 0 || move > 8)
			{
				cout << "Invalid Input: Please input a valid move: " << endl;
			}
			else
			{
				if (sb[move] == ' ')
				{
					sb[move] = toupper(p);
					goodMove = true;
					displayBoard(); //temp
					checkVictor();
					moveCount++;
				}
				else
				{
					cout << "Invalid Space: Space is taken" << endl;
				}
			}
		}
	}

	void checkVictor()
	{
		if (sb[0] == sb[1] && sb[0] == sb[2]) //Row 1 Victory
		{
			if (sb[0] == 'X')
			{
				Victory = true;
				Victor = 'X';
				displayBoard();
				cout << "X has won board " << boardName << "!" << endl;
			}
			else if (sb[0] == 'O')
			{
				Victory = true;
				Victor = 'O';
				displayBoard();
				cout << "O has won board " << boardName << "!" << endl;
			}
		}
		else if (sb[3] == sb[4] && sb[3] == sb[5]) //Row 2 Victory
		{
			if (sb[3] == 'X')
			{
				Victory = true;
				Victor = 'X';
				displayBoard();
				cout << "X has won board " << boardName << "!" << endl;
			}
			else if (sb[3] == 'O')
			{
				Victory = true;
				Victor = 'O';
				displayBoard();
				cout << "O has won board " << boardName << "!" << endl;
			}
		}
		else if (sb[6] == sb[7] && sb[6] == sb[8]) //Row 3 Victory
		{
			if (sb[6] == 'X')
			{
				Victory = true;
				Victor = 'X';
				displayBoard();
				cout << "X has won board " << boardName << "!" << endl;
			}
			else if (sb[6] == 'O')
			{
				Victory = true;
				Victor = 'O';
				displayBoard();
				cout << "O has won board " << boardName << "!" << endl;
			}
		}
		else if (sb[0] == sb[3] && sb[0] == sb[6]) //Column 1 Victory
		{
			if (sb[3] == 'X')
			{
				Victory = true;
				Victor = 'X';
				displayBoard();
				cout << "X has won board " << boardName << "!" << endl;
			}
			else if (sb[3] == 'O')
			{
				Victory = true;
				Victor = 'O';
				displayBoard();
				cout << "O has won board " << boardName << "!" << endl;
			}
		}
		else if (sb[1] == sb[4] && sb[1] == sb[7]) //Column 2 Victory
		{
			if (sb[3] == 'X')
			{
				Victory = true;
				Victor = 'X';
				displayBoard();
				cout << "X has won board " << boardName << "!" << endl;
			}
			else if (sb[3] == 'O')
			{
				Victory = true;
				Victor = 'O';
				displayBoard();
				cout << "O has won board " << boardName << "!" << endl;
			}
		}
		else if (sb[2] == sb[5] && sb[2] == sb[8]) //Column 3 Victory
		{
			if (sb[3] == 'X')
			{
				Victory = true;
				Victor = 'X';
				displayBoard();
				cout << "X has won board " << boardName << "!" << endl;
			}
			else if (sb[3] == 'O')
			{
				Victory = true;
				Victor = 'O';
				displayBoard();
				cout << "O has won board " << boardName << "!" << endl;
			}
		}
		else if (sb[0] == sb[4] && sb[0] == sb[8]) //Diagonal 1 Victory
		{
			if (sb[3] == 'X')
			{
				Victory = true;
				Victor = 'X';
				displayBoard();
				cout << "X has won board " << boardName << "!" << endl;
			}
			else if (sb[3] == 'O')
			{
				Victory = true;
				Victor = 'O';
				displayBoard();
				cout << "O has won board " << boardName << "!" << endl;
			}
		}
		else if (sb[2] == sb[4] && sb[2] == sb[6]) //Diagonal 2 Victory
		{
			if (sb[3] == 'X')
			{
				Victory = true;
				Victor = 'X';
				displayBoard();
				cout << "X has won board " << boardName << "!" << endl;
			}
			else if (sb[3] == 'O')
			{
				Victory = true;
				Victor = 'O';
				displayBoard();
				cout << "O has won board " << boardName << "!" << endl;
			}
		}
	}

	void displayBoard()
	{
		system("cls");
		cout << "       |       |       " << endl;
		cout << "   " << sb[0] << "   |   " << sb[1] << "   |   " << sb[2] << "   " << endl;
		cout << "_______|_______|_______" << endl;
		cout << "       |       |       " << endl;
		cout << "   " << sb[3] << "   |   " << sb[4] << "   |   " << sb[5] << "   " << endl;
		cout << "_______|_______|_______" << endl;
		cout << "       |       |       " << endl;
		cout << "   " << sb[6] << "   |   " << sb[7] << "   |   " << sb[8] << "   " << endl;
		cout << "       |       |       " << endl;
	}
};
#endif 
