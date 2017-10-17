#include "Menu.h"
using namespace std;
void menuText()
{
	system("cls");

	cout << "Welcome to Tic-Tacky-of-the-Toes" << endl;
	cout << "Choose one of the following options:" << endl;
	cout << "1. Display Instructions" << endl;
	cout << "2. Start Standard Game" << endl;
	cout << "3. Start Enhanced Game" << endl;
	cout << "4. Display version info" << endl;
	cout << "5. Display the main menu" << endl;
	cout << "6. Exit the program" << endl;
}

void menu()
{
	int menuOption = 0;

	menuText();

	while (menuOption != 6)
	{
		cin >> menuOption;
		if (cin.fail()) //if input is invalid
		{
			system("cls");
			cin.clear(); //clears input value
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignores character, allows new input via clearing out mem location
																		   //causes stream size to be only numeric values, and ignores everything else, and only lets you put in numeric limits
			cout << "Invalid input\nPlease try again" << endl;
			cin >> menuOption;
		}
		switch (menuOption)
		{
		case 1:
			getInstructions();
			break;
		case 2:
			system("cls");
			standardGameControl();
			break;
		case 3:
			system("cls");
			enhancedGameControl();
			break;
		case 4:
			getChangeLog();
			break;
		case 5:
			menuText();
			break;
		case 6:
			return;
			break;
		default:
			cout << "Error: Invalid Chocie" << endl;
			cout << "Please enter a valid choice: " << endl;
			break;
		}
	}
}
