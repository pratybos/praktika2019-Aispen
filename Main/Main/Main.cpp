#include<iostream>
#include"stdlib.h"
#include <cstdlib>
#include<iomanip>
#include<ctime>
#include<string>
#include<vector>
#include <fstream>
#include <windows.h>

using namespace std;

//KINTAMIEJI
bool running = true;
int choice = 0;


//FUNKCIJOS
void MainMenu(); // start menu
void InitGame(); // name and difficulty
void IngameMenu(); 
void levelUp();
void PlayerStats();
void Travel();
void Battle();
void PrintInventory();
void Shop();
void Buy();
void Sell();
void Equip();
void rEquip();
void Save();
void Load();
void Story();
void Achievements();
void Rating();
void Rules();
//STRUKTUROS

struct Items {
	string name;
	int value;
	int type;
	int dmg; //damage points
	int def; //defence points
	Items()
	{
		items[0].name = "Map Piece";      items[0].value = 0;      items[0].type = 0;
		items[1].name = "Potion";         items[1].value = 50;     items[1].type = 0;
		items[2].name = "Bronze Helm";    items[2].value = 80;     items[2].type = 2;  items[2].def = 8;
		items[3].name = "Bronze Armor";   items[3].value = 140;    items[3].type = 3;  items[3].def = 15;
		items[4].name = "Bronze Boots";   items[4].value = 80;     items[4].type = 4;  items[4].def = 6;
		items[5].name = "Bronze Sword";   items[5].value = 100;    items[5].type = 1;  items[5].dmg = 10;
		items[6].name = "Steel Helm";     items[6].value = 800;    items[6].type = 2;  items[6].def = 16;
		items[7].name = "Steel Armor";    items[7].value = 1400;   items[7].type = 3;  items[7].def = 30;
		items[8].name = "Steel Boots";    items[8].value = 800;    items[8].type = 4;  items[8].def = 12;
		items[9].name = "Steel Sword";    items[9].value = 1000;   items[9].type = 1;  items[9].dmg = 20;
		items[10].name = "Rune Helm";     items[10].value = 2000;  items[10].type = 2; items[10].def = 24;
		items[11].name = "Rune Armor";    items[11].value = 2500;  items[11].type = 3; items[11].def = 45;
		items[12].name = "Rune Boots";    items[12].value = 2000;  items[12].type = 4; items[12].def = 18;
		items[13].name = "Rune Sword";    items[13].value = 1500;  items[13].type = 1; items[13].dmg = 30;
	}
}items[13];

struct Player{
	string name;
	int level = 1;
	int exp = 0;
	int expNext = static_cast<int>((50 / 3)*(pow(level, 3) - 6 * pow(level, 2) + (17 * level) - 12)) + 20;
	int hp = hpMax;
	int hpMax = 20;
	int damageMin = 4;
	int damageMax = 6;
	int defence = 6;
	int accuracy = 8;
	int difficulty; //1 lengvas //2 sunkus
	int NumberOfItems = 0;
	int potions = 0;
	int gold = 1000;
	int deathcount = 0;
	int mappiece = 0;
	int achv1 = 0; // put on sword
	int achv2 = 0; // put on helm
	int achv3 = 0; // put on armor
	int achv4 = 0; // boots
	int achvBUY = 0; // buy 1, 10, 100 item
	int achvSELL = 0; // sell 1, 10, 100 item
	int achvLVL = level; // reach lvl 10, 25, 50
	int achvKILL = 0; //kill 10, 100
}player;

struct Enemy {
	int level = player.level;
	int hpMax = player.hpMax*0.7;
	int hp = hpMax;
	int damageMax = player.damageMax *0.7;
	int damageMin = (damageMax *0.5);
	int accuracy = (player.accuracy / 2);
	int defence = player.defence / 2;
}enemy;

struct Inventory {
	string name;
	int value;
	int type;
	int dmg; //damage points
	int def; //defence points
}Invv;

vector<Inventory> Inv; //Inv.insert(Inv.begin(), { items[0].name = "", items[0].value = 0, items[0].type = 0, items[0].dmg = 0, items[0].def = 0 });
Inventory Equipment[3];

int main()
{
	//srand(time(NULL));


	while(running)
	{
		MainMenu();
	}

	return 0;
}

void MainMenu()
{
	cout << "======= Main Menu =======" << endl;
	cout << "  1. New Game" << endl;
	cout << "  2. Game Rules" << endl;
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
		InitGame();
		IngameMenu();
		break;
	case 2:
		Rules();
		break;
	default:
		break;
	}
}

void InitGame()
{
	system("cls");
	cout << endl << endl;
	cout << "=== Enter your hero name === " << endl;
	cout << "Name is: ";
	cin >> player.name;
	cout << "============================";

	system("cls");
	while (true)
	{
		cout << endl << endl;
		cout << "===== Choose difficulty ===== " << endl;
		cout << "=== 1 - Normal / 2 - Hard === " << endl;
		cout << "Difficulty is: ";
		cin >> player.difficulty;
		cout << "=============================";
		if (player.difficulty == 1 || player.difficulty == 2)
		{
			break;
		}
		cout << "No such difficulty" << endl;
	}

	system("cls");
	Inv.insert(Inv.begin(), { items[0].name = "", items[0].value = 0, items[0].type = 0, items[0].dmg = 0, items[0].def = 0 });
}

void IngameMenu()
{
	while (running)
	{
		system("cls");
		cout << "======= Game menu =======" << endl;
		cout << "  1. Travel" << endl;
		cout << "  2. Inventory" << endl;
		cout << "  3. Player Stats" << endl;
		cout << "  4. Shop" << endl;
		cout << "  5. Achievements" << endl;
		cout << "  0. Quit game" << endl;
		cout << "=========================" << endl;
		cout << "Your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 0:
			running = false;
			break;
		case 1:
			Travel();
			break;
		case 2:
			PrintInventory();
			break;
		case 3:
			PlayerStats();
			break;
		case 4:
			Shop();
			break;
		case 5:
			Achievements();
			break;
		default:
			break;
		}
	}
}

void PlayerStats()
{
	system("cls");
	cout << "== Player Stats ==" << endl;
	cout << "== Name: " << player.name << endl;
	cout << "== Level: " << player.level << endl;
	cout << "== Current XP: " << player.exp << endl;
	cout << "== XP to next level: " << player.expNext << endl;
	cout << "== HP: " << player.hp << "/" << player.hpMax << endl;
	cout << "== Damage: " << player.damageMin << " - " << player.damageMax << endl;
	cout << "== Defence: " << player.defence << endl;
	cout << "====== Gear =====" << endl;
	cout << "Sword [ " << Equipment[0].name << " ]" << " + " << Equipment[0].dmg << " DMG" << endl;
	cout << "Helm  [ " << Equipment[1].name << " ]" << " + " << Equipment[1].def << " DEF" << endl;
	cout << "Armor [ " << Equipment[2].name << " ]" << " + " << Equipment[2].def << " DEF" << endl;
	cout << "Boots [ " << Equipment[3].name << " ]" << " + " << Equipment[3].def << " DEF" << endl;
	cout << "==================" << endl;
	cout << "== Game difficulty is: " << player.difficulty << endl;
	cout << "==================" << endl;
	system("pause");
}

void levelUp()
{
	while (player.exp >= player.expNext)
	{
		player.exp -= player.expNext;
		player.level++;
		player.expNext = 20*player.level;
		player.hpMax += 5;
		player.damageMin += 3;
		player.damageMax += 3;
		player.defence += 2;
		player.accuracy += 1;
	}
	return;
}

void Travel()
{
	system("cls");
	cout << " ENEMEY IS FOUND" << endl;
	cout << "=================" << endl;
	cout << "Level: " << enemy.level << " HP: " << enemy.hpMax << endl;
	cout << "=================" << endl;
	cout << "1. Fight" << endl;
	cout << "2. Run" << endl;
	cout << "=================" << endl;

	cin >> choice;
	switch (choice)
	{
	case 1:
		Battle();
		break;
	case 2:
		return;
		break;
	case 0:
		break;
	default:
		cout << "No such option" << endl;
	}

}

void Battle()
{
	system("cls");
	bool isAliveMob = true;
	bool IsAlivePlayer = true;
	int chance;
	//enemy
	int MhpMax = enemy.hpMax;
	int Mhp = enemy.hpMax;

	//player
	int Php = player.hpMax;
	int PhpMax = player.hpMax;

	while (isAliveMob && IsAlivePlayer)
	{
		cout << "====BATTLE====" << endl;
		cout << "Monster HP: "<< Mhp << " / " << MhpMax << endl;
		cout << "==============" << endl;
		cout << "Your HP: " << Php << " / " << PhpMax << endl;
		cout << "==============" << endl << endl;
		cout << "1. Attack" << endl;
		cout << "2. Drink HP Potion" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			if (chance = rand() % player.accuracy >= player.accuracy/2)
			{
				chance = rand() % 100;
				if (chance >= 50)
				{
					Mhp -= player.damageMax;
					cout << "Hit enemy for " << player.damageMax << endl;
				}
				if (chance < 50)
				{
					Mhp -= player.damageMin;
					cout << "Hit enemy for " << player.damageMin << endl;
				}
				if (Mhp <= 0)
				{
					isAliveMob = false;
				}
			}
			else
			{
				cout << "You missed" << endl;
			}
			break;
		case 2:
			if (player.potions > 0)
			{
				Php += 10 + (player.level*0.5);
				player.potions--;
				player.NumberOfItems--;
			}
			else 
			{
				cout << "You dont have any potions"<< endl;
			}
			break;
		default:
			cout << "No such option" << endl;
		}
		if (chance = rand() % enemy.accuracy >= enemy.accuracy/2)
		{
			chance = rand() % 100;
			if (chance >= 50)
			{
				Php -= enemy.damageMax;
				cout << "Enemy hit you enemy for " << enemy.damageMax << endl;
			}
			if (chance < 50)
			{
				Php -= enemy.damageMin;
				cout << "Enemy hit you enemy for " << enemy.damageMin << endl;
			}
			if (Php <= 0)
			{
				IsAlivePlayer = false;
			}
		}
		else
		{
			cout << "Enemy missed" << endl;
		}
	}
	if (!isAliveMob)
	{
		cout << "====BATTLE====" << endl;
		cout << "Monster HP: " << Mhp << " / " << MhpMax << endl;
		cout << "==============" << endl;
		cout << "Your HP: " << Php << " / " << PhpMax << endl;
		cout << "==============" << endl;
		cout << "You won and got: " << 10 * enemy.level*player.difficulty << "XP and Gold:" << 10 * enemy.level / 2 * player.difficulty << endl;
		player.exp += 10 + (enemy.level*player.difficulty);
		player.gold += 5 + (enemy.level / 2 * player.difficulty);
		levelUp();
		player.achvKILL++;
		if (chance = rand() % 100 > 50)
		{
			Inv.push_back({ items[0].name, items[0].value, items[0].type, items[0].dmg, items[0].def });
			player.mappiece++;
			cout << "You found map piece" << endl;
		}
		system("pause");
	}
	else if (!IsAlivePlayer)
	{
		cout << "====BATTLE====" << endl;
		cout << "Monster HP: " << Mhp << " / " << MhpMax << endl;
		cout << "==============" << endl;
		cout << "Your HP: " << Php << " / " << PhpMax << endl;
		cout << "==============" << endl;
		cout << "You died..." << player.deathcount << " / 3 " << endl;
		player.gold /= 2;
		player.deathcount++;
		system("pause");
	}
	Story();
	return;
}

void PrintInventory()
{
	while(true)
	{
		system("cls");
		cout << "=== Inventory ===" << endl;
		cout << "You .have gold: " << player.gold << endl;
		cout << "You have items: " << player.NumberOfItems << endl;
		cout << "You have HP potions: " << player.potions << endl;
		cout << "==================" << endl;
		for (int i = 1; i < Inv.size(); i++)
		{
			cout << i << ". " << Inv[i].name;
			cout << " | DMG: " << Inv[i].dmg;
			cout << "  |DEF: " << Inv[i].def;
			cout << " | Price: " << Inv[i].value << endl;
		}
		cout << "==================" << endl;
		cout << "1. Equip ===" << endl;
		cout << "2. Remove equiped ===" << endl;
		cout << "0. Leave ===" << endl << endl;
		cout << "== Your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			Equip();
			break;
		case 2:
			rEquip();
			break;
		case 0:
			return;
			break;
		default:
			cout << "No such option" << endl;
			break;
		}
	}
}

void Shop()
{
	system("cls");
	cout << "=== Shop ===" << endl;
	cout << "1. Buy ===" << endl;
	cout << "2. Sell ===" << endl;
	cout << "0. Leave shop ===" << endl << endl;
	cout << "== Your choice: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		Buy();
		break;
	case 2:
		Sell();
		break;
	case 0:
		break;
	default:
		cout << "No such option" << endl;
	}

}

void Buy()
{
	while (true)
	{
		system("cls");
		cout << "=== BUY ===" << endl;
		for (int i = 1; i <= 13; i++)
		{
			cout << i << ". " << items[i].name << " Price: " << items[i].value << endl;
		}
		cout << "0. Go back" << endl;
		cout << "Your gold: " << player.gold << endl;
		cout << "=================" << endl;;
		cout << "=== Your choice: ";
		cin >> choice;

		if (choice == 0) {
			break;
			return;
		}
		else if (choice < 0 || choice > 13)
		{
			cout << "Item does exsist" << endl;
			system("pause");
			continue;
		}
		else if (player.gold < items[choice].value) {
			cout << "Not enough gold" << endl;
			system("pause");
			continue;
		}
		else if (player.gold >= items[choice].value) // pirkimas
		{
			if (choice == 1)
			{
				player.gold -= items[choice].value;
				player.NumberOfItems += 1;
				player.potions++;
				continue;
			}
			else if (choice > 1)
			{
				player.gold -= items[choice].value;
				player.NumberOfItems += 1;
				Inv.push_back({ items[choice].name, items[choice].value, items[choice].type, items[choice].dmg, items[choice].def });
				continue;
			}
			player.achvBUY++;
		}
	}
}

void Sell()
{
	while (true)
	{
		system("cls");
		cout << "=== SELL ===" << endl;
		for (int i = 1; i < Inv.size(); i++)
		{
			if (Inv[i].name != "") { cout << i << ". " << Inv[i].name; }
			if (Inv[i].dmg != 0) { cout << " |DMG: " << Inv[i].dmg; }
			if (Inv[i].def != 0) { cout << " |DEF: " << Inv[i].def; }
			if (Inv[i].value != 0) { cout << " |Price: " << Inv[i].value << endl; }
		}
		
		cout << "==================" << endl;
		cout << "0. Go back" << endl;
		cout << "Your gold: " << player.gold << endl;
		cout << "=== Enter item number to sell choice: ";
		cin >> choice;
		if (choice == 0)
		{
			break;
		}
		else if (Inv.size() == 1 || choice > Inv.size())
		{
			cout << "=====================" << endl;
			cout << "Nothing to sell" << endl;
			system("pause");
		}
		else if (Inv.size() > 1) // apsauga+
		{
			player.gold += Inv[choice].value;
			player.NumberOfItems -= 1;
			Inv.erase(Inv.begin() + choice);
			player.achvSELL++;
		}

	}
}

void Equip()
{
	while (true)
	{
		choice = 0;
		system("cls");
		cout << "=== What to equip ===" << endl;
		cout << "======= Types =======" << endl;
		cout << "1 - Sword | 2 - Helm | 3 - Armor | 4 - Boots" << endl;
		cout << "=====================" << endl;
		for (int i = 1; i < Inv.size(); i++)
		{
			cout << i << ". " << Inv[i].name;
			cout << " | DMG: " << Inv[i].dmg;
			cout << " | DEF: " << Inv[i].def;
			cout << " | Price: " << Inv[i].value << endl;
		}
		cout << "====================" << endl;
		cout << "0. Go back to inventory ===" << endl << endl;
		cout << "Enter number to equip: ";
		cin >> choice;
		if (choice == 0)
		{
			break;
		}
		else if (choice < 0 || choice > Inv.size() || Inv[choice].name == "")
		{
			cout << "No such item" << endl;
			system("pause");
			continue;
		}
		else if (Inv[choice].type == 1)
		{
			if (Equipment[0].dmg == 0)
			{
				Equipment[0] = { Inv[choice].name, Inv[choice].value, Inv[choice].type, Inv[choice].dmg, Inv[choice].def };
				player.damageMin += Inv[choice].dmg;
				player.damageMax += Inv[choice].dmg;
				Inv.erase(Inv.begin() + choice);
				player.achv1++;
			}
			else
			{
				cout << "Already equiped sword" << endl;
				system("pause");
				continue;
			}
		}
		else if (Inv[choice].type == 2)
		{
			if (Equipment[1].def == 0)
			{
				Equipment[1] = { Inv[choice].name, Inv[choice].value, Inv[choice].type, Inv[choice].dmg, Inv[choice].def };
				player.defence += Inv[choice].def;
				Inv.erase(Inv.begin() + choice);
				player.achv2++;
			}
			else
			{
				cout << "Already equiped helm"<< endl;
				system("pause");
				continue;
			}
		}
		else if (Inv[choice].type == 3)
		{
			if (Equipment[2].def == 0)
			{
				Equipment[2] = { Inv[choice].name, Inv[choice].value, Inv[choice].type, Inv[choice].dmg, Inv[choice].def };
				player.defence += Inv[choice].def;
				Inv.erase(Inv.begin() + choice);
				player.achv3++;
			}
			else
			{
				cout << "Already equiped armor" << endl;
				system("pause");
				continue;
			}
		}
		else if (Inv[choice].type == 4)
		{
			if (Equipment[3].def == 0)
			{
				Equipment[3] = { Inv[choice].name, Inv[choice].value, Inv[choice].type, Inv[choice].dmg, Inv[choice].def };
				player.defence += Inv[choice].def;
				Inv.erase(Inv.begin() + choice);
				player.achv4++;
			}
			else
			{
				cout << "Already equiped boots" << endl;
				system("pause");
				continue;
			}
		}
		else if (Inv[choice].type == 0)
		{
			cout << "Cant equip this" << endl;
			system("pause");
		}
	}
}

void rEquip()
{
	while (true)
	{
		system("cls");
		cout << "====== Gear =====" << endl;
		cout << "1. Sword [ " << Equipment[0].name << " ]" << " + " << Equipment[0].dmg << " DMG" << endl;
		cout << "2. Helm  [ " << Equipment[1].name << " ]" << " + " << Equipment[1].def << " DEF" << endl;
		cout << "3. Armor [ " << Equipment[2].name << " ]" << " + " << Equipment[2].def << " DEF" << endl;
		cout << "4. Boots [ " << Equipment[3].name << " ]" << " + " << Equipment[3].def << " DEF" << endl;
		cout << "0. to leave" << endl;
		cout << "==================" << endl;
		cout << "Enter number to remove " << endl;
		cin >> choice;

		if (choice == 0)
		{
			break;
		}
		else if (choice < 0 || choice > 4)
		{
			cout << "No such option" << endl;
			continue;
		}
		else if (choice == 1)
		{
			if (Equipment[0].dmg == 0) {
				cout << "No sword equiped" << endl;
				system("pause");
			}
			else
			{
				Inv.push_back({ Equipment[0].name, Equipment[0].value, Equipment[0].type, Equipment[0].dmg, Equipment[0].def });
				player.damageMin -= Equipment[0].dmg;
				player.damageMax -= Equipment[0].dmg;
				Equipment[0] = { Equipment[0].name = "", Equipment[0].value = 0, Equipment[0].type = 0, Equipment[0].dmg = 0, Equipment[0].def = 0 };
			}
		}
		else if (choice == 2)
		{
			if (Equipment[1].def == 0) {
				cout << "No helm equiped" << endl;
				system("pause");
			}
			else
			{
				Inv.push_back({ Equipment[1].name, Equipment[1].value, Equipment[1].type, Equipment[1].dmg, Equipment[1].def });
				player.defence -= Equipment[1].def;
				Equipment[1] = { Equipment[1].name = "", Equipment[1].value = 0, Equipment[1].type = 0, Equipment[1].dmg = 0, Equipment[1].def = 0 };
			}
		}
		else if (choice == 3)
		{
			if (Equipment[2].def == 0) {
				cout << "No armor equiped" << endl;
				system("pause");
			}
			else
			{
				Inv.push_back({ Equipment[2].name, Equipment[2].value, Equipment[2].type, Equipment[2].dmg, Equipment[2].def });
				player.defence -= Equipment[2].def;
				Equipment[2] = { Equipment[2].name = "", Equipment[2].value = 0, Equipment[2].type = 0, Equipment[2].dmg = 0, Equipment[2].def = 0 };
			}
		}
		else if (choice == 4)
		{
			if (Equipment[3].def == 0) {
				cout << "No boots equiped" << endl;
				system("pause");
			}
			else
			{
				Inv.push_back({ Equipment[3].name, Equipment[3].value, Equipment[3].type, Equipment[3].dmg, Equipment[3].def });
				player.defence -= Equipment[3].def;
				Equipment[3] = { Equipment[3].name = "", Equipment[3].value = 0, Equipment[3].type = 0, Equipment[3].dmg = 0, Equipment[3].def = 0 };
			}
		}

	}

}

void Story()
{
	int map=0;
	if (player.deathcount == 3)
	{
		cout << "==================================================" << endl;
		cout << "|You died third time, your body cant take anymore.|" << endl;
		cout << "|It is the end                                    |" << endl;
		cout << "==================================================" << endl;
		system("pause");
		exit(0);
	}
	if (player.mappiece == 4)
	{
		cout << "=========================================================================" << endl;
		cout << "|You finally found the last piece of the map and put the puzzle together|" << endl;
		cout << "|Unimaginable riches are waiting for you... Or not...                   |" << endl;
		cout << "=========================================================================" << endl;
		system("pause");
		exit(0);
	}
}

void Save()
{
	fstream failas;
	failas.open("taskai.txt");
	if (failas.good()) {
		failas << player.name << " ";
		failas << 10*player.level*(player.gold*0.1)*player.difficulty << " ";
		failas << endl;
	}

	failas.close();
	/*ofstream offput;
	offput.open("playerstats.txt");
	if (!offput.is_open())
	{
		cout << "Error while saving stats" << endl;
	}
	else
	{
		cout << "Saving Game..." << endl;
		//stats
		offput << player.name << "\n";
		offput << player.level << "\n";
		offput << player.exp << "\n";
		offput << player.expNext << "\n";
		offput << player.hp << "\n";
		offput << player.hpMax << "\n";
		offput << player.defence << "\n";
		offput << player.difficulty << "\n";
		offput << player.NumberOfItems << "\n";
		offput << player.gold << "\n";
	}
	offput.close();
	// GEAR
	offput.open("playergear.txt");
	if (!offput.is_open())
	{
		cout << "Error while saving gear" << endl;
	}
	else
	{
			for (int i = 0; i <= 3; i++)
			{
				offput << Equipment[i].name << "\n";
				offput << Equipment[i].value << "\n";
				offput << Equipment[i].type << "\n";
				offput << Equipment[i].dmg << "\n";
				offput << Equipment[i].def << "\n";
			}
	}
	offput.close();
			// inventory
	offput.open("playerinventory.txt");
	if (!offput.is_open())
	{
		cout << "Error while saving inventory" << endl;
	}
	else
	{
			for (int i = 0; i <= Inv.size(); i++)
			{
				offput << items[i].name << "\n";
				offput << items[i].value << "\n";
				offput << items[i].type << "\n";
				offput << items[i].dmg << "\n";
				offput << items[i].def << "\n";
			}
	}
	offput.close();

	cout << "Done Saving" << endl << endl;
	system("pause");*/
}
/*
void Load()
{
	ifstream input;
	input.open("playerstats.txt");
	if (!input)
	{
		cout << "Error while loading stats" << endl;
	}
	else
	{
		cout << "Loading Stats..." << endl;
		while(!input.eof())
		input >> player.name;
		input >> player.level;
		input >> player.exp;
		input >> player.expNext;
		input >> player.hp;
		input >> player.hpMax;
		input >> player.defence;
		input >> player.difficulty;
		input >> player.NumberOfItems;
		input >> player.gold;
	}
	input.close();
	// GEAR
	input.open("playergear.txt");
	if (!input)
	{
		cout << "Error while loading gear" << endl;
	}
	else
	{
		cout << "Loading Gear..." << endl;
			for (int i = 0; i <= 3; i++)
			{
				input >> Equipment[i].name;
				input >> Equipment[i].value;
				input >> Equipment[i].type;
				input >> Equipment[i].dmg;
				input >> Equipment[i].def;
			}
	}
	input.close();
			// inventory
	input.open("playerinventory.txt");
	if (!input)
	{
		cout << "Error while loading inventory" << endl;
	}
	else
	{
		cout << "Loading Inventory..." << endl;
		int count = 1;
		int value;
		int type;
		int dmg;
		int def;
		string name;
		Inv.insert(Inv.begin(), { items[0].name = "", items[0].value = 0, items[0].type = 0, items[0].dmg = 0, items[0].def = 0 });
		Inv.push_back(Invv);
		while(!input.eof())
		{
			Inv.insert(Inv.begin() +count, { items[count].name = "", items[count].value = 0, items[count].type = 0, items[count].dmg = 0, items[count].def = 0 });
			input >> name;
			input >> value;	
			input >> type;
			input >> dmg;
			input >> def;
			Inv.push_back(Inv.begin() + count, {Inv[count].name = name, Inv[count].value = value, items[count].type = type, items[count].dmg = dmg, items[count].def = def});
			count++;
		}
	}
	input.close();

	cout << "Loading complete" << endl << endl;
	system("pause");
}
// -- ^^
*/
void Achievements()
{
	cout << "==== UNLOCKED ACHIEVEMENTS ====" << endl << endl;
	if (player.achv1 > 0)
	{
		cout << "Rising hero: put sword on" << endl;
	}
	if (player.achv2 > 0)
	{
		cout << "Rising hero: put helmet on" << endl;
	}
	if (player.achv3 > 0)
	{
		cout << "Rising hero: put armor on" << endl;
	}
	if (player.achv4 > 0)
	{
		cout << "Rising hero: put boots on" << endl;
	}
	// BUY
	if (player.achvBUY >= 10)
	{
		cout << "A few of those: Buy 10 items" << endl;
	}
	if (player.achvBUY >= 50)
	{
		cout << "Shopping spree: Buy 50 items" << endl;
	}
	if (player.achvBUY >= 100)
	{
		cout << "Too rich: Buy 100 items" << endl;
	}
	// SELL
	if (player.achvSELL >= 10)
	{
		cout << "Small salary: Sell 10 items" << endl;
	}
	if (player.achvSELL >= 50)
	{
		cout << "Normal haul: Sell 50 items" << endl;
	}
	if (player.achvSELL >= 100)
	{
		cout << "Making a living for a generation: Sell 100 items" << endl;
	}	
	// LEVEL
	if (player.achvLVL >= 10)
	{
		cout << "Little Man: Reach level 10" << endl;
	}
	if (player.achvLVL >= 25)
	{
		cout << "Known warrior: Reach level 25" << endl;
	}
	if (player.achvLVL >= 50)
	{
		cout << "Legend: Reach level 50" << endl;
	}
	// KILL
	if (player.achvKILL >= 10)
	{
		cout << "Village guard: Kill 10 enemies" << endl;
	}
	if (player.achvKILL >= 50)
	{
		cout << "Killing spree: Kill 50 enemies" << endl;
	}
	if (player.achvKILL >= 100)
	{
		cout << "Village guard: Kill 100 enemies" << endl;
	}
	system("pause");
}

void Rules()
{
	system("start rules.html");
	return;
}

void Rating()
{
	string file_header = "<html><head><link rel=\"stylesheet\" type=\"text/css\" href=\"main.css\"><title>Rezultatai</title></head><body>";
	string file_tail = "</body></html>";
	ofstream failas;
	ifstream taskai;

	int kiekis = -1;
	string a;
	int b;
	taskai.open("taskai.txt");
	if (taskai.good()) {
		while (!taskai.eof()) {
			taskai >> a;
			taskai >> b;
			kiekis++;
		}
	}
	taskai.close();
	string sorai[9000];
	int sortai[9000];

	taskai.open("taskai.txt");
	if (taskai.good()) {
		for (int i = 0; i < kiekis; i++) {
			taskai >> sorai[i];
			taskai >> sortai[i];
		}
	}
	
	system("start rezultatai.html");
	failas.close();
}
// -- ^^