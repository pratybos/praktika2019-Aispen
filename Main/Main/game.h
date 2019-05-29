#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include "pch.h"
#include "functions.h"

using namespace std;

class game
{
public:
	game();
	virtual ~game();

	// operatiors



	// functions
	void MainMenu(); // pagrindinis meniu ijungus


	// accessors
	inline bool getplaying() const { return this->running; }

	// modifiers


private:
	bool running; // ar zaidimas veikia, ar isjunktas
	int choice; // pasirinkimai
};

