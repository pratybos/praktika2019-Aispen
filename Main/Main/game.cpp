#include "game.h"

using namespace std;

game::game()
{
	choice = 0;
	running = true;
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
	cout << "  0. Quit Game" << endl;
}