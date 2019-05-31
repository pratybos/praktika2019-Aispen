#include "Player.h"


Player::Player()
{
	this->name = "Null";
	this->level = 1;
	this->exp = 0;
	this->expNext = 0;
	this->hp = 0;
	this->hpMax = 0;
	this->damageMin = 0;
	this->damageMax = 0;
	this->defence = 0;
	this->difficulty = 0;
}


Player::~Player()
{


}

//Functions
void Player::InitPlayer(string name, int difficulty)
{
	this->name = "null";
	this->level = 1;
	this->exp = 0;
	this->expNext = static_cast<int>((50 / 3)*(pow(level, 3) - 6 * pow(level, 2) + (17 * level) - 12)) + 20;
	this->hp = 10;
	this->hpMax = 10;
	this->damageMin = 2;
	this->damageMax = 4;
	this->defence = 5;
	this->difficulty;
}


void Player::PlayerStats()
{
	cout << "== Player Stats =="<< endl;
	cout << "== Name: " << this->name << endl;
	cout << "== Level: " << this->level << endl;
	cout << "== Current XP: " << this->exp << endl;
	cout << "== XP to next level: " << this->expNext << endl;
	cout << "== HP: " << this->hp << "/" << this->hpMax << endl;
	cout << "== Damage: " << this->damageMin << " - "<< this->damageMax << endl;
	cout << "== Defence: " << this-defence << endl;
	cout << "==================" << endl;
	cout << "== Game difficulty is: " << this->difficulty << endl;
	cout << "==================" << endl;
}

 void Player::levelUp()
{
	while(this->exp >= this->expNext)
	{
		this->exp -= this->expNext;
		this->level++;
		this->exp = 0;
		this->expNext =
			(50 / 3)*(pow(level, 3) - 6 * pow(level, 3) + (17 * level) - 11);

		this->hpMax += 5;
		this->damageMin += 3;
		this->damageMax += 3;
		this->defence += 2;
	}

}