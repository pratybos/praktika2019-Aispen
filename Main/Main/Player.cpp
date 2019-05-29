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
}


Player::~Player()
{


}

//Functions
void Player::InitPlayer(int level, std::string name)
{
	this->name = "Null";
	this->level = level;
	this->exp = 0;
	this->expNext = level*100;
	this->hp = 10;
	this->hpMax = 10;
	this->damageMin = 2;
	this->damageMax = 4;
	this->defence = 5;
}