#pragma once

#include"functions.h"
#include"Player.h"
#include<iostream>
#include<iomanip>
#include<ctime>

// function declatrations

using namespace std;

class GameLogic
{
public:
	GameLogic();
	virtual ~GameLogic();

	// operatiors



	// functions

	void MainMenu(); // pagrindinis meniu ijungus
	void InitGame();
	void IngameMenu();
	

	// accessors
	inline bool playing() const { return this->running; } // ar zaidzia

	// modifiers


private:
	bool running; // ar zaidimas veikia, ar isjunktas
	int choice; // pasirinkimai
	

	//Player.h 
	Player player;
};

