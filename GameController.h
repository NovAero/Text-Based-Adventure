#pragma once
#include <fstream>
#include "String.h"
#include "Spell.h"
#include "Room.h"
#include "Cat.h"
#include "ManaFtn.h"
#include "Enemy.h"
#include "Scroll.h"
#include "Door.h"
#include "Key.h"


#define FAERIE_ID 4


class GameController
{
public:

	GameController(String& playerName, Object* room00, Object* room01, Object* room02, Object* room10, Object* room11, Object* room12, Object* room20, Object* room21, Object* room22);
	~GameController();

public:


	void RunGame(int roomX, int roomY, bool isNewRoom);
	void LoadRoom(Room& toLoad, bool isNewRoom);
	void LoadRoom(int x, int y, bool isNewRoom);

	void GenerateRooms(Object* room00, Object* room01, Object* room02, Object* room10, Object* room11, Object* room12, Object* room20, Object* room21, Object* room22);

	void LoadCombat();

	void MHandlerNorth(int X, int Y);
	void MHandlerEast(int X, int Y, bool hasCemKey, bool levActive);
	void MHandlerSouth(int X, int Y);
	void MHandlerWest(int X, int Y, bool hasBoatKey, bool dispelMagUsed);

	void EndGameHandler();
	
	void KeyChecker(Object& obj);


	//player funcs

	void Attack();

	void Use(int itemID);

	void Cast(int spellID);
	void Cast(String& spellName);
	void Cast(const char* spellName);

	void DisplayInventory();
	void DisplaySpellbook();

	int FindFirstEmpty();
	void AddToInventory(Object& toAdd);
	bool InvHasCopy(Object& obj);

	int InvHas(int ID);
	int InvHas(String& itemName);

	bool FindSpell(int spellID);
	bool FindSpell(String& find);
	bool FindSpell(const char* find);

	void GiveSpellAccess(int spellID);

	void Hurt(int damage);

	int GetMana();
	void SetMana(int mana);

public:

	bool dispelMagUsed = false;

	bool fStoneActive = false;
	bool levActive = false;
	bool SwAActive = false;
	bool hasRustKey = false;
	bool hasCemKey = false;

private:

	String name;

	String command;

	Room rooms[3][3];

	bool canPickup[20] = { false,false,false,false,true,true,false,false,false,false,true,true,true ,true ,true ,true ,true ,true ,true ,true };

	Object inventory[5];
	Spell spellbook[10];

	int health = 30;
	const int maxHealth = 30;

	int mana = 15;
	const int maxMana = 15;

};