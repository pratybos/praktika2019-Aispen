#include<iostream>
#include"stdlib.h"
#include <cstdlib>
#include<iomanip>
#include<ctime>
#include<string>
#include<vector>

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
void PrintInventory();
void Shop();
void Buy();
void Sell();
void Equip();
void rEquip();

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
		items[13].name = "Rune SWORD";    items[13].value = 1500;  items[13].type = 1; items[13].dmg = 30;
	}
}items[13];

struct Player{
	string name;
	int level = 1;
	int exp = 0;
	int expNext = static_cast<int>((50 / 3)*(pow(level, 3) - 6 * pow(level, 2) + (17 * level) - 12)) + 20;
	int hp = 10, hpMax = 10;
	int damageMin = 4, damageMax = 6;
	int defence = 6;
	int difficulty; //1 lengvas //2 sunkus
	int NumberOfItems = 0;
	int gold = 1000;
}player;

struct Inventory {
	string name;
	int value;
	int type;
	int dmg; //damage points
	int def; //defence points
};

vector<Inventory> Inv;
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
		InitGame();
		IngameMenu();
		break;
	case 2:

		break;
	case 3:

		break;
	default:
		break;
	}
}
// Reikia apsaugu
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
		cout << "  5. TEST" << endl;
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
			for (int i = 0; i < 5; i++)
			{
				cout << i << "Item [ " << Equipment[i].name << " ]" << endl;
			}
			system("pause");
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
		player.expNext =
			(50 / 3)*(pow(player.level, 3) - 6 * pow(player.level, 3) + (17 * player.level) - 11);

		player.hpMax += 5;
		player.damageMin += 3;
		player.damageMax += 3;
		player.defence += 2;
	}
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
			player.gold -= items[choice].value;
			player.NumberOfItems += 1;
			Inv.push_back({ items[choice].name, items[choice].value, items[choice].type, items[choice].dmg, items[choice].def });
			continue;
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
		else if (choice > 3 || choice < 0) 
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

