#pragma once

#include <iostream>
#include <string>

using namespace std;

class Player
{
public:
	Player();
	virtual ~Player();

	//Functions
	void InitPlayer(string name, int difficulty);
	void PlayerStats();
	void levelUp();

	//Accessors
	string getName()const { return this->name; }
	int getLevel() const { return this->level; }
	int getExp() const { return this->exp; }
	int getExpNext() const { return this->expNext; }
	int getHp() const { return this->hp; }
	int getHpMax() const { return this->hpMax; }
	int getDamageMin() const { return this->damageMin; }
	int getDamageMax() const { return this->damageMax; }
	int getDefence() const { return this->defence; }

	int getDifficulty() const { return this->difficulty; }
	//Modifiers

private:

	string name; // zaidejo vardas
	int level;
	int exp;
	int expNext;
	int hp;
	int hpMax;
	int damageMin;
	int damageMax;
	int defence;

	int difficulty; //1 lengvas //2 sunkus
};

