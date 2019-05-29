#pragma once

#include"functions.h"
#include"Player.h"
#include<iostream>
#include<iomanip>
#include<ctime>

using namespace std;

class game
{
public:
	game();
	virtual ~game();

	// operatiors



	// functions
	void MainMenu(); // pagrindinis meniu ijungus
	void DifficultySetting(); // sunkumo pasirinkimas
	void CharacterCreation(); // zaidejo sukurimas

	// accessors
	inline bool playing() const { return this->running; } // ar zaidzia

	// modifiers


private:
	bool running; // ar zaidimas veikia, ar isjunktas
	int choice; // pasirinkimai
	int difficulty; //1 lengvas //2 sunkus
};

