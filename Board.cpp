#include "Board.h"
#include "BiggerBoard.h"
//REGULAR BOARD
using namespace std;
Board::Board() //default constructor, unsure if needed
{
	for (int i = 0; i < 9; i++)
	{
		sb[i] = ' ';
	}
	Victory = false;
	Victor = ' ';
	boardNumber = 0;
	int moveCount = 0;
}

Board::Board(int bn) //Constructor that allows you to name a board, used to construct all boards in the game
{
	for (int i = 0; i < 9; i++)
	{
		sb[i] = ' ';
	}
	Victory = false;
	Victor = ' ';
	boardNumber = bn;
	int moveCount = 0;
}

void Board::makeMove(char p) //make move in Enhanced game mode
{
	if (moveCount == 9)
	{
		cout << "The board is full: Tie Board" << endl;
		return;
	}
	bool goodMove = false;
	int move;
	cout << "Please input your move (0-8)" << endl;
	cout << "To quit, press 9" << endl;

	while (!goodMove)
	{
		cin >> move;
		if (cin.fail()) //if input is invalid
		{
			cin.clear(); //clears input value
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignores character, allows new input via clearing out mem location
																		   //causes stream size to be only numeric values, and ignores everything else, and only lets you put in numeric limits
			cout << "Invalid Input: Please input a valid move: " << endl;
			cin >> move;
		}
		else if (move < 0 || move > 9)
		{
			cout << "Invalid Input: Please input a valid move: " << endl;
		}
		else if (move == 9)
		{
			bool confirmed = false;
			while (!confirmed)
			{
				cout << "Are you sure you want to quit? Y/N" << endl;
				char confirmInput;
				cin >> confirmInput;
				toupper(confirmInput);
				if (confirmInput == 'Y')
				{
					confirmed = true;
					menu();
				}
				else if (confirmInput == 'N')
				{
					confirmed = true;
					cout << "Please input your move (0-8)";
					cout << "To quit, press 9" << endl;
				}
				else
				{
					if (cin.fail()) //if input is invalid
					{
						cin.clear(); //clears input value
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << "Invalid Input! Are you sure you want to quit? Please input Y/N: " << endl;
						cin >> confirmInput;
					}
				}
			}
		}
		else
		{
			if (sb[move] == ' ')
			{
				lastMove = move;
				sb[move] = toupper(p);
				goodMove = true;
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

void Board::makeStandardMove(char p) //make move in Standard game
{
	if (moveCount == 9) //If the board is full w/ no victor, the board is tied
	{
		cout << "The board is full: Tie Board" << endl;
		return;
	}
	bool goodMove = false; //used to check if the move is valid
	int move; //The int that represents the space in the board that the player selects as their move
	cout << "Please input your move" << endl;

	while (!goodMove)
	{
		cin >> move; //Take in the move
		if (cin.fail()) //if input is invalid
		{
			cin.clear(); //clears input value
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignores character, allows new input via clearing out mem location
																		   //causes stream size to be only numeric values, and ignores everything else, and only lets you put in numeric limits
			cout << "Invalid Input: Please input a valid move: " << endl;
			cin >> move;
		}
		else if (move < 0 || move > 8) //If the move int is outside of the range of the array/board, throw an error
		{
			cout << "Invalid Input: Please input a valid move: " << endl;
		}
		else
		{
			if (sb[move] == ' ') //if the space is empty
			{
				lastMove = move; //record the last move (For enhanced game reasons)
				sb[move] = toupper(p); //Set the move to an uppercase letter
				goodMove = true; //move is valid
				displayBoard(); //temp
				checkVictor(); //Check to see if victory has been achieved
				moveCount++; //increment the move count total
			}
			else //If the space is taken, throw an error
			{
				cout << "Invalid Space: Space is taken" << endl;
			}
		}
	}
}

void Board::checkVictor() //Checks to see if the board is won, cycles through all possible win scenarios
{
	if (sb[0] == sb[1] && sb[0] == sb[2]) //Row 1 Victory
	{
		if (sb[0] == 'X')
		{
			Victory = true;
			Victor = 'X';
			displayBoard();
			cout << "X has won board " << boardNumber << "!" << endl;
		}
		else if (sb[0] == 'O')
		{
			Victory = true;
			Victor = 'O';
			displayBoard();
			cout << "O has won board " << boardNumber << "!" << endl;
		}
	}
	else if (sb[3] == sb[4] && sb[3] == sb[5]) //Row 2 Victory
	{
		if (sb[3] == 'X')
		{
			Victory = true;
			Victor = 'X';
			displayBoard();
			cout << "X has won board " << boardNumber << "!" << endl;
		}
		else if (sb[3] == 'O')
		{
			Victory = true;
			Victor = 'O';
			displayBoard();
			cout << "O has won board " << boardNumber << "!" << endl;
		}
	}
	else if (sb[6] == sb[7] && sb[6] == sb[8]) //Row 3 Victory
	{
		if (sb[6] == 'X')
		{
			Victory = true;
			Victor = 'X';
			displayBoard();
			cout << "X has won board " << boardNumber << "!" << endl;
		}
		else if (sb[6] == 'O')
		{
			Victory = true;
			Victor = 'O';
			displayBoard();
			cout << "O has won board " << boardNumber << "!" << endl;
		}
	}
	else if (sb[0] == sb[3] && sb[0] == sb[6]) //Column 1 Victory
	{
		if (sb[0] == 'X')
		{
			Victory = true;
			Victor = 'X';
			displayBoard();
			cout << "X has won board " << boardNumber << "!" << endl;
		}
		else if (sb[0] == 'O')
		{
			Victory = true;
			Victor = 'O';
			displayBoard();
			cout << "O has won board " << boardNumber << "!" << endl;
		}
	}
	else if (sb[1] == sb[4] && sb[1] == sb[7]) //Column 2 Victory
	{
		if (sb[1] == 'X')
		{
			Victory = true;
			Victor = 'X';
			displayBoard();
			cout << "X has won board " << boardNumber << "!" << endl;
		}
		else if (sb[1] == 'O')
		{
			Victory = true;
			Victor = 'O';
			displayBoard();
			cout << "O has won board " << boardNumber << "!" << endl;
		}
	}
	else if (sb[2] == sb[5] && sb[2] == sb[8]) //Column 3 Victory
	{
		if (sb[2] == 'X')
		{
			Victory = true;
			Victor = 'X';
			displayBoard();
			cout << "X has won board " << boardNumber << "!" << endl;
		}
		else if (sb[2] == 'O')
		{
			Victory = true;
			Victor = 'O';
			displayBoard();
			cout << "O has won board " << boardNumber << "!" << endl;
		}
	}
	else if (sb[0] == sb[4] && sb[0] == sb[8]) //Diagonal 1 Victory
	{
		if (sb[0] == 'X')
		{
			Victory = true;
			Victor = 'X';
			displayBoard();
			cout << "X has won board " << boardNumber << "!" << endl;
		}
		else if (sb[0] == 'O')
		{
			Victory = true;
			Victor = 'O';
			displayBoard();
			cout << "O has won board " << boardNumber << "!" << endl;
		}
	}
	else if (sb[2] == sb[4] && sb[2] == sb[6]) //Diagonal 2 Victory
	{
		if (sb[2] == 'X')
		{
			Victory = true;
			Victor = 'X';
			displayBoard();
			cout << "X has won board " << boardNumber << "!" << endl;
		}
		else if (sb[2] == 'O')
		{
			Victory = true;
			Victor = 'O';
			displayBoard();
			cout << "O has won board " << boardNumber << "!" << endl;
		}
	}

	if (Victory == true) //In enhanced game, will re-write board to show who won as an X of X's or an O of O's
	{
		if (Victor == 'X')
		{
			sb[0] = 'X';
			sb[1] = ' ';
			sb[2] = 'X';
			sb[3] = ' ';
			sb[4] = 'X';
			sb[5] = ' ';
			sb[6] = 'X';
			sb[7] = ' ';
			sb[8] = 'X';
		}
		else if (Victor == 'O')
		{
			sb[0] = 'O';
			sb[1] = 'O';
			sb[2] = 'O';
			sb[3] = 'O';
			sb[4] = ' ';
			sb[5] = 'O';
			sb[6] = 'O';
			sb[7] = 'O';
			sb[8] = 'O';
		}
	}
}

void Board::displayBoard() //Displays the board
{
	system("cls"); //Clear the screen, then display the board
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

char Board::displayElement(int x) //Used in displaying the bigger board for the enhanced game
{
	return sb[x];
}

int Board::getLastMove() //Gets the last move, may not be needed
{
	return lastMove;
}

//BIGGER BOARD

BiggerBoard::BiggerBoard()
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
	nextBoard = -1;
}

void BiggerBoard::makeOpenMove(char p) //Move where player can choose the board they want to make their move in
{
	int boardnum;
	cout << "Please choose a board, Player " << p << endl;
	bool goodMove = false;

	while (!goodMove)
	{
		cin >> boardnum;
		if (cin.fail()) //if input is invalid
		{
			cin.clear(); //clears input value
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignores character, allows new input via clearing out mem location
																		   //causes stream size to be only numeric values, and ignores everything else, and only lets you put in numeric limits
			cout << "Invalid Input: Please input a valid board: " << endl;
			cin >> boardnum;
		}
		switch (boardnum) //Takes in the board number, directs you to then input the move on the relevant board
		{
		case 0:
			if (bb[0].Victory == true) //If the board is one, no move is valid
			{
				cout << "Board is already won. Select another board" << endl;
			}
			else
			{
				bb[0].makeMove(p); //Make a move in the board
				nextBoard = bb[0].lastMove; //Used to send the next player to the board who's number is the number of the move the previous player just made
				displayBiggerBoard(); //Display the board with the new move added
				checkVictorBB(); //Checks to see if overall victory has been achieved
				goodMove = true; //Move is valid, set goodMove to true, exit the while loop
			}
			break;
		case 1:
			if (bb[1].Victory == true)
			{
				cout << "Board is already won. Select another board" << endl;
			}
			else
			{
				bb[1].makeMove(p);
				nextBoard = bb[1].lastMove;
				displayBiggerBoard();
				checkVictorBB();
				goodMove = true;
			}
			break;
		case 2:
			if (bb[2].Victory == true)
			{
				cout << "Board is already won. Select another board" << endl;
			}
			else
			{
				bb[2].makeMove(p);
				nextBoard = bb[2].lastMove;
				displayBiggerBoard();
				checkVictorBB();
				goodMove = true;
			}
			break;
		case 3:
			if (bb[3].Victory == true)
			{
				cout << "Board is already won. Select another board" << endl;
			}
			else
			{
				bb[3].makeMove(p);
				nextBoard = bb[3].lastMove;
				displayBiggerBoard();
				checkVictorBB();
				goodMove = true;
			}
			break;
		case 4:
			if (bb[4].Victory == true)
			{
				cout << "Board is already won. Select another board" << endl;
			}
			else
			{
				bb[4].makeMove(p);
				nextBoard = bb[4].lastMove;
				displayBiggerBoard();
				checkVictorBB();
				goodMove = true;
			}
			break;
		case 5:
			if (bb[5].Victory == true)
			{
				cout << "Board is already won. Select another board" << endl;
			}
			else
			{
				bb[5].makeMove(p);
				nextBoard = bb[5].lastMove;
				displayBiggerBoard();
				checkVictorBB();
				goodMove = true;
			}
			break;
		case 6:
			if (bb[6].Victory == true)
			{
				cout << "Board is already won. Select another board" << endl;
			}
			else
			{
				bb[6].makeMove(p);
				nextBoard = bb[6].lastMove;
				displayBiggerBoard();
				checkVictorBB();
				goodMove = true;
			}
			break;
		case 7:
			if (bb[7].Victory == true)
			{
				cout << "Board is already won. Select another board" << endl;
			}
			else
			{
				bb[7].makeMove(p);
				nextBoard = bb[7].lastMove;
				displayBiggerBoard();
				checkVictorBB();
				goodMove = true;
			}
			break;
		case 8:
			if (bb[8].Victory == true)
			{
				cout << "Board is already won. Select another board" << endl;
			}
			else
			{
				bb[8].makeMove(p);
				nextBoard = bb[8].lastMove;
				displayBiggerBoard();
				checkVictorBB();
				goodMove = true;
			}
			break;
		default:
			cout << "Invalid Board Choice" << endl; //Invalid choice, try again
			cout << "Please input a valid choice" << endl;
		}
	}
}

void BiggerBoard::makeRegularMove(char p) //Standard move, where next player plays in board that corresponds to where the last player made their move in a sub board
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
			nextBoard = bb[0].lastMove;
			displayBiggerBoard();
			checkVictorBB();
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
			nextBoard = bb[1].lastMove;
			displayBiggerBoard();
			checkVictorBB();
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
			nextBoard = bb[2].lastMove;
			displayBiggerBoard();
			checkVictorBB();
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
			nextBoard = bb[3].lastMove;
			displayBiggerBoard();
			checkVictorBB();
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
			nextBoard = bb[4].lastMove;
			displayBiggerBoard();
			checkVictorBB();
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
			nextBoard = bb[5].lastMove;
			displayBiggerBoard();
			checkVictorBB();
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
			nextBoard = bb[6].lastMove;
			displayBiggerBoard();
			checkVictorBB();
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
			nextBoard = bb[7].lastMove;
			displayBiggerBoard();
			checkVictorBB();
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
			nextBoard = bb[8].lastMove;
			displayBiggerBoard();
			checkVictorBB();
		}
		break;
	}
}

void BiggerBoard::checkVictorBB()
{
	if (bb[0].Victor == bb[0].Victor && bb[0].Victor == bb[2].Victor) //Row 1 Victory
	{
		if (bb[0].Victor == 'X')
		{
			Victory = true;
			Victor = 'X';
			displayBiggerBoard();
			cout << "X has won the game!" << endl;
		}
		else if (bb[0].Victor == 'O')
		{
			Victory = true;
			Victor = 'O';
			displayBiggerBoard();
			cout << "O has won the game!" << endl;
		}
	}
	else if (bb[3].Victor == bb[4].Victor && bb[3].Victor == bb[5].Victor) //Row 2 Victory
	{
		if (bb[3].Victor == 'X')
		{
			Victory = true;
			Victor = 'X';
			displayBiggerBoard();
			cout << "X has won the game!" << endl;
		}
		else if (bb[3].Victor == 'O')
		{
			Victory = true;
			Victor = 'O';
			displayBiggerBoard();
			cout << "O has won the game!" << endl;
		}
	}
	else if (bb[6].Victor == bb[7].Victor && bb[6].Victor == bb[8].Victor) //Row 3 Victory
	{
		if (bb[6].Victor == 'X')
		{
			Victory = true;
			Victor = 'X';
			displayBiggerBoard();
			cout << "X has won the game!" << endl;
		}
		else if (bb[6].Victor == 'O')
		{
			Victory = true;
			Victor = 'O';
			displayBiggerBoard();
			cout << "O has won the game!" << endl;
		}
	}
	else if (bb[0].Victor == bb[3].Victor && bb[0].Victor == bb[6].Victor) //Column 1 Victory
	{
		if (bb[0].Victor == 'X')
		{
			Victory = true;
			Victor = 'X';
			displayBiggerBoard();
			cout << "X has won the game!" << endl;
		}
		else if (bb[0].Victor == 'O')
		{
			Victory = true;
			Victor = 'O';
			displayBiggerBoard();
			cout << "O has won the game!" << endl;
		}
	}
	else if (bb[1].Victor == bb[4].Victor && bb[1].Victor == bb[7].Victor) //Column 2 Victory
	{
		if (bb[1].Victor == 'X')
		{
			Victory = true;
			Victor = 'X';
			displayBiggerBoard();
			cout << "X has won the game!" << endl;
		}
		else if (bb[1].Victor == 'O')
		{
			Victory = true;
			Victor = 'O';
			displayBiggerBoard();
			cout << "O has won the game" << endl;
		}
	}
	else if (bb[2].Victor == bb[5].Victor && bb[2].Victor == bb[8].Victor) //Column 3 Victory
	{
		if (bb[2].Victor == 'X')
		{
			Victory = true;
			Victor = 'X';
			displayBiggerBoard();
			cout << "X has won the game!" << endl;
		}
		else if (bb[2].Victor == 'O')
		{
			Victory = true;
			Victor = 'O';
			displayBiggerBoard();
			cout << "O has won the game!" << endl;
		}
	}
	else if (bb[0].Victor == bb[4].Victor && bb[0].Victor == bb[8].Victor) //Diagonal 1 Victory
	{
		if (bb[0].Victor == 'X')
		{
			Victory = true;
			Victor = 'X';
			displayBiggerBoard();
			cout << "X has won the game!" << endl;
		}
		else if (bb[0].Victor == 'O')
		{
			Victory = true;
			Victor = 'O';
			displayBiggerBoard();
			cout << "O has won the game!" << endl;
		}
	}
	else if (bb[2].Victor == bb[4].Victor && bb[2].Victor == bb[6].Victor) //Diagonal 2 Victory
	{
		if (bb[2].Victor == 'X')
		{
			Victory = true;
			Victor = 'X';
			displayBiggerBoard();
			cout << "X has won the game!" << endl;
		}
		else if (bb[2].Victor == 'O')
		{
			Victory = true;
			Victor = 'O';
			displayBiggerBoard();
			cout << "O has won the game!" << endl;
		}
	}
}

void BiggerBoard::displayBiggerBoard()
{
	system("cls");
	//Tier 1
	cout << "       |       |       |||"; //T1 B0 R1
	cout << "       |       |       |||"; //T1 B1 R1
	cout << "       |       |       " << endl; //T1 B2 R1

	cout << "   " << bb[0].displayElement(0) << "   |   " << bb[0].displayElement(1) << "   |   " << bb[0].displayElement(2) << "   |||";//T1 B0 R2
	cout << "   " << bb[1].displayElement(0) << "   |   " << bb[1].displayElement(1) << "   |   " << bb[1].displayElement(2) << "   |||"; //T1 B1 R2
	cout << "   " << bb[2].displayElement(0) << "   |   " << bb[2].displayElement(1) << "   |   " << bb[2].displayElement(2) << "   " << endl; //T1 B2 R2

	cout << "_______|_______|_______|||"; //T1 B0 R3
	cout << "_______|_______|_______|||"; //T1 B1 R3
	cout << "_______|_______|_______" << endl; //T1 B2 R3

	cout << "       |       |       |||"; //T1 B0 R4
	cout << "       |       |       |||"; //T1 B1 R4
	cout << "       |       |       " << endl; //T1 B2 R4

	cout << "   " << bb[0].displayElement(3) << "   |   " << bb[0].displayElement(4) << "   |   " << bb[0].displayElement(5) << "   |||";//T1 B0 R5
	cout << "   " << bb[1].displayElement(3) << "   |   " << bb[1].displayElement(4) << "   |   " << bb[1].displayElement(5) << "   |||"; //T1 B1 R5
	cout << "   " << bb[2].displayElement(3) << "   |   " << bb[2].displayElement(4) << "   |   " << bb[2].displayElement(5) << "   " << endl; //T1 B2 R5

	cout << "_______|_______|_______|||"; //T1 B0 R6
	cout << "_______|_______|_______|||"; //T1 B1 R6
	cout << "_______|_______|_______" << endl; //T1 B2 R6

	cout << "       |       |       |||"; //T1 B0 R7
	cout << "       |       |       |||"; //T1 B1 R7
	cout << "       |       |       " << endl; //T1 B2 R7

	cout << "   " << bb[0].displayElement(6) << "   |   " << bb[0].displayElement(7) << "   |   " << bb[0].displayElement(8) << "   |||"; //T1 B0 R8
	cout << "   " << bb[1].displayElement(6) << "   |   " << bb[1].displayElement(7) << "   |   " << bb[1].displayElement(8) << "   |||"; //T1 B1 R8
	cout << "   " << bb[2].displayElement(6) << "   |   " << bb[2].displayElement(7) << "   |   " << bb[2].displayElement(8) << "   " << endl; //T1 B2 R8

	cout << "_______|_______|_______|||"; //T1 B0 R9
	cout << "_______|_______|_______|||"; //T1 B1 R9
	cout << "_______|_______|_______" << endl; //T1 B2 R9


	cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl; //T1 Dividing Line

																								   //Tier 2
	cout << "       |       |       |||"; //T2 B3 R1
	cout << "       |       |       |||"; //T2 B4 R1
	cout << "       |       |       " << endl; //T2 B5 R1

	cout << "   " << bb[3].displayElement(0) << "   |   " << bb[3].displayElement(1) << "   |   " << bb[3].displayElement(2) << "   |||"; //T2 B3 R2
	cout << "   " << bb[4].displayElement(0) << "   |   " << bb[4].displayElement(1) << "   |   " << bb[4].displayElement(2) << "   |||"; //T2 B4 R2
	cout << "   " << bb[5].displayElement(0) << "   |   " << bb[5].displayElement(1) << "   |   " << bb[5].displayElement(2) << "   " << endl; //T2 B5 R2

	cout << "_______|_______|_______|||"; //T2 B3 R3
	cout << "_______|_______|_______|||"; //T2 B4 R3
	cout << "_______|_______|_______" << endl; //T2 B5 R3

	cout << "       |       |       |||"; //T2 B3 R4
	cout << "       |       |       |||"; //T2 B4 R4
	cout << "       |       |       " << endl; //T2 B5 R4

	cout << "   " << bb[3].displayElement(3) << "   |   " << bb[3].displayElement(4) << "   |   " << bb[3].displayElement(5) << "   |||"; //T2 B3 R5
	cout << "   " << bb[4].displayElement(3) << "   |   " << bb[4].displayElement(4) << "   |   " << bb[4].displayElement(5) << "   |||"; //T2 B4 R5
	cout << "   " << bb[5].displayElement(3) << "   |   " << bb[5].displayElement(4) << "   |   " << bb[5].displayElement(5) << "   " << endl; //T2 B5 R5

	cout << "_______|_______|_______|||"; //T2 B3 R6
	cout << "_______|_______|_______|||"; //T2 B4 R6
	cout << "_______|_______|_______" << endl; //T2 B5 R6

	cout << "       |       |       |||"; //T2 B3 R7
	cout << "       |       |       |||"; //T2 B4 R7
	cout << "       |       |       " << endl; //T2 B5 R7

	cout << "   " << bb[3].displayElement(6) << "   |   " << bb[3].displayElement(7) << "   |   " << bb[3].displayElement(8) << "   |||"; //T2 B3 R8
	cout << "   " << bb[4].displayElement(6) << "   |   " << bb[4].displayElement(7) << "   |   " << bb[4].displayElement(8) << "   |||"; //T2 B4 R8
	cout << "   " << bb[5].displayElement(6) << "   |   " << bb[5].displayElement(7) << "   |   " << bb[5].displayElement(8) << "   " << endl; //T2 B5 R8

	cout << "_______|_______|_______|||"; //T2 B3 R9
	cout << "_______|_______|_______|||"; //T2 B4 R9
	cout << "_______|_______|_______" << endl; //T2 B5 R9

	cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl; //T2 Dividing Line

																								   //Tier 3
	cout << "       |       |       |||"; //T3 B6 R1
	cout << "       |       |       |||"; //T3 B7 R1
	cout << "       |       |       " << endl; //T3 B8 R1

	cout << "   " << bb[6].displayElement(0) << "   |   " << bb[6].displayElement(1) << "   |   " << bb[6].displayElement(2) << "   |||"; //T3 B6 R2
	cout << "   " << bb[7].displayElement(0) << "   |   " << bb[7].displayElement(1) << "   |   " << bb[7].displayElement(2) << "   |||"; //T3 B7 R2
	cout << "   " << bb[8].displayElement(0) << "   |   " << bb[8].displayElement(1) << "   |   " << bb[8].displayElement(2) << "   " << endl; //T3 B8 R2

	cout << "_______|_______|_______|||"; //T3 B6 R3
	cout << "_______|_______|_______|||"; //T3 B7 R3
	cout << "_______|_______|_______" << endl; //T3 B8 R3

	cout << "       |       |       |||"; //T3 B6 R4
	cout << "       |       |       |||"; //T3 B7 R4
	cout << "       |       |       " << endl; //T3 B8 R4

	cout << "   " << bb[6].displayElement(3) << "   |   " << bb[6].displayElement(4) << "   |   " << bb[6].displayElement(5) << "   |||"; //T3 B6 R5
	cout << "   " << bb[7].displayElement(3) << "   |   " << bb[7].displayElement(4) << "   |   " << bb[7].displayElement(5) << "   |||"; //T3 B7 R5
	cout << "   " << bb[8].displayElement(3) << "   |   " << bb[8].displayElement(4) << "   |   " << bb[8].displayElement(5) << "   " << endl; //T3 B8 R5

	cout << "_______|_______|_______|||"; //T3 B7 R6
	cout << "_______|_______|_______|||"; //T3 B6 R6
	cout << "_______|_______|_______" << endl; //T3 B8 R6

	cout << "       |       |       |||"; //T3 B6 R7
	cout << "       |       |       |||"; //T3 B7 R7
	cout << "       |       |       " << endl; //T3 B8 R7

	cout << "   " << bb[6].displayElement(6) << "   |   " << bb[6].displayElement(7) << "   |   " << bb[6].displayElement(8) << "   |||"; //T3 B6 R8
	cout << "   " << bb[7].displayElement(6) << "   |   " << bb[7].displayElement(7) << "   |   " << bb[7].displayElement(8) << "   |||"; //T3 B7 R8
	cout << "   " << bb[8].displayElement(6) << "   |   " << bb[8].displayElement(7) << "   |   " << bb[8].displayElement(8) << "   " << endl; //T3 B8 R8

	cout << "       |       |       |||"; //T3 B6 R1
	cout << "       |       |       |||"; //T3 B7 R1
	cout << "       |       |       " << endl; //T3 B8 R1

}
