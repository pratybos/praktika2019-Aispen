#include "GameLogic.h"

//cout << "\033[2J\033[1;1H"; clear screen
// function definitions

Player player;

GameLogic::GameLogic()
{
	choice = 0;
	running = true;
	int difficulty = 0;

}


GameLogic::~GameLogic()
{

}

// functions

void GameLogic::MainMenu() 
{
	cout << "======= Main Menu =======" << endl;
	cout << "  1. New Game" << endl;
	cout << "  2. Load Game" << endl;
	cout << "  3. Rating" << endl;
	cout << "  0. Quit Game" << endl << endl;
	cout << "=========================" << endl;
	cout << "Your choice: ";
	cin >> choice;

	switch (choice)
	{
	case 0:
		running = false;
		break;
	case 1:
		GameLogic::InitGame();
		while (running)
		{
			GameLogic::IngameMenu();
		}
		break;
	case 2:
		
		break;
	case 3:

		break;
	default:
		break;
	}
}

void GameLogic::InitGame() // nekeicia
{
	string name;
	int difficulty;
	cout << endl << endl;
	cout << "=== Enter your hero name === " << endl;
	cout << "Name is: ";
	cin >> name;
	cout << "============================";

	system("cls");

	cout << endl << endl;
	cout << "===== Choose difficulty ===== " << endl;
	cout << "=== 1 - Normal / 2 - Hard === " << endl;
	cout << "Difficulty is: ";
	cin >> difficulty;
	cout << "=============================";

	player.InitPlayer(name, difficulty);
	system("cls");
	
}

void GameLogic::IngameMenu()
{
	cout << "======= Game menu =======" << endl;
	cout << "  1. Travel" << endl;
	cout << "  2. Inventory" << endl;
	cout << "  3. Player Stats" << endl;
	cout << "  4. Town" << endl << endl;
	cout << "  5. Save game" << endl << endl;
	cout << "  0. Quit game" << endl << endl;
	cout << "=========================" << endl;
	cout << "Your choice: ";
	cin >> choice;

	switch (choice)
	{
	case 0:
		running = false;
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		player.PlayerStats();
		system("pause");
		system("cls");
		break;
	case 4:
		break;
	case 5:
		break;
	default:
		break;
	}
}