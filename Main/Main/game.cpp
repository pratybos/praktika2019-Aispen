#include "game.h"

game::game()
{
	choice = 0;
	running = true;
	string CharacterName;
	int difficulty = 0;
}


game::~game()
{

}

// functions
void game::MainMenu() 
{
	cout << "======= Main Menu =======" << endl;
	cout << "  1. New Game" << endl;
	cout << "  2. Load Game" << endl;
	cout << "  3. Rating" << endl;
	cout << "  0. Quit Game" << endl << endl;

	cout << "Your choice: ";
	cin >> choice;

	switch (choice)
	{
	case 0:
		running = false;
		break;
	case 1:
		void CharacterCreation();
		void DifficultySetting();
		break;
	case 2:

		break;
	case 3:

		break;
	default:
		break;
	}
}

void game::CharacterCreation() 
{
	cout << endl << endl;
	cout << "=== Enter your name: ";
	cin >> name;
}

void game::DifficultySetting()
{
	cout << endl << endl;
	cout << "=== Choose difficulty ===" << endl;
	cout << "  1. Normal" << endl;
	cout << "  2. Hard" << endl;
	switch (difficulty)
	{
	case 1:
		difficulty = 1;
		break;
	case 2:
		difficulty = 2;
		break;
	default:
		break;
	}
}