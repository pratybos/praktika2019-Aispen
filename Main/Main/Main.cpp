#include<iostream>
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
void PlayerStats();
void levelUp();
void PrintInventory();
void Shop();
void Buy();
void Sell();
void AddItem();

//STRUKTUROS

struct Items {
	string name;
	int value;
	int type;
	int dmg; //damage points
	int def; //defence points
	Items()
	{
		items[0].name = "Map Piece";
		items[0].value = 0;
		items[0].type = 10;
		items[1].name = "Potion";
		items[1].value = 50;
		items[1].type = 0;
		items[2].name = "Bronze Helm";    items[2].value = 80;   items[2].type = 2;  items[2].def = 8;
		items[3].name = "Bronze Armor";   items[3].value = 140;  items[3].type = 3;  items[3].def = 15;
		items[4].name = "Bronze Boots";   items[4].value = 80;   items[4].type = 4;  items[4].def = 6;
		items[5].name = "Bronze Sword";   items[5].value = 100;  items[5].type = 1;  items[5].dmg = 10;
		items[6].name = "Steel Helm";
		items[6].value = 800;
		items[6].type = 2;
		items[7].name = "Steel Armor";
		items[7].value = 1400;
		items[7].type = 3;
		items[8].name = "Steel Boots";
		items[8].value = 800;
		items[8].type = 4;
		items[9].name = "Steel Sword";
		items[9].value = 1000;
		items[9].type = 1;
		items[10].name = "Rune Helm";
		items[10].value = 2000;
		items[10].type = 2;
		items[11].name = "Rune Armor";
		items[11].value = 2500;
		items[11].type = 3;
		items[12].name = "Rune Boots";
		items[12].value = 2000;
		items[12].type = 4;
		items[13].name = "Rune Sword";
		items[13].value = 1500;
		items[13].type = 1;
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
vector<Inventory> Equipment;

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
		while (running)
		{
			IngameMenu();
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
// Reikia apsaugu
void InitGame()
{
	cout << endl << endl;
	cout << "=== Enter your hero name === " << endl;
	cout << "Name is: ";
	cin >> player.name;
	cout << "============================";

	system("cls");

	cout << endl << endl;
	cout << "===== Choose difficulty ===== " << endl;
	cout << "=== 1 - Normal / 2 - Hard === " << endl;
	cout << "Difficulty is: ";
	cin >> player.difficulty;
	cout << "=============================";

	system("cls");

}

void IngameMenu()
{
	system("cls");
	cout << "======= Game menu =======" << endl;
	cout << "  1. Travel" << endl;
	cout << "  2. Inventory" << endl;
	cout << "  3. Player Stats" << endl;
	cout << "  4. Shop" << endl;
	cout << "  5. Save game" << endl;
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
		system("pause");
		break;
	case 3:
		PlayerStats();
		system("pause");
		break;
	case 4:
		Shop();
		break;
	case 5:
		break;
	default:
		break;
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
	cout << "==================" << endl;
	cout << "== Game difficulty is: " << player.difficulty << endl;
	cout << "==================" << endl;
}

void levelUp()
{
	while (player.exp >= player.expNext)
	{
		player.exp -= player.expNext;
		player.level++;
		player.exp = 0;
		player.expNext =
			(50 / 3)*(pow(player.level, 3) - 6 * pow(player.level, 3) + (17 * player.level) - 11);

		player.hpMax += 5;
		player.damageMin += 3;
		player.damageMax += 3;
		player.defence += 2;
	}

}

void PrintInventory()
{
	system("cls");
	cout << "=== Inventory ===" << endl;
	cout << "You have gold: " << player.gold << endl;
	cout << "You have items: " << player.NumberOfItems << endl;
	cout << "==================" << endl;
	for (int i = 0; i < Inv.size(); i++)
	{
		cout << Inv[i].name;
		if (Inv[i].dmg != 0) { cout << " |DMG: " << Inv[i].dmg; }
		if (Inv[i].def != 0) { cout << " |DEF: " << Inv[i].def; }
		cout << " |Price: " << Inv[i].value << endl;
	}
	cout << "==================" << endl;
	cout << "1. Equip ===" << endl;
	cout << "2. Remove equiped ===" << endl;
	cout << "0. Leave ===" << endl << endl;
	cout << "== Your choice: ";
}

void Shop()
{
	system("cls");
	cout << "=== Shop ===" << endl;
	cout << "1. Buy ===" << endl;
	cout << "2. Sell ===" << endl;
	cout << "0. Leave ===" << endl << endl;
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
		IngameMenu();
		break;

	default:
		break;
	}

}

void Buy()
{
	system("cls");
	cout << "=== BUY ===" << endl;
	for (int i = 1; i <= 13; i++)
	{
		cout << i << ". " << items[i].name << " Price: " << items[i].value << endl;
	}
	cout << "0. Go back" << endl;
	cout << "Your gold: " << player.gold << endl;
	cout << "=== Your choice: ";
	cin >> choice;

	if (choice == 0) {
		Shop();
	}
	else if (choice < 0 || choice > 13)
	{
		cout << "Item does exsist" << endl;
		system("pause");
		Buy();
	}
	else if (player.gold < items[choice].value) {
		cout << "Not enough gold" << endl;
		system("pause");
		Buy();
	}
	else if (player.gold >= items[choice].value) // pirkimas
	{
		player.gold -= items[choice].value;
		player.NumberOfItems += 1;
		Inv.push_back({ items[choice].name, items[choice].value, items[choice].type, items[choice].dmg, items[choice].def});
		Buy();
	}
}

void Sell()
{
	system("cls");
	cout << "=== SELL ===" << endl;
	for (int i = 0; i < Inv.size(); i++)
	{
		cout << i+1 << ". " << Inv[i].name;
		if (Inv[i].dmg != 0) { cout << " |DMG: " << Inv[i].dmg; }
		if (Inv[i].def != 0) { cout << " |DEF: " << Inv[i].def; }
		cout << " |Price: " << Inv[i].value << endl;
	}
	cout << "==================" << endl;
	cout << "0. Go back" << endl;
	cout << "Your gold: " << player.gold << endl;
	cout << "=== Enter item number to sell choice: ";
	cin >> choice;
	player.gold += Inv[choice].value;
	player.NumberOfItems -= 1;
	Inv.erase(Inv.begin() + (choice-1)); // Neveikia kai issitrina visi
}

void AddItem()
{

}